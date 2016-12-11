#include "GameOverLayer.h"
#include "GameScene.h"

bool GameOverLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    createGameOver();
    initTouchEvent();
    
    this->scheduleUpdate();
    
    return true;
}

void GameOverLayer::createGameOver()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto background = Sprite::create("background_gameover.png");
    background->setScale(visibleSize.width / background->getContentSize().width, visibleSize.height / background->getContentSize().height);
    background->setPosition(Vec2(visibleSize.width*0.5f + origin.x, visibleSize.height*0.5f + origin.y));
    this->addChild(background, 0);
}

void GameOverLayer::initTouchEvent()
{
    mTouchListener = EventListenerTouchOneByOne::create();
    //mTouchListener->setSwallowTouches(true);
    mTouchListener->retain();
    
    mTouchListener->onTouchBegan = CC_CALLBACK_2(GameOverLayer::onTouchBegan, this);
    mTouchListener->onTouchMoved = CC_CALLBACK_2(GameOverLayer::onTouchMoved, this);
    mTouchListener->onTouchEnded = CC_CALLBACK_2(GameOverLayer::onTouchEnded, this);
    mTouchListener->onTouchCancelled = CC_CALLBACK_2(GameOverLayer::onTouchCancelled, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mTouchListener, this);
}

bool GameOverLayer::onTouchBegan(Touch* touch, Event* event)
{
    auto scene = GameScene::createScene();
    Director::getInstance()->replaceScene(scene);
    return true;
}

void GameOverLayer::onTouchMoved(Touch *touch, Event *event)
{
    
}

void GameOverLayer::onTouchEnded(Touch *touch, Event *event)
{
    
}

void GameOverLayer::onTouchCancelled(Touch *touch, Event *event)
{
    onTouchEnded(touch, event);
}
