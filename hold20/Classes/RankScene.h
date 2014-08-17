/* 
 * File:   RandScene.h
 * Author: mengjiangtao
 *
 * Created on August 17, 2014, 3:50 PM
 */

#ifndef RANDSCENE_H
#define	RANDSCENE_H
#include "cocos2d.h"
USING_NS_CC;

class RankScene : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void callBack(cocos2d::Ref *ref);
    CREATE_FUNC(RankScene);
    
};


#endif	/* RANDSCENE_H */

