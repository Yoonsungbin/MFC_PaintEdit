#pragma once
#include "YObject.h"

// YText

class YText : public YObject
{
	DECLARE_DYNAMIC(YText)

public:
	YText();
	virtual ~YText();

	virtual void moveAll() = 0;
	virtual void delteAll() = 0;
	virtual void draw(CDC*) = 0;
protected:
	DECLARE_MESSAGE_MAP()
};


