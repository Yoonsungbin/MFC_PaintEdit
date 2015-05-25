#pragma once
#include "MyObject.h"

class MyLine :public MyObject {
public:
	MyLine();
	MyLine(MyLine *);
	virtual~MyLine();
	void setpoint(int left, int top, int right, int bottom);
	virtual void move(int cx, int cy);
	virtual void draw(CDC* dc);
private:
	int line_Pattern;   //�����
	CPoint point_End;	//����

};
