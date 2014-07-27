#ifndef FILEUNIT_H
#define FILEUNIT_H

#include "cocos2d.h"
USING_NS_CC;

class fileUnit : public cocos2d::Layer
{
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	void createFile();
	void readFile();
private :
	Size visibleSize;


	CREATE_FUNC(fileUnit);
};
#endif