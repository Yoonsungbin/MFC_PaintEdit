#pragma once
#include "MyObject.h"

class MyPolyLine :public MyObject {

public:
	MyPolyLine();
	MyPolyLine(MyPolyLine *);
	virtual~MyPolyLine();
	virtual void setpoint(int left, int top, int right, int bottom);
	virtual void move(int cx, int cy);
	virtual void draw(CDC* dc);
private:
	CList<CPoint, CPoint&> points;
	int polyLine_Pattern;   //선모양
	CPoint point_End;	//끝점
};
