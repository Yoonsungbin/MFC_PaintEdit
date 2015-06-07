#include "stdafx.h"
#include "YGroup.h"


YGroup::YGroup()
{
}


YGroup::~YGroup()
{
}

YGroup::YGroup(CList<YObject*, YObject*>& list){

	// �׷� ����Ʈ �ʱ�ȭ
	YObject* tmp;
	POSITION pos = list.GetHeadPosition();
	while (pos){
		tmp = list.GetNext(pos);
		tmp->setSelect(FALSE);
		groupList.AddTail(tmp);
	}

	// ���� �簢���� ���� ��ǥ�� ����
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

	// ���� ����
	YGroup::setRgn();
}

// Virtual
void YGroup::moveAll(int s, int e){
	YObject* tmp;
	POSITION pos = groupList.GetHeadPosition();
	while (pos){
		tmp = groupList.GetNext(pos);
		tmp->moveAll(s,e);
	}
}
void YGroup::deleteAll(){

}
void YGroup::draw(CDC* dc){
	if (isSelected == TRUE){
		CPen pen(PS_DOT, 1, RGB(0, 0, 0));
		dc->SelectObject(pen);
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
	// ���� �簢�� ����
	YObject::setORect(sPoint.x, sPoint.y, ePoint.x, ePoint.y);
	// ���� ����
	rgn.DeleteObject();
	rgn.CreateRectRgn(sPoint.x-1, sPoint.y-1, ePoint.x+1, ePoint.y+1);
}
BOOL YGroup::checkRgn(CPoint point)
{
	if (rgn.PtInRegion(point))
		return TRUE;

	return FALSE;
}