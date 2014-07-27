#ifndef __ACTIONTEST__
#define __ACTIONTEST__

#include "cocos2d.h"
USING_NS_CC;

class ActionTest : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	virtual void callBackFunc(Node *pSender,void *data);
	CREATE_FUNC(ActionTest);
};

#endif