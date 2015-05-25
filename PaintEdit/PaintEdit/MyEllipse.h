#pragma once
#include "MyObject.h"

// MyEllipse

class MyEllipse : public  MyObject
{
	DECLARE_DYNAMIC(MyEllipse)

public:
	MyEllipse();
	MyEllipse(MyEllipse *);
	virtual ~MyEllipse();

	void setpoint(int left, int top, int right, int bottom);
	virtual void move(int cx, int cy);
	virtual void draw(CDC* dc);

private:
	CPoint point_End;	//³¡Á¡

protected:
	DECLARE_MESSAGE_MAP()
};


