#ifndef __HUD_LAYER_H__
#define __HUD_LAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class HudLayer : public Layer
{
public:
    HudLayer() { mInstance = this; }
    ~HudLayer() { mInstance = NULL; }
    static HudLayer* Instance() { return mInstance; }

    virtual bool init();
    CREATE_FUNC(HudLayer);
    
    void updateText(int cookies, int monsters);
    
private:
    void initText();
    Label* createLabel();

    static HudLayer* mInstance;
    Label* mCookieLabel;
    Label* mMonsterLabel;
    int mCookieCounter;
    int mMonsterCounter;
    
    const float COOKIES_IN_THE_JAR = 3;
};

#endif // __HUD_LAYER_H__
