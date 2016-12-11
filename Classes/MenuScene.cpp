#include "MenuScene.h"
#include "MenuLayer.h"

Scene* MenuScene::createScene()
{
    auto scene = Scene::create();
    
    auto menu = MenuLayer::create();
    scene->addChild(menu);
    
    return scene;
}
