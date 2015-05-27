#pragma once
#include "YObject.h"
class YText : public YObject
{
public:
	// Constructors, Destructor
	YText();													// 기본 생성자
	YText(CPoint point);										// CPoint 객체 하나를 받는 생성자
	~YText();													// 기본 소멸자
	

	// Virtual
	void setType(YObject_Type t) { yType = t; }					// 객체의 타입을 텍스트 타입으로 설정하는 함수
	void moveAll(int s, int e);									// 텍스트 객체를 이동시키는 함수
	void deleteAll();											// 텍스트 객체를 삭제하는 함수
	void draw(CDC* dc);											// 텍스트 객체를 그리는 함수

	void setSPoint(CPoint point) { sPoint = point; }			// 텍스트 박스의 왼쪽,위의 점을 설정하는 함수
	void setEPoint(CPoint point) { ePoint = point; }			// 텍스트 박스의 오른쪽,아래의 점을 설정하는 함수
	CPoint getSPoint() { return sPoint; }						// 텍스트 박스의 왼쪽,위의 점을 얻는 함수
	CPoint getEPoint() { return ePoint; }						// 텍스트 박스의 오른쪽,아래의 점을 얻는 함수
	virtual void setRgn();										// 리젼을 생성하는 함수
	BOOL checkRgn(CPoint point);								// 좌표가 리젼안에 존재하는지 확인하는 함수
	void setSelect(BOOL select) { isSelected = select; }		// 
	

	// Accessor
	void setRect(CPoint sPoint, CPoint ePoint)					// 텍스트 박스를 설정하는 함수
		{ rect.SetRect(sPoint.x, sPoint.y, ePoint.x, ePoint.y); }
	void setText(CString nText) { text = nText;  }				// 텍스트를 설정하는 함수
	void setFont(CString nFont) { font = nFont; }				// 글자체를 설정하는 함수
	void setFontColor(COLORREF nColor) { fontColor = nColor; }	// 글자색을 설정하는 함수
	void setBkColor(COLORREF nColor) { bkColor = nColor; }		// 배경색을 설정하는 함수
	void setFontSize(int nFontSize) { fontSize = nFontSize; }	// 글자크기를 설정하는 함수

	
	// Mutator
	CRect getRect() { return rect; }							// 텍스트 박스를 얻는 함수
	CString getText() { return text; }							// 텍스트를 얻는 함수
	CString getFont() { return font; }							// 글자체를 얻는 함수
	COLORREF getFontColor() { return fontColor; }				// 글자색을 얻는 함수 
	COLORREF getBkColor() { return bkColor; }					// 배경색을 얻는 함수
	int getFontSize() { return fontSize; }						// 글자크기를 얻는 함수


	// Variables
private:
	CPoint sPoint;			// 텍스트 박스의 왼쪽,위의 점
	CPoint ePoint;			// 텍스트 박스의 오른족,아래의 점
	CRect rect;				// 텍스트 박스
	CString text;			// 텍스트
	CString font;			// 글자체
	COLORREF fontColor;		// 글자색
	COLORREF bkColor;		// 배경색
	int fontSize;			// 글자크기
};