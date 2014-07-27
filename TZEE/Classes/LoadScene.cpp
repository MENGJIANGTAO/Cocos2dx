#include  "LoadingScene.h"
#include "changeScen.h"

USING_NS_CC;

Scene *LoadScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LoadScene::create();
	scene->addChild(layer);
	return scene;
}

bool LoadScene::init()
{
	if (!Layer::init())
		return false;
	Size visibleSize = Director::getInstance()->getVisibleSize();

	loadText = LabelTTF::create("Loading...", "Arial",20);
	loadPercent = LabelTTF::create("0%", "Arial", 20);

	addChild(loadText);
	addChild(loadPercent);

	Sprite *barback = Sprite::create(("loadingbar.png"));
	barback->setPosition(ccp(visibleSize.width*0.5, 300));
	addChild(barback);

	loadNum = 100;
	load = 0;

	progress = ProgressTimer::create(Sprite::create("sliderTrack2.png"));
	progress->setBarChangeRate(ccp(1, 0));
	progress->setType(kCCProgressTimerTypeBar);
	progress->setMidpoint(ccp(0, 0));
	progress->setPercentage(0.0f);
	progress->setPosition(ccp(visibleSize.width*0.5, 300));
	addChild(progress, 1);

	loadText->setPosition(ccp(visibleSize.width*0.4, 300));
	loadPercent->setPosition(ccp(visibleSize.width*0.5, 320));

	for (size_t i = 0; i < 100; i++)
	{
		TextureCache::sharedTextureCache()->addImageAsync("HelloWorld.png", CC_CALLBACK_1(LoadScene::loadOver, this));
	}
	//schedule(schedule_selector(LoadScene::loadOver, 0.5f));
	//barback->runAction(progressTo);
	return true;
}

//void LoadScene::loadOver(float dt)
void LoadScene::loadOver(Object *pSender)
{
	load++;
	char temp[10];
	float value = ((float)load / loadNum) * 100;
	sprintf(temp,"%d%%", (int)value);
	loadPercent->setString(temp);
	progress->setPercentage(value);

	if (load == loadNum)
	{
		removeAllChildren();
		Scene *scene = changeScen::createScene();
		Director::getInstance()->replaceScene(CCTransitionPageTurn::create(3.0f, scene, true));
	}
}

