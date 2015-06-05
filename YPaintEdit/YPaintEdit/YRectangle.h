#pragma once
#include "YTwoDimension.h"
class YRectangle :
	public YTwoDimension
{
public:
	YRectangle();
	YRectangle(CPoint start, CPoint end,int color, int thick, int pattern,int inColor);
	~YRectangle();


	void moveAll(int s, int e);
	void deleteAll();
	void draw(CDC*);

	void move(int s, int e);
	void changeLineColor();

	void setRgn();
	BOOL checkRgn(CPoint point);

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




private:
	CRect rect;
	CPoint sPoint;
	CPoint ePoint;
	CPoint mixPoint;
	CRect mRect[4]; //���� ���׶�� �׸������� 

	int moveMode; //������ ���� �� ��� �̵���Ű���� Ȯ���ϴ°�
};

