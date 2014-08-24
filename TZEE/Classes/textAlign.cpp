#include "textAlign.h"

Scene *textAlign::createScene()
{
	auto scene = Scene::create();
	auto layer = textAlign::create();
	scene->addChild(layer);
	return scene;
}

bool textAlign::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size size = Director::sharedDirector()->getVisibleSize();

	LabelBMFont *label1 = LabelBMFont::create("Test label Cocos2dx-Left", "fonts/arial16.fnt", 20, TextHAlignment::LEFT);
	label1->setPosition(ccp(size.width*0.2, size.height*0.8));
	this->addChild(label1);

	LabelBMFont *label2 = LabelBMFont::create("Test label Cocos2dx-Center", "fonts/arial16.fnt", 20, TextHAlignment::CENTER);
	label2->setPosition(ccp(size.width*0.5, size.height*0.5));
	this->addChild(label2);

	LabelBMFont *label3 = LabelBMFont::create("Test label Cocos2dx-Right", "fonts/arial16.fnt", 20, TextHAlignment::RIGHT);
	label3->setPosition(ccp(size.width*0.8, size.height*0.2));
	label3->setAnchorPoint(ccp(0.5, 0));
	this->addChild(label3);

	return true;
}

