#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	//������Ϸ�ı�����ɫ  
	auto layerColorBG = cocos2d::LayerColor::create(cocos2d::Color4B(180, 170, 160, 255));
	this->addChild(layerColorBG);
	//������Ƭ  
	createCardSprite(visibleSize);

    return true;
}

bool HelloWorld::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event *unused_event)
{
	Point touchPoint = touch->getLocation();
	touch->getLocationInView();
	firstX = touchPoint.x;
	firstY = touchPoint.y;

	return true;
}

void HelloWorld::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event *unused_event)
{
	Point touchPoint = touch->getLocation();
	endX = firstX - touchPoint.x;
	endY = firstY - touchPoint.y;

	// ���x����ƶ��������Y���ƶ����룬�������ƶ������Y��������ƶ�
	if (abs(endX) > abs(endY))
	{

		if (endX + 5 > 0)
		{
			doLeft(); 
		}
		else
		{
			doRight();
		}
	}
	else
	{
		if (endY + 5 > 0)
		{
			doDown();
		}
		else
		{
			doUp();
		}
	}
}


bool HelloWorld::doUp()
{
	bool isdo = false;
	for (int x = 0; x < 4; x++) {
		for (int y = 3; y >= 0; y--) {

			for (int y1 = y - 1; y1 >= 0; y1--) {
				if (cardArr[x][y1]->getNumber() > 0) {
					if (cardArr[x][y]->getNumber() <= 0) {
						cardArr[x][y]->setNumber(cardArr[x][y1]->getNumber());
						cardArr[x][y1]->setNumber(0);

						y++;
						isdo = true;
					}
					else if (cardArr[x][y]->getNumber() == cardArr[x][y1]->getNumber()){
						cardArr[x][y]->setNumber(cardArr[x][y]->getNumber() * 2);
						cardArr[x][y1]->setNumber(0);

						isdo = true;
					}
					break;
				}
			}

		}
	}
	return isdo;
}
bool HelloWorld::doDown()
{
	bool isdo = false;
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {

			for (int y1 = y + 1; y1 < 4; y1++) {
				if (cardArr[x][y1]->getNumber() > 0) {
					if (cardArr[x][y]->getNumber() <= 0) {
						cardArr[x][y]->setNumber(cardArr[x][y1]->getNumber());
						cardArr[x][y1]->setNumber(0);

						y--;
						isdo = true;
					}
					else if (cardArr[x][y]->getNumber() == cardArr[x][y1]->getNumber()){
						cardArr[x][y]->setNumber(cardArr[x][y]->getNumber() * 2);
						cardArr[x][y1]->setNumber(0);

						isdo = true;
					}
					break;
				}
			}

		}
	}
	return isdo;
}
bool HelloWorld::doLeft()
{
	bool isdo = false;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {

			for (int x1 = x + 1; x1 < 4; x1++) {
				if (cardArr[x1][y]->getNumber() > 0) {
					if (cardArr[x][y]->getNumber() <= 0) {
						cardArr[x][y]->setNumber(cardArr[x1][y]->getNumber());
						cardArr[x1][y]->setNumber(0);

						x--;
						isdo = true;
					}
					else if (cardArr[x][y]->getNumber() == cardArr[x1][y]->getNumber()){
						cardArr[x][y]->setNumber(cardArr[x][y]->getNumber() * 2);
						cardArr[x1][y]->setNumber(0);

						isdo = true;
					}
					break;
				}
			}

		}
	}
	return isdo;
}
bool HelloWorld::doRight()
{
	bool isdo = false;
	for (int y = 0; y < 4; y++) {
		for (int x = 3; x >= 0; x--) {

			for (int x1 = x - 1; x1 >= 0; x1--) {
				if (cardArr[x1][y]->getNumber() > 0) {
					if (cardArr[x][y]->getNumber() <= 0) {
						cardArr[x][y]->setNumber(cardArr[x1][y]->getNumber());
						cardArr[x1][y]->setNumber(0);

						x++;
						isdo = true;
					}
					else if (cardArr[x][y]->getNumber() == cardArr[x1][y]->getNumber()){
						cardArr[x][y]->setNumber(cardArr[x][y]->getNumber() * 2);
						cardArr[x1][y]->setNumber(0);

						isdo = true;
					}
					break;
				}
			}

		}
	}
	return isdo;
}


//������Ƭ  
void HelloWorld::createCardSprite(cocos2d::Size size)
{
	//�����Ԫ��Ŀ�Ⱥ͸߶�  
	int unitSize = (size.height - 28) / 4;

	//4*4�ĵ�Ԫ��  
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			CardSprite* card = CardSprite::createCardSprite(CCRANDOM_0_1() * 10, unitSize, unitSize, unitSize*i + 140, unitSize*j + 20);
			this->addChild(card);
			//�ѿ�Ƭ���뵽������  
			cardArr[i][j] = card;
		}
	}

}

//�Զ����ɿ�Ƭ  
void HelloWorld::autoCreateCardNumber()
{
	int i = CCRANDOM_0_1() * 4;
	int j = CCRANDOM_0_1() * 4;

	//�ж��Ƿ����λ���Ѵ��ڿ�Ƭ  
	if (cardArr[i][j]->getNumber() > 0)
	{
		autoCreateCardNumber();
	}
	else
	{
		cardArr[i][j]->setNumber(CCRANDOM_0_1() * 10 < 1 ? 2 : 4);
	}
}