#include "stdafx.h"
#include "YEllipse.h"


YEllipse::YEllipse()
{
}


YEllipse::~YEllipse()
{
}

IMPLEMENT_SERIAL(YEllipse, CObject, 1)

YEllipse::YEllipse(CPoint start, CPoint end, int color, int thick, int pattern, int inColor, int sidepattern, BOOL paflag)
{
	sPoint = start;
	ePoint = end;
	setLineColor(color);
	setLineThick(thick);
	setLinePattern(pattern);
	setSideColor(inColor);
	setSidePattern(sidepattern);
	setPatternflag(paflag);
}

YEllipse::YEllipse(YEllipse *p){
	sPoint = p->getSPoint();
	ePoint = p->getEPoint();
	setLineColor(p->getLineColor());
	setLineThick(p->getLineThick());
	setLinePattern(p->getLinePattern());
	setSideColor(p->getSideColor());
	setSidePattern(p->getSidePattern());
	setPatternflag(p->getPatternflag());
	setMoveMode(p->getMoveMode());
	setMixPoint(p->getMixPoint());
	setOrder(p->getOrder());
	setSelect(p->getSelect());
	setType(p->getType());
	setRgn();
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
	//�׸���
	CPen pen(getLinePattern(), getLineThick(), getLineColor());
	CPen* oldPen = pDC->SelectObject(&pen);

	if (getPatternflag() == FALSE)
	{
		CBrush brush(getSideColor());
		CBrush* oldBrush = pDC->SelectObject(&brush);
		pDC->Ellipse(sPoint.x, sPoint.y, ePoint.x, ePoint.y);
		pDC->SelectObject(&oldPen);
		pDC->SelectObject(oldBrush);
	}
	else
	{
		CBrush brush(getSidePattern() - 1, getSideColor());
		CBrush* oldBrush = pDC->SelectObject(&brush);
		pDC->Ellipse(sPoint.x, sPoint.y, ePoint.x, ePoint.y);
		pDC->SelectObject(&oldPen);
		pDC->SelectObject(oldBrush);
	}





	//Graphics graphics(*pDC);



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


void YEllipse::move(int s, int e){//�ø��� �۾�
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
	YObject::setORect(left - 1, top - 1, right + 1, bottom + 1);
	rgn.DeleteObject();
	rgn.CreateRectRgn(left, top, right, bottom);
}



//�����ȿ� �ִ��� �˻��ϴ��Լ�
BOOL YEllipse::checkRgn(CPoint point)
{

	if (rgn.PtInRegion(point))
	{
		return TRUE;
	}

	return FALSE;

}

void YEllipse::Serialize(CArchive& ar)
{
	YObject::Serialize(ar);
	YTwoDimension::Serialize(ar);
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
		ar << sPoint << ePoint << mixPoint;
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
		ar >> sPoint >> ePoint >> mixPoint;
		setRgn();
	}
}


