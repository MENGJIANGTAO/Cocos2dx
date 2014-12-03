#ifndef MYSCENE

#include "cocos2d.h"
#include "player.h"
USING_NS_CC;

class myScene : public cocos2d::Layer
{
public:
	static Scene *createScene();
	virtual bool init();
	void menuCallLeft(Ref* pSender);
	void menuCallRight(Ref* pSender);
	void updateGame(float dt);
	bool onContactBegin(PhysicsContact &contace);
	void setPhyWorld(PhysicsWorld *world){ m_world = world; }
	CREATE_FUNC(myScene);
private:
	player *players;
	Sprite *s_player;
	Size visibleSize;
	LabelTTF *scorePanel;
	LabelTTF *score;
	Vector<Sprite*> enemys;
	MenuItemSprite *left;
	MenuItemSprite *right;

	int count;
	PhysicsWorld *m_world;
};
#endif // !MYSCENE
