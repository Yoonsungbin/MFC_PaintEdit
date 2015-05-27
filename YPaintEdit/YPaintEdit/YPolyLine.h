#pragma once
#include "YOneDimension.h"
class YPolyLine :
	public YOneDimension
{
public:
	YPolyLine();
	~YPolyLine();

	virtual void moveAll(int s, int e);
	virtual void deleteAll();
	virtual void draw(CDC* pDC);

	virtual void move(int s, int e);
	virtual void changeLineColor();

	virtual void setRgn();				//리젼설정
	BOOL virtual checkRgn(CPoint point);	//리젼안에 있는지검사

	CRect* getMRect(){ return mRect; }	//점의 리젼 참조하기 위해서

	void drawCircle(CDC *pDC);	//클릭한 점 리젼설정하고 그리는 함수
	
	void setMPoint(CPoint point) { mPoint = point; }
	CPoint getMPoint(){ return mPoint; }

	void addPoint(CPoint point);
private:
	CList<CPoint, CPoint&> polyList;
	CRect* mRect;
	CPoint mPoint;
};

