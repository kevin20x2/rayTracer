#include "Light.hpp"

PointLight::PointLight(const Vector3<float> & pos):
    Light(pos),_intensity(1.0f)
    {
        Light::_type = Light::PointLight;

    }

PointLight::PointLight(const Vector3<float> & pos , const Color4 & color):
Light(pos,color),_intensity(1.0f)
{
    Light::_type = Light::PointLight;

}

float PointLight::getIntensity() const
{
    return this->_intensity;
}
