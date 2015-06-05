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

	void setSideColor(COLORREF c){ sideColor = c; };//���λ� ����
	COLORREF getSideColor() const{ return sideColor; }//���λ�


	void setSidePattern(int pa){ sidePattern = pa; }   //�� ����
	int getSidePattern() const{ return sidePattern; }////�� ����



private:
	COLORREF lineColor;//�� ����
	int lineThick;//�� �β�
	int linePattern;//�� ����


	COLORREF sideColor; //���� ����
	//int inPattern; //�� ����
	int sidePattern;

};

