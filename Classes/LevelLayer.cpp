#include "LevelLayer.h"

LevelLayer* LevelLayer::mInstance = 0;

bool LevelLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    initBackground();

    return true;
}

void LevelLayer::initBackground()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    mBackground = Sprite::create("background_dungeon.png");
    mBackground->setScale(visibleSize.height / mBackground->getContentSize().height);
    mBackground->setPosition(Vec2(visibleSize.width*0.5f + origin.x, visibleSize.height*0.5f + origin.y));
    this->addChild(mBackground, 0);
    
    mBackgroundRect = Rect(mBackground->getPosition().x,
                           mBackground->getPosition().y,
                           mBackground->getContentSize().width,
                           mBackground->getContentSize().height);
}
