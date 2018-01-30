#ifndef SHADINGMODEL_H
#define SHADINGMODEL_H
#include "Light.hpp"
#include "BaseObject.hpp"

class BaseShadingModel
{
    public:
    virtual Color4 Shading(const Light &light,const Surface<float> &sur,const Vector3<float> & view_pos){};
};

class LambertianShading : public BaseShadingModel
{
    public:
    Color4 Shading(const Light &light,const Surface<float> &sur,const Vector3<float> & view_pos );
};
#endif