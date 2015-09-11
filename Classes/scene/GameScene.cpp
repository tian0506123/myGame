//
//  GameScene.cpp
//  myGame
//
//  Created by XSugar on 15-9-11.
//
//

#include "GameScene.h"
#include "MayLayer.h"
#include "JostickLayer.h"

using namespace cocos2d;

cocos2d::Scene* Game::createScene(){
    auto scene= Scene::create();
    auto layer= Game::create();
    scene->addChild(layer);
    return scene;
}

bool Game::init(){
    if (!Layer::init()) {
        return false;
    }
    auto  winSize = Director::getInstance()->getWinSize();
    
    //添加地图
    MayLayer* mayLayer =MayLayer::create();
    this->addChild(mayLayer);
    
    JostickLayer* jostickLayer = JostickLayer::createJostick("control_bg.png", "CloseNormal.png", Vec2(winSize.width/6,winSize.height/6));
    jostickLayer->setDelegator(this);
    this->addChild(jostickLayer);
    
    
    return true;
}

void Game::menuCloseCallback(cocos2d::Ref* pSender){

}


void Game::jostickAttribute(float angle,ControlDirection dirction){
    switch (dirction) {
        case control_down:
            log("向下");
            break;
        case  control_lift:
            log("向左");
            break;
        case control_right:
            log("向右");
            break;
        case control_up:
            log("向上");
            break;
       case control_stop:
            log("停止");
            break;
    }
}