//
//  StartScene.h
//  myGame
//
//  Created by XSugar on 15-9-11.
//
//

#ifndef __myGame__StartScene__
#define __myGame__StartScene__

#include <stdio.h>
#include "cocos2d.h"

class Start : public cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();

    void menuCloseCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(Start);
};

#endif /* defined(__myGame__StartScene__) */
