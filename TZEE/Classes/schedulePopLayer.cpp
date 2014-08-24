#include "schedulePopLayer.h"

Scene *schedulePopLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = schedulePopLayer::create();
	scene->addChild(layer,0,"gameback");
	return scene;
}

bool schedulePopLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	size = Director::sharedDirector()->getVisibleSize();

	schedule(schedule_selector(schedulePopLayer::pushMsg),1,0,1);
	schedule(schedule_selector(schedulePopLayer::popMsg),1,0,2);
	return true;
}

void schedulePopLayer::pushMsg(float dt)
{
	LabelTTF *labelLanguage = LabelTTF::create(".", "fonts/myfont.fnt", 24, Size::ZERO, TextHAlignment::CENTER);
	msgLayer = LayerColor::create(ccc4(50, 255, 0, 255), 400, 150);
	msgLayer->setPosition(ccp(size.width*0.5,size.height*0.5));
	this->addChild(msgLayer,100,"msg");
	LanguageType currentLan = Application::sharedApplication()->getCurrentLanguage();
	switch (currentLan)
	{
	case kLanguageEnglish:
		labelLanguage->setString("current language is english.");
		break;
	case kLanguageChinese:
		labelLanguage->setString("current language is chinese.");
		break;
	}
	Size size  = msgLayer->getContentSize();
	labelLanguage->setPosition(ccp(size.width*0.5,size.height*0.5));
	msgLayer->addChild(labelLanguage);
}

void schedulePopLayer::popMsg(float dt)
{
	msgLayer->removeAllChildren();
	msgLayer->removeFromParentAndCleanup(true);
	this->removeChildByName("msg");
	log("clearup");
}