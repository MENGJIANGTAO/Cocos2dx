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
    void onEnter();
    void onExit();
    void callBack(cocos2d::Ref *ref);
    CREATE_FUNC(RankScene);
    
private:
    std::vector<std::string> num;
    int name_x,name_y;
    int score_x,score_y;
    
};


#endif	/* RANDSCENE_H */

