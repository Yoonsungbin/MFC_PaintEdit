#pragma once
#include "YObject.h"
class YText : public YObject
{
public:
	// Constructor, Destructor
	YText();
	~YText();

	// Virtual
	virtual void moveAll();
	virtual void deleteAll();
	virtual void draw(CDC*);

	// Setter
	void changePoint(CPoint nPoint);
	void changeText(CString nText);
	void changeFont(CFont nFont);
	void changeFontColor(COLORREF nColor);
	void changeBkColor(COLORREF nColor);
	void changeFontSize(int nFontSize);

	// Getter
	CPoint getPoint();
	CString getText();
	CFont getFont();
	COLORREF getFontColor();
	COLORREF getBkColor();
	int getFontSize();

	// Variables
private:
	CPoint point;
	CString text;
	CFont font;
	COLORREF fontColor;
	COLORREF bkColor;
	int fontSize;
};