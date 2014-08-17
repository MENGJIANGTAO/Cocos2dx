/* 
 * File:   GameOver.h
 * Author: mengjiangtao
 *
 * Created on August 14, 2014, 10:15 PM
 */

#ifndef GAMEOVER_H
#define	GAMEOVER_H
#include "cocos2d.h"
USING_NS_CC;

class GameOver : public cocos2d::Layer{
    public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    virtual bool onTouchBegan(Touch* touch,Event *event);
    std::string convertAppraise();
    virtual void onEnter();
    virtual void onExit();
    
    CREATE_FUNC(GameOver);
};
#endif	/* GAMEOVER_H */

