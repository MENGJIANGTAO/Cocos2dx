#include "MenuScene.h"
#include "GameScene.h"
USING_NS_CC;

Scene* MenuScene::createScene()
{
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool MenuScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    Size size = Director::sharedDirector()->getWinSize();
    
    // add title
    std::string titleStr = "Man with 20s";
    LabelTTF* plabel = LabelTTF::create(titleStr.c_str(),"Thonburi",30);
    plabel->setPosition(ccp(size.width/2,size.height*0.8f));
    this->addChild(plabel,1);
    
    // add background
    Sprite* background = Sprite::create("background.png");
    background->setPosition(ccp(size.width/2,size.height/2));
    this->addChild(background,0);
    
    // add button
    MenuItemFont::setFontName("Thonburi");
    MenuItemFont::setFontSize(25);
    
    std::string menuItemStr = "New Game";
    MenuItem *newGame = MenuItemFont::create(menuItemStr.c_str(),this,menu_selector(MenuScene::menuNewCallback));
    
    menuItemStr = "Game Option";
    MenuItem *optionGame = MenuItemFont::create(menuItemStr.c_str(),this,menu_selector(MenuScene::menuOptionCallback));
    
    menuItemStr = "Game Quit";
    MenuItem *quitGame = MenuItemFont::create(menuItemStr.c_str(),this,menu_selector(MenuScene::menuQuitCallback));
    
    // add menu
    Menu *menu = Menu::create(newGame,optionGame,quitGame,NULL);
    menu->alignItemsVertically();
    menu->alignItemsVerticallyWithPadding(30.5f);
    this->addChild(menu,1); 
    return true;
}

void MenuScene::menuNewCallback(cocos2d::Ref* pSender)
{
    Scene *gameScene = GameScene::createScene();
    Director::sharedDirector()->replaceScene(CCTransitionCrossFade::create(1.5f,gameScene));
}

void MenuScene::menuOptionCallback(cocos2d::Ref* pSender)
{
    
}

void MenuScene::menuQuitCallback(cocos2d::Ref* pSender)
{
    Director::sharedDirector()->end();
}