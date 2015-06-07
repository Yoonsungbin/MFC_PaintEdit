#include "stdafx.h"
#include "YGroup.h"


YGroup::YGroup()
{
}

YGroup::~YGroup()
{
}

YGroup::YGroup(CList<YObject*, YObject*>& list){

	// 그룹 리스트 초기화
	YObject* tmp;
	POSITION pos = list.GetHeadPosition();
	while (pos){
		tmp = list.GetNext(pos);
		tmp->setSelect(FALSE);
		groupList.AddTail(tmp);
	}

	// 리젼 사각형을 위한 좌표값 생성
	sPoint.SetPoint(10000, 10000);
	ePoint.SetPoint(0, 0);
	CRect rec;
	pos = groupList.GetHeadPosition();
	while (pos){
		tmp = groupList.GetNext(pos);
		rec = tmp->getORect();
		if (sPoint.x > rec.TopLeft().x) sPoint.x = rec.TopLeft().x;
		if (sPoint.y > rec.TopLeft().y) sPoint.y = rec.TopLeft().y;
		if (ePoint.x < rec.BottomRight().x) ePoint.x = rec.BottomRight().x;
		if (ePoint.y < rec.BottomRight().y) ePoint.y = rec.BottomRight().y;
	}
}


// Virtual
void YGroup::moveAll(int s, int e){
	YObject* tmp;
	POSITION pos = groupList.GetHeadPosition();
	while (pos){
		tmp = groupList.GetNext(pos);
		tmp->moveAll(s,e);
		tmp->setRgn();
	}
	sPoint.x += s;
	sPoint.y += e;
	ePoint.x += s;
	ePoint.y += e;
	setRgn();
}
void YGroup::deleteAll(){

}
void YGroup::draw(CDC* dc){
	if (isSelected == TRUE){
		CPen pen(PS_DOT, 1, RGB(0, 0, 0));
		dc->SelectObject(pen);
		//CBrush brush;
		//brush.CreateStockObject(NULL_BRUSH);
		dc->SelectStockObject(NULL_BRUSH);
		dc->Rectangle(sPoint.x, sPoint.y, ePoint.x, ePoint.y);
	}
	YObject* tmp;
	POSITION pos = groupList.GetHeadPosition();
	while (pos){
		tmp = groupList.GetNext(pos);
		tmp->draw(dc);
	}
}
void YGroup::setRgn(){
	// 리젼 사각형 생성
	setORect(sPoint.x, sPoint.y, ePoint.x, ePoint.y);
	// 리젼 생성
	rgn.DeleteObject();
	rgn.CreateRectRgn(sPoint.x, sPoint.y, ePoint.x, ePoint.y);
}
BOOL YGroup::checkRgn(CPoint point)
{
	if (rgn.PtInRegion(point))
		return TRUE;

	return FALSE;
}