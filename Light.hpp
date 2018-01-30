#ifndef TRACER_LIGHT_H
#define TRACER_LIGHT_H 
#include "BaseObject.hpp"

class Light{
    public:
    Light(const Vector3<float > & pos):
    _pos(pos),_color(Color4(1.0f,1.0f,1.0f)){}
    Light(const Vector3<float > & pos,const Color4 & color):
    _pos(pos),_color(color){}
    Vector3 <float > getPos() const { return _pos;}

protected:
  Vector3<float> _pos;
  Color4  _color;
};

class PointLight : public Light{
    public:
    PointLight(const Vector3<float> & pos);
    PointLight(const Vector3<float> & pos,const Color4 & color);
protected:
float _intensity;

};
#endif 