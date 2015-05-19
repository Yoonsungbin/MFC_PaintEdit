#include "stdafx.h"
#include "MyPolyLine.h"


MyPolyLine::MyPolyLine()
{
}

MyPolyLine::MyPolyLine(MyPolyLine *)
{
}


MyPolyLine::~MyPolyLine()
{
}


void MyPolyLine::setpoint(int left, int top, int right, int bottom){
	//MyObject::setpoint( left,  top,  right,  bottom);
	point_Start.x = left;
	point_Start.y = top;
	point_End.x = right;
	point_End.y = bottom;
}

void MyPolyLine::move(int cx, int cy){
	point_Start.x += cx;
	point_Start.y += cy;
	point_End.x += cx;
	point_End.y += cy;
}
void MyPolyLine::draw(CDC* pDC)
{

	CPen pen(PS_SOLID, thick, color);
	CPen* oldPen = pDC->SelectObject(&pen);

	Graphics graphics(*pDC);
	/*
	GDI+ 사용법
	Pen pen1(Color(0, 0, 255),5);  // 불투명 (255), 검정색(0,0,0)
	pen1.SetDashStyle(DashStyleSolid);
	pen1.SetStartCap(LineCapRound);
	pen1.SetEndCap(LineCapAnchorMask);
	graphics.DrawLine(&pen1, point_Start.x, point_Start.y, point_End.x, point_End.y);
	*/

	pDC->MoveTo(point_Start);
	pDC->LineTo(point_End);
	pDC->SelectObject(&oldPen);

}
