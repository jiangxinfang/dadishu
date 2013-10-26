//
//  Game.h
//  dadishu
//
//  Created by jxf on 10/26/13.
//
//

#ifndef __dadishu__Game__
#define __dadishu__Game__

#include <iostream>
#include "cocos2d.h"
#include "GameLayer.h"
using namespace cocos2d;
USING_NS_CC;
class Game:public CCScene{
public:
    Game();
    ~Game();
    virtual bool init();
    CREATE_FUNC(Game);
    CC_SYNTHESIZE(GameLayer*, _gameLayer, GameLayer);
};
#endif /* defined(__dadishu__Game__) */
