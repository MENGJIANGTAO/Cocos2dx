#ifndef SOUNDPLAY_H
#define SOUNDPLAY_H

#include "cocos2d.h"
USING_NS_CC;

class soundPlay : public cocos2d::Layer
{
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	void menuCallBack(Ref *pSender);
	void showScreenShoot();

	CREATE_FUNC(soundPlay);
private:
	Size visibleSize;
	bool isPlay = false;
};
#endif