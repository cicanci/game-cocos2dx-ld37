#include "GameScene.h"
#include "LevelLayer.h"
#include "PlayerLayer.h"
#include "MonsterLayer.h"
#include "HudLayer.h"

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    
    auto level = LevelLayer::create();
    scene->addChild(level);
    
    auto player = PlayerLayer::create();
    scene->addChild(player);
    
    auto monster = MonsterLayer::create();
    scene->addChild(monster);
    
    auto hud = HudLayer::create();
    scene->addChild(hud);
    
    return scene;
}
