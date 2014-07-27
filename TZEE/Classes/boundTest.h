#ifndef BOUND_TEST_H
#define BOUND_TEST_H

#include "cocos2d.h"
USING_NS_CC;
class boundTest : public cocos2d::Layer
{

public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(Touch *touch, Event *event);
	void onTouchMoved(Touch *touch, Event *event);
	void ontTouchEnded(Touch *touch, Event *event);
	virtual void onAcceleration(Acceleration *p,Event * event);
private:
	Sprite* sp1;
	Sprite* sp2;
	LabelBMFont* label;
	Size visibleSize;
	bool canMove = false;;
	CREATE_FUNC(boundTest);
};
#endif