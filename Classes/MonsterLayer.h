#ifndef __MONSTER_LAYER_H__
#define __MONSTER_LAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class MonsterLayer : public Layer
{
public:
    MonsterLayer() { mInstance = this; }
    ~MonsterLayer() { mInstance = NULL; }
    static MonsterLayer* Instance() { return mInstance; }

    virtual bool init();
    CREATE_FUNC(MonsterLayer);
    
    void update(float dt);
    Rect getMonsterRect();
    void spawnMonster();
    
private:
    void createSpawnPoints();
    void createMonster();
    Vec2 getRandomSpawn();
    void checkCollision();

    static MonsterLayer* mInstance;
    Sprite* mMonster;
    Vec2 mSpawnRight;
    Vec2 mSpawnLeft;
    Vec2 mSpawnUp;
    Vec2 mSpawnDown;
    Rect mItemRect;

    const float SPEED_IN_SECONDS = 5;
};

#endif // __MONSTER_LAYER_H__
