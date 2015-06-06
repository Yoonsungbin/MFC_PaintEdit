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

	virtual void setRgn();				//리젼설정
	BOOL virtual checkRgn(CPoint point);	//리젼안에 있는지검사

	CRect* getMRect(){ return mRect; }	//점의 리젼 참조하기 위해서
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
	CRect rect;  //영역 그릴 사격형 매개변수
	BOOL drawingPolyLine;  //폴리라인 다음으로 이어질 직선을 계속 보여주고 있다. 불리언변수를 통해 마지막 노드의 다음직선을 안보이게한다.(마지막 더블클릭 떄문에 발생하는 문제같다)
	int index; //이동할 위치의 좌표를 가리키는 인덱스
	int moveMode;  //0 -> 전체이동 1-> 점하나이동
};

