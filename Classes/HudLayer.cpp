#include "HudLayer.h"

HudLayer* HudLayer::mInstance = 0;

bool HudLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }

    initText();

    return true;
}

void HudLayer::initText()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    mCookieLabel = createLabel();
    mCookieLabel->setPosition(Vec2(origin.x + 20, origin.y + visibleSize.height - mCookieLabel->getContentSize().height - 20));
    
    mMonsterLabel = createLabel();
    mMonsterLabel->setPosition(Vec2(origin.x + 20, origin.y + visibleSize.height - mMonsterLabel->getContentSize().height - 50));
    
    mCookieCounter = COOKIES_IN_THE_JAR;
    mMonsterCounter = 0;
    
    updateText(0, 0);
}

Label* HudLayer::createLabel()
{
    auto label = Label::createWithTTF("TEMP TEXT", "fonts/arial.ttf", 24);
    label->setAnchorPoint(Vec2(0, 0));
    label->setColor(Color3B::BLACK);
    label->setAlignment(TextHAlignment::LEFT);
    this->addChild(label, 4);
    return label;
}

void HudLayer::updateText(int cookies, int monsters)
{
    mCookieCounter += cookies;
    std::string cookieCounter = StringUtils::format("Cookies Left: %d", mCookieCounter);
    mCookieLabel->setString(cookieCounter.c_str());
    
    mMonsterCounter += monsters;
    std::string monsterCounter = StringUtils::format("Monsters Killed: %d", mMonsterCounter);
    mMonsterLabel->setString(monsterCounter.c_str());
}
