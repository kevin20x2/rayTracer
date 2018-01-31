#include "ShadingModel.hpp"
#include <algorithm>
#include <cmath>


Color4 LambertianShading:: Shading(const Light &light, const Surface<float> &sur, const Vector3<float> &view_pos)
{
    Vector3<float > l = (light.getPos()- sur._pos).normalize();
    Vector3<float> n = sur._normal.normalize();
    return sur._color*std::max(0.0f,l*n);
}