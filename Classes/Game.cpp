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
        CCNode *pNode=CCSSceneReader::sharedSceneReader()->createNodeWithSceneFile("StartScreen.json");;
        this->addChild(pNode);
        
//        helpLayer=UILayer::create();
//        this->addChild(helpLayer);
        
        CCNode *node=pNode->getChildByTag(10004);
        CCComRender *com=(CCComRender *)node->getComponent("GUIComponent");
        //得到ui
        UILayer* layer=(UILayer *)com->getNode();
        Layout* p = dynamic_cast<Layout*>(layer->getWidgetByName("Panel"));
        //获得帮助界面
        helpPanel=dynamic_cast<Layout*>(layer->getWidgetByName("helpPanel"));
        helpPanel->removeFromParent();
        UILayer* helpLayer=UILayer::create();
        this->addChild(helpLayer,10);
        helpLayer->addWidget(helpPanel);
        //开始游戏面板
        Layout* panel = dynamic_cast<Layout*>(p->getChildByName("Panel"));
        //处理按钮
        UIButton* startBtn = dynamic_cast<UITextButton*>(panel->getChildByName("Button"));
        startBtn->addReleaseEvent(this, coco_releaseselector(Game::starCallBack));
        
        UIButton* help=dynamic_cast<UITextButton*>(panel->getChildByName("helpBtn"));
        help->addReleaseEvent(this, coco_releaseselector(Game::helpCallback));
        
        UIButton* startBtn2= dynamic_cast<UITextButton*>(helpPanel->getChildByName("startBtn"));
        startBtn2->addReleaseEvent(this, coco_releaseselector(Game::starCallBack));

        
        bl=true;
    } while (0);
    return bl;
}
void Game::starCallBack(CCObject *pSender){
    CCLog("点击");
    this->removeAllChildrenWithCleanup(true);
     _gameLayer=GameLayer::create();
    this->addChild(_gameLayer,0);
}
void Game::helpCallback(CCObject *pSender){
    CCLog("帮助");
    helpPanel->setVisible(true);
    
    helpPanel->setZOrder(100);
}
