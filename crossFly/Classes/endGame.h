#ifndef END_GAME
#define END_GAME

#include "cocos2d.h"
USING_NS_CC;

class endGame:public cocos2d::Layer
{
public:
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(endGame);
};
#endif