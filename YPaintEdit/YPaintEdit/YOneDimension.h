#pragma once
#include "YObject.h"
class YOneDimension :
	public YObject
{
public:
	YOneDimension();
	~YOneDimension();

	virtual void moveAll() = 0;
	virtual void deleteAll() = 0;
	virtual void draw(CDC*) = 0;
};

