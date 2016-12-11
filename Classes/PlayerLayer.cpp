#include "PlayerLayer.h"
#include "LevelLayer.h"

bool PlayerLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    loadPlayer();
    initTouchEvent();
    
    this->scheduleUpdate();
    
    return true;
}

void PlayerLayer::loadPlayer()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    mPlayer = Sprite::create("player_idle.png");
    mPlayer->setPosition(Vec2(visibleSize.width*0.5f + origin.x, visibleSize.height*0.5f + origin.y));
    this->addChild(mPlayer, 1);
}

void PlayerLayer::initTouchEvent()
{
    mTouchListener = EventListenerTouchOneByOne::create();
    //mTouchListener->setSwallowTouches(true);
    mTouchListener->retain();
    
    mTouchListener->onTouchBegan = CC_CALLBACK_2(PlayerLayer::onTouchBegan, this);
    mTouchListener->onTouchMoved = CC_CALLBACK_2(PlayerLayer::onTouchMoved, this);
    mTouchListener->onTouchEnded = CC_CALLBACK_2(PlayerLayer::onTouchEnded, this);
    mTouchListener->onTouchCancelled = CC_CALLBACK_2(PlayerLayer::onTouchCancelled, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mTouchListener, this);
}

bool PlayerLayer::onTouchBegan(Touch* touch, Event* event)
{
    onTouchMoved(touch, event);
    return true;
}

void PlayerLayer::onTouchMoved(Touch *touch, Event *event)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    mMoveRight = (touch->getLocation().x > visibleSize.width*0.5f) ? true : false;
    mMoveUp = (touch->getLocation().y > visibleSize.height*0.5f) ? true : false;
    mIsMoving = true;
}

void PlayerLayer::onTouchEnded(Touch *touch, Event *event)
{
    mIsMoving = false;
}

void PlayerLayer::onTouchCancelled(Touch *touch, Event *event)
{
    onTouchEnded(touch, event);
}

void PlayerLayer::update(float dt)
{
    if (mIsMoving)
    {
        Vec2 position = Vec2::ZERO;
        
        if (mMoveRight)
        {
            position.x -= (SPEED) * dt;
            mPlayer->setFlippedX(true);
        }
        else
        {
            mPlayer->setFlippedX(false);
            position.x += (SPEED) * dt;
        }
        
        if (mMoveUp)
        {
            position.y -= (SPEED) * dt;
        }
        else
        {
            position.y += (SPEED) * dt;
        }
        
        mPlayer->setPosition(mPlayer->getPosition() + ((-1)*position));
        
        //checkCollision();
    }
}

void PlayerLayer::checkCollision()
{
    Rect level = LevelLayer::Instance()->getLevelRect();
    Rect player = Rect(mPlayer->getPosition().x,
                       mPlayer->getPosition().y,
                       mPlayer->getContentSize().width,
                       mPlayer->getContentSize().height);
    
    if (!player.intersectsRect(level))
    {
        mIsMoving = false;
    }
}
