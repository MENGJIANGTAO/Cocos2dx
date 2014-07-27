#ifndef __ANIMATION__
#define __ANIMATION__

#include "cocos2d.h"

class animation : public cocos2d::Layer
{
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	CREATE_FUNC(animation);
};
#endif