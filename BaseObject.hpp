#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H 
#include <cmath>
#include <algorithm>

struct Color4{
    Color4(float _r,float _g,float _b):
    r(_r),g(_g),b(_b),a(1.0f)
    {}
    Color4():
    r(0.0f),g(0.0f),b(0.0f),a(1.0f){}
    Color4 operator*(const float k){
        return Color4(r*k,g*k,b*k);
    }
    Color4 operator*(const float k) const 
    {
        return Color4(r*k,g*k,b*k);
    }
    Color4 operator+(const Color4 & o)
    {
        return Color4(r+o.r,g+o.g,b+o.b);
    }
    float r,g,b,a;
};

template <typename Dtype>
struct Vector3{
    Vector3<Dtype>(Dtype _x,Dtype _y,Dtype _z):
    x(_x),y(_y),z(_z){}
    Vector3<Dtype>():
    x(0.0f),y(0.0f),z(0.0f){}
    Vector3<Dtype> normalize() const
    {
        Vector3<Dtype > ans(*this);
        Dtype len = sqrt(x*x+y*y+z*z);
        ans.x /= len;
        ans.y /= len;
        ans.z /= len;
        return ans; 
    }
    Vector3 <Dtype> normalize()
    {
        Dtype len = sqrt(x*x+y*y+z*z);
        this->x /= len;
        this->y /= len;
        this->z /= len;
        return *this;
    }
    Dtype x,y,z;
};

template <typename Dtype>
Dtype operator * (const Vector3<Dtype> &a,const Vector3<Dtype> &b)
{
    return a.x*b.x+ a.y*b.y+a.z*b.z;
}

template <typename Dtype>
Vector3<Dtype> operator * (const Dtype k,const Vector3<Dtype> &b)
{
    return Vector3<Dtype>(k*b.x,k*b.y,k*b.z);
}


template <typename Dtype>
Vector3 <Dtype> operator + (const Vector3<Dtype> &a,const Vector3<Dtype> &b)
{
    return Vector3<Dtype>(a.x+b.x,a.y+b.y,a.z+b.z);
}
template <typename Dtype>
Vector3 <Dtype> operator - (const Vector3<Dtype> &a,const Vector3<Dtype> &b)
{
    return Vector3<Dtype>(a.x-b.x,a.y-b.y,a.z-b.z);
}
template <typename Dtype>
struct Surface{
    Surface<Dtype>(const Vector3<Dtype> & pos,const Vector3<Dtype> & normal):
        _pos(pos),_normal(normal)
    {
    }
    Surface<Dtype>() {
    }
    Vector3 <Dtype> _pos;
    Vector3 <Dtype> _normal;
    Color4 _color;

};


template <typename Dtype>
class TracerObject {

    public:
    virtual bool intersection(const Vector3<Dtype> & origin ,
     const Vector3<Dtype> & dir ,
     Surface<Dtype> & sur
    ) const{};
    void setPos(const Vector3 <Dtype> & pos)
    {
        this->_pos = pos;
    }
    Color4 getBaseColor() const
    {
        return _base_color;
    }
    protected:
    Vector3 <Dtype> _pos;
    Color4 _base_color;

};

template <typename Dtype>
class Sphere : public TracerObject<Dtype>{
    public:
      Sphere<Dtype>(Dtype rad) : _radius(rad)
      {
          TracerObject<Dtype>::_base_color= Color4(1.0f, 1.0f, 1.0f);
      }

      bool intersection(const Vector3<Dtype> &origin,
                        const Vector3<Dtype> &dir,
                        Surface<Dtype> &sur) const
                        {
    Vector3 <Dtype > e_c = origin - TracerObject<Dtype>::_pos;
    Dtype delta = (dir * e_c)*(dir * e_c)-(dir*dir)*(e_c*e_c - _radius*_radius);
    if(delta < 0)
    {
        return false;
    }
    Dtype t_1 = (-1.0f* dir*(e_c) + sqrt(delta))/(dir*dir);
    Dtype t_2 = (-1.0f* dir*(e_c) - sqrt(delta))/(dir*dir);
    Dtype mint = std::min(t_1,t_2);
    if( std::max(t_1,t_2) < 1.0f)
        return false;
    sur._pos = origin + mint * dir;
    sur._normal = sur._pos - this->_pos;
    sur._color = this->_base_color;
    return true;


}
    protected:
    Dtype _radius;



};

#endif
