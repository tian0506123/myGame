//
//  JostickLayer.h
//  myGame
//
//  Created by ngu on 15/6/17.
//
//

#ifndef __myGame__JostickLayer__
#define __myGame__JostickLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "JostickDelegaor.h"

USING_NS_CC;


class JostickLayer : public Layer{
public:
    virtual bool init();
    //触摸事件
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    virtual void onEnter();
    //创建摇杆，dpad是摇杆的大圈，jostick是摇杆的点，point是摇杆的位置
    static JostickLayer* createJostick(const char* dpad,const char* jostick,Point point);
    float getRad(Point pos1,Point pos2);
    bool isInDpad(Point touchPoint);
private:
    bool m_isMove;  //是否可以移动
    ControlDirection m_direction; //当前方位
    const char* m_dpadImage;
    const char* m_jostickImage;
    Point m_point;
    CC_SYNTHESIZE_RETAIN(Sprite*, dpadSpr, DpadSpr);
    CC_SYNTHESIZE_RETAIN(Sprite*, jostickSpr, JostickSpr);
    CC_SYNTHESIZE(JostickDelegator*, delegator, Delegator);
};
#endif /* defined(__myGame__JostickLayer__) */
