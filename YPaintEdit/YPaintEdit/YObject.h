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

	virtual void setNPoint(CPoint point){ nPoint = point; }

	virtual void setPoint(CPoint point) = 0;
protected:
	YObject_Type yType;
	CRgn rgn; //리젼
	BOOL IsExist; // 리젼안에 있는지 판별
	BOOL selected;
	CPoint nPoint;
};

