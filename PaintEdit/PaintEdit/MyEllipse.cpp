// MyEllipse.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "PaintEdit.h"
#include "MyEllipse.h"
#include "MyObject.h"
#include "MyRectangle.h"


// MyEllipse

IMPLEMENT_DYNAMIC(MyEllipse, CWnd)

MyEllipse::MyEllipse()
{
 

}


MyEllipse::MyEllipse(MyEllipse *){

}

MyEllipse::~MyEllipse()
{
}

void MyEllipse::setpoint(int left, int top, int right, int bottom)
{
	//MyObject::setpoint( left,  top,  right,  bottom);
	//����, ��, ������, �Ʒ�
	point_Start.x = left;
	point_Start.y = top;
}

void MyEllipse::move(int cx, int cy)
{
	point_End.x = cx;
	point_End.y = cy;

}



void MyEllipse::draw(CDC* pDC)
{
	
}


BEGIN_MESSAGE_MAP(MyEllipse, CWnd)
END_MESSAGE_MAP()



// MyEllipse �޽��� ó�����Դϴ�.


