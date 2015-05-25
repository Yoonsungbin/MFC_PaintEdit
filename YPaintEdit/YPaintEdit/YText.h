#pragma once
#include "YObject.h"
class YText :
	public YObject
{
public:
	YText();
	~YText();

	virtual void moveAll() = 0;
	virtual void deleteAll() = 0;
	virtual void draw(CDC*) = 0;
};

