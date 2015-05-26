#pragma once
#include "YTwoDimension.h"
class YEllipse :public YTwoDimension
{
public:
	YEllipse();
	YEllipse(CPoint start, CPoint end);
	~YEllipse();


	void setType(YObject_Type t){ yType = t; }
	void moveAll(int s, int e) ;
	void deleteAll() ;
	void draw(CDC*) ;

	void move();
	void changeLineColor();

	void setRgn();
	BOOL  checkRgn(CPoint point);

	void setSPoint(CPoint point){
		sPoint = point;
	}
	CPoint getSPoint(){ return sPoint; }
	void setEPoint(CPoint point){
		ePoint = point;
	}
	CPoint getEPoint(){ return ePoint; }


	void setSelect(BOOL select) { isSelected = select; }



	void ChangeinColor();
	void ChangeSize(); //크기변경


private:
	CRect rect;
	CPoint sPoint;
	CPoint ePoint;

};

