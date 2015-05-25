// MyEllipse.cpp : 구현 파일입니다.
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
	//왼쪽, 위, 오른쪽, 아래
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



// MyEllipse 메시지 처리기입니다.


