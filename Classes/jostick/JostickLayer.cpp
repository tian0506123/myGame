//
//  JostickLayer.cpp
//  myGame
//
//  Created by ngu on 15/6/17.
//
//

#include "JostickLayer.h"

//初始化
bool JostickLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    dpadSpr=Sprite::create(m_dpadImage);
    dpadSpr->setPosition(m_point);
    this->addChild(dpadSpr);
    
    jostickSpr=Sprite::create(m_jostickImage);
    jostickSpr->setPosition(m_point);
    this->addChild(jostickSpr);
    return true;
}

//创建摇杆
JostickLayer* JostickLayer::createJostick(const char* dpad,const char* jostick,Point point)
{
    JostickLayer* layer = new JostickLayer();
    layer->setDelegator(NULL);
    layer->m_dpadImage=dpad;
    layer->m_jostickImage=jostick;
    layer->m_point=point;
    if (layer && layer->init())
    {
        layer->autorelease();
        return layer;
    }
    else
    {
        delete layer;
        layer = NULL;
        return NULL;
    }
    return layer;
}

void JostickLayer::onEnter(){
    Layer::onEnter();
    this->setTouchEnabled(true);
    this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
}

//触摸时
bool JostickLayer::onTouchBegan(Touch *touch, Event *unused_event){
    //  printf("点击了\n");
    Point touchPoint=touch->getLocation();
    if (isInDpad(touchPoint)) {
        m_isMove=true;
    }
    return true;
}

void JostickLayer::onTouchMoved(Touch *touch, Event *unused_event){
    if (m_isMove) {
        Point touchPoint=touch->getLocation();
        Point oldPoint=touch->getPreviousLocation();
        Point point=Point(touchPoint.x-oldPoint.x,touchPoint.y-oldPoint.y);
        Point toPoint=jostickSpr->getPosition()+point;
        //中心点移动的位置
        if (isInDpad(toPoint)) {
            jostickSpr->setPosition(toPoint);
            //中心点得角度
            float x= getRad(dpadSpr->getPosition(),toPoint);
           
            if(x>=-45&&x<45){
                m_direction=ControlDirection::control_right;
            }else if(x>=-135&&x<-45){
                m_direction=ControlDirection::control_down;
            }else if(x>=135||x<-135){
                m_direction=ControlDirection::control_lift;
            }else if(x>=45&&x<135){
                m_direction=ControlDirection::control_up;
            }else{
                printf("your angle is：%f\n",x);
            }
            
            if (delegator!=NULL)
                delegator->jostickAttribute(x, m_direction);
            
        }
    }
}

void JostickLayer::onTouchEnded(Touch *touch, Event *unused_event){
    m_isMove=false;
    jostickSpr->runAction(MoveTo::create(0.1, dpadSpr->getPosition()));
    m_direction=ControlDirection::control_stop;
    if (delegator!=NULL) {
          delegator->jostickAttribute(0, m_direction);
    }
  
}

//该点是否在圆圈中
bool JostickLayer::isInDpad(Point touchPoint){
    //获取摇杆位置
    int r=dpadSpr->getBoundingBox().size.width/2;
    Point dpadPoint=dpadSpr->getPosition();
    int x=abs(touchPoint.x-dpadPoint.x);
    int y=abs(touchPoint.y-dpadPoint.y);
    int zui=sqrt(x*x+y*y);
    if (zui<=r) {
        return true;
    }
    return false;
}


//获取当前摇杆与用户触屏点的角度
float JostickLayer::getRad(Point pos1,Point pos2)
{
    float px1 = pos1.x;
    float py1 = pos1.y;
    float px2 = pos2.x;
    float py2 = pos2.y;
    
    //得到两点x的距离
    float x = px2 - px1;
    //得到两点y的距离
    float y = py1 - py2;
    //算出斜边长度
    float xie = sqrt(pow(x,2) + pow(y,2));
    //得到这个角度的余弦值(通过三角函数中的店里：角度余弦值=斜边/斜边)
    
    float cosAngle = x / xie;
    //通过反余弦定理获取到期角度的弧度
    float rad = acos(cosAngle);
    //注意：当触屏的位置Y坐标<摇杆的Y坐标，我们要去反值-0~-180
    if (py2 < py1)
    {
        rad = -rad;
    }
    
    return (rad*180)/3.14;
}