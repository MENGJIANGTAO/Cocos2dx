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
    name_x = size.width*0.5 - 100;
    name_y = size.height - 50;
    
    score_x = size.width*0.5 + 100;
    score_y = name_y;
    std::string name = "Name";
    MenuItemFont *title1 = MenuItemFont::create(name.c_str(), NULL, NULL);
    title1->setEnabled(false);
    title1->setPosition(ccp(name_x,name_y));
    addChild(title1);
    
    
    std::string score = "Score";
    MenuItemFont *title2 = MenuItemFont::create(score.c_str(), NULL, NULL);
    title2->setEnabled(false);
    title2->setPosition(ccp(score_x,score_y));
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

void RankScene::onEnter()
{
    Layer::onEnter();
    UserDefault * temp = UserDefault::getInstance();
    std::string str = temp->getStringForKey("name");
    int score = temp->getIntegerForKey("score");
    
    char szBuf[128];
    memset(szBuf, 0, sizeof (szBuf));
    sprintf(szBuf, "%d", (int) score);
    std::string temp_num = str+ "&" +szBuf;
    log("log:%s",temp_num.c_str());
    num.push_back(temp_num);
    

    const char charac = '&';
    int point = num.at(0).find(charac,0);
    log("Point:%d",point);
    std::string name = (std::string)num.at(0).substr(0,point);
    log("name:%s",name.c_str());
    std::string score1 = num.at(0).substr(point + 1,strlen(temp_num.c_str())-(point+1));
    
    MenuItemFont *true_name = MenuItemFont::create(name.c_str(), NULL, NULL);
    true_name->setPosition(ccp(name_x,name_y - 40));
    addChild(true_name);
    
    MenuItemFont *true_score = MenuItemFont::create(score1.c_str(), NULL, NULL);
    true_score->setPosition(ccp(score_x,score_y - 40));
    addChild(true_score);
}

void RankScene::onExit()
{
    Layer::onExit();
}

void RankScene::callBack(cocos2d::Ref* ref)
{
    Scene *scene = MenuScene::createScene();
    Director::sharedDirector()->replaceScene(CCTransitionFlipX::create(1.2f, scene));
}

