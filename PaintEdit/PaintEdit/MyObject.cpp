// MyObject.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "PaintEdit.h"
#include "MyObject.h"

ULONG_PTR gdiplusToken;
// MyObject

IMPLEMENT_DYNAMIC(MyObject, CWnd)

MyObject::MyObject()
{
	thick = 1;
	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
}

MyObject::~MyObject()
{
	GdiplusShutdown(gdiplusToken);
}


void MyObject::setpoint(int left, int top, int right, int bottom){
	point_Start.x = left;
	point_Start.y = top;
}



BEGIN_MESSAGE_MAP(MyObject, CWnd)
END_MESSAGE_MAP()








// MyObject �޽��� ó�����Դϴ�.


