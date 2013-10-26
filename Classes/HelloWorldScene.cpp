#include "HelloWorldScene.h"
#include "ItemDisplay.h"
USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    //添加a参照图
    CCSprite* back=CCSprite::create("canzhao.png");
    back->setAnchorPoint(CCPointZero);
    back->setPosition(CCPointZero);
    this->addChild(back);
    
    //初始化角色资源
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("laoshuAction.plist");

    
//    CCSprite* spt=CCSprite::createWithSpriteFrameName("laoshuAction/normal_0000");
//    
//    int i;
//    //空闲动作
//    CCArray *idleFrames = CCArray::createWithCapacity(22);
//    for (i = 0; i < 21; i++)
//    {
//        CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("laoshuAction/hit_00%02d", i)->getCString());
//        idleFrames->addObject(frame);
//    }
//    //laoshuAction/hit_0000
//    CCAnimation *idleAnimation = CCAnimation::createWithSpriteFrames(idleFrames, 1.0 / 24.0);
//    spt->runAction(CCRepeatForever::create(CCAnimate::create(idleAnimation)));
//
//    CCLOG("%f%f",spt->getContentSize().width,spt->getContentSize().height);
//    this->addChild(spt);
//    spt->setPosition(ccp(352,480-414));
//    spt->setOpacity(100);
//    //spt->setScale(0.5);
    ItemDisplay* display=ItemDisplay::create();
    display->transformSize(ccp(229.25, 58.9));
    display->transformPoint(ccp(350.85, 406.75));
    this->addChild(display);
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
