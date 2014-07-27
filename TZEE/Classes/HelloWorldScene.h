#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cardSprite.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
	virtual bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event *unused_event);
	virtual void onTouchEnded(cocos2d::Touch * touch, cocos2d::Event *unused_event);

	bool doUp();
	bool doDown();
	bool doLeft();
	bool doRight();

	//������Ƭ  
	void createCardSprite(cocos2d::Size size);
	//�Զ����ɿ�Ƭ  
	void autoCreateCardNumber();
    CREATE_FUNC(HelloWorld);
private:
	int firstX, firstY, endX, endY;
	//����һ����Ƭ��λ����  
	CardSprite* cardArr[4][4];
};

#endif // __HELLOWORLD_SCENE_H__
