#include <iostream>
#include "TracerScene.hpp"
#include "BaseObject.hpp"
using namespace std;
int main()
{
    TracerScene * scene = new TracerScene();
    scene->addObject(new Sphere<float>(0.5));
    TracerView * view = new TracerView(400,400,1.0f);
    view->setScene(scene);
    view->render();
    view->savePng("test.png");

    
    return 0;
}