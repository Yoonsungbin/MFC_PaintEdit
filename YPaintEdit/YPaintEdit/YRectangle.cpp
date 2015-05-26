#include "stdafx.h"
#include "YRectangle.h"


YRectangle::YRectangle()
{
}


YRectangle::~YRectangle()
{
	
}


YRectangle::YRectangle(CPoint start, CPoint end)
{
	sPoint = start;
	ePoint = end;
}


void YRectangle::moveAll()
{

}


void YRectangle::deleteAll(){
}


void YRectangle::draw(CDC* pDc)
{


}


void YRectangle::move(){

}

void YRectangle::changeLineColor(){

}


void  YRectangle::ChangeinColor()
{


}



void  YRectangle::ChangeSize()
{

}//크기변경


void YRectangle::setRgn(){

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
}




//리젼안에 있는지 검사하는함수
BOOL YRectangle::checkRgn(CPoint point)
{
	if (rgn.PtInRegion(point))
	{
		return TRUE;
	}
	return FALSE;
}

void YRectangle::drawRgn(CPoint point, CPoint point2){

	rect.SetRect(point.x, point.y, point2.x, point2.y);  //사각형설정
}

