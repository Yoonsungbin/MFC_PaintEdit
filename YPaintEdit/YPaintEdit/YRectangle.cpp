#include "stdafx.h"
#include "YRectangle.h"


YRectangle::YRectangle()
{
}


YRectangle::~YRectangle()
{
	
}


YRectangle::YRectangle(CPoint start, CPoint end, int color, int thick, int pattern,int inColor)
{
	sPoint = start;
	ePoint = end;
	setLineColor(color);
	setLineThick(thick);
	setLinePattern(pattern);
	ChangeinColor(inColor);
}


void YRectangle::moveAll(int s, int e)
{
	sPoint.x += s;
	sPoint.y += e;
	ePoint.x += s;
	ePoint.y += e;
}


void YRectangle::deleteAll(){
}


void YRectangle::draw(CDC* pDC)
{
	//�׸���
	CPen pen(getLinePattern(), getLineThick(), getLineColor());
	CPen* oldPen = pDC->SelectObject(&pen);
	CBrush brush(getinColor());
	//CBrush brush(HS_BDIAGONAL, getinColor());
	CBrush* oldBrush = pDC->SelectObject(&brush);
	//Graphics graphics(*pDC);

	pDC->Rectangle(sPoint.x, sPoint.y, ePoint.x, ePoint.y);
	pDC->SelectObject(&oldPen);
	pDC->SelectObject(oldBrush);

	if (getSelect()){

		//�׵θ� ���� �׸���
		CRect rect;
		CPen* oldPen;
		rect.SetRect(sPoint, ePoint);
		pDC->SelectObject(&oldPen);
		CPen pen1(PS_DOT, 1, BLACK_PEN);
		oldPen = pDC->SelectObject(&pen1);
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->Rectangle(rect);  //rect �׸���
		pDC->SelectObject(&oldPen);


		//draw circle
		mRect[0].SetRect(sPoint.x - 15, sPoint.y - 15, sPoint.x + 15, sPoint.y + 15);//1��и�
		mRect[1].SetRect(ePoint.x - 15, ePoint.y - 15, ePoint.x + 15, ePoint.y + 15);//4��и�
		mRect[2].SetRect(sPoint.x - 15, ePoint.y - 15, sPoint.x + 15, ePoint.y + 15);//3��и�
		mRect[3].SetRect(ePoint.x - 15, sPoint.y - 15, ePoint.x + 15, sPoint.y + 15);//2��и�

		CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
		oldPen = pDC->SelectObject(&pen);
		pDC->SelectStockObject(WHITE_BRUSH);
		pDC->Ellipse(mRect[0]);
		pDC->Ellipse(mRect[1]);
		pDC->Ellipse(mRect[2]);
		pDC->Ellipse(mRect[3]);
	}

}


void YRectangle::move(int s, int e){
	if (getMoveMode() == -1){  //�������ø���
		sPoint.x += s;
		sPoint.y += e;
	}

	else if (getMoveMode() == 1)//���� �ø���
	{
		ePoint.x += s;
		ePoint.y += e;
	}


	else if (getMoveMode() == 2)//3��и� �ø���
	{
		sPoint.x += s;
		ePoint.y += e;
	}

	else if (getMoveMode() == 3)//2��и� �ø���
	{

		ePoint.x += s;
		sPoint.y += e;
	}
}

void YRectangle::changeLineColor(){

}


void YRectangle::setRgn(){

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




//�����ȿ� �ִ��� �˻��ϴ��Լ�
BOOL YRectangle::checkRgn(CPoint point)
{
	if (rgn.PtInRegion(point))
	{
		return TRUE;
	}
	return FALSE;
}