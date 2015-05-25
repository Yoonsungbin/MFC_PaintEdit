#pragma once
#include "YTwoDimension.h"
class YRectangle :
	public YTwoDimension
{
public:
	YRectangle();
	~YRectangle();

	virtual void moveAll() = 0;
	virtual void deleteAll() = 0;
	virtual void draw(CDC*) = 0;
};

