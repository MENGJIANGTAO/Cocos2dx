#ifndef PROGRESS_TEST

#include "cocos2d.h"
USING_NS_CC;

class progressTest : public cocos2d::Layer
{
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	CREATE_FUNC(progressTest);
};
#endif