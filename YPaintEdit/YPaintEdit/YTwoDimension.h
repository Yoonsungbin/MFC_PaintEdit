#pragma once
#include "YObject.h"
class YTwoDimension :
	public YObject
{
public:
	YTwoDimension();
	~YTwoDimension();

	virtual void moveAll() = 0;
	virtual void deleteAll() = 0;
	virtual void draw(CDC*) = 0;
};

