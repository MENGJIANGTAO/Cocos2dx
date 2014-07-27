#ifndef _CHANGESCEN_H
#define _CHANGESCEN_H

#include "cocos2d.h"
USING_NS_CC;

class changeScen : public cocos2d::Layer
{
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	void doChange(float dt);
	void menuCallback(Object *pSender);
	CREATE_FUNC(changeScen);

};
#endif