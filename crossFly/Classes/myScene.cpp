#include "myScene.h"
#include "endGame.h"

Scene * myScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	auto layer = myScene::create();
	layer->setPhyWorld(scene->getPhysicsWorld());
	scene->addChild(layer);
	return scene;
}

bool myScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	srand((unsigned)GetCurrentTime());
	UserDefault::getInstance()->setIntegerForKey("score", 0);
	visibleSize = Director::getInstance()->getVisibleSize();
	players = new player(Point(0,visibleSize.height*0.35));
	auto body = PhysicsBody::createBox(Size(55, 75));
	body->setRotationEnable(false);
	body->setGravityEnable(false);
	body->setCategoryBitmask(1);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	s_player = players->getPlayer();
	s_player->setPhysicsBody(body);
	s_player->setTag(1);
	s_player->setPosition(Point(0, visibleSize.height*0.35));
	addChild(s_player);

	left = MenuItemImage::create("b1.png", "b2.png", CC_CALLBACK_1(myScene::menuCallLeft,this));
	right = MenuItemImage::create("f1.png", "f2.png", CC_CALLBACK_1(myScene::menuCallRight, this));

	left->setPosition(ccp(0,0));
	left->setAnchorPoint(ccp(0, 0));
	right->setPosition(ccp(left->getPositionX() + 100,0));
	right->setAnchorPoint(ccp(0, 0));
	auto handle_menu = Menu::create(left, right,nullptr);
	handle_menu->setPosition(ccp(0, visibleSize.height *0.1));
	addChild(handle_menu);

	scorePanel = LabelTTF::create("score:", "fonts/Marker Felt.ttf", 20);
	addChild(scorePanel);
	scorePanel->setPosition(ccp(visibleSize.width - 150, visibleSize.height - 20));
	score = LabelTTF::create("", "fonts/Marker Felt.ttf", 20);
	addChild(score);
	score->setPosition(scorePanel->getPositionX() + 50, scorePanel->getPositionY());

	enemys.reserve(5);
	auto body2 = PhysicsBody::createBox(Size(35, 55));

	for (int i = 0; i < enemys.capacity(); i++)
	{
		enemys.pushBack(Sprite::create("player.png"));
		enemys.at(i)->setAnchorPoint(ccp(0, 0));
		enemys.at(i)->setPhysicsBody(PhysicsBody::createBox(Size(35,55)));
		enemys.at(i)->getPhysicsBody()->setRotationEnable(false);
		enemys.at(i)->getPhysicsBody()->setGravityEnable(false);
		enemys.at(i)->getPhysicsBody()->setCategoryBitmask(1);
		enemys.at(i)->getPhysicsBody()->setCollisionBitmask(1);
		enemys.at(i)->getPhysicsBody()->setContactTestBitmask(1);
		enemys.at(i)->setTag(i + 2);
		enemys.at(i)->setPosition(ccp(rand() % 200, 640+rand() % 1280));
		addChild(enemys.at(i));
	}
	auto contactListener = EventListenerPhysicsContact::create();

	contactListener->onContactBegin = CC_CALLBACK_1(myScene::onContactBegin, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
	
	schedule(schedule_selector(myScene::updateGame), 0, kRepeatForever, 0);
	count = 0;
	return true;
}

void myScene::menuCallLeft(Ref* pSender)
{
	if (s_player->getPositionX() <= 0)
	{
		return;
	}
	auto move_left = MoveTo::create(0.2f, ccp(s_player->getPositionX() - 50, visibleSize.height*0.35));
	s_player->runAction(move_left);
}

void myScene::menuCallRight(Ref* pSender)
{
	if (s_player->getPositionX() >= 150)
	{
		return;
	}
	auto move_right = MoveTo::create(0.2f, ccp(s_player->getPositionX() + 50, visibleSize.height*0.35));
	s_player->runAction(move_right);
}

void myScene::updateGame(float dt)
{
	for (int i = 0; i < enemys.capacity(); i++)
	{
		if (enemys.at(i)->isVisible())
		{
			if (enemys.at(i)->getPositionY() < players->getPositionY()+200)
			{
				enemys.at(i)->setVisible(false);
				count++;
			}
			else
			{
				enemys.at(i)->setPositionY(enemys.at(i)->getPositionY() - 5);
			}
		}
		else
		{
			enemys.at(i)->setPosition(ccp(rand() % 200, 640 + rand() % 1280));
			enemys.at(i)->setVisible(true);
		}
	}
	score->setString(std::to_string(count));
}

bool myScene::onContactBegin(PhysicsContact &contace)
{
	auto body_1 = (Sprite*)contace.getShapeA()->getBody()->getNode();
	auto body_2 = (Sprite*)contace.getShapeB()->getBody()->getNode();

	if ((body_1->getTag() == 1 && body_2->getTag() != 1) ||
		(body_1->getTag() != 1 && body_2->getTag() == 1))
	{
		contace.getShapeA()->getBody()->getNode()->setVisible(false);
		UserDefault::getInstance()->setIntegerForKey("score", count);
		Director::getInstance()->replaceScene(endGame::createScene());
	}
	return true;
}