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

}
BOOL YPolyLine::checkRgn(CPoint point){

	return FALSE;
}
void YPolyLine::addPoint(CPoint point){
	polyList.AddTail(point);
}


void YPolyLine::drawCircle(CDC *pDC){

}