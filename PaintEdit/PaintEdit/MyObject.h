#pragma once
#include <gdiplus.h>
using namespace Gdiplus;


// MyObject
typedef enum Object_Type{ default, rectangle, ellipse, line, polyline, text } Object_Type;

class MyObject : public CWnd
{
	DECLARE_DYNAMIC(MyObject)

public:
	MyObject();
	virtual ~MyObject();

	void SetColor(COLORREF c){ color = c; }
	COLORREF GetColor() const{ return color; }
	void SetThick(int th){ thick = th; }
	int GetThick() const{ return thick; }
	void SetBoundary();
	int GetBoundary();
	void SetObject_Type();
	int GetObject_Type();

	virtual void setpoint(int left, int top,int right,int bottom) = 0;
	virtual void move(int cx,int cy) = 0;
	virtual void draw(CDC* pDC) = 0;   //draw 함수 생각해보니 각 객체마다 다르게 그려져야되서 가상화 추가

protected:
	DECLARE_MESSAGE_MAP()
protected:
	int thick;		// 두께
	COLORREF color; // 색깔
	CPoint point_Start;   // 첫 클릭 시작점

	//friend class CPaineEditView;
};
