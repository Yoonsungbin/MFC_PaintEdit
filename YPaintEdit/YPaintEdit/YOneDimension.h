#pragma once
#include "YObject.h"
class YOneDimension :public YObject
{
	DECLARE_SERIAL(YOneDimension);
public:
	YOneDimension();
	~YOneDimension();

	virtual void moveAll(int s, int e){};							// ��ü�� �̵���Ű�� �Լ�
	virtual void deleteAll(){};									// ��ü�� ����Ʈ���� �����ϴ� �Լ�
	virtual void draw(CDC*){};									// ��ü�� �׸��� �Լ�

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

