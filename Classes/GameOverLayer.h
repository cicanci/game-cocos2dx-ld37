#ifndef __GAME_OVER_LAYER_H__
#define __GAME_OVER_LAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class GameOverLayer : public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(GameOverLayer);
    
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch *touch, Event *event);
    void onTouchEnded(Touch *touch, Event *event);
    void onTouchCancelled(Touch *touch, Event *event);
    
private:
    void initTouchEvent();
    void createGameOver();
    
    EventListenerTouchOneByOne* mTouchListener;
};

#endif // __GAME_OVER_LAYER_H__
