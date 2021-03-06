#include <iostream>
#include "TracerScene.hpp"
#include "BaseObject.hpp"
#include "Triangle.hpp"
#include "Mesh.hpp"
using namespace std;
int main()
{
    TracerScene * scene = new TracerScene();
    scene->addObject(new Sphere<float>(1.0f,Vector3<float>(1.5f,0.0f,0.0f),Color4(0.0f,1.0f,1.0f)));
    scene->addObject(new Sphere<float>(1.0f,Vector3<float>(-1.0f,0.0f,-0.2f)));
    scene->addObject(new Triangle<float>(
        Vector3<float >(10.0f,-1.0f,-5.0f),
        Vector3<float >(-10.0f,-1.0f,5.0f),
        Vector3<float >(10.0f,-1.0f,5.0f)
    ));
    scene->addObject(new Triangle<float>(
        Vector3<float>(-10.0f, -1.0f, -5.0f),
        Vector3<float>(-10.0f, -1.0f, 5.0f),
        Vector3<float>(10.0f, -1.0f, -5.0f)));
    scene->addLight(new PointLight(Vector3<float>(-1.0f,1.0f,2.0f)));
    scene->addLight(new PointLight(Vector3<float>(2.0f,2.0f,2.0f)));
    TracerView * view = new TracerView(800,1200,2.0f);
    view->setReflectDepth(3);
    view->setRange(-1.0f,1.0f,-1.5f,1.5f);
    view->setPos(Vector3<float>(0.0f,0.0f,5.0f));
    view->setShadingModel(new LambertianShading());
    view->setScene(scene);
    view->render();
    view->savePng("test.png");

    
    return 0;
}