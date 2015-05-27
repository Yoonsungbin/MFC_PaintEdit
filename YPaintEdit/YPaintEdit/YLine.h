#pragma once
#include "YOneDimension.h"
class YLine :
	public YOneDimension
{
public:
	YLine();
	YLine(CPoint start, CPoint end);
	~YLine();
	virtual void moveAll(int s, int e);
	virtual void deleteAll();
	virtual void draw(CDC* cPC);

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

private:
	CPoint sPoint;
	CPoint ePoint;
};

