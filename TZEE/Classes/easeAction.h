#ifndef __EASEACTION__
#define __EASEACTION__
	
#include "cocos2d.h"

class easeAction : public cocos2d::Layer
{
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	CREATE_FUNC(easeAction);
};
#endif