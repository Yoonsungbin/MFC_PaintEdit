#pragma once
#include "YOneDimension.h"
class YLine :
	public YOneDimension
{
public:
	YLine();
	YLine(CPoint start, CPoint end);
	~YLine();
	virtual void moveAll();
	virtual void deleteAll();
	virtual void draw(CDC* cPC);

	virtual void move();
	virtual void changeLineColor();
	
	virtual void setRgn();
	BOOL virtual checkRgn(CPoint point);

	//void setNPoint(CPoint point){nPoint = point;}
	void setPoint(CPoint point){ ePoint = point; }

private:
	CRect rect;
	CPoint sPoint;
	CPoint ePoint;
	//CPoint nPoint;
};

