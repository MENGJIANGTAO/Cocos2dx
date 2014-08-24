#include "ActionTest.h"

Scene *ActionTest::createScene()
{
	auto scene = Scene::create();
	auto layer = ActionTest::create(); 
	scene->addChild(layer);
	return scene;
}

bool ActionTest::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	
	Sprite *sprite1 = Sprite::create("person/poster_char_xiaohai2.png");
 	sprite1->setScale(0.5f);
	addChild(sprite1, 1, 1);
	sprite1->setPosition(0, 0);
	ActionInterval *action1 = MoveTo::create(3.0f, ccp(visibleSize.width, visibleSize.height));
	ActionInstant *func = CCCallFuncND::create(this, SEL_CallFuncND(&ActionTest::callBackFunc),(void*)10);

	Follow *action_follow = Follow::create(sprite1, Rect::ZERO);

	sprite1->runAction(Sequence::create(action1,func,NULL));
	this->runAction(action_follow);
}

void ActionTest::callBackFunc(Node *pSender,void *data)
{
	CCLog("every thing is ok.");
	this->stopAllActions();
	Sprite *person = (Sprite*)(this->getChildByTag(1));
	person->runAction(MoveTo::create(2.0f, ccp(100, 100)));
}