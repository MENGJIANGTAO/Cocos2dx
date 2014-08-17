/* 
 * File:   InputDialog.h
 * Author: mengjiangtao
 *
 * Created on August 17, 2014, 12:23 PM
 */

#ifndef INPUTDIALOG_H
#define	INPUTDIALOG_H
#include "cocos2d.h"
#include "GameScene.h";
USING_NS_CC;


class InputDialog : public cocos2d::Layer,public cocos2d::TextFieldDelegate
{
public:
    static  cocos2d::Scene *createScene();
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    
    // TextFieldDelegate

    virtual bool onTextFieldAttachWithIME(TextFieldTTF* sender);
    virtual bool onTextFieldDetachWithIME(TextFieldTTF* sender);
    virtual bool onTextFieldInsertText(TextFieldTTF* sender, const char* text, size_t nLen);
    
    void callBack(cocos2d::Ref *pSender);
    CREATE_FUNC(InputDialog);
private:
    int strNum = 0;
    Size size;
    TextFieldTTF *text;
};

#endif	/* INPUTDIALOG_H */

