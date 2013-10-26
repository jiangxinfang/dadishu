//
//  Game.cpp
//  dadishu
//
//  Created by jxf on 10/26/13.
//
//

#include "Game.h"
Game::Game(){
    _gameLayer=NULL;
}
Game::~Game(){}
bool Game::init(){
    bool bl=false;
    do {
        CC_BREAK_IF(!CCScene::init());
        _gameLayer=GameLayer::create();
        this->addChild(_gameLayer,0);
        bl=true;
    } while (0);
    return bl;
}
