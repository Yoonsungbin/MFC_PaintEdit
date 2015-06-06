#pragma once
#include "YOneDimension.h"
class YPolyLine :
	public YOneDimension
{
public:
	YPolyLine();
	YPolyLine(int color, int thick, int pattern);
	~YPolyLine();

	virtual void moveAll(int s, int e);
	virtual void deleteAll();
	virtual void draw(CDC* pDC);

	virtual void move(int s, int e);

	virtual void setRgn();				//��������
	BOOL virtual checkRgn(CPoint point);	//�����ȿ� �ִ����˻�

	CRect* getMRect(){ return mRect; }	//���� ���� �����ϱ� ���ؼ�
	//void setMRect(int i, CPoint rect){ mRect[i].SetRect(rect.x-15,rect.y-15,rect.x+15,rect.y+15); }
	

	void setEPoint(CPoint point) { ePoint = point; }
	CPoint getEPoint(){ return ePoint; }
	void addPoint(CPoint point);

	CList<CPoint, CPoint&>* getPolyList(){ return &polyList; }

	void setDrawPolyLine(BOOL a){ drawingPolyLine = a; }
	BOOL getDrawPolyLine(){ return drawingPolyLine; }

	void setIndex(int a){ index = a; }
	int getIndex(){ return index; }

	void setMoveMode(int a){ moveMode = a; }
	int getMoveMode(){ return moveMode; }
private:
	CList<CPoint, CPoint&> polyList;
	CRect mRect[100];
	CPoint ePoint;
	CRect rect;  //���� �׸� ����� �Ű�����
	BOOL drawingPolyLine;  //�������� �������� �̾��� ������ ��� �����ְ� �ִ�. �Ҹ��𺯼��� ���� ������ ����� ���������� �Ⱥ��̰��Ѵ�.(������ ����Ŭ�� ������ �߻��ϴ� ��������)
	int index; //�̵��� ��ġ�� ��ǥ�� ����Ű�� �ε���
	int moveMode;  //0 -> ��ü�̵� 1-> ���ϳ��̵�
};

