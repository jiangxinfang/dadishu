//
//  ItemDisplay.h
//  dadishu
//
//  Created by jxf on 10/26/13.
//
//

#ifndef __dadishu__ItemDisplay__
#define __dadishu__ItemDisplay__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
USING_NS_CC;
class ItemDisplay:public CCSprite,public CCTargetedTouchDelegate{
public:
    ItemDisplay();
    ~ItemDisplay();
    virtual bool init();
    //播放动作
    void doAction(int value);
    //转化正常坐标为opengl坐标
    void transformPoint(CCPoint pt);
    //用宽高转化成正确缩放大小
    void transformSize(CCPoint size);
    
    //添加触屏委托，重新此方法
    virtual void onEnter();
    //移除监听事件，防止内存溢出
    virtual void   onExit();
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);//松开
    CREATE_FUNC(ItemDisplay);
    
};

#endif /* defined(__dadishu__ItemDisplay__) */
