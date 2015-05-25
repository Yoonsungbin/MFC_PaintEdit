#pragma once
#include "YObject.h"

// YOneDimension

class YOneDimension : public YObject
{
	DECLARE_DYNAMIC(YOneDimension)

public:
	YOneDimension();
	virtual ~YOneDimension();

	virtual void moveAll() = 0;
	virtual void delteAll() = 0;
	virtual void draw(CDC*) = 0;
protected:
	DECLARE_MESSAGE_MAP()
};


