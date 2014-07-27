#ifndef __TESTFONT_H__
#define __TESTFONT_H__

#include "cocos2d.h"

class TestFont : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(TestFont);
};

#endif