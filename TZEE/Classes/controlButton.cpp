#include "controlButton.h"

Scene *controlButton::createScene()
{
	auto scene = Scene::create();
	auto layer = controlButton::create();
	scene->addChild(layer);
	return scene;
}

bool controlButton::init()
{
	if (!Layer::init())
	{
		return false;
	}

	size = Director::sharedDirector()->getWinSize();

	label = LabelTTF::create("No event", "Marker Felt", 25);
	label->setPosition(ccp(size.width / 2, size.height*0.8));
	addChild(label);

	Scale9Sprite *backgroundButton = Scale9Sprite::create("button/button_p.png");
	Scale9Sprite *backgroundHighlightedButton = Scale9Sprite::create("button/buttonHighlighted.png");

	LabelTTF *titleButton = LabelTTF::create("Touch me", "Marker Felt", 30);

	ControlButton *button = ControlButton::create(titleButton, backgroundButton);
	button->setPosition(ccp(size.width / 2, size.height / 2));
	button->setPreferredSize(Size(200,100));
	button->setBackgroundSpriteForState(backgroundHighlightedButton, Control::State::HIGH_LIGHTED);
	addChild(button);

	// Sets up event handlers
	button->addTargetWithActionForControlEvents(this, cccontrol_selector(controlButton::touchDownAction), Control::EventType::TOUCH_DOWN);
	button->addTargetWithActionForControlEvents(this, cccontrol_selector(controlButton::touchDragInsideAction), Control::EventType::DRAG_INSIDE);
	button->addTargetWithActionForControlEvents(this, cccontrol_selector(controlButton::touchDragOutsideAction), Control::EventType::DRAG_OUTSIDE);
	button->addTargetWithActionForControlEvents(this, cccontrol_selector(controlButton::touchDragEnterAction), Control::EventType::DRAG_ENTER);
	button->addTargetWithActionForControlEvents(this, cccontrol_selector(controlButton::touchDragExitAction), Control::EventType::DRAG_EXIT);
	button->addTargetWithActionForControlEvents(this, cccontrol_selector(controlButton::touchUpInsideAction), Control::EventType::TOUCH_UP_INSIDE);
	button->addTargetWithActionForControlEvents(this, cccontrol_selector(controlButton::touchUpOutsideAction), Control::EventType::TOUCH_UP_OUTSIDE);
	button->addTargetWithActionForControlEvents(this, cccontrol_selector(controlButton::touchCancelAction), Control::EventType::TOUCH_CANCEL);

	ControlButton *btn1 = ControlButton::create("click", "Consolas", 24);
	btn1->setPosition(ccp(size.width*0.1, size.height / 2));
	addChild(btn1);
	btn1->setTitleForState("clicked", Control::State::NORMAL);


	ControlButton *btn2 = ControlButton::create(Scale9Sprite::create("button/button_n.png"));
	btn2->setPreferredSize(Size(100, 50));
	btn2->setPosition(ccp(size.width*0.9, size.height / 2));
	addChild(btn2);

	return true;
}

void controlButton::touchDownAction(Ref *sender, Control::EventType controlEvent)
{
	label->setString("touch down");
}
void controlButton::touchDragInsideAction(Ref *sender, Control::EventType controlEvent)
{
	label->setString("touch Drag inside");
}
void controlButton::touchDragOutsideAction(Ref *sender, Control::EventType controlEvent)
{
	label->setString("touch drag outside");
}
void controlButton::touchDragEnterAction(Ref *sender, Control::EventType controlEvent)
{
	label->setString("touch drag enter");
}
void controlButton::touchDragExitAction(Ref *sender, Control::EventType controlEvent)
{
	label->setString("touch drag exit");
}
void controlButton::touchUpInsideAction(Ref *sender, Control::EventType controlEvent)
{
	label->setString("touch up inside");
}
void controlButton::touchUpOutsideAction(Ref *sender, Control::EventType controlEvent)
{
	label->setString("touch down");
}
void controlButton::touchCancelAction(Ref *sender, Control::EventType controlEvent)
{
	label->setString("touch cancel");
}
void controlButton::touchBitmaskAction(Ref *sender, Control::EventType controlEvent)
{
	label->setString("touch bit mask action");
}