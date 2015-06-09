#pragma once
#include "YTwoDimension.h"

class YEllipse :public YTwoDimension
{
	DECLARE_SERIAL(YEllipse);
public:
	YEllipse();
	YEllipse(CPoint start, CPoint end, int color, int thick, int pattern, int inColor, int sidepattern, BOOL patternFlag);
	~YEllipse();

	YEllipse(YEllipse *p);

	//void setType(YObject_Type t){ yType = t; }
	void moveAll(int s, int e);
	void deleteAll();
	void draw(CDC*);

	void move(int s, int e);

	void setRgn();
	BOOL  checkRgn(CPoint point);

	void setSPoint(CPoint point){
		sPoint = point;
	}
	CPoint getSPoint(){ return sPoint; }

	void setEPoint(CPoint point){
		ePoint = point;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////
	CPoint getMixPoint(){ return mixPoint; }
	void setMixPoint(CPoint point){
		mixPoint = point;
	}
	////////////////////////////////////////////////////////////////////////////////////
	CPoint getEPoint(){ return ePoint; }
	CRect* getMRect(){ return mRect; }
	void setSelect(BOOL select) { isSelected = select; }
	void setMoveMode(int val){ moveMode = val; }
	int getMoveMode(){ return moveMode; }

	virtual void Serialize(CArchive& ar);

private:
	CRect rect;
	CPoint sPoint;
	CPoint ePoint;
	CPoint mixPoint;
	CRect mRect[4]; //���� ���׶�� �׸������� 

	int moveMode; //������ ���� �� ��� �̵���Ű���� Ȯ���ϴ°�
	/*
	BOOL drawingPolyLine;  //�������� �������� �̾��� ������ ��� �����ְ� �ִ�. �Ҹ��𺯼��� ���� ������ ����� ���������� �Ⱥ��̰��Ѵ�.(������ ����Ŭ�� ������ �߻��ϴ� ��������)
	int index; //�̵��� ��ġ�� ��ǥ�� ����Ű�� �ε���
	int moveMode;  //0 -> ��ü�̵� 1-> ���ϳ��̵�
	*/

};

