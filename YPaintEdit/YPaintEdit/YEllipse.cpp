#include "stdafx.h"
#include "YEllipse.h"


YEllipse::YEllipse()
{
}


YEllipse::~YEllipse()
{
}



YEllipse::YEllipse(CPoint start, CPoint end)
{
	sPoint = start;
	ePoint = end;
}

void YEllipse::moveAll(int s, int e)
{
	sPoint.x += s;
	sPoint.y += e;
	ePoint.x += s;
	ePoint.y += e;
}


void YEllipse::deleteAll(){
}


void YEllipse::draw(CDC* pDC)
{
	//그리기
	CPen pen(linePattern, lineThick, lineColor);
	CPen* oldPen = pDC->SelectObject(&pen);

	Graphics graphics(*pDC);
	/*
	//GDI+ 사용법
	Pen pen1(Color(0, 0, 255),5);  // 불투명 (255), 검정색(0,0,0)
	pen1.SetDashStyle(DashStyleSolid);
	pen1.SetStartCap(LineCapRound);
	pen1.SetEndCap(LineCapAnchorMask);
	graphics.DrawLine(&pen1, sPoint.x, sPoint.y, nPoint.x, nPoint.y);
	*/

	pDC->Ellipse(sPoint.x, sPoint.y, ePoint.x,ePoint.y);
	pDC->SelectObject(&oldPen);

	
		if (getSelect()){


			//테두리 리젼 그리기
			CRect rect;
			CPen* oldPen;
			rect.SetRect(sPoint, ePoint);
			pDC->SelectObject(&oldPen);
			CPen pen1(PS_DOT, 1, BLACK_PEN);
			oldPen = pDC->SelectObject(&pen1);
			pDC->SelectStockObject(NULL_BRUSH);
			pDC->Rectangle(rect);  //rect 그리기

			pDC->SelectObject(&oldPen);
		}



}


void YEllipse::move(){
	
}

void YEllipse::changeLineColor(){

}


void  YEllipse::ChangeinColor()
{


}



void  YEllipse::ChangeSize()
{

}//크기변경


void YEllipse::setRgn(){
	
	int left, top, right, bottom;
	//4 side rect divided
	if (sPoint.x < ePoint.x && sPoint.y < ePoint.y){  //1 -> 4 
		left = sPoint.x;
		top = sPoint.y;
		right = ePoint.x;
		bottom = ePoint.y;
	}
	else if (sPoint.x < ePoint.x && sPoint.y > ePoint.y){  // 3 -> 2
		left = sPoint.x;
		top = ePoint.y;
		right = ePoint.x;
		bottom = sPoint.y;
	}
	else if (sPoint.x > ePoint.x && sPoint.y < ePoint.y) { // 2 -> 3
		left = ePoint.x;
		top = sPoint.y;
		right = sPoint.x;
		bottom = ePoint.y;
	}
	else {  	// 4 -> 1
		left = ePoint.x;
		top = ePoint.y;
		right = sPoint.x;
		bottom = sPoint.y;
	}

	rgn.CreateRectRgn(left, top, right, bottom);
	
}



//리젼안에 있는지 검사하는함수
BOOL YEllipse::checkRgn(CPoint point)
{
	/*
	if (rgn.PtInRegion(point))
	{
		return TRUE;
	}
	*/
	return FALSE;
	
}


