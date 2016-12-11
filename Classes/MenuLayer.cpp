#include "MenuLayer.h"
#include "GameScene.h"

bool MenuLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    createMenu();
    initTouchEvent();
    
    this->scheduleUpdate();
    
    return true;
}

void MenuLayer::createMenu()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto background = Sprite::create("background_menu.png");
    background->setScale(visibleSize.width / background->getContentSize().width, visibleSize.height / background->getContentSize().height);
    background->setPosition(Vec2(visibleSize.width*0.5f + origin.x, visibleSize.height*0.5f + origin.y));
    this->addChild(background, 0);
}

void MenuLayer::initTouchEvent()
{
    mTouchListener = EventListenerTouchOneByOne::create();
    //mTouchListener->setSwallowTouches(true);
    mTouchListener->retain();
    
    mTouchListener->onTouchBegan = CC_CALLBACK_2(MenuLayer::onTouchBegan, this);
    mTouchListener->onTouchMoved = CC_CALLBACK_2(MenuLayer::onTouchMoved, this);
    mTouchListener->onTouchEnded = CC_CALLBACK_2(MenuLayer::onTouchEnded, this);
    mTouchListener->onTouchCancelled = CC_CALLBACK_2(MenuLayer::onTouchCancelled, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mTouchListener, this);
}

bool MenuLayer::onTouchBegan(Touch* touch, Event* event)
{
    auto scene = GameScene::createScene();
    Director::getInstance()->replaceScene(scene);
    return true;
}

void MenuLayer::onTouchMoved(Touch *touch, Event *event)
{
    
}

void MenuLayer::onTouchEnded(Touch *touch, Event *event)
{

}

void MenuLayer::onTouchCancelled(Touch *touch, Event *event)
{
    onTouchEnded(touch, event);
}
