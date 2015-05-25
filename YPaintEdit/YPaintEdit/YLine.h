#pragma once
#include "YOneDimension.h"

// YLine

class YLine : public YOneDimension
{
	DECLARE_DYNAMIC(YLine)

public:
	YLine();
	virtual ~YLine();

	virtual void moveAll() = 0;
	virtual void delteAll() = 0;
	virtual void draw(CDC*) = 0;
protected:
	DECLARE_MESSAGE_MAP()
};


