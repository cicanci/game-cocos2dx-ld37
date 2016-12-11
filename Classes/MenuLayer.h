#ifndef __MENU_LAYER_H__
#define __MENU_LAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class MenuLayer : public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(MenuLayer);
    
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch *touch, Event *event);
    void onTouchEnded(Touch *touch, Event *event);
    void onTouchCancelled(Touch *touch, Event *event);
    
private:
    void initTouchEvent();
    void createMenu();
    
    EventListenerTouchOneByOne* mTouchListener;
};

#endif // __MENU_LAYER_H__
