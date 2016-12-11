#ifndef __LEVEL_LAYER_H__
#define __LEVEL_LAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class LevelLayer : public Layer
{
public:
    LevelLayer() { mInstance = this; }
    ~LevelLayer() { mInstance = NULL; }
    static LevelLayer* Instance() { return mInstance; }
    
    virtual bool init();
    CREATE_FUNC(LevelLayer);
    
    Rect getLevelRect() { return mBackgroundRect; }
    
private:
    void initBackground();
    
    static LevelLayer* mInstance;
    Sprite* mBackground;
    Rect mBackgroundRect;
};

#endif // __LEVEL_LAYER_H__
