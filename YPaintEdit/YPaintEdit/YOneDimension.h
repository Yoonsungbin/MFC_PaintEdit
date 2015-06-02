#pragma once
#include "YObject.h"
class YOneDimension :public YObject
{
public:
	YOneDimension();
	~YOneDimension();

	void setLineColor(COLORREF c){ lineColor = c; }
	COLORREF getLineColor() const{ return lineColor; }

	void setLineThick(int th){ lineThick = th; }
	int getLineThick() const{ return lineThick; }

	void setLinePattern(int pa){ linePattern = pa; }
	int getLinePattern() const{ return linePattern; }
private:
	COLORREF lineColor;
	int lineThick;
	int linePattern;
};

