#include "particleTest.h"
USING_NS_CC;

Scene *particleTest::createScene()
{
	auto scene = Scene::create();
	auto layer = particleTest::create();
	scene->addChild(layer);
	return scene;
}

bool particleTest::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::sharedDirector()->getVisibleSize();

	/*ParticleSnow *snow = ParticleSnow::create();
	snow->setPosition(visibleSize.width / 2, visibleSize.height);
	snow->setSpeed(35);
	addChild(snow);

	ParticleSun *sun = ParticleSun::create();
	sun->setPosition(visibleSize.width / 2, visibleSize.height);
	sun->setTexture(Director::getInstance()->getTextureCache()->addImage("icon.png"));
	addChild(sun);*/

	boom = ParticleSystemQuad::create("boom.plist");
	boom->setPosition(visibleSize.width / 2, visibleSize.height*0.7);
	addChild(boom);
	boom->setVisible(false);

	//boom1 = ParticleSystemQuad::create("boom2.plist");
	//boom1->setPosition(visibleSize.width / 2, visibleSize.height*0.7);

	ParticleSystem *up = ParticleSystemQuad::create("fireUp.plist");
	up->setPosition(visibleSize.width / 2, 0);
	addChild(up);

	CallFunc *func = CallFunc::create(this, callfunc_selector(particleTest::callback));
	MoveTo *upMove = MoveTo::create(1.0f, ccp(visibleSize.width / 2, visibleSize.height * 0.7));
	up->runAction(Sequence::create(upMove, Hide::create(), DelayTime::create(0.5f),func, NULL));


	//up->runAction(upMove);
	//up->runAction(Hide::create());
	//up->runAction(DelayTime::create(3.0f));
	//addChild(boom1);
	//boom1->runAction(SkewTo::create(1, 1, 1));
	//Hide::create();
	//runAction(DelayTime::create(1.0f));
	//addChild(boom);
	//boom->runAction(MoveBy::create(4.0f, ccp(visibleSize.width / 2, visibleSize.height*0.7)));
	return true;
}

void particleTest::callback()
{
	//runAction(DelayTime::create(1.0f));
	boom->setVisible(true);
}