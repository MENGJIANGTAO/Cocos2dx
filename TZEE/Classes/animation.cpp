#include "animation.h"
USING_NS_CC;

Scene* animation::createScene()
{
	auto scene = Scene::create();
	auto layer = animation::create();
	scene->addChild(layer);
	return scene;
}

bool animation::init()
{
	if (!Layer::init())
		return false;
	Size visibleSize = Director::getInstance()->getVisibleSize();

	SpriteFrameCache *framecache = SpriteFrameCache::getInstance();
	framecache->addSpriteFramesWithFile("grossini.plist");


	Vector<SpriteFrame*> array(15);
	char str[50] = { 0 };
	for (int i = 1; i < 15; i++)
	{
		sprintf(str, "grossini_dance_%02d.png", i);
		auto *frame = framecache->getSpriteFrameByName(str);
		array.pushBack(frame);
	}

	auto animation = Animation::createWithSpriteFrames(array, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation, "dance");

	auto animCache = AnimationCache::getInstance();
	auto normal = animCache->getAnimation("dance");
	normal->setRestoreOriginalFrame(true);

	auto grossini = Sprite::create();
	auto frame = framecache->getSpriteFrameByName("grossini_dance_01.png");
	grossini->setSpriteFrame(frame);
	grossini->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(grossini);
	grossini->runAction(RepeatForever::create(Animate::create(animation)));

}