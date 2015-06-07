#include "stdafx.h"
#include "YGroup.h"
#include "YLine.h"
#include "YPolyLine.h"
#include "YRectangle.h"
#include "YEllipse.h"
#include "YText.h"

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
}

void YGroup::move(int s, int e){
	if (getMoveMode() == -1){  //������ 2
		sPoint.x += s;
		sPoint.y += e;

		YObject* tmp;
		POSITION pos = groupList.GetHeadPosition();
		while (pos){
			tmp = groupList.GetNext(pos);
			if (tmp->getType() == line){
				YLine* pL = (YLine*)tmp;
				pL->setMoveMode(-1);
				pL->move(s,e);
			}
			else if (tmp->getType() == polyline){
				YPolyLine* pPL = (YPolyLine*)tmp;
				pPL->setMoveMode(-1);
				pPL->move(s, e);
			}
			else if (tmp->getType() == ellipse){
				YEllipse* pE = (YEllipse*)tmp;
				pE->setMoveMode(-1);
				pE->move(s, e);
			}
			else if (tmp->getType() == rectangle){
				YRectangle* pR = (YRectangle*)tmp;
				pR->setMoveMode(-1);
				pR->move(s, e);
			}
		}
	}

	else if (getMoveMode() == 1)//���� 4
	{
		ePoint.x += s;
		ePoint.y += e;

		YObject* tmp;
		POSITION pos = groupList.GetHeadPosition();
		while (pos){
			tmp = groupList.GetNext(pos);
			if (tmp->getType() == line){
				YLine* pL = (YLine*)tmp;
				pL->setMoveMode(1);
				pL->move(s, e);
			}
			else if (tmp->getType() == polyline){
				YPolyLine* pPL = (YPolyLine*)tmp;
				pPL->setMoveMode(1);
				pPL->move(s, e);
			}
			else if (tmp->getType() == ellipse){
				YEllipse* pE = (YEllipse*)tmp;
				pE->setMoveMode(1);
				pE->move(s, e);
			}
			else if (tmp->getType() == rectangle){
				YRectangle* pR = (YRectangle*)tmp;
				pR->setMoveMode(1);
				pR->move(s, e);
			}
		}
	}


	else if (getMoveMode() == 2)// 4
	{
		ePoint.x += s;
		sPoint.y += e;

		YObject* tmp;
		POSITION pos = groupList.GetHeadPosition();
		while (pos){
			tmp = groupList.GetNext(pos);

			if (tmp->getType() == ellipse){
				YEllipse* pE = (YEllipse*)tmp;
				pE->setMoveMode(3);
				pE->move(s, e);
			}
			else if (tmp->getType() == rectangle){
				YRectangle* pR = (YRectangle*)tmp;
				pR->setMoveMode(3);
				pR->move(s, e);
			}
		}
	}

	else if (getMoveMode() == 3)// 3
	{
		sPoint.x += s;
		ePoint.y += e;

		YObject* tmp;
		POSITION pos = groupList.GetHeadPosition();
		while (pos){
			tmp = groupList.GetNext(pos);

			if (tmp->getType() == ellipse){
				YEllipse* pE = (YEllipse*)tmp;
				pE->setMoveMode(2);
				pE->move(s, e);
			}
			else if (tmp->getType() == rectangle){
				YRectangle* pR = (YRectangle*)tmp;
				pR->setMoveMode(2);
				pR->move(s, e);
			}
		}
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

		CPen pen0(PS_DOT, 1, RGB(0, 0, 0));
		dc->SelectObject(pen0);
		dc->SelectStockObject(NULL_BRUSH);
		dc->Rectangle(sPoint.x, sPoint.y, ePoint.x, ePoint.y);
		
		//draw circle
		mRect[0].SetRect(sPoint.x - 10, sPoint.y - 10, sPoint.x + 10, sPoint.y + 10);
		mRect[1].SetRect(ePoint.x - 10, ePoint.y - 10, ePoint.x + 10, ePoint.y + 10);
		mRect[2].SetRect(ePoint.x - 10, sPoint.y - 10, ePoint.x + 10, sPoint.y + 10);
		mRect[3].SetRect(sPoint.x - 10, ePoint.y - 10, sPoint.x + 10, ePoint.y + 10);

		CPen* oldPen;
		CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
		oldPen = dc->SelectObject(&pen);
		dc->SelectStockObject(WHITE_BRUSH);
		dc->Ellipse(mRect[0]);
		dc->Ellipse(mRect[1]);
		dc->Ellipse(mRect[2]);
		dc->Ellipse(mRect[3]);

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
	setORect(sPoint.x, sPoint.y, ePoint.x, ePoint.y);
	// ���� ����
	rgn.DeleteObject();
	rgn.CreateRectRgn(sPoint.x, sPoint.y, ePoint.x, ePoint.y);
}
BOOL YGroup::checkRgn(CPoint point)
{
	if (rgn.PtInRegion(point))
		return TRUE;

	return FALSE;
}