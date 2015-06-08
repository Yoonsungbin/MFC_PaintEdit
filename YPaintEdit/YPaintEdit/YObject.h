#pragma once
#include "afx.h"
#include <gdiplus.h>

using namespace Gdiplus;

typedef enum Object_Type{ choice, rectangle, ellipse, line, polyline, text, group, default } YObject_Type;

class YObject : public CObject
{
	DECLARE_SERIAL(YObject);
public:
	YObject();
	~YObject();
	
	//YObject(const YObject &s){ *this = s; }							// ???
	//YObject& operator=(const YObject &s) { return *this; }			// ???

	void setOrder(int num){ order = num; }							// ��ü�� ������ȣ�� �����ϴ� �Լ�
	int getOrder(){ return order; }									// ��ü�� ������ȣ�� �������� �Լ�

	void setORect(int x1, int y1, int x2, int y2)					// ��ü�� ���� �簢���� �����ϴ� �Լ�
		{ rect.SetRect(x1,y1,x2,y2); }
	CRect getORect(){ return rect; }								// ��ü�� ���� �簢���� �������� �Լ�


	virtual void setType(YObject_Type t){ yType = t; }				// ��ü�� Ÿ�� �����ϴ� �Լ�
	YObject_Type getType(){ return yType; }							// ��ü�� Ÿ�� �������� �Լ�

	virtual void moveAll(int s, int e) {};							// ��ü�� �̵���Ű�� �Լ�
	virtual void deleteAll(){};									// ��ü�� ����Ʈ���� �����ϴ� �Լ�
	virtual void draw(CDC*){};									// ��ü�� �׸��� �Լ�
	
	virtual void setRgn() {};										// ������ �����ϴ� �Լ�
	CRgn* getRgn(){ return &rgn; }									// ������ �������� �Լ�
	virtual BOOL checkRgn(CPoint point) { return FALSE; }			// ��ǥ�� �����ȿ� �����ϴ��� Ȯ���ϴ� �Լ�

	virtual void setSelect(BOOL select) { isSelected = select; }	//��ü�� ���õ̴����������ؼ�
	BOOL getSelect() const { return isSelected; }					//���õ����ƴ� BOOL���� ���������Լ�

	virtual void Serialize(CArchive& ar);

protected:
	YObject_Type yType;		// ������ Ÿ��
	CRgn rgn;				// ������ ����
	CRect rect;				// ������ ���� �簢��
	BOOL isSelected;		// ������ ���� ����
	int order;				// ������ ������ȣ
};
