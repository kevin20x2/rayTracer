#ifndef TRACER_MESH_H
#define TRACER_MESH_H 

#include "BaseObject.hpp"

class Mesh{
    public:
    std::vector < int [3] > _tInd;
    std::vector <Vector2f> _uv;
    std::vector <Vector3f > _verts;
};




#endif