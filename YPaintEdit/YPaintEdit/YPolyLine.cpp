#include "stdafx.h"
#include "YPolyLine.h"


YPolyLine::YPolyLine()
{
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
	CPoint sPoint = polyList.GetNext(pos); //시작점
	CPoint tPoint; //임시
	if (polyList.GetCount == 1){
		pDC->MoveTo(sPoint);
		pDC->LineTo(mPoint);
	}
	else {
		while (pos){
			tPoint = polyList.GetNext(pos);
			pDC->MoveTo(sPoint);
			pDC->LineTo(tPoint);
			sPoint = tPoint;
		}
	}

	pDC->MoveTo(sPoint);
	pDC->LineTo(mPoint);
	pDC->SelectObject(&oldPen);

}

void YPolyLine::move(int s, int e){

}
void YPolyLine::changeLineColor(){

}

void YPolyLine::setRgn(){

}
BOOL YPolyLine::checkRgn(CPoint point){

}
void YPolyLine::addPoint(CPoint point){
	polyList.AddTail(point);
}


void YPolyLine::drawCircle(CDC *pDC){

}