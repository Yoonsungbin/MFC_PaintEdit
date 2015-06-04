#pragma once
#include "YTwoDimension.h"
class YRectangle :
	public YTwoDimension
{
public:
	YRectangle();
	YRectangle(CPoint start, CPoint end,int color, int thick, int pattern);
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
	CPoint getEPoint(){ return ePoint; }

	CRect* getMRect(){ return mRect; }


	void setSelect(BOOL select) { isSelected = select; }
	void setMoveMode(int val){ moveMode = val; }
	int getMoveMode(){ return moveMode; }



	void drawCircle(CDC *pDC);// ���� ���� ���ý� �� ����� �Ҷ��!!


private:
	CRect rect;
	CPoint sPoint;
	CPoint ePoint;
	CRect mRect[2]; //���� ���׶�� �׸������� 

	int moveMode; //������ ���� �� ��� �̵���Ű���� Ȯ���ϴ°�
};

