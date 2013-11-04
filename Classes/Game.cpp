//
//  Game.cpp
//  dadishu
//
//  Created by jxf on 10/26/13.
//
//

#include "Game.h"
#include "CocosGUI.h" 
#include "UIWidget.h"
Game::Game(){
    _gameLayer=NULL;
}
Game::~Game(){}
bool Game::init(){
    bool bl=false;
    do {
        CC_BREAK_IF(!CCScene::init());
//        UILayer* layer=UILayer::create();
//        layer->scheduleUpdate();
//        addChild(layer);
//        layer->setTag(88);
//
//        // equip root from json
//        Layout* equipe_root =dynamic_cast<Layout*>(CCUIHELPER->createWidgetFromJsonFile("StartPenel_1.json"));
//        equipe_root->setWidgetTag(1000);
//        layer->addWidget(equipe_root);
//        
//        Layout* panel = dynamic_cast<Layout*>(equipe_root->getChildByName("Panel"));
//        UIButton* startBtn = dynamic_cast<UITextButton*>(panel->getChildByName("Button"));
//        startBtn->addReleaseEvent(this, coco_releaseselector(Game::starCallBack));
        
        //引入场景
       CCNode *pNode=CCSSceneReader::sharedSceneReader()->createNodeWithSceneFile("StartrScreen/StartScreen.json");
        
        // ActionManager::shareManager()->playActionByName("eye.ExportJson", "Animation3");
        //CCDirector::sharedDirector()->pushScene((CCScene *)pNode);
        //this->addChild(pNode);
         _gameLayer=GameLayer::create();
        this->addChild(_gameLayer,0);
        bl=true;
    } while (0);
    return bl;
}
void Game::starCallBack(CCObject *pSender){
    CCLog("点击");
    this->removeAllChildren();
    this->release();
     _gameLayer=GameLayer::create();
    this->addChild(_gameLayer,0);
}
