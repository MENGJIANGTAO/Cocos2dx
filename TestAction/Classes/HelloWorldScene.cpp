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

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("Image/HelloWorld.png");
	//pSprite->setScale(0.5);
	//pSprite->setAnchorPoint(ccp(0, 0));
    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	//------------------------------
	//--------CCMoveTo,CCMoveBy-----
	//------------------------------
	//CCActionInterval* actionTo = CCMoveTo::create(2, ccp(0,0));
	//CCActionInterval* actionBy = CCMoveBy::create(4, ccp(80, 80));
	//pSprite->runAction(actionTo);
	//pSprite->runAction(CCMoveTo::create(1, ccp(100, 100)));
	//pSprite->runAction(CCSequence::create(actionTo, actionBy,NULL));

	//------------------------------
	//--------CCScaleTo,CCScaleBy---
	//------------------------------
	//CCActionInterval* scaleTo = CCScaleTo::create(2.0f, 0.5f,0.25f);
	//CCActionInterval* scaleBack = CCScaleTo::create(2.0f, 1.0f, 1.0f);
	//CCActionInterval* scaleBy = CCScaleBy::create(1, 1.0f,5.0f);
	//CCActionInterval* scaleBy2 = CCScaleBy::create(2, 5.0f, 1.0f);
	//pSprite->runAction(CCSequence::create(scaleTo, scaleBack, NULL));
	//pSprite->runAction(scaleTo);
	//pSprite->runAction(scaleBack);
	//pSprite->runAction(scaleBy);
	//pSprite->runAction(CCSequence::create(scaleTo, scaleTo->reverse(), NULL));

	//------------------------------
	//--------CCSkewTo,CCSkewBy-----
	//------------------------------
	//CCActionInterval* skewTo = CCSkewTo::create(2, 0, -135);
	//CCActionInterval* skewBy = CCSkewBy::create(2, -159, 0);
	//CCActionInterval* skewBy_reverse = skewBy->reverse();
	//pSprite->runAction(skewTo);
	//pSprite->runAction(skewBy);
	//pSprite->runAction(CCSequence::create(skewBy, skewBy_reverse, NULL));

	//------------------------------
	//--------CCSkewTo,CCSkewBy-----
	//------------------------------
	//CCRotateTo* rotateTo = CCRotateTo::create(2, 45.0f, -45.0f);
	//CCRotateTo* rotateTo_back = CCRotateTo::create(2, -45.0f, 45.0f);
	//CCRotateBy* rotateBy = CCRotateBy::create(2, 0.0f, 90.0f);
	//CCRotateBy* rotateBy_back = (CCRotateBy*)rotateBy->reverse();
	//pSprite->runAction(rotateTo);
	//pSprite->runAction(rotateBy);
	//pSprite->runAction(CCSequence::create(rotateTo, rotateTo_back, NULL));
	//pSprite->runAction(CCSequence::create(rotateBy, rotateBy_back, NULL));

	//------------------------------
	//--------	Skew Comparison-----
	//------------------------------
	//pSprite->removeFromParentAndCleanup(true);
	//CCSize boxSize = CCSizeMake(100.0f, 100.0f);
	//CCLayerColor* box = CCLayerColor::create(ccc4(255, 255, 0, 255));
	//box->setAnchorPoint(ccp(0.5,0.5));
	//box->setContentSize(boxSize);
	//box->ignoreAnchorPointForPosition(false);
	//box->setPosition(ccp(visibleSize.width / 2, visibleSize.height - 100 - box->getContentSize().height / 2));
	//this->addChild(box);
	//CCLabelTTF* label = CCLabelTTF::create("Standard cocos2d Skew", "Marker Felt", 16);
	//label->setPosition(ccp(visibleSize.width / 2, visibleSize.height - 100 + label->getContentSize().height));
	//this->addChild(label);
	//CCSkewBy* actionTo = CCSkewBy::create(2, 360, 0);
	//CCSkewBy* actionToBack = CCSkewBy::create(2, -360, 0);
	//box->runAction(CCSequence::create(actionTo, actionToBack, NULL));

	//------------------------------
	//--------	Rotational Skew-----
	//------------------------------
	//pSprite->removeFromParentAndCleanup(true);
	//CCSize boxSize = CCSizeMake(100.0f, 100.0f);
	//CCLayerColor* box = CCLayerColor::create(ccc4(255, 255, 0, 255));
	//box->setAnchorPoint(ccp(0.5, 0.5));
	//box->setContentSize(boxSize);
	//box->ignoreAnchorPointForPosition(false);
	//box->setPosition(ccp(visibleSize.width / 2, visibleSize.height - 100 - box->getContentSize().height / 2));
	//this->addChild(box);
	//CCLabelTTF* label = CCLabelTTF::create("Rotational cocos2d Skew", "Marker Felt", 16);
	//label->setPosition(ccp(visibleSize.width / 2, visibleSize.height - 100 + label->getContentSize().height));
	//this->addChild(label);
	//CCRotateBy* actionBy = CCRotateBy::create(2, 360, 0);
	//CCRotateBy* actionBy2 = CCRotateBy::create(2, -360, 0);
	//box->runAction(CCSequence::create(actionBy, actionBy2, NULL));


	//------------------------------
	//--------ActionSkewRotateScale-
	//------------------------------
	//CCSize boxSize = CCSizeMake(100.0f, 100.0f);

	//CCLayerColor* box = CCLayerColor::create(ccc4(255, 255, 0, 255));
	//box->setAnchorPoint(ccp(0, 0));
	//box->setPosition(ccp(190, 110));
	//box->setContentSize(boxSize);

	//static float markside = 10.0f;
	//CCLayerColor*uL = CCLayerColor::create(ccc4(255, 0, 0, 255));
	//box->addChild(uL);
	//uL->setContentSize(CCSizeMake(markside, markside));
	//uL->setPosition(ccp(0.0f, boxSize.height - markside));
	//uL->setAnchorPoint(ccp(0, 0));

	//CCLayerColor*uR = CCLayerColor::create(ccc4(0, 0, 255, 255));
	//box->addChild(uR);
	//uR->setContentSize(CCSizeMake(markside, markside));
	//uR->setPosition(ccp(boxSize.width - markside,boxSize.height-markside));
	//uR->setAnchorPoint(ccp(0, 0));
	//addChild(box);
	//
	//CCActionInterval* actionTo = CCSkewTo::create(2, 0.0f, 2.0f);
	//CCActionInterval* rotateTo = CCRotateTo::create(2, 0.0f, 15.0f);
	//CCActionInterval* actionScaleTo = CCScaleTo::create(2, 0.5f, -0.5f);
	//
	//CCActionInterval* actionScaleBack = CCScaleTo::create(2, 1.0f, 1.0f);
	//CCActionInterval* rotateToBack = CCRotateTo::create(2, 0);
	//CCActionInterval* actionToBack = CCSkewTo::create(2, 0, 0);

	//box->runAction(CCSequence::create(actionTo, actionToBack, NULL));
	//box->runAction(CCSequence::create(rotateTo, rotateToBack, NULL));
	//box->runAction(CCSequence::create(actionScaleTo, actionScaleBack, NULL));

	//------------------------------------------------------------------
	//
	//    ActionRotate
	//
	//------------------------------------------------------------------

	//CCActionInterval* actionTo = CCRotateTo::create(2, 45);
	//CCActionInterval* actionTo2 = CCRotateTo::create(2, -45);

	//CCActionInterval* actionT0 = CCRotateTo::create(2, 0);
	//pSprite->runAction(CCSequence::create(actionTo, actionT0, NULL));

	//CCActionInterval* actionBy = CCRotateBy::create(2, 360);
	//CCActionInterval* actionByBack = actionBy->reverse();
	//pSprite->runAction(CCSequence::create(actionBy, actionByBack, NULL));
	//pSprite->runAction(CCSequence::create(actionTo2, actionT0->copy()->autorelease(), NULL));
	
	
	//------------------------------------------------------------------
	//
	// ActionJump
	//
	//------------------------------------------------------------------
	//CCActionInterval* actionTo = CCJumpTo::create(2, ccp(300, 300), 50, 4);
	//CCActionInterval*  actionUp = CCJumpBy::create(2, ccp(0, 0), 80, 4);
	//pSprite->runAction(CCRepeatForever::create(CCSequence::create(actionTo,actionUp,NULL)));
	//pSprite->runAction(actionUp);

	//------------------------------------------------------------------
	//
	// ActionBezier
	//
	//------------------------------------------------------------------
	//ccBezierConfig bezier;
	//bezier.controlPoint_1 = ccp(0, visibleSize.height / 2);
	//bezier.controlPoint_2 = ccp(300, -visibleSize.height / 2);
	//bezier.endPosition = ccp(300, 100);

	//CCActionInterval* bezierForward = CCBezierBy::create(3, bezier);
	//CCActionInterval* bezierBack = bezierForward->reverse();
	//CCAction* rep = CCRepeatForever::create(CCSequence::create(bezierForward, bezierBack, NULL));

	//pSprite->runAction(rep);

	//------------------------------------------------------------------
	//
	// ActionBlink
	//
	//------------------------------------------------------------------
	//CCActionInterval* action1 = CCBlink::create(2, 10);
	//pSprite->runAction(action1);
	//CCActionInterval* action2 = CCBlink::create(2, 100);
	//pSprite->runAction(action2);
	
	
	//------------------------------------------------------------------
	//
	// ActionFade
	//
	//------------------------------------------------------------------

	//CCActionInterval* action1 = CCFadeIn::create(5.0f);
	//CCActionInterval* action1_back = action1->reverse();

	//CCActionInterval* action2 = CCFadeOut::create(1.0f);
	//CCActionInterval* action2_back = action2->reverse();

	//pSprite->runAction(action1);

	//------------------------------------------------------------------
	//
	// ActionTint
	//
	//------------------------------------------------------------------
	//CCActionInterval* action1 = CCTintTo::create(2, 255, 200, 100);
	//CCActionInterval* action2 = CCTintBy::create(2, -255, -200, -100);
	//pSprite->runAction(action2);

	
	//------------------------------------------------------------------
	//
	// ActionAnimate
	//
	//------------------------------------------------------------------

	//CCAnimation* animation = CCAnimation::create();
	//for (int i = 1; i < 15; i++)
	//{
	//	char szName[100] = { 0 };
	//	sprintf(szName, "Image/grossini_dance_%02d.png",i);
	//	animation->addSpriteFrameWithFileName(szName);
	//}
	//animation->setDelayPerUnit(2.5f / 14.0f);
	//animation->setRestoreOriginalFrame(true);
	//CCAnimate* action = CCAnimate::create(animation);
	//CCSprite* grossini = CCSprite::create("Image/grossini.png");
	//grossini->runAction(CCSequence::create(action, action->reverse(), NULL));
	//grossini->setPosition(ccp(visibleSize.width *0.5 , visibleSize.height*0.5));
	////this->addChild(grossini, 0);


	////File animation
	//CCAnimationCache* cache = CCAnimationCache::sharedAnimationCache();
	//cache->addAnimationsWithFile("animation/animations-2.plist");
	//CCAnimation* animation2 = cache->animationByName("dance_1");
	//CCAnimate* action2 = CCAnimate::create(animation2);
	//CCSprite* sister = CCSprite::create("Image/grossinis_sister1.png");
	//sister->runAction(CCSequence::create(action2, action2->reverse(), NULL));
	//sister->setPosition(ccp(visibleSize.width *0.5 - 100, visibleSize.height*0.5));
	//animation2->setLoops(4);
	//this->addChild(sister, 0);


	//------------------------------------------------------------------
	//
	// ActionSequence
	//
	//------------------------------------------------------------------

	//CCFiniteTimeAction* action = CCSequence::create(CCMoveBy::create(2, ccp(240, 0)), CCRotateBy::create(2, 540), NULL);
	//pSprite->runAction(action);

	//------------------------------------------------------------------
	//
	// ActionSequence2
	//
	//------------------------------------------------------------------
	//CCFiniteTimeAction* action = CCSequence::create(
	//CCPlace::create(ccp(200, 200)),
	//CCShow::create(),
	//CCMoveBy::create(1, ccp(100, 0)),
	//CCCallFunc::create(this, callfunc_selector(XXX:callback1))
	//);

	//------------------------------------------------------------------
	//
	// ActionSpawn
	//
	//------------------------------------------------------------------
	
	//CCAction* action = CCSpawn::create(CCJumpBy::create(2, ccp(300, 0), 50, 4), CCRotateBy::create(2, 720), NULL);
	//pSprite->setScale(0.5);
	//pSprite->runAction(action);

	//------------------------------------------------------------------
	//
	// ActionRepeatForever
	//
	//------------------------------------------------------------------
	//CCFiniteTimeAction* action = CCSequence::create(
	//CCDelayTime::create(1.5),
	//CCCallFuncN::create(this, callfuncN_selector(HelloWorld::repeatForever)),
	//NULL);
	//pSprite->runAction(action);

	//------------------------------------------------------------------
	//
	// ActionRotateToRepeat
	//
	//------------------------------------------------------------------
	//CCActionInterval* act1 = CCRotateTo::create(1, 90);
	//CCActionInterval* act2 = CCRotateTo::create(1, 0);
	//CCActionInterval* seq = CCSequence::create(act1, act2, NULL);
	//CCAction* rep1 = CCRepeatForever::create(seq);
	//CCActionInterval* rep2 = CCRepeat::create((CCFiniteTimeAction*)(seq->copy()->autorelease()), 10);
	//pSprite->runAction(rep1);
	//pSprite->runAction(rep2);


	this->addChild(pSprite, 0);
    return true;
}

void HelloWorld::repeatForever(CCNode* pSender)
{
	CCRepeatForever* repeat = CCRepeatForever::create(CCRotateBy::create(1.0f, 360));
	pSender->runAction(repeat);
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
