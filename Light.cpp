#include "Light.hpp"

PointLight::PointLight(const Vector3<float> & pos):
    Light(pos)
    {

    }

PointLight::PointLight(const Vector3<float> & pos , const Color4 & color):
Light(pos,color)
{
}
