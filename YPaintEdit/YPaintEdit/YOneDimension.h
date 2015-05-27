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
protected:
	COLORREF lineColor;
	int lineThick;
	int linePattern;
};

