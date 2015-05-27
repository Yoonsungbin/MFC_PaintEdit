#pragma once
#include "afx.h"
#include <gdiplus.h>	//gdi++

using namespace Gdiplus;	//gdi++

typedef enum Object_Type{ choice, rectangle, ellipse, line, polyline, text } YObject_Type;

class YObject : public CObject
{
public:
	YObject();
	~YObject();
	
	virtual void setType(YObject_Type t){ yType = t; }  //Ÿ�Լ����ϴ��Լ�
	YObject_Type* getType(){ return &yType; }			//Ÿ�԰��������Լ�

	YObject(const YObject &s){ *this = s; }
	YObject& operator=(const YObject &s) { return *this; }

	virtual void moveAll(int s, int e) = 0;
	virtual void deleteAll() = 0;
	virtual void draw(CDC*) = 0;
	
	/*
	������ ����� rgn�� �����ؾ��ϴµ� ������ �������� �������� rgn �� ������. rgn.create�� setrgb�����ϴ°� ���� �˼���������
	�� ���� ������ ������ getrgn���� �����ͼ� ��ȯ���� crgn������ �׺��������� checkrgn�Լ�����  PtInRegion �޼ҵ带 ���� �����ȿ� �ִ��� �Ǻ�
	*/
	virtual void setRgn() = 0; //���� ������ �������� ����
	CRgn* getRgn(){ return &rgn; }  //������������ �Լ�
	virtual BOOL checkRgn(CPoint point) { return FALSE; }  //������ �ִ��� Ȯ���ϴ� �Լ�

	/*
	������ �׸��� �̹� ���õǾ� �ִ� ������ �����ؾ��ϰ� ���� �ȵ� ������ ������ �׷������ �׷��� ������ ���õǾ��ִ���(������ ���̴���) �ƴ����� �˱�����
	�޼ҵ尡 �ʿ�
	*/
	virtual void setSelect(BOOL select) { isSelected = select; }  //��ü�� ���õ̴����������ؼ�
	BOOL getSelect()const { return isSelected; }		//���õ����ƴ� BOOL���� ���������Լ�


	/*
	������ ���� ����
	*/
	virtual void setSPoint(CPoint point) = 0;	//������ ����
	virtual CPoint getSPoint() = 0;

	/*
	������ ������ ���Ҷ����� ������ ���α׷����ϴµ� �׶����� ������ ������ �˱����� ����
	*/
	virtual void setEPoint(CPoint point) = 0;		//��������
	virtual CPoint getEPoint() = 0;
	
protected:
	YObject_Type yType;  //Ÿ��
	CRgn rgn; //����
	BOOL isExist; // �����ȿ� �ִ��� �Ǻ�
	BOOL isSelected;  //���õ��� �ȵ��� �������ؼ�
};

