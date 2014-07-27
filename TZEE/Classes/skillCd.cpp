#include "skillCd.h"
USING_NS_CC;

Scene *skillCd::createScene()
{
	auto scene = Scene::create();
	auto layer = skillCd::create();
	scene->addChild(layer);
	return scene;
}

bool skillCd::init()
{
	if (!Layer::init())
		return false;
	Size visibleSize = Director::getInstance()->getVisibleSize();

	ProgressTo *to = ProgressTo::create(3.0f, 100);
	
	Sprite *skill_icon = Sprite::create("icon.png");
	ProgressTimer *skill = ProgressTimer::create(skill_icon);
	skill->setType(kCCProgressTimerTypeRadial);
	skill->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(skill);

	Sprite *skill_icon_back = skill_icon;
	skill_icon_back->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	skill_icon_back->setOpacity(100);
	addChild(skill_icon_back);
	skill->runAction(to);
	return true;
}