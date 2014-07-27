#include "changeScen.h"
#include "skillCd.h"

USING_NS_CC;

Scene *changeScen::createScene()
{
	auto scene = Scene::create();
	auto layer = changeScen::create();
	scene->addChild(layer);
	return scene;
}

bool changeScen::init()
{
	if (!Layer::init())
		return false;

	Size visibleSize = Director::getInstance()->getVisibleSize();

	Texture2D *bg = TextureCache::sharedTextureCache()->textureForKey("HelloWorld.png");

	Sprite *background = Sprite::createWithTexture(bg);
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(background);

	Sprite *person = Sprite::create("person/poster_char_baihuzi.png");
	person->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(person);

	//CCGridAction *action = CCLiquid::create(5.0f, Size(5, 5), 3, 3.0f);
	//person->runAction(action);
	MenuItemImage *icon1 = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(changeScen::menuCallback, this));
	Menu *menu = Menu::create(icon1,NULL);
	addChild(menu);
	menu->setPosition(400, 50);/*
	schedule(schedule_selector(changeScen::doChange), 1.0f);*/
	return true;
}

void changeScen::doChange(float dt)
{
	Scene *scene = skillCd::createScene();
	Director::getInstance()->replaceScene(CCTransitionPageTurn::create(3.0f,scene,true));
}

void changeScen::menuCallback(Object *pSender)
{
	Scene *scene = skillCd::createScene();
	Director::getInstance()->replaceScene(CCTransitionPageTurn::create(3.0f, scene,true));
}