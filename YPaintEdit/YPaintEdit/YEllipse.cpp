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
void YEllipse::setRgn(){

}

//�����ȿ� �ִ��� �˻��ϴ��Լ�
BOOL YEllipse::checkRgn(CPoint point)
{

	return FALSE;
}

void YEllipse::drawRgn(CPoint point, CPoint point2){

	rect.SetRect(point.x, point.y, point2.x, point2.y);  //�簢������
}