#ifndef _LINECONTAINER_H
#define _LINECONTAINER_H

#include "cocos2d.h"
using namespace cocos2d;

typedef enum lineTypes{
	LINE_TEMP,
	LINE_DASHED,
	LINE_NONE
}LineType;

class LineContainer : public CCNode{
public :
	CC_SYNTHESIZE(float, _energy, Energy);
	CC_SYNTHESIZE(CCPoint, _pivot, Pivot);
	CC_SYNTHESIZE(CCPoint, _tip, Tip);
	CC_SYNTHESIZE(float, _lineLength, LineLength);
	CC_SYNTHESIZE(LineType, _lineType, _LineType);

	LineContainer();
	static LineContainer * create();

	virtual void draw();
	void update(float dt);
	void setEnergyDecrement(float value);
	void reset(void);


private:
	float _lineAngle;
	float _energyLineX;
	float _energyHeight;
	float _energyDecrement;

	int _dash;
	int _dashSpace;
	CCSize _screensize;
};

#endif