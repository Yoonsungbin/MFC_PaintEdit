#include "stdafx.h"
#include "MyText.h"


MyText::MyText()
{
}

MyText::MyText(CPoint point)
{
	this->point.x = point.x;
	this->point.y = point.y;
	textSize = 500;
	font.CreatePointFont(textSize,_T("±¼¸²"));
	textColor = RGB(0, 0, 255);
	bgColor = RGB(255, 255, 0);	
}

MyText::~MyText()
{
}