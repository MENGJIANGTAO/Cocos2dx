#ifndef MYFONT_H
#define MYFONT_H

#include "cocos2d.h"
USING_NS_CC;

class myfont : public cocos2d::Layer
{
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	CREATE_FUNC(myfont);
};
#endif