#pragma once
#include "afx.h"
#include <gdiplus.h>	//gdi++
using namespace Gdiplus;	//gdi++

typedef enum Object_Type{ default, rectangle, ellipse, line, polyline, text } YObject_Type;

class YObject :
	public CObject
{
public:
	YObject();
	~YObject();
	
	YObject(const YObject &s){ *this = s; }
	YObject& operator=(const YObject &s) { return *this; }

	virtual void moveAll() = 0;
	virtual void deleteAll() = 0;
	virtual void draw(CDC*) = 0;

	virtual void setRgn() = 0;
	CRgn* getRgn(){ return &rgn; }
	BOOL virtual checkRgn(CPoint point) { return FALSE; }

	virtual void setSelect(BOOL select) { selected = select; }  //객체가 선택됫는지보기위해서
	BOOL getSelect(){ return selected; }

	virtual void setSPoint(CPoint point) = 0;
	virtual CPoint getSPoint() = 0;

	virtual void setEPoint(CPoint point) = 0;
	virtual CPoint getEPoint() = 0;

	virtual void drawRgn(CPoint point, CPoint point2) = 0;  //리젼테두리 그리기위한함수
protected:
	YObject_Type yType;
	CRgn rgn; //리젼
	BOOL IsExist; // 리젼안에 있는지 판별
	BOOL selected;  //선택된지 안된지 보기위해서
	
};

