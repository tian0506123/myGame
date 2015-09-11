//
//  JostickDelegaor.h
//  myGame
//
//  Created by ngu on 15/6/17.
//
//

#ifndef __myGame__JostickDelegaor__
#define __myGame__JostickDelegaor__

#include <stdio.h>


typedef enum {
    control_up=0,   //向上
    control_down,   //向下
    control_lift,   //向左
    control_right,   //向右
    control_stop    //停止
}ControlDirection;

class JostickDelegator
{
public:
    virtual void jostickAttribute(float angle,ControlDirection dirction)=0;
};

#endif /* defined(__myGame__JostickDelegaor__) */
