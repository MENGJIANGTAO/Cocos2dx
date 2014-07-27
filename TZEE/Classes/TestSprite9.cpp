#include "TestSprite9.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

Scene* TestSprite9::createScene()
{
	auto scene = Scene::create();
	auto layer = TestSprite9::create();
	scene->addChild(layer);
	return scene;
}

bool TestSprite9::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite *person_1 = Sprite::create();

	auto *test = Scale9Sprite::create("CloseNormal.png");
	test->setScaleX(3.0f);
	test->setScaleY(3.0f);
	test->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	test->setCapInsets(Rect(10, 10, 5, 5));
	test->setPreferredSize(Size(50, 50));
	addChild(test);
	return true;
}