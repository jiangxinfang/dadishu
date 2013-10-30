//
//  GameLayer.cpp
//  dadishu
//
//  Created by jxf on 10/26/13.
//
//

#include "GameLayer.h"
#include "ItemDisplay.h"
GameLayer::GameLayer(){}
GameLayer::~GameLayer(){}
bool GameLayer::init(){
    bool bl=false;
    do {
        CC_BREAK_IF(!CCLayer::create());
        //添加a参照图
        CCSprite* back=CCSprite::create("sceneBack.png");
        back->setAnchorPoint(CCPointZero);
        back->setPosition(CCPointZero);
        this->addChild(back);
        
        //初始化角色资源
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("laoshuAction.plist");
        _actors = CCSpriteBatchNode::create("laoshuAction.png");
		_actors->getTexture()->setAliasTexParameters();
		this->addChild(_actors, -5);
        //老鼠列表
        mouseList=CCArray::create();
        //添加老鼠
        //0
        ItemDisplay* display=ItemDisplay::create();
        display->transformSize(ccp(101, 26));
        display->transformPoint(ccp(116, 179));
        this->addChild(display);
        display->setTag(0);
        mouseList->addObject(display);
        //1
        display=ItemDisplay::create();
        display->transformSize(ccp(115.35, 29.65));
        display->transformPoint(ccp(277, 208));
        this->addChild(display);
        display->setTag(1);
        mouseList->addObject(display);
        //2
        display=ItemDisplay::create();
        display->transformSize(ccp(101, 26));
        display->transformPoint(ccp(424.2, 179.45));
        this->addChild(display);
        display->setTag(2);
        mouseList->addObject(display);
        //3
        display=ItemDisplay::create();
        display->transformSize(ccp(95.45, 24.55));
        display->transformPoint(ccp(648, 180));
        this->addChild(display);
        display->setTag(3);
        mouseList->addObject(display);
        //4
        display=ItemDisplay::create();
        display->transformSize(ccp(115.35, 29.65));
        display->transformPoint(ccp(93.55, 243.4));
        this->addChild(display);
        display->setTag(4);
        mouseList->addObject(display);
        //5
        display=ItemDisplay::create();
        display->transformSize(ccp(146, 37.5));
        display->transformPoint(ccp(417, 241));
        this->addChild(display);
        display->setTag(5);
        mouseList->addObject(display);
        //6
        display=ItemDisplay::create();
        display->transformSize(ccp(130, 33));
        display->transformPoint(ccp(598, 223));
        this->addChild(display);
        display->setTag(6);
        mouseList->addObject(display);
        //7
        display=ItemDisplay::create();
        display->transformSize(ccp(162, 41.7));
        display->transformPoint(ccp(232, 302));
        this->addChild(display);
        display->setTag(7);
        mouseList->addObject(display);
        bl=true;
        //8
        display=ItemDisplay::create();
        display->transformSize(ccp(169, 43));
        display->transformPoint(ccp(466, 329));
        this->addChild(display);
        display->setTag(8);
        mouseList->addObject(display);
        //9
        display=ItemDisplay::create();
        display->transformSize(ccp(144, 37));
        display->transformPoint(ccp(675, 284));
        this->addChild(display);
        display->setTag(9);
        mouseList->addObject(display);
        //10
        display=ItemDisplay::create();
        display->transformSize(ccp(187, 48));
        display->transformPoint(ccp(129, 366));
        display->setTag(10);
        this->addChild(display);
        mouseList->addObject(display);
        //11
        display=ItemDisplay::create();
        display->transformSize(ccp(229, 59));
        display->transformPoint(ccp(351, 407));
        this->addChild(display);
        display->setTag(11);
        mouseList->addObject(display);
        //12
        display=ItemDisplay::create();
        display->transformSize(ccp(187, 48));
        display->transformPoint(ccp(632, 378));
        this->addChild(display);
        display->setTag(12);
        mouseList->addObject(display);
        mouseList->retain();
        /////////////启动游戏心跳//////////////
        this->schedule(schedule_selector(GameLayer::ontick), 2.0);
    } while (0);
    return true;
}
void GameLayer::ontick( float fDelta){
    //randomBetweenInt(0,)
    CCObject* item=mouseList->randomObject();
    ItemDisplay* display=(ItemDisplay*)item;
    display->goUp();
}
int GameLayer::randomBetweenInt(int max, int min)
{
    time_t t;
    std::srand((unsigned int)time(&t));//随机数种子
    return std::rand() % (max - min) + min;
}