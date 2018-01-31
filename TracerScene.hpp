#ifndef TRACERSCENE_H
#define TRACERSCENE_H
#define LOG printf
#include <iostream>
#include <cstdio>
#include "BaseObject.hpp"
#include "Light.hpp"
#include "ShadingModel.hpp"
#include <vector>

class TracerScene
{
  public:
  int addObject(TracerObject<float > * obj);
  int addLight(Light * light);
  const TracerObject<float > * getObject(int index);
  const Light * getLight(int index);
  int getLightListLength();
  int getObjectListLength();
private:
  std::vector<TracerObject<float> *> _object_list;
  std::vector<Light *> _light_list;

};

class TracerView
{
  public:
    TracerView(const int height,const int width,const float focal_length);
    void setScene(TracerScene * scene);
    void setRange(float l,float r,float up,float down);
    void setShadingModel(BaseShadingModel* model);
    void render();
    int savePng(const char * file_name);
  private:
    void init_ray_dir();
    Color4 compute_pixel(const Surface<float > & sur,const Vector3<float>& view_pos);
    float _focal_length;
    int _image_height,_image_width;
    float _left,_right,_upper,_bottom;
    Vector3<float > _pos;
    TracerScene * _scene;
    std::vector <Vector3 <float> > _ray_dir;
    Color4 * _image_data;
    BaseShadingModel * _shading_model;
};

#endif