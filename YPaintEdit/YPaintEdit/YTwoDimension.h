#pragma once
#include "YObject.h"
class YTwoDimension :public YObject
{
public:
	YTwoDimension();
	~YTwoDimension();

	void setLineColor(COLORREF c){ lineColor = c; }//선색
	COLORREF getLineColor() const{ return lineColor; }//선색

	void setLineThick(int th){ lineThick = th; }//두께
	int getLineThick() const{ return lineThick; }

	void setLinePattern(int pa){ linePattern = pa; }
	int getLinePattern() const{ return linePattern; }

	void setSideColor(COLORREF c){ sideColor = c; };//내부색 변경
	COLORREF getSideColor() const{ return sideColor; }//내부색


	void setSidePattern(int pa){ sidePattern = pa; }   //면 패턴
	int getSidePattern() const{ return sidePattern; }////면 패턴



private:
	COLORREF lineColor;//선 색깔
	int lineThick;//선 두께
	int linePattern;//선 패턴


	COLORREF sideColor; //내부 색깔
	//int inPattern; //속 패턴
	int sidePattern;

};

