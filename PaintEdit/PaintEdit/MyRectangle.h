#pragma once


// MyRectangle
#include "MyObject.h"

class MyRectangle : public MyObject
{
	DECLARE_DYNAMIC(MyRectangle)

public:
	MyRectangle();
	virtual ~MyRectangle();


protected:
	DECLARE_MESSAGE_MAP()
};


