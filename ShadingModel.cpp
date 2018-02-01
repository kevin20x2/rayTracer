#include "ShadingModel.hpp"
#include <algorithm>
#include <cmath>


Color4 LambertianShading:: Shading(const Light &light, const Surface<float> &sur, const Vector3<float> &view_pos)
{
    if(light.getType() == Light::PointLight)
    {
       float intensity = dynamic_cast<const PointLight *>(&light)->getIntensity();
       Vector3<float> l = (light.getPos() - sur._pos).normalize();
       Vector3<float> n = sur._normal.normalize();
       Vector3<float> v = (view_pos - sur._pos).normalize();
       Vector3<float> h = (v+l).normalize();
       float len = (light.getPos() - sur._pos).length();
       float I = intensity/(len*len);
       return light.getColor()*0.1f +sur._mat._color *I* std::max(0.0f, l * n) + light.getColor()*I*pow(
           std::max(0.0f,n*h)
           ,sur._mat._specular_power);
    }
}