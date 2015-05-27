#include "stdafx.h"
#include "YText.h"
#include "YObject.h"

// Constructors, Destructor
YText::YText()
{
}
YText::YText(CPoint point){
	yType = text;					// YObject의 타입을 Text로 초기화
	sPoint = point;					// 텍스트 박스의 왼쪽,위의 점을 초기화
	fontSize = 500;					// 글자크기 초기화
	font = _T("바탕");				// 글자체 초기화
	fontColor = RGB(0, 0, 0);		// 글자색 초기화
	bkColor = RGB(255, 255, 255);	// 배경색 초기화
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
	rgn.CreateRectRgn(left, top, right, bottom);
}
BOOL YText::checkRgn(CPoint point)
{
	if (rgn.PtInRegion(point))
		return TRUE;

	return FALSE;
}