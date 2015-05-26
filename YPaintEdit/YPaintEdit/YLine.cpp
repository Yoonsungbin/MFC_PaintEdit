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

void YLine::moveAll(int s, int e){
	
	/*
	if (s.x < e.x && s.y < e.y){  //1 -> 4 
		dx = e - s;
	}
	else if (s.x < e.x && s.y > e.y){  // 3 -> 2
		dx.x = s.x - e.x;
		dx.y = e.y - s.y;
	}
	else if (s.x > e.x && s.y < e.y) { // 2 -> 3
		left = e.x;
		top = s.y;
		right = s.x;
		bottom = e.y;
	}
	else {  	// 4 -> 1
		left = e.x;
		top = e.y;
		right = s.x;
		bottom = s.y;
	}
	*/
	sPoint.x += s;
	sPoint.y += e;
	ePoint.x += s;
	ePoint.y += e;
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

	pDC->MoveTo(sPoint);
	pDC->LineTo(ePoint);
	pDC->SelectObject(&oldPen);

	if (isSelected){
		CPen pen1(PS_DOT, 1, BLACK_PEN);
		CPen* oldPen = pDC->SelectObject(&pen1);
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->Rectangle(rect);  //rect 그리기
		pDC->SelectObject(&oldPen);
	}
	else {
		CPen pen1(PS_SOLID, 1, BLACK_PEN);
		CPen* oldPen = pDC->SelectObject(&pen1);
		pDC->SetROP2(R2_XORPEN);
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->Rectangle(rect);
		pDC->SelectObject(&oldPen);
		
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
