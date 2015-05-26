#pragma once
#include "YObject.h"
class YOneDimension :public YObject
{
public:
	YOneDimension();
	~YOneDimension();

	void setLineColor(COLORREF c){ lineColor = c; }
	COLORREF getLineColor() const{ return lineColor; }

	void SetThick(int th){ lineThick = th; }
	int GetThick() const{ return lineThick; }

	virtual void moveAll() = 0;
	virtual void deleteAll() = 0;
	virtual void draw(CDC*) = 0;
	virtual void setPoint(CPoint point) = 0;
protected:
	COLORREF lineColor;
	int lineThick;
	int LinePattern;
};

