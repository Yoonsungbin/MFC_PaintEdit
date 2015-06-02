#include "stdafx.h"
#include "YPolyLine.h"


YPolyLine::YPolyLine()
{
	polyList.RemoveAll();
}

YPolyLine::YPolyLine(int color, int thick, int pattern)
{
	setLineColor(color);
	setLineThick(thick);
	setLinePattern(pattern);
	polyList.RemoveAll();
}

YPolyLine::~YPolyLine()
{
}
void YPolyLine::moveAll(int s, int e){
	CList<CPoint, CPoint&> temp;
	POSITION pos1 = polyList.GetHeadPosition();
	
	while (pos1){
		CPoint tPoint = polyList.GetNext(pos1);
		tPoint.x += s;
		tPoint.y += e;
		temp.AddTail(tPoint);
	}

	polyList.RemoveAll();
	POSITION pos2 = temp.GetHeadPosition();
	while (pos2){
		CPoint tPoint = temp.GetNext(pos2);
		polyList.AddTail(tPoint);
	}

}

void YPolyLine::deleteAll(){

}
void YPolyLine::draw(CDC* pDC){
	
	CPen pen(getLinePattern(), getLineThick(), getLineColor());
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

	if (drawingPolyLine == TRUE){
		pDC->MoveTo(t1Point);
		pDC->LineTo(ePoint);
	}
	pDC->SelectObject(&oldPen);

	
	if (getSelect()){
		//테두리 리젼 그리기
		CPen* oldPen;
		rect.SetRect(rect.left,rect.top,rect.right,rect.bottom);
		pDC->SelectObject(&oldPen);
		CPen pen1(PS_DOT, 1, BLACK_PEN);
		oldPen = pDC->SelectObject(&pen1);
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->Rectangle(rect);  //rect 그리기
		pDC->SelectObject(&oldPen);

		//draw circle
		int i = 0;
		POSITION pos = polyList.GetHeadPosition();
		while (pos){
			CPoint temp = polyList.GetNext(pos);
			mRect[i].SetRect(temp.x - 15, temp.y - 15, temp.x + 15, temp.y + 15);
			CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
			 oldPen = pDC->SelectObject(&pen);
			pDC->SelectStockObject(WHITE_BRUSH);
			pDC->Ellipse(mRect[i]);
			i++;
		}
	}
	
}

void YPolyLine::move(int s, int e){
	
	CList<CPoint, CPoint&> temp;
	POSITION pos1 = polyList.GetHeadPosition();

	int i = 0;
	while (pos1){
		CPoint tPoint = polyList.GetNext(pos1);
		if (i == getIndex()) {
			tPoint.x += s;
			tPoint.y += e;
		}
		temp.AddTail(tPoint);
		i++;
	}

	polyList.RemoveAll();
	POSITION pos2 = temp.GetHeadPosition();
	while (pos2){
		CPoint tPoint = temp.GetNext(pos2);
		polyList.AddTail(tPoint);
	}

}
void YPolyLine::changeLineColor(){

}

void YPolyLine::setRgn(){
	POSITION pos = polyList.GetHeadPosition();
	
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
	rgn.DeleteObject();  //이전영역 지우고 다시만들기
	rgn.CreateRectRgn(rect.left, rect.top, rect.right, rect.bottom);
}

BOOL YPolyLine::checkRgn(CPoint point){
	if (rgn.PtInRegion(point))
	{
		return TRUE;
	}
	return FALSE;
}
void YPolyLine::addPoint(CPoint point){
	polyList.AddTail(point);
}

