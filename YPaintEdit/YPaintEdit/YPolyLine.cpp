#include "stdafx.h"
#include "YPolyLine.h"


YPolyLine::YPolyLine()
{
	polyList.RemoveAll();
}


YPolyLine::~YPolyLine()
{
}
void YPolyLine::moveAll(int s, int e){

}

void YPolyLine::deleteAll(){

}
void YPolyLine::draw(CDC* pDC){
	
	CPen pen(linePattern, lineThick, lineColor);
	CPen* oldPen = pDC->SelectObject(&pen);
	POSITION pos = polyList.GetHeadPosition();
	CPoint t1Point,t2Point;
	t1Point = polyList.GetNext(pos);
	while (pos) {
		
			t2Point = polyList.GetNext(pos);
			
			pDC->MoveTo(t1Point);
			pDC->LineTo(t2Point);
			t1Point = t2Point;
	
	}
	pDC->MoveTo(t1Point);
	pDC->LineTo(ePoint);
	pDC->SelectObject(&oldPen);

	
	
}

void YPolyLine::move(int s, int e){

}
void YPolyLine::changeLineColor(){

}

void YPolyLine::setRgn(){
	POSITION pos = polyList.GetHeadPosition();
	CRect rect;
	rect.left = 10000;
	rect.top = 10000;
	rect.right = -10000;
	rect.bottom = -10000;
	
	//제일 멀리있는점 구하기
	while (pos){ 
		CPoint &dPoint = polyList.GetNext(pos);  
		if (rect.left > dPoint.x) rect.left = dPoint.x;
		if (rect.top > dPoint.y)rect.top = dPoint.y;
		if (rect.right < dPoint.x)rect.right = dPoint.x;
		if (rect.bottom < dPoint.y) rect.bottom = dPoint.y;
	}
	rgn.CreateRectRgn(rect.left, rect.top, rect.right, rect.bottom);
}
BOOL YPolyLine::checkRgn(CPoint point){

	return FALSE;
}
void YPolyLine::addPoint(CPoint point){
	polyList.AddTail(point);
}


void YPolyLine::drawCircle(CDC *pDC){
	/*
	mRect[0].SetRect(sPoint.x - 15, sPoint.y - 15, sPoint.x + 15, sPoint.y + 15);
	mRect[1].SetRect(ePoint.x - 15, ePoint.y - 15, ePoint.x + 15, ePoint.y + 15);
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CPen* oldPen = pDC->SelectObject(&pen);
	pDC->SelectStockObject(WHITE_BRUSH);
	pDC->Ellipse(mRect[0]);
	pDC->Ellipse(mRect[1]);
	*/
}