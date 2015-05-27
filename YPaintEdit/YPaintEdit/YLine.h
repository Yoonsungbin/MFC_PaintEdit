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

	 void setSPoint(CPoint point){
		sPoint = point;
	}
	 CPoint getSPoint(){ return sPoint; }

	 void setEPoint(CPoint point){
		ePoint = point;
	}
	 CPoint getEPoint(){ return ePoint; }
	 
	 CRect* getmRect(){ return mRect; }

private:
	CPoint sPoint;
	CPoint ePoint;
	CRect mRect[2];
};

