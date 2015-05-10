#pragma once


// MyObject
typedef enum Object_Type{ default, rectangle, ellipse, line, polyline, text } Object_Type;

class MyObject : public CWnd
{
	DECLARE_DYNAMIC(MyObject)

public:
	MyObject();
	virtual ~MyObject();

	void SetColor();
	COLORREF GetColor();
	void SetThick();
	int GetThick();
	void SetBoundary();
	int GetBoundary();
	void SetObject_Type();
	int GetObject_Type();

	virtual void set() = 0;
	virtual void move() = 0;
	virtual void draw() = 0;

protected:
	DECLARE_MESSAGE_MAP()
protected:
	int thick;		// 두께
	COLORREF color; // 색깔
	CPoint point;   // 첫 클릭 시작점
};


