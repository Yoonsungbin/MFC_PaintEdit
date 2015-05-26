#include "stdafx.h"
#include "YEllipse.h"


YEllipse::YEllipse()
{
}


YEllipse::~YEllipse()
{
}



YEllipse::YEllipse(CPoint start, CPoint end)
{
	sPoint = start;
	ePoint = end;
}

void YEllipse::moveAll()
{

}


void YEllipse::deleteAll(){
}


void YEllipse::draw(CDC* pDc)
{


}


void YEllipse::move(){

}

void YEllipse::changeLineColor(){

}


void  YEllipse::ChangeinColor()
{


}



void  YEllipse::ChangeSize()
{

}//크기변경


void YEllipse::setRgn(){
	/*
	int left, top, right, bottom;
	//4 side rect divided
	if (sPoint.x < ePoint.x && sPoint.y < ePoint.y){  //1 -> 4 
		left = sPoint.x;
		top = sPoint.y;
		right = ePoint.x;
		bottom = ePoint.y;
	}
	else if (sPoint.x < ePoint.x && sPoint.y > ePoint.y){  // 3 -> 2
		left = sPoint.x;
		top = ePoint.y;
		right = ePoint.x;
		bottom = sPoint.y;
	}
	else if (sPoint.x > ePoint.x && sPoint.y < ePoint.y) { // 2 -> 3
		left = ePoint.x;
		top = sPoint.y;
		right = sPoint.x;
		bottom = ePoint.y;
	}
	else {  	// 4 -> 1
		left = ePoint.x;
		top = ePoint.y;
		right = sPoint.x;
		bottom = sPoint.y;
	}

	rgn.CreateRectRgn(left, top, right, bottom);
	*/
}




//리젼안에 있는지 검사하는함수
BOOL YEllipse::checkRgn(CPoint point)
{
	/*
	if (rgn.PtInRegion(point))
	{
		return TRUE;
	}
	*/
	return FALSE;
	
}


