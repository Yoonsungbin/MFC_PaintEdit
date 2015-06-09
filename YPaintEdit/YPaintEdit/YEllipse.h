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
	CRect mRect[4]; //끝점 동그라미 그리기위한 

	int moveMode; //시작점 끝점 중 어떤거 이동시키는지 확인하는거
	/*
	BOOL drawingPolyLine;  //폴리라인 다음으로 이어질 직선을 계속 보여주고 있다. 불리언변수를 통해 마지막 노드의 다음직선을 안보이게한다.(마지막 더블클릭 떄문에 발생하는 문제같다)
	int index; //이동할 위치의 좌표를 가리키는 인덱스
	int moveMode;  //0 -> 전체이동 1-> 점하나이동
	*/

};

