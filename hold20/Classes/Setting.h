/* 
 * File:   Setting.h
 * Author: mengjiangtao
 *
 * Created on August 13, 2014, 11:37 PM
 */

#ifndef SETTING_H
#define	SETTING_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
class Setting : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void backCallback(cocos2d::Ref* pSender);
    void soundCallback(cocos2d::Ref* pSender);
    void bulletNumCallback(cocos2d::Ref* pSender);
    void controlCallback(cocos2d::Ref *pSender);
    CREATE_FUNC(Setting);
};
#endif	/* SETTING_H */

