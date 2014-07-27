#ifndef LOADINGSCENE_H
#define LOADINGSCENE_H

#include "cocos2d.h"
USING_NS_CC;

class LoadScene : public cocos2d::Layer
{

public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	//void loadOver(float dt);
	void loadOver(Object *pSender);

private:
	LabelTTF *loadText;
	LabelTTF *loadPercent;
	ProgressTimer *progress;
	ProgressTo * progressTo;
	int loadNum;
	int load;

	CREATE_FUNC(LoadScene);
};

#endif