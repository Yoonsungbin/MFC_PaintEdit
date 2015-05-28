#pragma once
#include "YOneDimension.h"
class YPolyLine :
	public YOneDimension
{
public:
	YPolyLine();
	~YPolyLine();

	virtual void moveAll(int s, int e);
	virtual void deleteAll();
	virtual void draw(CDC* pDC);

	virtual void move(int s, int e);
	virtual void changeLineColor();

	virtual void setRgn();				//��������
	BOOL virtual checkRgn(CPoint point);	//�����ȿ� �ִ����˻�

	CRect* getMRect(){ return mRect; }	//���� ���� �����ϱ� ���ؼ�

	void drawCircle(CDC *pDC);	//Ŭ���� �� ���������ϰ� �׸��� �Լ�
	

	void setEPoint(CPoint point) { ePoint = point; }
	CPoint getEPoint(){ return ePoint; }
	void addPoint(CPoint point);

	CList<CPoint, CPoint&>* getPolyList(){ return &polyList; }

private:
	CList<CPoint, CPoint&> polyList;
	CRect* mRect;
	CPoint ePoint;
	CRect rect;  //���� �׸� ����� �Ű�����
};

