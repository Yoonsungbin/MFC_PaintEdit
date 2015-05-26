#pragma once
#include "YObject.h"
class YText : public YObject
{
public:
	// Constructors, Destructor
	YText();
	YText(CPoint point);
	~YText();
	

	// Virtual
	void setType(YObject_Type t) { yType = t; }
	void moveAll();
	void deleteAll();
	void draw(CDC*);

	void setSPoint(CPoint point) { sPoint = point; }
	void setEPoint(CPoint point) { ePoint = point; }
	CPoint getSPoint() { return sPoint; }
	CPoint getEPoint() { return ePoint; }
	void setRgn();
	BOOL checkRgn(CPoint point);
	void drawRgn(CPoint point, CPoint point2) { rect.SetRect(point.x, point.y, point2.x, point2.y); }
	void setSelect(BOOL select) { isSelected = select; }

	
	// Accessor
	void setText(CString nText) { text = nText;  }
	void setFont(CFont* nFont) { font = nFont; }
	void setFontColor(COLORREF nColor) { fontColor = nColor; }
	void setBkColor(COLORREF nColor) { bkColor = nColor; }
	void setFontSize(int nFontSize) { fontSize = nFontSize; }

	
	// Mutator
	CRect getRect() { return rect; }
	CString getText() { return text; }
	CFont* getFont() { return font; }
	COLORREF getFontColor() { return fontColor; }
	COLORREF getBkColor() { return bkColor; }
	int getFontSize() { return fontSize; }

	
	// Variables
private:
	CPoint sPoint;
	CPoint ePoint;
	CRect rect;
	CString text;
	CFont* font;
	COLORREF fontColor;
	COLORREF bkColor;
	int fontSize;
};