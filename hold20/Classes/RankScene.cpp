#include "RankScene.h"
#include "MenuScene.h"

Scene *RankScene::createScene() {
    auto scene = Scene::create();
    auto layer = RankScene::create();
    scene->addChild(layer);
    return scene;
}

bool RankScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    Size size = Director::sharedDirector()->getWinSize();
    
    std::string name = "Name";
    MenuItemFont *title1 = MenuItemFont::create(name.c_str(), NULL, NULL);
    title1->setEnabled(false);
    title1->setPosition(ccp(size.width*0.5 - 100,size.height - 50));
    addChild(title1);
    
    
    std::string score = "Score";
    MenuItemFont *title2 = MenuItemFont::create(score.c_str(), NULL, NULL);
    title2->setEnabled(false);
    title2->setPosition(ccp(size.width*0.5 + 100,size.height - 50));
    addChild(title2);
    
    
    UserDefault * temp = UserDefault::getInstance();
    const char* str = temp->getStringForKey("name").c_str();
    int scorenum = temp->getIntegerForKey("score");
    
 
    MenuItem *back = MenuItemFont::create("back", this, menu_selector(RankScene::callBack));
    Menu *menu = Menu::create(back, NULL);
    menu->setPosition(ccp(size.width-50, 50));
    addChild(menu);
    
    return true;
}

void RankScene::callBack(cocos2d::Ref* ref)
{
    Scene *scene = MenuScene::createScene();
    Director::sharedDirector()->replaceScene(CCTransitionFlipX::create(1.2f, scene));
}

