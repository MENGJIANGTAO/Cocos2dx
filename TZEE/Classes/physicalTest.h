#ifndef PHYSICAL_TEST_H
#define PHYSICAL_TEST_H

#include "cocos2d.h"
USING_NS_CC;

class physicalTest : public Layer
{
public:
	virtual bool init();
	static cocos2d::Scene *createScene();
	virtual void onEnter() override;
	void menuCloseCallback(cocos2d::Ref * pSender);
	CREATE_FUNC(physicalTest);

	void setPhyWorld(cocos2d::PhysicsWorld* world){ m_world = world; }
	virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);
	void addNewSpriteAtPosition(cocos2d::Point p);
	bool onContactBegin(PhysicsContact& contact);
	void logic(float dt);
private:
	cocos2d::PhysicsWorld* m_world;
	Sprite *sp,*sp2;
	Sprite *edgeSp;
};
#endif