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
	void moveAll(int s, int e);
	void deleteAll();
	void draw(CDC*);

	void setSPoint(CPoint point) { sPoint = point; }
	void setEPoint(CPoint point) { ePoint = point; }
	CPoint getSPoint() { return sPoint; }
	CPoint getEPoint() { return ePoint; }
	virtual void setRgn();
	BOOL checkRgn(CPoint point);
	void setSelect(BOOL select) { isSelected = select; }
	void drawRgn(CPoint point, CPoint point2) { rect.SetRect(point.x, point.y, point2.x, point2.y); }
	
	// Accessor
	void setText(CString nText) { text = nText;  }
	void setFont(CString nFont) { font = nFont; }
	void setFontColor(COLORREF nColor) { fontColor = nColor; }
	void setBkColor(COLORREF nColor) { bkColor = nColor; }
	void setFontSize(int nFontSize) { fontSize = nFontSize; }

	
	// Mutator
	CRect getRect() { return rect; }
	CString getText() { return text; }
	CString getFont() { return font; }
	COLORREF getFontColor() { return fontColor; }
	COLORREF getBkColor() { return bkColor; }
	int getFontSize() { return fontSize; }

	//////////////////////////
	virtual void setLineColor(COLORREF c){
		fontColor = c;
	}
	virtual void SetLineThick(int c) {
		fontSize = c;
	}
	virtual void SetLinePattern(int c) {
		fontSize = c;
	}
	///////////////////////////
	// Variables
private:
	CPoint sPoint;
	CPoint ePoint;
	CRect rect;
	CString text;
	CString font;
	COLORREF fontColor;
	COLORREF bkColor;
	int fontSize;
};