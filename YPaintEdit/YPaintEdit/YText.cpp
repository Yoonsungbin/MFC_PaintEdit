#include "stdafx.h"
#include "YText.h"
#include "YObject.h"

// Constructors, Destructor
YText::YText()
{
}
YText::YText(CPoint point){
	yType = text;					// YObject�� Ÿ���� Text�� �ʱ�ȭ
	sPoint = point;					// �ؽ�Ʈ �ڽ��� ����,���� ���� �ʱ�ȭ
	fontSize = 500;					// ����ũ�� �ʱ�ȭ
	font = _T("����");				// ����ü �ʱ�ȭ
	fontColor = RGB(0, 0, 0);		// ���ڻ� �ʱ�ȭ
	bkColor = RGB(255, 255, 255);	// ���� �ʱ�ȭ
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
	rgn.CreateRectRgn(left, top, right, bottom);
}
BOOL YText::checkRgn(CPoint point)
{
	if (rgn.PtInRegion(point))
		return TRUE;

	return FALSE;
}