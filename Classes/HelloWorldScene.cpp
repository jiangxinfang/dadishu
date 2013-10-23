#include "HelloWorldScene.h"

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
    
    //初始化角色资源
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("laoshuAction.plist");
    CCSpriteBatchNode *_actors;
    _actors=CCSpriteBatchNode::create("laoshuAction.png");
    //关闭角色抗锯齿效果
    //_actors->getTexture()->setAliasTexParameters();
    this->addChild(_actors, -5);
    //initWithSpriteFrameName("hero_idle_00.png")
    CCSprite* spt=CCSprite::createWithSpriteFrameName("laoshuAction/out_0000");
    
//    int i;
//    //空闲动作
//    CCArray *idleFrames = CCArray::createWithCapacity(16);
//    for (i = 0; i < 15; i++)
//    {
//        CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("laoshuAction/out_00%00d", i)->getCString());
//        idleFrames->addObject(frame);
//    }
//    CCAnimation *idleAnimation = CCAnimation::createWithSpriteFrames(idleFrames, 1.0 / 24.0);
//    spt->runAction(CCRepeatForever::create(CCAnimate::create(idleAnimation)));
    //
    CCLOG("%f%f",spt->getContentSize().width,spt->getContentSize().height);
    this->addChild(spt);
    //spt->setAnchorPoint(ccp(0, 0));
    //spt->setPosition(ccp(100,300));
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
