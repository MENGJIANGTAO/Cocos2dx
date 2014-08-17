/* 
 * File:   MenuScene.h
 * Author: mengjiangtao
 *
 * Created on August 7, 2014, 8:41 PM
 */

#ifndef MENUSCENE_H
#define	MENUSCENE_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

class MenuScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // a selector callback
    void menuNewCallback(cocos2d::Ref* pSender);
    void menuOptionCallback(cocos2d::Ref* pSender);
    void menuScoreCallback(cocos2d::Ref* pSender);
    void menuQuitCallback(cocos2d::Ref* pSender);
    Size size;
    CREATE_FUNC(MenuScene);
};

#endif	/* MENUSCENE_H */

