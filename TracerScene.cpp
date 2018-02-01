#include "TracerScene.hpp"
#include <vector>
#include "svpng.inc"

TracerView::TracerView(const int height ,const int width,
const float focal_length):
_image_height(height),_image_width(width),_scene(nullptr),_image_data(nullptr),
_focal_length(focal_length),_left(-0.5f),_right(0.5f),
_upper(0.5f),_bottom(-0.5f),_shading_model(nullptr)
{
    _pos = Vector3<float>(0,0,1.0f);
    init_ray_dir();
}
void TracerView::setPos(Vector3<float > pos)
{
    _pos = pos;
}
void TracerView::init_ray_dir() // init ray direction
{
    _ray_dir.clear();
    for(int i = 0;i<_image_height;++i)
    {
        float dy = _bottom + (_upper - _bottom)*(i+0.5f) /_image_height;
        for (int j = 0; j < _image_width; ++j)
        {
            float dx = _left + (_right - _left)*(j + 0.5f) /_image_width ;
            _ray_dir.push_back(Vector3<float>(dx,dy,-_focal_length));
        }
    }
}

void TracerView::setScene(TracerScene * scene)
{
    if(this->_scene != nullptr)
    {
        ;
    }
    this->_scene = scene;

}

void TracerView::setShadingModel(BaseShadingModel *model)
{
    if(this->_shading_model != nullptr)
    {
        ;
    }
    this->_shading_model = model;

}
Color4 TracerView::compute_pixel(const Surface<float> & sur,const Vector3<float>& view_pos,int depth)
{
    Color4 ans(0.0f,0.0f,0.0f);
    if( depth == 0)
    {
        return ans;
    }
    int len = this->_scene->getLightListLength();
    int objlen = this->_scene->getObjectListLength();
    Surface <float > tt;
    for(int i = 0;i<len;++i) // 枚举光源
    {
        const Light * light_ptr = this->_scene->getLight(i);
        float l = 1e-5, r = floatInf;
        Vector3 <float> inter_pos = sur._pos;
        Vector3 <float> ray_dir = light_ptr->getPos()- inter_pos;
        bool flag = false;
        for(int j = 0;j<objlen;++j)  //算影子枚举物体
        {
            const TracerObject <float> * obj = this->_scene->getObject(j);
            if(obj->intersection(inter_pos,ray_dir,tt,l,r))
            {
                flag = true;
                break;  // 碰到障碍物直接 确定处于阴影之中，暂不考虑透明物体
            }
        }
        if(flag == false)
            ans = ans + this->_shading_model->Shading(*light_ptr, sur, view_pos);
        else 
        {
            // 如果在阴影中则不考虑漫反射
            Surface <float >tmp = sur;
            tmp._mat._color = Color4(0.0f,0.0f,0.0f);
            ans = ans + this->_shading_model->Shading(*light_ptr,tmp,view_pos);
        }
    }

    Vector3 <float > n = sur._normal.normalize();
    Vector3 <float > d = (sur._pos - view_pos).normalize();
    Vector3 <float > r = d - 2*(d*n)*n;
    Surface <float > res ;
    float left = 1e-4; 
    float right = floatInf;
    bool intersect_flag = false;
    for(int i = 0;i<objlen;++i)
    {
        const TracerObject<float > *obj = this->_scene->getObject(i);
        if(obj->intersection(sur._pos,r,res,left,right))
        {
            intersect_flag = true;
        }
    }
    if(intersect_flag)
    {
        ans = ans +  compute_pixel(res,sur._pos,depth-1)*sur._mat._reflection_rate;
    }

    return ans;
}
void TracerView::render()
{
    Vector3 <float > view_pos = _pos + Vector3<float>(0,0,_focal_length);
    _image_data =  new Color4[_image_height*_image_width];
    if(this->_shading_model == nullptr)
    {
        LOG("shading model null ptr\n");
        return ;
    }
    if(this->_scene  == nullptr)
    {
        LOG("scene null ptr\n");
        return;
    }
    for(int i = 0;i<_image_height;++i)
    {
        for(int j =0;j<_image_width;++j)
        {
            Vector3<float > & dir = _ray_dir[i*_image_width+j];
            int len = this->_scene->getObjectListLength();
            float l = 1.0f;
            float r = floatInf;
            Surface <float>ans ;
            bool intersect_flag = false;
            for(int t = 0 ; t<len;++t)
            {
                const TracerObject <float>* obj = this->_scene->getObject(t);
                Surface <float> res ;
                if(obj->intersection(view_pos,dir,res,l,r))
                {
                  //  LOG("intersect in %d %d \n",i,j);
                    //todo 
                    ans = res;
                    intersect_flag = true;
                }
            }
            // 反射的深度为2
            if(intersect_flag == true)
                _image_data[i * _image_width + j] = compute_pixel(ans, view_pos,2);

        }

    }

}
int TracerView::savePng(const char * file_name)
{
    if(_image_data == nullptr)
    {
        LOG("null image ptr\n");
        return -1;
    }
    unsigned char * img = new unsigned char[_image_height*_image_width*3];
    for(int i = 0 ;i < _image_height*_image_width;++i)
    {
        img[i*3+ 0] = (unsigned char ) (std::min(this->_image_data[i].r*255.0f,255.0f));
        img[i*3+ 1] = (unsigned char ) (std::min(this->_image_data[i].g*255.0f,255.0f));
        img[i*3+ 2] = (unsigned char ) (std::min(this->_image_data[i].b*255.0f,255.0f));
    }
    svpng(fopen(file_name,"wb"),_image_width,_image_height,img,0);

}
void TracerView::setRange(float up, float down, float l, float r)
{
    this->_left = l;
    this->_right = r;
    this->_upper = up;
    this->_bottom = down;
    init_ray_dir();
}

int TracerScene::addObject(TracerObject <float>* obj)
{
    this->_object_list.push_back(obj);
}

const TracerObject<float> * TracerScene::getObject(int index)
{
    if(index >= _object_list.size()) 
        return nullptr;
    return _object_list[index];
}
const Light * TracerScene::getLight(int index)
{
    if(index >= _light_list.size())
        return nullptr;
    return _light_list[index];
}

int TracerScene::getObjectListLength()
{
    return _object_list.size();
}
int TracerScene::getLightListLength()
{
    return _light_list.size();
}
int TracerScene::addLight(Light * light)
{
    this->_light_list.push_back(light);
}


