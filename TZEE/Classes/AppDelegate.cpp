#include "AppDelegate.h"
//#include "HelloWorldScene.h"
//#include "TestFont.h"
//#include "TestSprite9.h"
//#include "TestDataStruct.h"
//#include "ActionTest.h"
//#include "animation.h"
//#include "easeAction.h"
//#include "skillCd.h"
//#include "changeScen.h"
//#include "myfont.h"
//#include "screenShoot.h"
//#include "soundPlay.h"
//#include "touchTest.h"
//#include "boundTest.h"
//#include "fileUnit.h"
//#include "particleTest.h"
//#include "clickTest.h"
//#include "gestureRecognition.h"
//#include "textAlign.h"
//#include "menuItem.h"
//#include "schedulePopLayer.h"
//#include "progressTest.h"
#include "loadBar.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
		//glview->setFrameSize(800, 800);
        director->setOpenGLView(glview);
    }
	//glview->setDesignResolutionSize(640, 320, kResolutionExactFit);
	//glview->setDesignResolutionSize(640, 320, kResolutionNoBorder);
	//glview->setDesignResolutionSize(640, 320, kResolutionFixedWidth);
	//glview->setDesignResolutionSize(640, 320, kResolutionFixedHeight);
	//glview->setDesignResolutionSize(640, 320, kResolutionUnKnown);
	//glview->setDesignResolutionSize(640, 320, kResolutionShowAll);

	//Size frameSize = glview->getFrameSize();

	//Size winSize = Size(640,320);

	//float widthRate = frameSize.width / winSize.width;
	//float heightRate = frameSize.height / winSize.height;

	//if (widthRate > heightRate)
	//{
	//	float height = winSize.height*heightRate / widthRate;
	//	glview->setDesignResolutionSize(winSize.width, height, kResolutionShowAll);
	//}
	//else
	//{
	//	float width = winSize.width*widthRate / heightRate;
	//	glview->setDesignResolutionSize(width, winSize.height, kResolutionShowAll);
	//}

    // turn on display FPS
    //director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    //director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    //auto scene = HelloWorld::createScene();
	//auto scene = TestFont::createScene();
	//auto scene = TestSprite9::createScene();
	//auto scene = TestDataStruct::createScene();
	//auto scene = animation::createScene();
	//auto scene = easeAction::createScene();
	//auto scene = skillCd::createScene();
	//auto scene = changeScen::createScene();
	//auto scene = myfont::createScene();
	//auto scene = screenShoot::createScene();
	//auto scene = soundPlay::createScene();
	//auto scene = touchTest::createScene();
	//auto scene = boundTest::createScene();
	//auto scene = fileUnit::createScene();
	//auto scene = particleTest::createScene();
	//auto scene = clickTest::createScene();
	//auto scene = gestureRecognition::createScene();
	//auto scene = textAlign::createScene();
	//auto scene = menuItem::createScene();
	//auto scene = schedulePopLayer::createScene();
	//auto scene = progressTest::createScene();
	auto scene = loadBar::createScene();
	director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
