/* 
 * File:   GameScene.h
 * Author: mengjiangtao
 *
 * Created on August 8, 2014, 11:34 PM
 */

#ifndef GAMESCENE_H
#define	GAMESCENE_H

#include <vector>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

class GameScene : public cocos2d::Layer {
public:
    virtual bool init();
    static cocos2d::Scene* createScene();
    virtual bool onTouchBegan(Touch* touch, Event *event);
    void onTouchMoved(Touch* touch, Event *event);
    void onTouchEnded(Touch* touch, Event *event);
    void onAcceleration(Acceleration* acc, Event* event);
    virtual void onEnter();
    virtual void onExit();

    CREATE_FUNC(GameScene);
private:
    void menuReturnCallBack(cocos2d::Ref *ref);
    void createBullet(float dt);
    void checkBullet(float dt);
    void flying(float dt);
    void explosionEndDid();
    void saveTime(long dt);
    Point center;
    float radius;
    Sprite *joystick;
    Sprite * joystick1;
    Sprite *plane;
    float speedX;
    float speedY;
    bool isFlying;
    bool dead;
    std::vector<Sprite*> bullets;

    Sprite *explosion;
};


#endif	/* GAMESCENE_H */

