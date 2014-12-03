#include "player.h"


player::player(Point point)
{
	m_player = Sprite::create("player.png");
	m_player->setAnchorPoint(ccp(0, 0));
	m_player->setPosition(point);
}

Sprite *player::getPlayer()
{
	if (m_player != nullptr)
	{
		return m_player;
	}
}