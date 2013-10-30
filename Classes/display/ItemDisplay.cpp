//
//  ItemDisplay.cpp
//  dadishu
//
//  Created by jxf on 10/26/13.
//
//

#include "ItemDisplay.h"
ItemDisplay::ItemDisplay(){
    touchRect=CCRect(-42, -10,80, 90);
    isTouch=false;

    _actionState=kActionStateNormal;

}
ItemDisplay::~ItemDisplay(){}
bool ItemDisplay::init(){
    bool bl=false;
    do {
        CC_BREAK_IF(!CCSprite::init());
        //初始化sprite
        _display=CCSprite::createWithSpriteFrameName("laoshuAction/normal_0000");
        _display->setPositionY(-6);
        this->addChild(_display);
        

        // normal();
        //hit();
        goUp();
        bl=true;
    } while (0);
    return bl;
}
CCAction* ItemDisplay::getAction(ActionState state){
    
    int i;
    CCAction *action=NULL;
    CCSpriteFrame *frame=NULL;
    switch (state) {
        case kActionStateNone:
            break;
        case kActionStateNormal:{         CCArray* normalFrames=  CCArray::create();
            frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("laoshuAction/normal_0001");
            normalFrames->addObject(frame);
            frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("laoshuAction/normal_0001");
            normalFrames->addObject(frame);
            CCAnimation *normalAnimation = CCAnimation::createWithSpriteFrames(normalFrames, 1.0 / 24.0);
            action=CCSequence::create(CCAnimate::create(normalAnimation),NULL);}
            //正常
   
            break;
        case kActionStateHit:{
            //击中
            CCArray *hitFrames = CCArray::create();
            for (i = 0; i < 22; i++)
            {
                frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("laoshuAction/hit_00%02d", i)->getCString());
                hitFrames->addObject(frame);
            }
            CCAnimation *hitAnimation = CCAnimation::createWithSpriteFrames(hitFrames, 1.0 / 24.0);
            //动作只播放一次
            action=CCSequence::create(
                                          CCAnimate::create(hitAnimation),
                                          CCCallFunc::create(this, callfunc_selector(ItemDisplay::normal)),
                                          NULL);
        }
            break;
        case kActionStateGoUp:{
            //出现
            CCArray* goUpFrames= CCArray::create();
            for (i = 0; i < 13; i++)
            {
                frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("laoshuAction/goup_00%02d", i)->getCString());
                goUpFrames->addObject(frame);
            }
            CCAnimation *goUpAnimation = CCAnimation::createWithSpriteFrames(goUpFrames, 1.0 / 24.0);
            action=CCSequence::create(
                                           CCAnimate::create(goUpAnimation),
                                           CCDelayTime::create(2.0),
                                           CCCallFunc::create(this, callfunc_selector(ItemDisplay::goDown)),
                                           NULL);
        }
            break;
        case kActionStateGoDown:{
            //回缩
            CCArray* goDownFrames=CCArray::createWithCapacity(3);
            for (i = 0; i < 3; i++)
            {
                frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("laoshuAction/godown_00%02d", i)->getCString());
                goDownFrames->addObject(frame);
            }
            CCAnimation *goDownAnimation = CCAnimation::createWithSpriteFrames(goDownFrames, 1.0 / 24.0);
            action=CCSequence::create(
                                             CCAnimate::create(goDownAnimation),
                                             CCCallFunc::create(this, callfunc_selector(ItemDisplay::normal)),
                                             NULL);
        }
            break;
            
    }
    return action;
}
//正常动作
void ItemDisplay::normal(){
    if(_actionState==kActionStateNormal)return;
    _display->stopAllActions();
    _display->runAction(getAction(kActionStateNormal));
    _actionState=kActionStateNormal;
}
//击中动作
void ItemDisplay::hit(){
    if(_actionState==kActionStateHit)return;
    _display->stopAllActions();
    _display->runAction(getAction(kActionStateHit));
    _actionState=kActionStateHit;
}
//出现动作
void ItemDisplay::goUp(){
    if(_actionState==kActionStateGoUp)return;
    _display->stopAllActions();
    _display->runAction(getAction(kActionStateGoUp));
    _actionState=kActionStateGoUp;
}
//回缩动作
void ItemDisplay::goDown(){
    if(_actionState==kActionStateGoDown)return;
    _display->stopAllActions();
    _display->runAction(getAction(kActionStateGoDown));
    _actionState=kActionStateGoDown;
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
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
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
    if(isTouch)return false;
    //获得点击的坐标
    CCPoint point=convertTouchToNodeSpaceAR(pTouch);
    if(!touchRect.containsPoint(point))return false;
    //CCLOG("按下%d=%f=%f",this->getTag(),point.x,point.y);
    if(_actionState==kActionStateGoUp)hit();
    isTouch=true;
    return true;
}

void ItemDisplay::ccTouchEnded(CCTouch* pTouch, CCEvent* event)
{
    CCLOG("抬起");
    isTouch=false;
}

