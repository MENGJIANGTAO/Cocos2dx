#ifndef TESTDATASTRUCT
#define TESTDATASTRUCT

#include "cocos2d.h"

class TestDataStruct : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(TestDataStruct);
};

#endif