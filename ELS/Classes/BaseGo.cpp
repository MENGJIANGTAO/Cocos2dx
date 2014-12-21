#include "BaseGo.h"
#include "Resources.h"
#include "AppDelegate.h"
#include "VisibleRect.h"

USING_NS_CC;

void BaseGo::onEnter()
{
	Layer::onEnter();
	AppDelegate* app = (AppDelegate *)Application::getInstance();
	app->setCurrentGo(this);
	// add title and subtitle
	std::string str = title();
	const char * pTitle = str.c_str();
	TTFConfig ttfConfig("fonts/Marker Felt.ttf", 32);
	auto label = Label::createWithTTF(ttfConfig, pTitle);
	addChild(label, 9999);
	label->setPosition(VisibleRect::center().x, VisibleRect::top().y - 30);

	std::string strSubtitle = subtitle();
	if (!strSubtitle.empty())
	{
		ttfConfig.fontFilePath = "fonts/Marker Felt.ttf";
		ttfConfig.fontSize = 16;
		auto l = Label::createWithTTF(ttfConfig, strSubtitle.c_str());
		addChild(l, 9999);
		l->setPosition(VisibleRect::center().x, VisibleRect::top().y - 60);
	}

	// add menu
	// CC_CALLBACK_1 == std::bind( function_ptr, instance, std::placeholders::_1, ...)
	auto item1 = MenuItemImage::create(s_pathB1, s_pathB2, CC_CALLBACK_1(BaseGo::backCallback, this));
	auto item2 = MenuItemImage::create(s_pathR1, s_pathR2, CC_CALLBACK_1(BaseGo::restartCallback, this));
	auto item3 = MenuItemImage::create(s_pathF1, s_pathF2, CC_CALLBACK_1(BaseGo::nextCallback, this));

	auto menu = Menu::create(item1, item2, item3, nullptr);

	menu->setPosition(Vec2::ZERO);
	item1->setPosition(VisibleRect::center().x - item2->getContentSize().width * 2, VisibleRect::bottom().y + item2->getContentSize().height / 2);
	item2->setPosition(VisibleRect::center().x, VisibleRect::bottom().y + item2->getContentSize().height / 2);
	item3->setPosition(VisibleRect::center().x + item2->getContentSize().width * 2, VisibleRect::bottom().y + item2->getContentSize().height / 2);

	addChild(menu, 9999);
}

void BaseGo::onExit()
{
	AppDelegate* app = (AppDelegate *)Application::getInstance();
	app->setCurrentGo(nullptr);
	Layer::onExit();
}

std::string BaseGo::title() const
{
	return "";
}

std::string BaseGo::subtitle() const
{
	return "";
}

void BaseGo::restartCallback(Ref* sender)
{
	log("override restart!");
}

void BaseGo::nextCallback(Ref* sender)
{
	log("override next!");
}

void BaseGo::backCallback(Ref* sender)
{
	log("override back!");
}
