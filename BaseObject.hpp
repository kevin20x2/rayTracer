#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H 
#include <cmath>
#include <algorithm>
#include "Material.hpp"

const int _inf = 0x7f800000;
const float floatInf = *(float*)(&_inf);
template <typename Dtype>
struct Vector3{
    Vector3<Dtype>(Dtype _x,Dtype _y,Dtype _z):
    x(_x),y(_y),z(_z){}
    Vector3<Dtype>():
    x(0.0f),y(0.0f),z(0.0f){}
    Dtype length()
    {
        return sqrt(x*x+y*y+z*z);
    }
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
Vector3 <Dtype> cross(Vector3<Dtype>  a,Vector3 <Dtype>  b)
{
    return Vector3<Dtype>(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}

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
    Material _mat;
   // Dtype _specular_power;
    //Color4 _color;

};


template <typename Dtype>
class TracerObject {

    public:
    virtual bool intersection(const Vector3<Dtype> & origin ,
     const Vector3<Dtype> & dir ,
     Surface<Dtype> & sur,Dtype & t_0,Dtype &t_1
    ) const{};
    void setPos(const Vector3 <Dtype> & pos)
    {
        this->_pos = pos;
    }
    Color4 getBaseColor() const
    {
        return _mat._color;
    }
    protected:
    Vector3 <Dtype> _pos;
    Material _mat;
    //Color4 _base_color;

};

template <typename Dtype>
class Sphere : public TracerObject<Dtype>{
    public:
      Sphere<Dtype>(Dtype rad) : _radius(rad)
      {
          //TracerObject<Dtype>::_base_color= Color4(1.0f, 1.0f, 1.0f);
      }
      Sphere<Dtype>(Dtype rad, Vector3<float > pos, Color4 color = Color4(1.0f,1.0f,1.0f)) :
      _radius(rad)
      {
          TracerObject<Dtype>::_pos = pos;
          TracerObject<Dtype>::_mat._color= color;
      }

      bool intersection(const Vector3<Dtype> &origin,
                        const Vector3<Dtype> &dir,
                        Surface<Dtype> &sur ,Dtype & l,Dtype & r) const
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
    if( std::max(t_1,t_2) < l)
        return false;
    if(mint > r) return false;
    sur._pos = origin + mint * dir;
    sur._normal = sur._pos - this->_pos;
    sur._mat = this->_mat;
    r = mint;
    return true;
}
    protected:
    Dtype _radius;



};
template <typename Dtype>
struct Vector2 {
    int x,y;
};
typedef Vector3<float> Vector3f;
typedef Vector2<float > Vector2f;
#endif
