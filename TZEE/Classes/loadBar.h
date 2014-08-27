#ifndef LOAD_BAR

#include "cocos2d.h"
USING_NS_CC;

class loadBar : public cocos2d::Layer
{
public:
	virtual bool init();
	static cocos2d::Scene *createScene();
	void turnScene();
	void loadCallBack(cocos2d::Texture2D *texture);
	CREATE_FUNC(loadBar);
private:
	LabelTTF *m_pLabelLoading;
	LabelTTF *m_pLabelPercent;
	int m_nNumberOfSprite;
	int m_nNumberLoadedSprite;
	ProgressTimer* loadProgress;
};
#endif // !LOAD_BAR
