#include <iostream>
#include "TracerScene.hpp"
#include "BaseObject.hpp"
using namespace std;
int main()
{
    TracerScene * scene = new TracerScene();
    scene->addObject(new Sphere<float>(0.5));
    scene->addLight(new PointLight(Vector3<float>(1.0f,1.0f,-1.0f)));
    TracerView * view = new TracerView(400,400,1.0f);
    view->setShadingModel(new LambertianShading());
    view->setScene(scene);
    view->render();
    view->savePng("test.png");

    
    return 0;
}