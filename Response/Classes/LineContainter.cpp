#include "LineContainer.h"

using namespace cocos2d;

LineContainer::LineContainer(){
	_dash = 10;
	_dashSpace = 10;
	_lineType = LINE_NONE;
	_screensize = CCDirector::sharedDirector()->getWinSize();
	_energyLineX = _screensize.width * 0.96f;
	_energyHeight = _screensize.height * 0.8f;

	glLineWidth(8.0 * CC_CONTENT_SCALE_FACTOR());
	this->reset();
}

LineContainer * LineContainer::create(){
	LineContainer* node = new LineContainer(); 
	if (node){
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
}

void LineContainer::reset(){
	_energy = 1.0;
	_energyDecrement = 0.015f;
}

void LineContainer::update(float dt){
	_energy -= dt * _energyDecrement;
	if (_energy < 0) _energy = 0;
}

void LineContainer::setEnergyDecrement(float value){
	_energyDecrement += value;
}

void LineContainer::draw(){
	switch (_lineType){
	case LINE_NONE:
			break;
		case LINE_TEMP:
			ccDrawColor4F(1.0, 1.0, 1.0, 1.0);
			ccDrawLine(_tip,_pivot);
			ccDrawCircle(_pivot, 10, CC_DEGREES_TO_RADIANS(360), 10, false);
			break;
		case LINE_DASHED:
			ccDrawColor4F(1.0, 1.0, 1.0, 1.0);
			ccDrawCircle(_pivot, 10, M_PI, 10, false);

			int segments = _lineLength / (_dash + _dashSpace);

			float t = 0.0f;
			float x_;
			float y_;
			for (int i = 0; i < segments + 1; i++){
				x_ = _pivot.x + t*(_tip.x - _pivot.x);
				y_ = _pivot.y + t *(_tip.y - _pivot.y);
				ccDrawCircle(ccp(x_, y_), 4, M_PI, 6, false);
				t += (float)1 / segments;
			}
			break;
	}
	ccDrawColor4F(0.0, 0.0, 0.0, 1.0);
	ccDrawLine(ccp(_energyLineX, _screensize.height * 0.1f), ccp(_energyLineX, _screensize.height * 0.9f));

	ccDrawColor4F(1.0, 0.5, 0.0, 1.0);
	ccDrawLine(ccp(_energyLineX, _screensize.height * 0.1f), ccp(_energyLineX, _screensize.height*0.1f + _energy * _energyHeight));
}