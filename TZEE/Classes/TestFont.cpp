#include "TestFont.h"
USING_NS_CC;

Scene* TestFont::createScene()
{
	auto scene = Scene::create();
	auto layer = TestFont::create();
	scene->addChild(layer);
	return scene;
}

bool TestFont::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite *person_1 = Sprite::create();

	Sprite *person_2 = Sprite::create("person/poster_char_abisi.png");
	person_2->setPosition(visibleSize.width / 2, visibleSize.height * 0.5);
	person_2->setScale(0.5f);
	addChild(person_2);

	Sprite *person_3 = Sprite::create("person/poster_char_aisi.png", Rect(100, 100, 100, 100));
	person_3->setScale(0.5f);
	person_3->setPosition(visibleSize.width * 0.3,visibleSize.height * 0.5);
	addChild(person_3);

	SpriteFrame *person_4_frame = SpriteFrame::create("person/poster_char_aozi.png",Rect(0,0,400,400));
	Sprite *person_4 = Sprite::createWithSpriteFrame(person_4_frame);
	person_4->setScale(0.5);
	person_4->setPosition(visibleSize.width * 0.8, visibleSize.height * 0.5);
	addChild(person_4);

	// static Sprite* createWithTexture 	( 	Texture2D *  	texture)

	SpriteBatchNode *spritebathcnode = SpriteBatchNode::create("person/poster_char_baji.png");
	spritebathcnode->setPosition(visibleSize.width*0.7, visibleSize.height*0.5);
	addChild(spritebathcnode);

	Sprite *person_5 = Sprite::createWithTexture(spritebathcnode->getTexture());
	person_5->setScale(0.5);
	person_5->setPosition(visibleSize.width*0.3, visibleSize.height*0.5);
	addChild(person_5);

}