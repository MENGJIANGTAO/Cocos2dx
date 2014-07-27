#include "easeAction.h"

USING_NS_CC;

Scene *easeAction::createScene()
{
	auto scene = Scene::create();
	auto layer = easeAction::create();
	scene->addChild(layer);
	return scene;
}

bool easeAction::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Sprite *p_aisi = Sprite::create("person/poster_char_aisi.png");
	//ActionInterval *move = ;
	addChild(p_aisi);
	//p_aisi->runAction(EaseBackOut::create(MoveTo::create(2.0f, ccp(300, 400))));
	//p_aisi->runAction(EaseBackIn::create(MoveTo::create(2.0f, ccp(300, 400))));
	//p_aisi->runAction(EaseCircleActionOut::create(MoveTo::create(2.0f, ccp(300, 400))));
	//p_aisi->runAction(EaseBackInOut::create(MoveTo::create(2.0f, ccp(300, 400))));
	p_aisi->runAction(Sequence::create(MoveTo::create(2.0f,ccp(400, 400)), EaseCubicActionOut::create(MoveTo::create(2.0f, ccp(300, 400))),NULL));

}