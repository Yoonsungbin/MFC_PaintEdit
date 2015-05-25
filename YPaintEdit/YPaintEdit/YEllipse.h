#pragma once
#include "YTwoDimension.h"
class YEllipse :
	public YTwoDimension
{
public:
	YEllipse();
	~YEllipse();

	virtual void moveAll() = 0;
	virtual void deleteAll() = 0;
	virtual void draw(CDC*) = 0;
};

