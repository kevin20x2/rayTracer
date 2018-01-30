#include "BaseObject.hpp"
#include <algorithm>
#include <cmath>
/*
template <typename Dtype>
bool Sphere<Dtype>::intersection(const Vector3<Dtype> & origin,
const Vector3<Dtype> &dir,
Surface<Dtype> & sur
) const
{
    Vector3 <Dtype > e_c = origin - TracerObject<Dtype>::_pos;
    Dtype delta = (dir * e_c)*(dir * e_c)-(dir*dir)(e_c*e_c - _radius*_radius);
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
    return true;


}
*/