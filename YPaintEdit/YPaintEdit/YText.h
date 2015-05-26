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
	void changePoint(CPoint nPoint){ point = nPoint; }
	void changeText(CString nText) { text = nText;  }
	void changeFont(CFont nFont) { font = nFont; }
	void changeFontColor(COLORREF nColor) { fontColor = nColor; }
	void changeBkColor(COLORREF nColor) { bkColor = nColor; }
	void changeFontSize(int nFontSize) { fontSize = nFontSize; }

	// Getter
	CPoint getPoint() { return point; }
	CString getText() { return text; }
	CFont getFont() { return font; }
	COLORREF getFontColor() { return fontColor; }
	COLORREF getBkColor() { return bkColor; }
	int getFontSize() { return fontSize; }

	// Variables
private:
	CPoint point;
	CString text;
	CFont font;
	COLORREF fontColor;
	COLORREF bkColor;
	int fontSize;
};