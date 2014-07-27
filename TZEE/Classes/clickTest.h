#ifndef CLICK_TEST_H
#define CLICK_TEST_H

#include "cocos2d.h"
USING_NS_CC;

class clickTest : public cocos2d::Layer
{
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	virtual bool onTouchBegan(Touch *touch,Event *event);
	virtual void onEnter();
	virtual void onExit();
	void singleClick();
	void doubleClick();
	void judgeClick(float dt);

private:
	bool isClick = false;

	CREATE_FUNC(clickTest);
};
#endif