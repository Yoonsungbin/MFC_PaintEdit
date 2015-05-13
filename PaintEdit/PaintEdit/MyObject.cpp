// MyObject.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PaintEdit.h"
#include "MyObject.h"


// MyObject

IMPLEMENT_DYNAMIC(MyObject, CWnd)

MyObject::MyObject()
{
	thick = 3;
}

MyObject::~MyObject()
{
}

void MyObject::move(int cx,int cy){
	point_start.x += cx;
	point_start.y += cy;
}


void MyObject::setpoint(int left, int top, int right, int bottom){
	point_start.x = left;
	point_start.y = top;
}

MyLine::MyLine() {

}
MyLine::~MyLine() {

}
void MyLine::setpoint(int left, int top, int right, int bottom){
	MyObject::setpoint();
	point_end.x = right;
	point_end.y = bottom;
}

void MyLine::move(int cx, int cy){
	point_start.x += cx;
	point_start.y += cy;
	point_end.x += cx;
	point_end.y += cy;
}
void MyLine::draw(CDC* pDC){  
	CClientDC dc(this);
	CPen pen(PS_SOLID, thick, RGB(255, 0, 0));
	pDC->SelectObject(&pen);
	pDC->MoveTo(point_start);
	pDC->LineTo(point_end);

}


BEGIN_MESSAGE_MAP(MyObject, CWnd)
END_MESSAGE_MAP()








// MyObject 메시지 처리기입니다.


