#pragma once
#include "YObject.h"
class YGroup : public YObject
{
public:
	// Constructors, Destructor
	YGroup();
	YGroup(CList<YObject*, YObject*>& list);
	~YGroup();


	// Virtual
	void setType(YObject_Type t) { yType = t; }					// 객체의 타입을 텍스트 타입으로 설정하는 함수
	void moveAll(int s, int e);									// 텍스트 객체를 이동시키는 함수
	void deleteAll();											// 텍스트 객체를 삭제하는 함수
	void draw(CDC* dc);											// 텍스트 객체를 그리는 함수

	virtual void setRgn();										// 리젼을 생성하는 함수
	BOOL checkRgn(CPoint point);								// 좌표가 리젼안에 존재하는지 확인하는 함수
	void setSelect(BOOL select) { isSelected = select; }		// 객체가 선택되었음을 나타내는 함수


	// Mutator, Accessor
	CList<YObject*, YObject*>* getList(){ return &groupList; }
	void setSPoint(CPoint point) { sPoint = point; }			// 그룹의 왼쪽,위의 점을 설정하는 함수
	void setEPoint(CPoint point) { ePoint = point; }			// 그룹의 오른쪽,아래의 점을 설정하는 함수
	CPoint getSPoint() { return sPoint; }						// 그룹의 왼쪽,위의 점을 얻는 함수
	CPoint getEPoint() { return ePoint; }						// 그룹의 오른쪽,아래의 점을 얻는 함수
	CRect* getMRect(){ return mRect; }
	void setMoveMode(int val){ moveMode = val; }
	int getMoveMode(){ return moveMode; }
	CPoint getMixPoint(){ return mixPoint; }
	void setMixPoint(CPoint point){mixPoint = point;}


	//
	void move(int s, int e);


	// Variables
private:
	CList<YObject*, YObject*> groupList;
	CPoint sPoint;
	CPoint ePoint;
	CPoint mixPoint;
	CRect mRect[4];
	int moveMode;

};
