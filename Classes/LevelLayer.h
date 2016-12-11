#ifndef __LEVEL_LAYER_H__
#define __LEVEL_LAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class LevelLayer : public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(LevelLayer);
    
private:
    void initBackground();
    
    Sprite* mBackground;
};

#endif // __LEVEL_LAYER_H__
