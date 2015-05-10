
// PaintEditView.h : CPaintEditView Ŭ������ �������̽�
//
#include "MyObject.h"
#pragma once


class CPaintEditView : public CView
{
public:
	Object_Type type;
protected: // serialization������ ��������ϴ�.
	CPaintEditView();
	DECLARE_DYNCREATE(CPaintEditView)

// Ư���Դϴ�.
public:
	CPaintEditDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CPaintEditView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // PaintEditView.cpp�� ����� ����
inline CPaintEditDoc* CPaintEditView::GetDocument() const
   { return reinterpret_cast<CPaintEditDoc*>(m_pDocument); }
#endif

