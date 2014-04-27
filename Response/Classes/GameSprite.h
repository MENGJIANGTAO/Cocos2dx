#ifndef _GAMESPRITE_H
#define _GAMESPRITE_H

#include "cocos2d.h"

USING_NS_CC;

class GameSprite : public CCSprite{


public:
	CC_SYNTHESIZE(float, _radius, Radius);
	static GameSprite* createWithFrameName(const char* pszSpriteFrameName);
};
#endif