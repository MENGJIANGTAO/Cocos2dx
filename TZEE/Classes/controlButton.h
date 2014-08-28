#ifndef CONTROL_BUTTON

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC_EXT;
USING_NS_CC;

class controlButton : public cocos2d::Layer
{
public:
	virtual bool init();
	static cocos2d::Scene *createScene();
	void touchDownAction(Ref *sender, Control::EventType controlEvent);
	void touchDragInsideAction(Ref *sender, Control::EventType controlEvent);
	void touchDragOutsideAction(Ref *sender, Control::EventType controlEvent);
	void touchDragEnterAction(Ref *sender, Control::EventType controlEvent);
	void touchDragExitAction(Ref *sender, Control::EventType controlEvent);
	void touchUpInsideAction(Ref *sender, Control::EventType controlEvent);
	void touchUpOutsideAction(Ref *sender, Control::EventType controlEvent);
	void touchCancelAction(Ref *sender, Control::EventType controlEvent);
	void touchBitmaskAction(Ref *sender, Control::EventType controlEvent);

private:
	Size size;
	LabelTTF *label;
	CREATE_FUNC(controlButton);
};
#endif // !CONTROL_BUTTON
