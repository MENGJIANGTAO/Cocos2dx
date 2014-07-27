#include "myfont.h"

USING_NS_CC;

Scene *myfont::createScene()
{
	auto scene = Scene::create();
	auto layer = myfont::create();
	scene->addChild(layer);
	return scene;
}

bool myfont::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	LabelBMFont *myfont = LabelBMFont::create("meng_jiangtao's font.", "fonts/myfont.fnt");
	myfont->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(myfont);
	return true;
}