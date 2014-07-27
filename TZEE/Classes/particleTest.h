#ifndef PARTICLE_TEST_H
#define PARTICLE_TEST_H

#include "cocos2d.h"
USING_NS_CC;

class particleTest : public cocos2d::Layer
{
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	void callback();
	

	ParticleSystem *boom;
	//ParticleSystem *boom1;
	CREATE_FUNC(particleTest);
};
#endif