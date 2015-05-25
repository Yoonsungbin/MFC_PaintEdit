#pragma once
#include "YOneDimension.h"

// YPolyLine

class YPolyLine : public YOneDimension
{
	DECLARE_DYNAMIC(YPolyLine)

public:
	YPolyLine();
	virtual ~YPolyLine();

	virtual void moveAll() = 0;
	virtual void delteAll() = 0;
	virtual void draw(CDC*) = 0;
protected:
	DECLARE_MESSAGE_MAP()
};


