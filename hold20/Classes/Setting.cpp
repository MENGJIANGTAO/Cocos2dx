#include "Setting.h"
#include "MenuScene.h"
#include "Tools.h"
#include "global.h"
USING_NS_CC;

Scene* Setting::createScene() {
    auto scene = Scene::create();
    auto layer = Setting::create();
    scene->addChild(layer);
    return scene;
}

bool Setting::init() {
    if (!Layer::init()) {
        return false;
    }
    MenuItemFont::setFontName("American Typewriter");
    MenuItemFont::setFontSize(20);

    std::string str = "Option";
    MenuItemFont *title1 = MenuItemFont::create(str.c_str(), NULL, NULL);
    title1->setEnabled(false);

    str = "Open";
    MenuItemFont *openItem = MenuItemFont::create(str.c_str(), NULL, NULL);
    str = "Close";
    MenuItemFont *closeItem = MenuItemFont::create(str.c_str(), NULL, NULL);

    MenuItemToggle *soundItem = MenuItemToggle::createWithTarget(this, menu_selector(
            Setting::soundCallback), openItem, closeItem, NULL);
    soundItem->setSelectedIndex(g_playSound ? 0 : 1);

    str = "BulletNum";
    MenuItemFont *title2 = MenuItemFont::create(str.c_str(), NULL, NULL);
    title2->setEnabled(false);

    str = "50";
    MenuItemFont *bulletNum50Item = MenuItemFont::create(str.c_str(), NULL, NULL);
    str = "100";
    MenuItemFont *bulletNum100Item = MenuItemFont::create(str.c_str(), NULL, NULL);
    str = "150";
    MenuItemFont *bulletNum150Item = MenuItemFont::create(str.c_str(), NULL, NULL);
    MenuItemToggle *bulletNumItem = MenuItemToggle::createWithTarget(this, menu_selector(Setting::bulletNumCallback), bulletNum50Item, bulletNum100Item, bulletNum150Item, NULL);
    bulletNumItem->setSelectedIndex(g_bulletNumber / 50 - 1);
    MenuItemFont::setFontName("Marker Felt");
    MenuItemFont::setFontSize(26);

    str = "back";
    MenuItem *back = MenuItemFont::create(str.c_str(), this, menu_selector(Setting::backCallback));
    Menu *menu = Menu::create(title1, soundItem, title2, bulletNumItem, back, NULL);

    menu->alignItemsInColumns(2, 2, 1);
    addChild(menu);

    back->setScale(0.8f);
    back->setPosition(ccp(back->getPosition().x, back->getPosition().y - 20));
    return true;
}

void Setting::backCallback(cocos2d::Ref* pSender) {
    Scene *scene = MenuScene::createScene();
    Director::sharedDirector()->replaceScene(CCTransitionFlipX::create(1.2f, scene));
}

void Setting::bulletNumCallback(cocos2d::Ref* pSender) {

    g_bulletNumber+= 50;
    if(g_bulletNumber>150)
    {
        g_bulletNumber = 50;
    }
}

void Setting::soundCallback(cocos2d::Ref* pSender) {

    g_playSound = !g_playSound;
}
