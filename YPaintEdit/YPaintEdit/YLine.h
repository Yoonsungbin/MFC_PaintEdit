#pragma once
#include "YOneDimension.h"
class YLine :
	public YOneDimension
{
public:
	YLine();
	~YLine();
	virtual void moveAll() = 0;
	virtual void deleteAll() = 0;
	virtual void draw(CDC*) = 0;
};

