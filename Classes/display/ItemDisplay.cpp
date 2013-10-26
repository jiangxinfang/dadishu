//
//  ItemDisplay.cpp
//  dadishu
//
//  Created by jxf on 10/26/13.
//
//

#include "ItemDisplay.h"
ItemDisplay::ItemDisplay(){}
ItemDisplay::~ItemDisplay(){}
bool ItemDisplay::init(){
    bool bl=false;
    do {
        CC_BREAK_IF(!CCSprite::init());
        //初始化sprite
        CCSprite* spt=CCSprite::createWithSpriteFrameName("laoshuAction/normal_0000");
        
        int i;
        //空闲动作
        CCArray *idleFrames = CCArray::createWithCapacity(22);
        for (i = 0; i < 21; i++)
        {
            CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("laoshuAction/hit_00%02d", i)->getCString());
            idleFrames->addObject(frame);
        }
        CCAnimation *idleAnimation = CCAnimation::createWithSpriteFrames(idleFrames, 1.0 / 24.0);
        spt->runAction(CCRepeatForever::create(CCAnimate::create(idleAnimation)));
        spt->setPositionY(-6);
        this->addChild(spt);
        
       // spt->setOpacity(100);
       
        bl=true;
    } while (0);
    return bl;
}
//播放动作
void ItemDisplay::doAction(int value){

}
//转化正常坐标为opengl坐标
void ItemDisplay::transformPoint(CCPoint pt){
    this->setPosition(ccp(pt.x, 480-pt.y));
}
//用宽高转化成正确缩放大小
void ItemDisplay::transformSize(CCPoint size){
    float wSl=size.x/214.15;
    float hSl=size.y/55;
    this->setScaleX(wSl);
    this->setScaleY(hSl);
}
//系统自动调用，注册监听委托
void ItemDisplay::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    //添加一个触摸委托给dispatcher的列表,委托对象this,
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    CCSprite::onEnter();
}
void ItemDisplay::onExit()
{
     CCDirector* pDirector = CCDirector::sharedDirector();
    //移除监听
    
    pDirector->getTouchDispatcher()->removeDelegate(this);
    
    CCSprite::onExit();
}
//用户按下
bool ItemDisplay::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
    CCLOG("按下");
    return true;
}

void ItemDisplay::ccTouchEnded(CCTouch* pTouch, CCEvent* event)
{
    CCLOG("抬起");
}

//获取可点击区域
//CCRect ItemDisplay::rect(){
//    CCSize s=getTexture()->getContentSize();
//    return
//}


