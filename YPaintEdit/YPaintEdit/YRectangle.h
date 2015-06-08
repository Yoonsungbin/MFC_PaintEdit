#pragma once
#include "YTwoDimension.h"
class YRectangle :public YTwoDimension
{
	DECLARE_SERIAL(YRectangle);
public:
	YRectangle();
	YRectangle(CPoint start, CPoint end, int color, int thick, int pattern, int inColor, int sidepattern, BOOL patternFlag);
	~YRectangle();


	void moveAll(int s, int e);
	void deleteAll();
	void draw(CDC*);

	void move(int s, int e);

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

	virtual void Serialize(CArchive& ar);
private:
	CRect rect;
	CPoint sPoint;
	CPoint ePoint;
	CPoint mixPoint;
	CRect mRect[4]; //끝점 동그라미 그리기위한 

	int moveMode; //시작점 끝점 중 어떤거 이동시키는지 확인하는거
};

