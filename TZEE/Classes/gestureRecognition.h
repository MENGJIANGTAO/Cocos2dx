#ifndef GESTURE_H
#define GESTURE_H

#include "cocos2d.h"
USING_NS_CC;

class gestureRecognition : public cocos2d::Layer
{
public:
	static cocos2d::Scene  *createScene();
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(Touch *touch, Event *event);
	virtual void onTouchMoved(Touch *touch,Event *event);
	virtual void onTouchEnded(Touch *touch,Event *event);
	void recognitionDirection(float dt);
private:
	Point curPos;
	Point endPos;
	float pathLength;

	CREATE_FUNC(gestureRecognition);
};
#endif