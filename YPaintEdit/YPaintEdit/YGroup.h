#pragma once
#include "YObject.h"
class YGroup : public YObject
{
public:
	YGroup();
	YGroup(CList<YObject*, YObject*>& list);
	~YGroup();

	// Virtual
	void setType(YObject_Type t) { yType = t; }					// ��ü�� Ÿ���� �ؽ�Ʈ Ÿ������ �����ϴ� �Լ�
	void moveAll(int s, int e);									// �ؽ�Ʈ ��ü�� �̵���Ű�� �Լ�
	void deleteAll();											// �ؽ�Ʈ ��ü�� �����ϴ� �Լ�
	void draw(CDC* dc);											// �ؽ�Ʈ ��ü�� �׸��� �Լ�

	virtual void setRgn();										// ������ �����ϴ� �Լ�
	BOOL checkRgn(CPoint point);								// ��ǥ�� �����ȿ� �����ϴ��� Ȯ���ϴ� �Լ�
	void setSelect(BOOL select) { isSelected = select; }		// ��ü�� ���õǾ����� ��Ÿ���� �Լ�

	void setSPoint(CPoint point) { sPoint = point; }			// �׷��� ����,���� ���� �����ϴ� �Լ�
	void setEPoint(CPoint point) { ePoint = point; }			// �׷��� ������,�Ʒ��� ���� �����ϴ� �Լ�
	CPoint getSPoint() { return sPoint; }						// �׷��� ����,���� ���� ��� �Լ�
	CPoint getEPoint() { return ePoint; }						// �׷��� ������,�Ʒ��� ���� ��� �Լ�

	//
	CList<YObject*, YObject*>* getList(){ return &groupList; }
private:
	CList<YObject*, YObject*> groupList;
	CPoint sPoint;
	CPoint ePoint;
};

