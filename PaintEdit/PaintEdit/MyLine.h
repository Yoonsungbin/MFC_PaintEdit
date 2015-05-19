#pragma once
#include "MyObject.h"

class MyLine :public MyObject {
public:
	MyLine();
	MyLine(MyLine *);
	virtual~MyLine();
	virtual void setpoint(int left, int top, int right, int bottom);
	virtual void move(int cx, int cy);
	virtual void draw(CDC* dc);
private:
	int line_Pattern;   //선모양
	CPoint point_End;	//끝점

};
