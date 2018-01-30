#include "TracerScene.hpp"
#include <vector>
#include "svpng.inc"

TracerView::TracerView(const int height ,const int width,
const float focal_length):
_image_height(height),_image_width(width),_scene(nullptr),_image_data(nullptr),
_focal_length(focal_length),_left(-0.5f),_right(0.5f),
_upper(0.5f),_bottom(-0.5f)
{
    _pos = Vector3<float>(0,0,1.0f);
    _ray_dir.clear();
    init_ray_dir();
}

void TracerView::init_ray_dir() // init ray direction
{
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

void TracerView::render()
{
    Vector3 <float > view_pos = _pos + Vector3<float>(0,0,_focal_length);
    _image_data =  new Color4[_image_height*_image_width];
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
            for(int t = 0 ; t<len;++t)
            {
                const TracerObject <float>* obj = this->_scene->getObject(t);
                Surface <float> res ;
                if(obj->intersection(view_pos,dir,res))
                {
                    LOG("intersect in %d %d \n",i,j);
                    //todo 
                    _image_data[i*_image_width + j] = obj->getBaseColor();

                }
                //LOG("not intersect in %d %d \n",i,j);
            }

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
        img[i*3+ 0] = (unsigned char ) (this->_image_data[i].r*255.0f);
        img[i*3+ 1] = (unsigned char ) (this->_image_data[i].g*255.0f);
        img[i*3+ 2] = (unsigned char ) (this->_image_data[i].b*255.0f);
    }
    svpng(fopen(file_name,"wb"),_image_width,_image_height,img,0);

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

int TracerScene::getObjectListLength()
{
    return _object_list.size();
}

