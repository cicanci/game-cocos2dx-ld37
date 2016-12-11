#include "GameScene.h"
#include "LevelLayer.h"
#include "PlayerLayer.h"

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    
    auto level = LevelLayer::create();
    scene->addChild(level);
    
    auto player = PlayerLayer::create();
    scene->addChild(player);
    
    return scene;
}
