#pragma once
#include "YObject.h"
class YOneDimension :public YObject
{
	DECLARE_SERIAL(YOneDimension);
public:
	YOneDimension();
	~YOneDimension();

	virtual void moveAll(int s, int e){};							// 객체를 이동시키는 함수
	virtual void deleteAll(){};									// 객체를 리스트에서 삭제하는 함수
	virtual void draw(CDC*){};									// 객체를 그리는 함수

	virtual void setRgn(){};


	void setLineColor(COLORREF c){ lineColor = c; }
	COLORREF getLineColor() const{ return lineColor; }

	void setLineThick(int th){ lineThick = th; }
	int getLineThick() const{ return lineThick; }

	void setLinePattern(int pa){ linePattern = pa; }
	int getLinePattern() const{ return linePattern; }
	virtual void Serialize(CArchive& ar);
private:
	COLORREF lineColor;
	int lineThick;
	int linePattern;
};

