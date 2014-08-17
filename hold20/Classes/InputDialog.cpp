#include "InputDialog.h"
#include "global.h"

Scene* InputDialog::createScene()
{
    auto scene = Scene::create();
    auto layer = InputDialog::create();
    layer->setColor(Color3B(100,0,0));
    layer->setContentSize(Size(100.0f,100.0f));
    scene->addChild(layer);
    return scene;
}

bool InputDialog::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    size = Director::sharedDirector()->getWinSize();
    text = TextFieldTTF::textFieldWithPlaceHolder("input your name:","",30);
    text->setPosition(ccp(size.width*0.5,size.height*0.5));
    addChild(text);
    text->setDelegate(this);
    text->attachWithIME();
    MenuItem *ok = MenuItemFont::create("OK",this,menu_selector(InputDialog::callBack));

    Menu *menu = Menu::create(ok,NULL);
    menu->setPosition(ccp(size.width*0.5,size.height*0.4));
    addChild(menu);
    return true;
}

void InputDialog::onEnter()
{
    Layer::onEnter();
    this->setSwallowsTouches(true);
}

void InputDialog::onExit()
{
    Layer::onExit();
}

bool InputDialog::onTextFieldAttachWithIME(TextFieldTTF* sender)
{
    this->setPosition(ccp(0,200));
    return false;
}

bool InputDialog::onTextFieldDetachWithIME(TextFieldTTF* sender)
{
    this->setPosition(ccp(0,0));
    return false;
}

bool InputDialog::onTextFieldInsertText(TextFieldTTF* sender, const char* text, size_t nLen)
{
    strNum+=nLen;
    if(strNum>5)
    {
        return true;
    }
    return false;
}

void InputDialog::callBack(cocos2d::Ref* pSender) {
    log("Name:%s", text->getString().c_str());
    UserDefault * temp = UserDefault::getInstance();
    temp->setStringForKey("name", text->getString());
    Scene *gameScene = GameScene::createScene();
    Director::sharedDirector()->replaceScene(CCTransitionFadeUp::create(1.5f, gameScene));
}


