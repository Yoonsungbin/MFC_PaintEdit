#pragma once
#include "YTwoDimension.h"
class YRectangle :
	public YTwoDimension
{
public:
	YRectangle();
	YRectangle(CPoint start, CPoint end);
	~YRectangle();


	virtual void moveAll();
	virtual void deleteAll();
	virtual void draw(CDC*);

	virtual void move();
	virtual void changeLineColor();

	virtual void setRgn();
	BOOL virtual checkRgn(CPoint point);

	virtual void setSPoint(CPoint point){
		sPoint = point;
	}
	virtual CPoint getSPoint(){ return sPoint; }
	virtual void setEPoint(CPoint point){
		ePoint = point;
	}
	virtual CPoint getEPoint(){ return ePoint; }

	virtual void drawRgn(CPoint point, CPoint point2);


	virtual void ChangeinColor();
	virtual void ChangeSize(); //크기변경


private:
	CRect rect;
	CPoint sPoint;
	CPoint ePoint;

};

