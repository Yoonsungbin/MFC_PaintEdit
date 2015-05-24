#pragma once
#include "MyObject.h"
class MyText
{
public:
	MyText();
	MyText(CPoint point);
	~MyText();
public:
	CPoint point;
	CString text;
	int textSize;
	CFont font;
	COLORREF textColor;
	COLORREF bgColor;
};