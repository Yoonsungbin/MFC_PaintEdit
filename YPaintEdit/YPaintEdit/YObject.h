#pragma once
#include "afx.h"
#include <gdiplus.h>

using namespace Gdiplus;

typedef enum Object_Type{ choice, rectangle, ellipse, line, polyline, text, default } YObject_Type;

class YObject : public CObject
{
public:
	YObject();
	~YObject();
	
	YObject(const YObject &s){ *this = s; }							// ???
	YObject& operator=(const YObject &s) { return *this; }			// ???

	virtual void setType(YObject_Type t){ yType = t; }				// ��ü�� Ÿ�� �����ϴ� �Լ�
	YObject_Type getType(){ return yType; }							// ��ü�� Ÿ�� �������� �Լ�

	virtual void moveAll(int s, int e) = 0;							// ��ü�� �̵���Ű�� �Լ�
	virtual void deleteAll() = 0;									// ��ü�� ����Ʈ���� �����ϴ� �Լ�
	virtual void draw(CDC*) = 0;									// ��ü�� �׸��� �Լ�
	
	/*
	������ ����� rgn�� �����ؾ��ϴµ� ������ �������� �������� rgn �� ������. rgn.create�� setrgb�����ϴ°� ���� �˼���������
	�� ���� ������ ������ getrgn���� �����ͼ� ��ȯ���� crgn������ �׺��������� checkrgn�Լ�����  PtInRegion �޼ҵ带 ���� �����ȿ� �ִ��� �Ǻ�
	*/
	virtual void setRgn() = 0;										// ������ �����ϴ� �Լ�
	CRgn* getRgn(){ return &rgn; }									// ������ �������� �Լ�
	virtual BOOL checkRgn(CPoint point) { return FALSE; }			// ��ǥ�� �����ȿ� �����ϴ��� Ȯ���ϴ� �Լ�

	/*
	������ �׸��� �̹� ���õǾ� �ִ� ������ �����ؾ��ϰ� ���� �ȵ� ������ ������ �׷������ �׷��� ������ ���õǾ��ִ���(������ ���̴���) �ƴ����� �˱�����
	�޼ҵ尡 �ʿ�
	*/
	virtual void setSelect(BOOL select) { isSelected = select; }	//��ü�� ���õ̴����������ؼ�
	BOOL getSelect() const { return isSelected; }					//���õ����ƴ� BOOL���� ���������Լ�

protected:
	YObject_Type yType;		// ������ Ÿ��
	CRgn rgn;				// ������ ����
	BOOL isExist;			// ???
	BOOL isSelected;		// ������ ���� ����
};
