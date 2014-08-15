#include "GameOver.h"
#include "MenuScene.h"
#include "global.h"
#include "Tools.h"
using namespace CocosDenshion;
USING_NS_CC;

Scene* GameOver::createScene()
{
    auto scene = Scene::create();
    auto layer = GameOver::create();
    scene->addChild(layer);
    return scene;
}

bool GameOver::init()
{
    if(!Layer::init())
    {
        return false;
    }
    Size size = Director::sharedDirector()->getWinSize();
    std::string titleStr = "GameOver";
    
    LabelTTF *pLabel = LabelTTF::create(titleStr.c_str(),"Thonburi",30);
    pLabel->setPosition(ccp(size.width/2,size.height*0.9));
    addChild(pLabel,1);
    
    std::string keepTime="Time:";
    std::string second = "Second:";
    
    char szBuf[128];
    memset(szBuf,0,sizeof(szBuf));
    sprintf(szBuf,"%d",(int)g_gameTime);
    std::string titleStr3 = keepTime + szBuf + second;
    
    LabelTTF *pLabel3 = LabelTTF::create(titleStr3.c_str(),"Thonburi",30);
    pLabel3->setPosition(ccp(size.width/2,size.height*0.7f));
    addChild(pLabel3,1);
    
    std::string yourAppraise="Appraise";
    LabelTTF *pLabel4 = LabelTTF::create(yourAppraise.c_str(),"Thonburi",30);
    pLabel4->setPosition(ccp(size.width/2,size.height*0.5f));
    addChild(pLabel4,1);
    
    std::string appraise=convertAppraise();
    LabelTTF *pLabel5 = LabelTTF::create(appraise.c_str(),"Thonburi",30);
    pLabel5->setPosition(ccp(size.width/2,size.height*0.3f));
    addChild(pLabel5,1);
    
    std::string titleStr2 = "Touch to continue.";
    LabelTTF *pLabel2 = LabelTTF::create(titleStr2.c_str(),"Thonburi",30);
    pLabel2->setPosition(ccp(size.width / 2, size.height*0.1f));
    addChild(pLabel2, 1);
    
    return true;
}
void GameOver::onEnter()
{
    Layer::onEnter();
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameOver::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
void GameOver::onExit()
{
    Layer::onExit();
}
std::string GameOver::convertAppraise()
{
    std::string appraise = "Appraise.";
    
    return appraise;
}
bool GameOver::onTouchBegan(Touch *touch,Event *event)
{
    SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
    Scene *scene = MenuScene::createScene();
    Director::sharedDirector()->replaceScene(CCTransitionFadeUp::create(1.5f,scene));
}