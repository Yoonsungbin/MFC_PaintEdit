#pragma once
#include "YObject.h"
class YOneDimension :public YObject
{
public:
	YOneDimension();
	~YOneDimension();

	void setLineColor(COLORREF c){ lineColor = c; }
	COLORREF getLineColor() const{ return lineColor; }

	void SetLineThick(int th){ lineThick = th; }
	int GetLineThick() const{ return lineThick; }

	void SetLinePattern(int pa){ linePattern = pa; }
	int GetLinePattern() const{ return linePattern; }

	virtual void moveAll(int s, int e) = 0;
	virtual void move() =0;
	virtual void deleteAll() = 0;
	virtual void draw(CDC*) = 0;

	virtual void setSPoint(CPoint point) = 0;
	virtual CPoint getSPoint() = 0;

	virtual void setEPoint(CPoint point) = 0;
	virtual CPoint getEPoint() = 0;

protected:
	COLORREF lineColor;
	int lineThick;
	int linePattern;
};

