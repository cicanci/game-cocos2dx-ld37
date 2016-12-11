#ifndef __MONSTER_LAYER_H__
#define __MONSTER_LAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class MonsterLayer : public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(MonsterLayer);
    
    void update(float dt);
    
private:
    void createSpawnPoints();
    void spawnMonster();
    Vec2 getRandomSpawn();
    void checkCollision();

    Vec2 mSpawnRight;
    Vec2 mSpawnLeft;
    Vec2 mSpawnUp;
    Vec2 mSpawnDown;
    Rect mItemRect;

    const float SPEED_IN_SECONDS = 5;
};

#endif // __MONSTER_LAYER_H__
