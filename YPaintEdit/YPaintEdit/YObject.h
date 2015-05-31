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
	
	YObject(const YObject &s){ *this = s; }							// ???
	YObject& operator=(const YObject &s) { return *this; }			// ???

	virtual void setType(YObject_Type t){ yType = t; }				// 객체의 타입 설정하는 함수
	YObject_Type getType(){ return yType; }							// 객체의 타입 가져오는 함수

	virtual void moveAll(int s, int e) = 0;							// 객체를 이동시키는 함수
	virtual void deleteAll() = 0;									// 객체를 리스트에서 삭제하는 함수
	virtual void draw(CDC*) = 0;									// 객체를 그리는 함수
	
	/*
	도형을 만들면 rgn을 설정해야하는데 도형의 시작점과 끝점으로 rgn 을 생성함. rgn.create를 setrgb에서하는거 보면 알수있을꺼임
	그 다음 생성된 리젼은 getrgn으로 가져와서 반환값이 crgn변수임 그변수를통해 checkrgn함수에서  PtInRegion 메소드를 통해 리젼안에 있는지 판별
	*/
	virtual void setRgn() = 0;										// 리젼을 생성하는 함수
	CRgn* getRgn(){ return &rgn; }									// 리젼을 가져오는 함수
	virtual BOOL checkRgn(CPoint point) { return FALSE; }			// 좌표가 리젼안에 존재하는지 확인하는 함수

	/*
	리젼을 그릴때 이미 선택되어 있는 리젼은 제거해야하고 선택 안된 리젼은 리젼을 그려줘야함 그래서 리젼이 선택되어있는지(점선이 보이는지) 아닌지를 알기위한
	메소드가 필요
	*/
	virtual void setSelect(BOOL select) { isSelected = select; }	//객체가 선택됫는지보기위해서
	BOOL getSelect() const { return isSelected; }					//선택된지아는 BOOL변수 가져오는함수

protected:
	YObject_Type yType;		// 도형의 타입
	CRgn rgn;				// 도형의 리젼
	BOOL isExist;			// ???
	BOOL isSelected;		// 도형의 선택 여부
};
