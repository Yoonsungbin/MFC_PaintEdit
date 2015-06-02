#include "stdafx.h"
#include "YEllipse.h"


YEllipse::YEllipse()
{
}


YEllipse::~YEllipse()
{
}



YEllipse::YEllipse(CPoint start, CPoint end, int color, int thick, int pattern)
{
	sPoint = start;
	ePoint = end;
	setLineColor(color);
	setLineThick(thick);
	setLinePattern(pattern);
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
	CPen pen(getLinePattern(), getLineThick(), getLineColor());
	CPen* oldPen = pDC->SelectObject(&pen);

	//Graphics graphics(*pDC);
	
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


void YEllipse::move(int s, int e){
	if (getMoveMode() == -1){  //시작점이동
		sPoint.x += s;
		sPoint.y += e;
	}
	else{
		ePoint.x += s;
		ePoint.y += e;
	}
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

	rgn.DeleteObject();
	rgn.CreateRectRgn(left, top, right, bottom);
}



//리젼안에 있는지 검사하는함수
BOOL YEllipse::checkRgn(CPoint point)
{
	
	if (rgn.PtInRegion(point))
	{
		return TRUE;
	}
	
	return FALSE;
	
}


void YEllipse::drawCircle(CDC *pDC){
	//시작점 끝점 원그리기
	mRect[0].SetRect(sPoint.x - 15, sPoint.y - 15, sPoint.x + 15, sPoint.y + 15);//시작점
	mRect[1].SetRect(ePoint.x - 15, ePoint.y - 15, ePoint.x + 15, ePoint.y + 15);
	//mRect[2].SetRect(ePoint.x - 15, ePoint.y - 15, ePoint.x + 15, ePoint.y + 15);
	//mRect[3].SetRect(ePoint.x - 15, ePoint.y - 15, ePoint.x + 15, ePoint.y + 15);
	
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CPen* oldPen = pDC->SelectObject(&pen);
	pDC->SelectStockObject(WHITE_BRUSH);
	pDC->Ellipse(mRect[0]);
	pDC->Ellipse(mRect[1]);
}