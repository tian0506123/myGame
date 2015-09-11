//
//  StartScene.cpp
//  myGame
//
//  Created by XSugar on 15-9-11.
//
//

#include "StartScene.h"
using namespace cocos2d;


Scene* Start::createScene(){
    auto scene = Scene::create();

    auto layer = Start::create();

    scene->addChild(layer);

    return scene;
}

bool Start::init(){
    if (!Layer::init()) {
        return false;
    }
    
    auto winSize = Director::getInstance()->getWinSize();
    
    
    return true;
}

void menuCloseCallback(cocos2d::Ref* pSender){

}