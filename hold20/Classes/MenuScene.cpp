#include "MenuScene.h"
#include "GameScene.h"
#include "Setting.h"
#include "InputDialog.h"
#include "RankScene.h"
USING_NS_CC;

Scene* MenuScene::createScene() {
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool MenuScene::init() {
    if (!Layer::init()) {
        return false;
    }
    size = Director::sharedDirector()->getWinSize();

    // add title
    std::string titleStr = "Man with 20s";
    LabelTTF* plabel = LabelTTF::create(titleStr.c_str(), "Thonburi", 30);
    plabel->setPosition(ccp(size.width / 2, size.height * 0.8f));
    this->addChild(plabel, 1);

    // add background
    Sprite* background = Sprite::create("background.png");
    background->setPosition(ccp(size.width / 2, size.height / 2));
    this->addChild(background, 0);

    // add button
    MenuItemFont::setFontName("Thonburi");
    MenuItemFont::setFontSize(25);

    std::string menuItemStr = "New Game";
    MenuItem *newGame = MenuItemFont::create(menuItemStr.c_str(), this, menu_selector(MenuScene::menuNewCallback));

    menuItemStr = "Game Option";
    MenuItem *optionGame = MenuItemFont::create(menuItemStr.c_str(), this, menu_selector(MenuScene::menuOptionCallback));

    menuItemStr = "Score Rank";
    MenuItem *rankOption = MenuItemFont::create(menuItemStr.c_str(), this, menu_selector(MenuScene::menuScoreCallback));
    
    menuItemStr = "Game Quit";
    MenuItem *quitGame = MenuItemFont::create(menuItemStr.c_str(), this, menu_selector(MenuScene::menuQuitCallback));

    // add menu
    Menu *menu = Menu::create(newGame, optionGame, rankOption, quitGame, NULL);
    menu->alignItemsVertically();
    menu->alignItemsVerticallyWithPadding(30.5f);
    this->addChild(menu, 1);

    return true;
}

void MenuScene::menuNewCallback(cocos2d::Ref* pSender) {
    UserDefault * temp = UserDefault::getInstance();
    log("xmlpath:%s", temp->getXMLFilePath().c_str());
    const char* str = temp->getStringForKey("name").c_str();
    log("name:%s", str);
    
    if (strcmp(str, "") == 0) {
        Scene *input = InputDialog::createScene();
        Director::sharedDirector()->replaceScene(CCTransitionFadeUp::create(1.5f, input));
    } else {
        log("Have name.");
        Scene *gameScene = GameScene::createScene();
        Director::sharedDirector()->replaceScene(CCTransitionFadeUp::create(1.5f, gameScene));
    }
}

void MenuScene::menuOptionCallback(cocos2d::Ref* pSender) {
    Scene *optionScene = Setting::createScene();
    Director::sharedDirector()->replaceScene(CCTransitionFadeUp::create(1.5f, optionScene));
}

void MenuScene::menuScoreCallback(cocos2d::Ref* pSender) {
    Scene *scene = RankScene::createScene();
    Director::sharedDirector()->replaceScene(CCTransitionFlipX::create(1.2f, scene));
}

void MenuScene::menuQuitCallback(cocos2d::Ref* pSender) {
    Director::sharedDirector()->end();
}