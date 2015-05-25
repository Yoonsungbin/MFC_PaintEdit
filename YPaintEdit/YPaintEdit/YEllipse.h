#pragma once
#include "YTwoDimension.h"

// YEllipse

class YEllipse : public YTwoDimension
{
	DECLARE_DYNAMIC(YEllipse)

public:
	YEllipse();
	virtual ~YEllipse();

	virtual void moveAll() = 0;
	virtual void delteAll() = 0;
	virtual void draw(CDC*) = 0;
protected:
	DECLARE_MESSAGE_MAP()
};


