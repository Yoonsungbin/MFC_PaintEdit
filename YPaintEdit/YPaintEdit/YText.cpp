#include "stdafx.h"
#include "YText.h"

// Constructors, Destructor
YText::YText()
{
}
YText::YText(CPoint point){
	sPoint = point;
	fontSize = 1000;
	font = _T("±¼¸²");
	fontColor = RGB(1, 0, 0);
	bkColor = RGB(255, 255, 0);
}
YText::~YText()
{
}


// Virtual
void YText::moveAll(){

}
void YText::deleteAll(){

}
void YText::draw(CDC* dc){
	CFont f;
	f.CreatePointFont(fontSize, font);
	dc->SelectObject(f);
	dc->SetBkColor(bkColor);
	dc->SetTextColor(fontColor);
	dc->DrawText(text, rect, NULL);
}
void YText::setRgn(){
	int left, top, right, bottom;

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

	rgn.CreateRectRgn(left, top, right, bottom);
}
BOOL YText::checkRgn(CPoint point)
{
	if (rgn.PtInRegion(point))
		return TRUE;

	return FALSE;
}