#include "menuItem.h"

Scene *menuItem::createScene()
{
	auto scene = Scene::create();
	auto layer = menuItem::create();
	scene->addChild(layer);
	return scene;
}

bool menuItem::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size size = Director::sharedDirector()->getVisibleSize();
	MenuItemFont *menuitem1 = MenuItemFont::create("MenuItem1", this, menu_selector(menuItem::menuCallback));
	menuitem1->setPosition(ccp(size.width*0.5, size.height*0.9));
	menuitem1->setTag(0);

	LabelBMFont *lableitem1 = LabelBMFont::create("LableItem1", "fonts/myfont.fnt");
	MenuItemLabel *menuitem2 = MenuItemLabel::create(lableitem1, this, menu_selector(menuItem::menuCallback));
	menuitem2->setPosition(ccp(size.width*0.5, size.height*0.7));
	menuitem2->setTag(1);

	MenuItemImage *menuitem3 = MenuItemImage::create("button/btn-play-normal.png", "button/btn-play-selected.png", this, menu_selector(menuItem::menuCallback));
	menuitem3->setPosition(ccp(size.width*0.5, size.height*0.5));
	menuitem3->setTag(2);

	Sprite *about_normal = Sprite::create("button/btn-about-normal.png");
	Sprite *about_selected = Sprite::create("button/btn-about-selected.png");
	Sprite *about_disable = Sprite::create("button/btn-about-selected.png");
	MenuItemSprite *menuitem4 = MenuItemSprite::create(about_normal, about_selected, CC_CALLBACK_1(menuItem::menuCallback, this));
	menuitem4->setPosition(ccp(size.width*0.5, size.height*0.3));
	menuitem4->setTag(3);

	MenuItemToggle *menuitem5 = MenuItemToggle::createWithTarget(this, menu_selector(menuItem::menuCallback), MenuItemFont::create("on"), MenuItemFont::create("off"), NULL);
	menuitem5->setPosition(ccp(size.width*0.5, size.height*0.1));
	menuitem5->setTag(4);

	Menu *menu = Menu::create(menuitem1, menuitem2, menuitem3, menuitem4, menuitem5, NULL);
	menu->setPosition(CCPointZero);
	addChild(menu);

	return true;
}

void menuItem::menuCallback(cocos2d::Ref *ref)
{
	// process
	switch (static_cast<Node*>(ref)->getTag())
	{
	case 0:
		log("item1");
		break;
	case 1:
		log("item2");
		break;
	case 2:
		log("item3");
		break;
	case 3:
		log("item4");
		break;
	case 4:
		log("item5");
		break;
	}
}

