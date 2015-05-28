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
	//void setMRect(int i, CPoint rect){ mRect[i].SetRect(rect.x-15,rect.y-15,rect.x+15,rect.y+15); }
	void drawCircle(CDC *pDC);	//Ŭ���� �� ���������ϰ� �׸��� �Լ�
	

	void setEPoint(CPoint point) { ePoint = point; }
	CPoint getEPoint(){ return ePoint; }
	void addPoint(CPoint point);

	CList<CPoint, CPoint&>* getPolyList(){ return &polyList; }

	void setDrawPolyLine(BOOL a){ drawingPolyLine = a; }
	BOOL getDrawPolyLine(){ return drawingPolyLine; }

	void setIndex(int a){ index = a; }
	int getIndex(){ return index; }

	void setMoveSetting(int a){ moveSetting = a; }
	int getMoveSetting(){ return moveSetting; }
private:
	CList<CPoint, CPoint&> polyList;
	CRect mRect[100];
	CPoint ePoint;
	CRect rect;  //���� �׸� ����� �Ű�����
	BOOL drawingPolyLine;  //�������� �������� �̾��� ������ ��� �����ְ� �ִ�. �Ҹ��𺯼��� ���� ������ ����� ���������� �Ⱥ��̰��Ѵ�.(������ ����Ŭ�� ������ �߻��ϴ� ��������)
	int index; //�̵��� ��ġ�� ��ǥ�� ����Ű�� �ε���
	int moveSetting;  //0 -> ��ü�̵� 1-> ���ϳ��̵�
};

