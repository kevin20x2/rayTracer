#ifndef MATERIAL_H
#define MATERIAL_H 


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

struct Material {
    Material():
    _color(1.0f,1.0f,1.0f),_specular_power(2.0f),_reflection_rate(0.2f)
    {
    }
    Color4 _color;
    float _specular_power;
    float _reflection_rate;

};


#endif