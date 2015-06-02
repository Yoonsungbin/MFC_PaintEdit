#pragma once
#include "afx.h"
#include <gdiplus.h>

using namespace Gdiplus;

typedef enum Object_Type{ choice, rectangle, ellipse, line, polyline, text, default } YObject_Type;

class YObject : public CObject
{
public:
	YObject();
	~YObject();
	
	//YObject(const YObject &s){ *this = s; }							// ???
	//YObject& operator=(const YObject &s) { return *this; }			// ???

	virtual void setType(YObject_Type t){ yType = t; }				// 객체의 타입 설정하는 함수
	YObject_Type getType(){ return yType; }							// 객체의 타입 가져오는 함수

	virtual void moveAll(int s, int e) = 0;							// 객체를 이동시키는 함수
	virtual void deleteAll() = 0;									// 객체를 리스트에서 삭제하는 함수
	virtual void draw(CDC*) = 0;									// 객체를 그리는 함수
	
	virtual void setRgn() = 0;										// 리젼을 생성하는 함수
	CRgn* getRgn(){ return &rgn; }									// 리젼을 가져오는 함수
	virtual BOOL checkRgn(CPoint point) { return FALSE; }			// 좌표가 리젼안에 존재하는지 확인하는 함수

	virtual void setSelect(BOOL select) { isSelected = select; }	//객체가 선택됫는지보기위해서
	BOOL getSelect() const { return isSelected; }					//선택된지아는 BOOL변수 가져오는함수

protected:
	YObject_Type yType;		// 도형의 타입
	CRgn rgn;				// 도형의 리젼
	BOOL isSelected;		// 도형의 선택 여부
};
