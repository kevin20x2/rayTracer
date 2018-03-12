#ifndef TRACER_INTERACTION_H
#define TRACER_INTERACTION_H
#include "BaseObject.hpp"

struct Interaction{
    Interaction (const Vector3f & pos,const Vector3f & normal):
    _pos(pos),_normal(normal)
    {

    }
    Vector3f _pos;
    Vector3f _normal;
    Material _mat;
};

// TODO : dpdu , dpdv ,dndu ,dndv 

class SurfaceInteraction :public Interaction{
    public:
    Vector2f uv;
};

#endif