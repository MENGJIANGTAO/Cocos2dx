#include "TestDataStruct.h"

USING_NS_CC;

Scene* TestDataStruct::createScene()
{
	auto scene = Scene::create();
	auto layer = TestDataStruct::create();
	scene->addChild(layer);
	return scene;
}

bool TestDataStruct::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	String *name = String::create("mengjiangtao");
	String *name2 = ccs("mengjiangtao");
	
	LabelTTF *namelabel = LabelTTF::create("", "Marker Felt.ttf", 20, Size::ZERO, cocos2d::TextHAlignment::CENTER, TextVAlignment::TOP);
	namelabel->setString(name->_string);
	namelabel->setPosition(100, 100);

	Dictionary *namedictionary = Dictionary::create();
	namedictionary->setObject(ccs("mengjiangtao1"), "key1");
	namedictionary->setObject(ccs("mengjiangtao2"), "key2");
	namedictionary->setObject(ccs("mengjiangtao3"), "key3");

	LabelTTF *namelabel2 = LabelTTF::create("", "Marker Felt.ttf", 20, Size::ZERO, cocos2d::TextHAlignment::CENTER, TextVAlignment::TOP);
	namelabel2->setString(namedictionary->valueForKey("key1")->_string);
	namelabel2->setPosition(100, 130);

	LabelTTF *namelabel3 = LabelTTF::create("", "Marker Felt.ttf", 20, Size::ZERO, cocos2d::TextHAlignment::CENTER, TextVAlignment::TOP);
	namelabel3->setString(namedictionary->valueForKey("key2")->_string);
	namelabel3->setPosition(100, 160);

	LabelTTF *namelabel4 = LabelTTF::create("", "Marker Felt.ttf", 20, Size::ZERO, cocos2d::TextHAlignment::CENTER, TextVAlignment::TOP);
	namelabel4->setString(namedictionary->valueForKey("key3")->_string);
	namelabel4->setPosition(100, 190);

	addChild(namelabel);
	addChild(namelabel2);
	addChild(namelabel3);
	addChild(namelabel4);

	return true;
}