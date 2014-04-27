#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

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
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	show = "Hello,world!";
	canpress = false;

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));

	CCMenuItemImage *StartItem = CCMenuItemImage::create(
		"start1.png",
		"start2.png",
		this,
		menu_selector(HelloWorld::menuStartCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

	StartItem->setPosition(ccp(100,
		100));


    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem,StartItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
	pLabel = CCLabelTTF::create(show, "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);
	this->setTouchEnabled(true);

	_numdisplay = CCLabelBMFont::create("0", "font.fnt", visibleSize.width * 0.5, kCCTextAlignmentLeft);
	_numdisplay->setAnchorPoint(ccp(0, 0.5));
	_numdisplay->setPosition(ccp(240, 150));
	_numdisplay->setScale(0.5);
	this->addChild(_numdisplay);
    return true;
}

void HelloWorld::ccTouchesBegan(CCSet* pTouches, CCEvent* event)
{
	CCTouch* touch = (CCTouch*)pTouches->anyObject();
	if (touch && canpress)
	{
		// start time
		//update time
		//starttime = getCurrentTime();
	}
}
void HelloWorld::ccTouchesEnded(CCSet* pTouches, CCEvent* event)
{
	CCTouch* touch = (CCTouch*)pTouches->anyObject();
	char result[100] = { 0 };
	if (touch && canpress)
	{
		//endtime
		endtime = getCurrentTime();
		sprintf(result, "%i",endtime-starttime);
		_numdisplay->setString(result);
		pLabel->setString(result);
		canpress = false;
	}
}

long HelloWorld::getCurrentTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
//如果要获得a~b之间的一个随机数，则应该是CCRANDOM_0_1*(b-a)+a，传入的参数就是a和b  
int HelloWorld::getRandomNumber(int start, int end)
{
	return CCRANDOM_0_1()*(end - start) + start;
}
void HelloWorld::menuStartCallback(CCObject* pSender)
{
	Sleep(getRandomNumber(1, 10)*1000);
	pLabel->setString("hurry up!");
	starttime = getCurrentTime();
	canpress = true;
}
