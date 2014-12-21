#ifndef _BASE_GO_H
#define _BASE_GO_H

#include "cocos2d.h"

class BaseGo:public cocos2d::Layer 
{
public:
	virtual std::string title() const;
	virtual std::string subtitle() const;

	virtual void restartCallback(Ref* sender);
	virtual void nextCallback(Ref* sender);
	virtual void backCallback(Ref* sender);

	virtual void onEnter() override;
	virtual void onExit() override;
};
#endif