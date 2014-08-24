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

	Size frameSize = Director::sharedDirector()->getOpenGLView()->getFrameSize();
	log("frameSize:x:%.2f,y:%.2f", frameSize.width, frameSize.height);

	Size visibleSize = Director::sharedDirector()->getVisibleSize();
	log("visibleSize:x:%.2f,y:%.2f", visibleSize.width, visibleSize.height);

	Size winSize = Director::sharedDirector()->getWinSize();
	log("winSize:x:%.2f,y:%.2f", winSize.width, winSize.height);

	Sprite *bg = Sprite::create("HelloWorld.png");
	bg->setPosition(ccp(size.width*0.5, size.height*0.5));
	addChild(bg);
	schedule(schedule_selector(schedulePopLayer::pushMsg),1,0,1);
	schedule(schedule_selector(schedulePopLayer::popMsg),1,0,2);

	srand((unsigned)time(NULL));
	for (int i = 0; i < 10;i++)
	{
		int n = rand() % 100 + 1;  // 1~100
		log("%d", n);
	}
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
	//this->removeChildByName("msg");
	log("clearup");
}