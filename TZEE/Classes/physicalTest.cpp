#include "physicalTest.h"
USING_NS_CC;

Scene *physicalTest::createScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	auto layer = physicalTest::create();
	layer->setPhyWorld(scene->getPhysicsWorld());
	scene->addChild(layer);
	return scene;
}

bool physicalTest::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size  visibleSize = Director::sharedDirector()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	edgeSp = Sprite::create();
	auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	edgeSp->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	edgeSp->setPhysicsBody(body);
	this->addChild(edgeSp);
	edgeSp->setTag(0);

	this->schedule(schedule_selector(physicalTest::logic));
	return true;
}

void physicalTest::onEnter()
{
	Layer::onEnter();

	sp = Sprite::create("boom2.png");
	sp->setTag(1);  // 角色
	auto body = PhysicsBody::createBox(Size(64, 64));
	body->setRotationEnable(false);
	body->setCategoryBitmask(1);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	sp->setPhysicsBody(body);
	sp->setPosition(ccp(100,200));
	this->addChild(sp);

	sp2 = Sprite::create("boom2.png");
	auto body2 = PhysicsBody::createBox(Size(64, 64));
	body2->setCategoryBitmask(1);
	body2->setCollisionBitmask(1);
	body2->setContactTestBitmask(1);
	sp2->setTag(2); // 石头
	sp2->setPhysicsBody(body2);
	sp2->setPosition(ccp(100, 64));
	addChild(sp2);

	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesEnded = CC_CALLBACK_2(physicalTest::onTouchesEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(physicalTest::onContactBegin, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}

bool physicalTest::onContactBegin(PhysicsContact& contact)
{
	log("onContactBegin.");
	auto body_1 = (Sprite*)contact.getShapeA()->getBody()->getNode();
	auto body_2 = (Sprite*)contact.getShapeB()->getBody()->getNode();

	if ((body_1->getTag() == 1 && body_2->getTag() == 2) ||
		(body_1->getTag() == 2 && body_2->getTag() == 1))
	{
		// 碰撞发生
	}
	return true;
}

void physicalTest::onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
{
	for (auto touch : touches)
	{
		auto location = touch->getLocation();

		sp->getPhysicsBody()->setVelocity(Vec2(0,100));
		sp->getPhysicsBody()->setMass(5.0f);
		sp->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
		//addNewSpriteAtPosition(location);
	}
}

void physicalTest::addNewSpriteAtPosition(cocos2d::Point p)
{
	//auto sp = Sprite::create("boom2.png");
	//sp->setTag(1);
	//auto body = PhysicsBody::createBox(Size(64, 64));
	//sp->setPhysicsBody(body);
	//sp->setPosition(p);
	//this->addChild(sp);
}

void physicalTest::menuCloseCallback(cocos2d::Ref * pSender)
{
	if (m_world->getDebugDrawMask() != PhysicsWorld::DEBUGDRAW_NONE)
	{
		m_world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);
	}
	else
	{
		m_world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	}
}

void  physicalTest::logic(float dt)
{

}