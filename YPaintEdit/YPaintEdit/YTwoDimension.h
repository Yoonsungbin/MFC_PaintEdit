#pragma once
#include "YObject.h"
class YTwoDimension :public YObject
{
public:
	YTwoDimension();
	~YTwoDimension();

	void setLineColor(COLORREF c){ lineColor = c; }//����
	COLORREF getLineColor() const{ return lineColor; }//����



	void SetThick(int th){ lineThick = th; }//�β�
	int GetThick() const{ return lineThick; }

	virtual void moveAll() = 0;//�̵� myobject ���
	virtual void deleteAll() = 0;//���� myobject ���
	virtual void draw(CDC*) = 0;//�׸��� myobject ���

	virtual void ChangeinColor()=0;//���λ� ����
	virtual void ChangeSize() = 0; //ũ�⺯��

	virtual void setSPoint(CPoint point) = 0;//������
	virtual CPoint getSPoint() = 0;//������

	virtual void setEPoint(CPoint point) = 0;
	virtual CPoint getEPoint() = 0;//����

	virtual void drawRgn(CPoint point, CPoint point2) = 0;

	
protected:
	COLORREF lineColor;//�� ����
	int lineThick;//�� �β�
	int linePattern;//�� ����


	COLORREF inColor; //���� ����
	int inPattern; //�� ����

};

