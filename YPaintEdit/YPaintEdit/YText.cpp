#include "stdafx.h"
#include "YText.h"
#include "YObject.h"

// Constructors, Destructor
YText::YText()
{
}
YText::YText(CPoint point, CString f, COLORREF fc, COLORREF bkc, int s){
	sPoint = point;					// �ؽ�Ʈ �ڽ��� ����,���� ���� �ʱ�ȭ
	font = f;						// ����ü �ʱ�ȭ
	fontColor = fc;					// ���ڻ� �ʱ�ȭ
	bkColor = bkc;					// ���� �ʱ�ȭ
	fontSize = s;					// ����ũ�� �ʱ�ȭ
}
YText::~YText()
{
}


// Virtual
void YText::moveAll(int s, int e){

}
void YText::deleteAll(){

}
void YText::draw(CDC* dc){
	if (isSelected == TRUE){
		CPen pen(PS_DOT, 1, RGB(0, 0, 0));
		dc->SelectObject(pen);
		dc->Rectangle(sPoint.x - 1, sPoint.y - 1, ePoint.x + 1, ePoint.y + 1);
	}

	CFont f;
	f.CreatePointFont(fontSize, font);
	dc->SelectObject(f);
	dc->SetBkColor(bkColor);
	dc->SetTextColor(fontColor);
	dc->DrawText(texts, rect, NULL);
}
void YText::setRgn(){
	int left, top, right, bottom;
	
	// ��쿡 ���� ���� ���������Լ��� �Է��� ��ǥ ����
	if (sPoint.x < ePoint.x && sPoint.y < ePoint.y){
		left = sPoint.x;
		top = sPoint.y;
		right = ePoint.x;
		bottom = ePoint.y;
	}
	else if (sPoint.x < ePoint.x && sPoint.y > ePoint.y){
		left = sPoint.x;
		top = ePoint.y;
		right = ePoint.x;
		bottom = sPoint.y;
	}
	else if (sPoint.x > ePoint.x && sPoint.y < ePoint.y){
		left = ePoint.x;
		top = sPoint.y;
		right = sPoint.x;
		bottom = ePoint.y;
	}
	else {
		left = ePoint.x;
		top = ePoint.y;
		right = sPoint.x;
		bottom = sPoint.y;
	}

	// ���� ����
	rgn.DeleteObject();
	rgn.CreateRectRgn(left, top, right, bottom);
}
BOOL YText::checkRgn(CPoint point)
{
	if (rgn.PtInRegion(point))
		return TRUE;

	return FALSE;
}