#ifndef __PLAYER_LAYER_H__
#define __PLAYER_LAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class PlayerLayer : public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(PlayerLayer);
    
    void update(float dt);
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch *touch, Event *event);
    void onTouchEnded(Touch *touch, Event *event);
    void onTouchCancelled(Touch *touch, Event *event);
    
private:
    void initTouchEvent();
    void loadPlayer();
    void checkCollision();
    
    EventListenerTouchOneByOne* mTouchListener;
    Sprite* mPlayer;
    bool mIsMoving;
    bool mMoveRight;
    bool mMoveUp;
    
    const int SPEED = 200;
};

#endif // __PLAYER_LAYER_H__
