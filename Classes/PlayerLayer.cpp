#include "PlayerLayer.h"
#include "MonsterLayer.h"
#include "HudLayer.h"

bool PlayerLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    createPlayer();
    initTouchEvent();
    
    this->scheduleUpdate();
    
    return true;
}

void PlayerLayer::createPlayer()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    mPlayerIdle = Sprite::create("player_idle.png");
    mPlayerIdle->setPosition(Vec2(visibleSize.width*0.5f + origin.x, visibleSize.height*0.5f + origin.y));
    this->addChild(mPlayerIdle, 2);
    
    mPlayerAttack = Sprite::create("player_attack.png");
    mPlayerAttack->setPosition(mPlayerIdle->getPosition());
    mPlayerAttack->setVisible(false);
    this->addChild(mPlayerAttack, 2);
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
    mPlayerIdle->setVisible(false);
    mPlayerAttack->setVisible(true);
}

void PlayerLayer::onTouchEnded(Touch *touch, Event *event)
{
    mIsMoving = false;
    mPlayerIdle->setVisible(true);
    mPlayerAttack->setVisible(false);
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
            mPlayerIdle->setFlippedX(true);
            mPlayerAttack->setFlippedX(true);
        }
        else
        {
            position.x += (SPEED) * dt;
            mPlayerIdle->setFlippedX(false);
            mPlayerAttack->setFlippedX(false);
        }
        
        if (mMoveUp)
        {
            position.y -= (SPEED) * dt;
        }
        else
        {
            position.y += (SPEED) * dt;
        }
        
        mPlayerIdle->setPosition(mPlayerIdle->getPosition() + ((-1)*position));
        mPlayerAttack->setPosition(mPlayerIdle->getPosition());
        
        checkCollision();
    }
}

void PlayerLayer::checkCollision()
{
    Rect monster = MonsterLayer::Instance()->getMonsterRect();
    
    Rect player = Rect(mPlayerAttack->getPosition().x, mPlayerAttack->getPosition().y,
                       mPlayerAttack->getContentSize().width, mPlayerAttack->getContentSize().height);
    
    if (monster.intersectsRect(player))
    {
        HudLayer::Instance()->updateText(0, 1);
        MonsterLayer::Instance()->spawnMonster();
    }
}

