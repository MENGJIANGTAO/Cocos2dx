#ifndef TEXT_ALIGN

#include "cocos2d.h"
USING_NS_CC;

class textAlign : public cocos2d::Layer
{
public :
	static cocos2d::Scene *createScene();
	virtual bool init();
	CREATE_FUNC(textAlign);
};
#endif // !TEXT_ALIGN
