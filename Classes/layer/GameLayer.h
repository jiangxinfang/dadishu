//
//  GameLayer.h
//  dadishu
//
//  Created by jxf on 10/26/13.
//
//

#ifndef __dadishu__GameLayer__
#define __dadishu__GameLayer__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
USING_NS_CC;
class GameLayer:public CCLayer{
public:
    GameLayer();
    ~GameLayer();
    virtual bool init();
    CCArray* mouseList;
    CREATE_FUNC(GameLayer);
};


#endif /* defined(__dadishu__GameLayer__) */
