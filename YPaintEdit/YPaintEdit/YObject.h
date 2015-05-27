#pragma once
#include "afx.h"
#include <gdiplus.h>	//gdi++

using namespace Gdiplus;	//gdi++

typedef enum Object_Type{ choice, rectangle, ellipse, line, polyline, text } YObject_Type;

class YObject : public CObject
{
public:
	YObject();
	~YObject();
	
	virtual void setType(YObject_Type t){ yType = t; }  //타입설정하는함수
	YObject_Type* getType(){ return &yType; }			//타입가져오는함수

	YObject(const YObject &s){ *this = s; }
	YObject& operator=(const YObject &s) { return *this; }

	virtual void moveAll(int s, int e) = 0;
	virtual void deleteAll() = 0;
	virtual void draw(CDC*) = 0;
	
	/*
	도형을 만들면 rgn을 설정해야하는데 도형의 시작점과 끝점으로 rgn 을 생성함. rgn.create를 setrgb에서하는거 보면 알수있을꺼임
	그 다음 생성된 리젼은 getrgn으로 가져와서 반환값이 crgn변수임 그변수를통해 checkrgn함수에서  PtInRegion 메소드를 통해 리젼안에 있는지 판별
	*/
	virtual void setRgn() = 0; //리젼 시작점 끝점으로 생성
	CRgn* getRgn(){ return &rgn; }  //리젼가져오는 함수
	virtual BOOL checkRgn(CPoint point) { return FALSE; }  //리젼에 있는지 확인하는 함수

	/*
	리젼을 그릴때 이미 선택되어 있는 리젼은 제거해야하고 선택 안된 리젼은 리젼을 그려줘야함 그래서 리젼이 선택되어있는지(점선이 보이는지) 아닌지를 알기위한
	메소드가 필요
	*/
	virtual void setSelect(BOOL select) { isSelected = select; }  //객체가 선택됫는지보기위해서
	BOOL getSelect()const { return isSelected; }		//선택된지아는 BOOL변수 가져오는함수


	/*
	시작점 끝점 설정
	*/
	virtual void setSPoint(CPoint point) = 0;	//시작점 설정
	virtual CPoint getSPoint() = 0;

	/*
	끝점은 도형을 변할때마다 리젼을 새로그려야하는데 그때마다 도형의 끝점을 알기위해 선언
	*/
	virtual void setEPoint(CPoint point) = 0;		//끝점설정
	virtual CPoint getEPoint() = 0;
	
protected:
	YObject_Type yType;  //타입
	CRgn rgn; //리젼
	BOOL isExist; // 리젼안에 있는지 판별
	BOOL isSelected;  //선택된지 안된지 보기위해서
};

