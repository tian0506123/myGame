//
//  GameScene.h
//  myGame
//
//  Created by XSugar on 15-9-11.
//
//

#ifndef __myGame__GameScene__
#define __myGame__GameScene__

#include <stdio.h>
#include "cocos2d.h"
#include "JostickDelegaor.h"

class Game : public cocos2d::Layer,public JostickDelegator{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();

    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void jostickAttribute(float angle,ControlDirection dirction);

    CREATE_FUNC(Game);
};


#endif /* defined(__myGame__GameScene__) */
