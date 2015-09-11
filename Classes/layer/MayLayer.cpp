//
//  MayLayer.cpp
//  myGame
//
//  Created by XSugar on 15-9-11.
//
//

#include "MayLayer.h"


using namespace cocos2d;

bool MayLayer::init(){
    if(!Layer::init()){
        return false;
    }
    TMXTiledMap* tiledMap = TMXTiledMap::create("map.tmx");
    tiledMap->setPosition(Vec2(0,0));
    this->addChild(tiledMap);
    
    Sprite* spr = Sprite::create("enemy_bee1_w1.png");
    spr->setPosition(Vec2(100,100));
    this->addChild(spr
                   );
    
    
    return true;
}