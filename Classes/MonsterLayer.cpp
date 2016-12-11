#include "MonsterLayer.h"

MonsterLayer* MonsterLayer::mInstance = 0;

bool MonsterLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    createSpawnPoints();
    createMonster();
    spawnMonster();
    
    this->scheduleUpdate();
    
    return true;
}

void MonsterLayer::createSpawnPoints()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    mSpawnDown = Vec2(visibleSize.width*0.5f, 0);
    mSpawnUp = Vec2(visibleSize.width*0.5f, visibleSize.height);
    mSpawnRight = Vec2(visibleSize.width, visibleSize.height*0.5f);
    mSpawnLeft = Vec2(0, visibleSize.height*0.5f);
    
    mItemRect = Rect(visibleSize.width*0.5f + origin.x, visibleSize.height*0.5f + origin.y, 100, 100);
}

void MonsterLayer::createMonster()
{
    mMonster = Sprite::create("monster_idle.png");
    this->addChild(mMonster, 3);
}

void MonsterLayer::spawnMonster()
{
    if (mMonster->isRunning())
    {
        mMonster->stopAllActions();
    }
    
    mMonster->setPosition(getRandomSpawn());
    
    auto moveTo = MoveTo::create(SPEED_IN_SECONDS, Vec2(mItemRect.origin.x, mItemRect.origin.y));
    mMonster->runAction(moveTo);
}

Vec2 MonsterLayer::getRandomSpawn()
{
    int spawn = random(0, 3);
    log("Spawn at %d", spawn);

    switch (spawn) {
        case 0:
            return mSpawnUp;
        case 1:
            return mSpawnRight;
        case 2:
            return mSpawnDown;
        case 3:
            return mSpawnLeft;
        default:
            return Vec2(0, 0);
    }
}

void MonsterLayer::update(float dt)
{
    checkCollision();
}

void MonsterLayer::checkCollision()
{
    if (mItemRect.intersectsRect(getMonsterRect()))
    {
        log("Game Over!");
        spawnMonster();
    }
}

Rect MonsterLayer::getMonsterRect()
{
    return Rect(mMonster->getPosition().x, mMonster->getPosition().y,
                mMonster->getContentSize().width, mMonster->getContentSize().height);

}
