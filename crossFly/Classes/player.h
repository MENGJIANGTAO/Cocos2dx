#ifndef PLAYER

#include "cocos2d.h"
USING_NS_CC;

class player : public Sprite
{
public:
	player(Point point);
	Sprite *getPlayer();
private:
	Sprite* m_player;
};
#endif // !PLAYER
