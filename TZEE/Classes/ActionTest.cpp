#include "ActionTest.h"

Scene *ActionTest::createScene()
{
	auto scene = Scene::create();
	auto layer = ActionTest::create(); 
	scene->addChild(layer);
	return scene;
}

bool ActionTest::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	
	//Sprite *sprite1 = Sprite::create("person/poster_char_xiaohai2.png");
 //	sprite1->setScale(0.5f);
	//addChild(sprite1, 1, 1);
	//sprite1->setPosition(0, 0);
	//ActionInterval *action1 = MoveTo::create(3.0f, ccp(visibleSize.width, visibleSize.height));
	//ActionInstant *func = CCCallFuncND::create(this, SEL_CallFuncND(&ActionTest::callBackFunc),(void*)10);

	//Follow *action_follow = Follow::create(sprite1, Rect::ZERO);

	//sprite1->runAction(Sequence::create(action1,func,NULL));
	//sprite1->runAction(action_follow);

	int x = visibleSize.width;
	int y = visibleSize.height;
	Node *blue = LayerColor::create(ccc4(0, 0, 255, 255));
	Node *red = LayerColor::create(ccc4(255, 0, 0, 255));
	Node *green = LayerColor::create(ccc4(0, 255, 0, 255));
	Node *white = LayerColor::create(ccc4(255, 255, 255, 255));

	blue->setScale(0.5f);
	blue->setPosition(ccp(-x / 4, -y / 4));

	red->setScale(0.5f);
	red->setPosition(ccp(x / 4, -y / 4));

	green->setScale(0.5f);
	green->setPosition(ccp(-x / 4, y / 4));

	white->setScale(0.5f);
	white->setPosition(ccp(x / 4, y / 4));
	
	addChild(blue);
	addChild(red);
	addChild(green);
	addChild(white);

	Action *rot = RotateBy::create(8, 720);
	blue->runAction(rot);

	Action *rot1 = RotateBy::create(8, 720);
	red->runAction(rot1);

	Action *rot2 = RotateBy::create(8, 720);
	green->runAction(rot2);

	Action *rot3 = RotateBy::create(8, 720);
	white->runAction(rot3);

	SpriteFrameCache *cache = SpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile("grossini.plist");

	Sprite *_grossini = Sprite::createWithSpriteFrameName("grossini_dance_01.png");
	_grossini->setPosition(ccp(visibleSize.width*0.5, visibleSize.height*0.5));
	addChild(_grossini);

	//CCArray* animFrames = CCArray::createWithCapacity(14);
	Vector<SpriteFrame*> animFrames;
	char str[50] = { 0 };
	for (int i = 1; i < 15;i++)
	{
		sprintf(str, "grossini_dance_%02d.png", i);
		SpriteFrame *frame = cache->spriteFrameByName(str);
		animFrames.pushBack(frame);
	}

	Animation *animation = Animation::createWithSpriteFrames(animFrames, 0.3f);
	_grossini->runAction(RepeatForever::create(Animate::create(animation)));
	return true;
}

void ActionTest::callBackFunc(Node *pSender,void *data)
{
	CCLog("every thing is ok.");
	this->stopAllActions();
	Sprite *person = (Sprite*)(this->getChildByTag(1));
	person->runAction(MoveTo::create(2.0f, ccp(100, 100)));
}