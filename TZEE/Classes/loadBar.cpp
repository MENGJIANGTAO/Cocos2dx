#include "loadBar.h"
#include "progressTest.h"

Scene *loadBar::createScene()
{
	auto scene = Scene::create();
	auto layer = loadBar::create();
	scene->addChild(layer);
	return scene;
}

bool loadBar::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size size = Director::sharedDirector()->getWinSize();

	m_pLabelLoading = LabelTTF::create("Loading...", "Arial", 15);
	m_pLabelPercent = LabelTTF::create("%0", "Arial", 15);

	m_pLabelLoading->setPosition(ccp(size.width / 2, size.height / 2));
	m_pLabelPercent->setPosition(ccp(size.width / 2, size.height*0.3));

	this->addChild(m_pLabelLoading);
	this->addChild(m_pLabelPercent);

	m_nNumberLoadedSprite = 0;
	m_nNumberOfSprite = 200;

	Sprite *loadBg = Sprite::create("sliderTrack.png");
	loadBg->setPosition(ccp(size.width / 2, size.height*0.2));
	this->addChild(loadBg);

	loadProgress = ProgressTimer::create(Sprite::create("sliderProgress.png"));
	loadProgress->setBarChangeRate(ccp(1,0));
	loadProgress->setType(kCCProgressTimerTypeBar);
	loadProgress->setMidpoint(ccp(0, 0));
	loadProgress->setPosition(ccp(size.width / 2, size.height*0.2));
	loadProgress->setPercentage(0.0f);
	this->addChild(loadProgress, 1);

	for (int i = 0; i < 100; i++)
	{
		TextureCache::sharedTextureCache()->addImageAsync("HelloWorld.png", CC_CALLBACK_1(loadBar::loadCallBack, this));
		TextureCache::sharedTextureCache()->addImageAsync("icon.png", CC_CALLBACK_1(loadBar::loadCallBack, this));
	}
	return true;
}

void loadBar::loadCallBack(cocos2d::Texture2D *texture)
{
	m_nNumberLoadedSprite++;
	char tmp[10];
	float value = ((float)m_nNumberLoadedSprite / m_nNumberOfSprite) * 100;
	sprintf(tmp, "%d%%", (int)(value));
	m_pLabelPercent->setString(tmp);
	loadProgress->setPercentage(value);
	if (m_nNumberLoadedSprite == m_nNumberOfSprite)
	{
		turnScene();
	}
}

void loadBar::turnScene()
{
	Director::sharedDirector()->replaceScene(progressTest::createScene());
}
