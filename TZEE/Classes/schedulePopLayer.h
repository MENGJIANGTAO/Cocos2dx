#ifndef SCHEDULE_POPLAYER

#include "cocos2d.h"
USING_NS_CC;

class schedulePopLayer : public cocos2d::Layer
{
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	void pushMsg(float dt);
	void popMsg(float dt);
	LayerColor *msgLayer;
	Size size;
	CREATE_FUNC(schedulePopLayer);
};
#endif // !SCHEDULE_POPLAYER
