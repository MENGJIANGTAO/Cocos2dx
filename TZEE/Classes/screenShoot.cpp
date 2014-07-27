#include "cocos2d.h"
#include "screenShoot.h"

Scene *screenShoot::createScene()
{
	auto *layer = screenShoot::create();
	auto *scene = Scene::create();
	scene->addChild(layer);
	return scene;
}

bool screenShoot::init()
{
	if (!Layer::init())
	{
		return false;
	}
	visibleSize = Director::sharedDirector()->getVisibleSize();
	Sprite* pitcure = Sprite::create("person/poster_char_pangbai.png");
	pitcure->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(pitcure);

	MenuItemFont *button = MenuItemFont::create("PrintScreen", CC_CALLBACK_1(screenShoot::menuCallBack,this));
	Menu *menu = Menu::create(button, NULL);
	menu->setPosition(visibleSize.width / 2, visibleSize.height*0.3);
	this->addChild(menu);
}


void screenShoot::menuCallBack(Ref *pSender)
{
	RenderTexture *shoot = RenderTexture::create(visibleSize.width, visibleSize.height);
	shoot->begin();
	Director::sharedDirector()->getRunningScene()->visit();
	shoot->end();

	if (shoot->saveToFile("screenShoot.png", cocos2d::Image::Format::PNG))
	{
		log("Save the screenShoot scuess.");
		showScreenShoot();
	}
}

void screenShoot::showScreenShoot()
{
	std::string path = (FileUtils::sharedFileUtils()->getWritablePath() + "screenShoot.png").c_str();
	log("screenShoot's path is %s",path);
	Sprite* screen = Sprite::create(path);
	screen->setScale(0.5f);
	screen->setAnchorPoint(ccp(0, 0));
	screen->setPosition(0, visibleSize.height*0.7);
	addChild(screen);
}