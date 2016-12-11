#include "GameOverScene.h"
#include "GameOverLayer.h"

Scene* GameOverScene::createScene()
{
    auto scene = Scene::create();
    
    auto gameover = GameOverLayer::create();
    scene->addChild(gameover);
    
    return scene;
}
