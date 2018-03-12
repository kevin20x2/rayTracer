#ifndef TEXTUREMAPPING_H
#define TEXTUREMAPPING_H
#include "Interaction.hpp"

class TextureMapping2D{
    public:
    virtual Vector2f Map(const SurfaceInteraction &si,
                        Vector2f * dstdx,Vector2f *dstdy) const = 0;
};

class UVMapping2D : public TextureMapping2D
{
    public:
    UVMapping2D(float su,float sv,float du,float dv):
        _su(su),_sv(sv),_du(_du),_dv(dv)
        {
        }
    UVMapping2D():
        _su(1.0f),_sv(1.0f),_du(0.0f),_dv(0.0f)
    {
    }

    Vector2f Map(const SurfaceInteraction & si,
                    Vector2f * dstdx,Vector2f *dstdy)
                    {
                        //*dstdx = Vector2f(_su * si)
                        return Vector2f(su*si._uv.x + _du,
                                        sv*si._uv.y + _dv);
                    }
    private:
    const float _su,_sv,_du,_dv;
};
#endif