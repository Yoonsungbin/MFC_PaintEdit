#pragma once
#include "YObject.h"
class YTwoDimension :public YObject
{
public:
	YTwoDimension();
	~YTwoDimension();

	void setLineColor(COLORREF c){ lineColor = c; }//����
	COLORREF getLineColor() const{ return lineColor; }//����

	void setLineThick(int th){ lineThick = th; }//�β�
	int getLineThick() const{ return lineThick; }

	void setLinePattern(int pa){ linePattern = pa; }
	int getLinePattern() const{ return linePattern; }

	void ChangeinColor(COLORREF c){ inColor = c; };//���λ� ����
	COLORREF getinColor() const{ return inColor; }//���λ�



private:
	COLORREF lineColor;//�� ����
	int lineThick;//�� �β�
	int linePattern;//�� ����


	COLORREF inColor; //���� ����
	int inPattern; //�� ����

};

