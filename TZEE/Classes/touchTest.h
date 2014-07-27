#ifndef TOUCHTEST_H
#define TOUCHTEST_H

#include "cocos2d.h"
USING_NS_CC;
class touchTest : public cocos2d::Layer
{

public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(Touch *touch,Event *event);
	void onTouchMoved(Touch *touch, Event *event);
	void ontTouchEnded(Touch *touch, Event *event);
	CREATE_FUNC(touchTest);
};
#endif