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

	sPoint.x += s;
	sPoint.y += e;
	ePoint.x += s;
	ePoint.y += e;
}

void YLine::deleteAll(){

}

void YLine::draw(CDC* pDC){

	CPen pen(linePattern,lineThick ,lineColor );
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
	/*
	else {
		CPen pen1(PS_SOLID, 1, BLACK_PEN);
		CPen* oldPen = pDC->SelectObject(&pen1);
		//pDC->SetROP2(R2_XORPEN);
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->Rectangle(rect);
		pDC->SelectObject(&oldPen);
		
	}
	*/
	
}

void YLine::move(int s,int e){
	if (getMPoint() == -1){  //시작점이동
		sPoint.x += s;
		sPoint.y += e;
	}
	else{
		ePoint.x += s;
		ePoint.y += e;
	}
}

void YLine::changeLineColor(){

}

void YLine::setRgn(){
	int left, top, right, bottom;
	//4 side rect divided
	if (sPoint.x < ePoint.x && sPoint.y < ePoint.y){  //1 -> 4 
		left = sPoint.x+10;
		top = sPoint.y+10;
		right = ePoint.x-10;
		bottom = ePoint.y-10;
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
	//이전꺼지우고 새로만듬
	rgn.DeleteObject();   
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

void YLine::drawCircle(CDC *pDC){
	//시작점 끝점 원그리기
	mRect[0].SetRect(sPoint.x - 15, sPoint.y - 15, sPoint.x + 15, sPoint.y + 15);
	mRect[1].SetRect(ePoint.x - 15, ePoint.y - 15, ePoint.x + 15, ePoint.y + 15);
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CPen* oldPen = pDC->SelectObject(&pen);
	pDC->SelectStockObject(WHITE_BRUSH);
	pDC->Ellipse(mRect[0]);
	pDC->Ellipse(mRect[1]);
}