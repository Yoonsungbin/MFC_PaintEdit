#include "stdafx.h"
#include "YText.h"
#include "YObject.h"

// Constructors, Destructor
YText::YText()
{
}
YText::YText(CPoint point, CString f, COLORREF fc, COLORREF bkc, int s){
	sPoint = point;					// 텍스트 박스의 왼쪽,위의 점을 초기화
	font = f;						// 글자체 초기화
	fontColor = fc;					// 글자색 초기화
	bkColor = bkc;					// 배경색 초기화
	fontSize = s;					// 글자크기 초기화
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
	
	// 경우에 수에 따라 리젼생성함수에 입력할 좌표 설정
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

	// 리젼 생성
	rgn.DeleteObject();
	rgn.CreateRectRgn(left, top, right, bottom);
}
BOOL YText::checkRgn(CPoint point)
{
	if (rgn.PtInRegion(point))
		return TRUE;

	return FALSE;
}