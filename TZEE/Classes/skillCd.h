#ifndef SKILLCD_H
#define SKILLCD_H

#include "cocos2d.h"
class skillCd : public cocos2d::Layer
{
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	CREATE_FUNC(skillCd);
};
#endif