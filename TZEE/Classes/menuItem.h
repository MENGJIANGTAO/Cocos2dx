#ifndef MENU_ITEM

#include "cocos2d.h"
USING_NS_CC;

class menuItem : public cocos2d::Layer
{
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	void menuCallback(cocos2d::Ref *ref);

	CREATE_FUNC(menuItem);
};
#endif // !MENU_ITEM

