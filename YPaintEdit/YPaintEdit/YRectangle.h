#pragma once
#include "YTwoDimension.h"

// YRectangle

class YRectangle : public YTwoDimension
{
	DECLARE_DYNAMIC(YRectangle)

public:
	YRectangle();
	virtual ~YRectangle();

	virtual void moveAll() = 0;
	virtual void delteAll() = 0;
	virtual void draw(CDC*) = 0;
protected:
	DECLARE_MESSAGE_MAP()
};


