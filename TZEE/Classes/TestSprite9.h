#ifndef __TESTSPRITE9__
#define __TESTSPRITE9__

#include "cocos2d.h"

class TestSprite9 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(TestSprite9);
};

#endif