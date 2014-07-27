#include "cocos2d.h"
#include "soundPlay.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

#define MUSCI_BG "adventure.mp3"

Scene *soundPlay::createScene()
{
	auto *layer = soundPlay::create();
	auto *scene = Scene::create();
	scene->addChild(layer);
	return scene;
}

bool soundPlay::init()
{
	if (!Layer::init())
	{
		return false;
	}
	visibleSize = Director::sharedDirector()->getVisibleSize();

	MenuItemFont *button = MenuItemFont::create("PrintScreen", CC_CALLBACK_1(soundPlay::menuCallBack, this));
	Menu *menu = Menu::create(button, NULL);
	menu->setPosition(visibleSize.width / 2, visibleSize.height*0.3);
	this->addChild(menu);

	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(MUSCI_BG);
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.2f);
}


void soundPlay::menuCallBack(Ref *pSender)
{
	if (!isPlay)
	{
		SimpleAudioEngine::getInstance()->playBackgroundMusic(MUSCI_BG, true);
		isPlay = true;
	}
	else
	{
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		isPlay = false;
	}
}