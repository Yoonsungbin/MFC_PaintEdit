#include "stdafx.h"
#include "YLine.h"


YLine::YLine()
{
}

YLine::~YLine()
{
}

YLine::YLine(CPoint start, CPoint end, int color, int thick,int pattern)
{
	sPoint = start;
	ePoint = end;
	setLineColor(color);
	setLineThick(thick);
	setLinePattern(pattern);
}
IMPLEMENT_SERIAL(YLine,CObject,1)

void YLine::moveAll(int s, int e){

	sPoint.x += s;
	sPoint.y += e;
	ePoint.x += s;
	ePoint.y += e;
}

void YLine::deleteAll(){

}

void YLine::draw(CDC* pDC){ 

	CPen pen(getLinePattern(),getLineThick() ,getLineColor() );
//	CPen* oldPen = pDC->SelectObject(&pen);
	pDC->SelectObject(&pen);
	/*
	Graphics graphics(*pDC);
	
	//GDI+ ����
	Pen pen1(Color(0, 0, 255),5);  // ������ (255), ������(0,0,0)
	pen1.SetDashStyle(DashStyleSolid);
	pen1.SetStartCap(LineCapRound);
	pen1.SetEndCap(LineCapAnchorMask);
	graphics.DrawLine(&pen1, sPoint.x, sPoint.y, nPoint.x, nPoint.y);
	*/

	pDC->MoveTo(sPoint);
	pDC->LineTo(ePoint);
	//pDC->SelectObject(&oldPen);

	if (getSelect()){ 
		//�׵θ� ���� �׸���
		CRect rect;
		CPen* oldPen;
		rect.SetRect(sPoint, ePoint);
	
		CPen pen1(PS_DOT, 1, RGB(0,0,0));
		oldPen = pDC->SelectObject(&pen1);
		pDC->SelectObject(&pen1);
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->Rectangle(rect);  //rect �׸���
		pDC->SelectObject(&oldPen);

		//draw circle
		mRect[0].SetRect(sPoint.x - 10, sPoint.y - 10, sPoint.x + 10, sPoint.y + 10);
		mRect[1].SetRect(ePoint.x - 10, ePoint.y - 10, ePoint.x + 10, ePoint.y + 10);
		CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
		oldPen = pDC->SelectObject(&pen);
		pDC->SelectObject(&pen);
		pDC->SelectStockObject(WHITE_BRUSH);
		pDC->Ellipse(mRect[0]);
		pDC->Ellipse(mRect[1]);
	}
	
}

void YLine::move(int s,int e){
	if (getMoveMode() == -1){  //�������̵�
		sPoint.x += s;
		sPoint.y += e;
	}
	else{
		ePoint.x += s;
		ePoint.y += e;
	}
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
	setORect(left-11, top-11, right+11, bottom+11);
	//����������� ���θ���
	rgn.DeleteObject();   
	rgn.CreateRectRgn(left, top, right, bottom);
}

//�����ȿ� �ִ��� �˻��ϴ��Լ�
BOOL YLine::checkRgn(CPoint point)  
{
	if (rgn.PtInRegion(point))
	{
		return TRUE;
	}

	return FALSE;
}


void YLine::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
		ar << sPoint << ePoint << mRect[0] << mRect[1] << moveMode << getLineThick()<<getLineColor() << getLinePattern() << getType()  << getORect() << getSelect() << getOrder();
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
		int lineThick;
		int lineColor;
		int linePattern;
		int yType;		// ������ Ÿ��
		CRect rect;				// ������ ���� �簢��
		BOOL isSelected;		// ������ ���� ����
		int order;


		ar >> sPoint >> ePoint;
		ar >> mRect[0] >>mRect[1];
		ar >> moveMode;
		ar >> lineThick >> lineColor >> linePattern >> yType  >> rect >> isSelected >> order;

		YLine* line = new YLine(sPoint, ePoint, lineColor, lineThick, linePattern);
		line->yType = (YObject_Type)yType;
		line->isSelected = isSelected;
		line->order = order;
		line->setRgn();

		
	}
}


