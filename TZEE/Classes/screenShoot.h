#ifndef SCREEN_SHOOT_H
#define SCREEN_SHOOT_H

#include "cocos2d.h"
USING_NS_CC;

class screenShoot : public cocos2d::Layer
{
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	void menuCallBack(Ref *pSender);
	void showScreenShoot();

	CREATE_FUNC(screenShoot);
private:
	Size visibleSize;
};
#endif