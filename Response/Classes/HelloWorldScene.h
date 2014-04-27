#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::CCLayer
{
public:
	long starttime;
	long endtime;
	CCLabelTTF* pLabel;
	char* show;
	bool canpress;
	CCLabelBMFont *_numdisplay;
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
	void menuStartCallback(CCObject* pSender);

	virtual int getRandomNumber(int start, int end);
	virtual void ccTouchesBegan(CCSet* pTouches,CCEvent* event);

	virtual void ccTouchesEnded(CCSet* pTouches, CCEvent* event);

	virtual long getCurrentTime();

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
