#pragma once
#include "YObject.h"
class YTwoDimension :public YObject
{
public:
	YTwoDimension();
	~YTwoDimension();

	void setLineColor(COLORREF c){ lineColor = c; }//선색
	COLORREF getLineColor() const{ return lineColor; }//선색



	void SetThick(int th){ lineThick = th; }//두께
	int GetThick() const{ return lineThick; }

	virtual void moveAll() = 0;//이동 myobject 상속
	virtual void deleteAll() = 0;//삭제 myobject 상속
	virtual void draw(CDC*) = 0;//그리기 myobject 상속

	virtual void ChangeinColor()=0;//내부색 변경
	virtual void ChangeSize() = 0; //크기변경

	virtual void setSPoint(CPoint point) = 0;//시작점
	virtual CPoint getSPoint() = 0;//시작점

	virtual void setEPoint(CPoint point) = 0;
	virtual CPoint getEPoint() = 0;//끝점

	virtual void drawRgn(CPoint point, CPoint point2) = 0;

	
protected:
	COLORREF lineColor;//선 색깔
	int lineThick;//선 두께
	int linePattern;//선 패턴


	COLORREF inColor; //내부 색깔
	int inPattern; //속 패턴

};

