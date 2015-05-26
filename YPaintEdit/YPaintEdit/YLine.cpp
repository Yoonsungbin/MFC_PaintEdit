#include "stdafx.h"
#include "YLine.h"


YLine::YLine()
{
}


YLine::~YLine()
{
}

YLine::YLine(CPoint start, CPoint end)
{
	sPoint = start;
	ePoint = end;
}

void YLine::moveAll(){

}
void YLine::deleteAll(){

}
void YLine::draw(CDC* pDC){

	CPen pen(PS_SOLID,1 ,lineColor );
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

	pDC->SelectObject(&pen);
	pDC->MoveTo(sPoint);
	pDC->LineTo(ePoint);
	pDC->SelectObject(&oldPen);

	if (isSelected){
		/*
		CRect rect;
		rect.SetRect(sPoint, ePoint);
		
		rect.left = sPoint.x;
		rect.top = sPoint.y;
		rect.right = ePoint.x;
		rect.bottom = ePoint.y;
		CPen pen1(PS_DOT, 1, BLACK_PEN);
		CPen* oldPen = pDC->SelectObject(&pen1);
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->Rectangle(rect.left, rect.top, rect.right, rect.bottom);
		pDC->SelectObject(&oldPen);
		*/
		CPen pen1(PS_DOT, 1, BLACK_PEN);
		CPen* oldPen = pDC->SelectObject(&pen1);
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->Rectangle(rect);
	}
	else {
		
		CPen pen1(PS_DOT, 1, WHITE_PEN);
		CPen* oldPen = pDC->SelectObject(&pen1);
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->Rectangle(rect);
		
	}
	
}
void YLine::move(){

}

void YLine::changeLineColor(){

}
void YLine::setRgn(){
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
BOOL YLine::checkRgn(CPoint point)  
{
	if (rgn.PtInRegion(point))
	{
		return TRUE;
	}

	return FALSE;
}
void YLine::drawRgn(CPoint point, CPoint point2){
	
	rect.SetRect(point.x, point.y, point2.x, point2.y);  //사각형설정
}