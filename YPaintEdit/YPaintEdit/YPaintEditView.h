// �� MFC ���� �ҽ� �ڵ�� MFC Microsoft Office Fluent ����� �������̽�("Fluent UI")�� 
// ����ϴ� ����� ���� �ָ�, MFC C++ ���̺귯�� ����Ʈ��� ���Ե� 
// Microsoft Foundation Classes Reference �� ���� ���� ������ ���� 
// �߰������� �����Ǵ� �����Դϴ�.  
// Fluent UI�� ����, ��� �Ǵ� �����ϴ� �� ���� ��� ����� ������ �����˴ϴ�.  
// Fluent UI ���̼��� ���α׷��� ���� �ڼ��� ������ 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// YPaintEditView.h : CYPaintEditView Ŭ������ �������̽�
//

#pragma once
#include "YObject.h"
#include "YOneDimension.h"
#include "YTwoDimension.h"
#include "YLine.h"
#include "YPolyLine.h"
#include "YRectangle.h"
#include "YEllipse.h"
#include "YText.h"


class CYPaintEditView : public CView
{
protected: // serialization������ ��������ϴ�.
	CYPaintEditView();
	DECLARE_DYNCREATE(CYPaintEditView)

// Ư���Դϴ�.
public:
	CYPaintEditDoc* GetDocument() const;

// �۾��Դϴ�.
public:
	CPoint	dx_sPoint;
// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CYPaintEditView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void MenuLineButton();
	afx_msg void MenuDefaultButton();
	afx_msg void MenuTextButton();
};

#ifndef _DEBUG  // YPaintEditView.cpp�� ����� ����
inline CYPaintEditDoc* CYPaintEditView::GetDocument() const
   { return reinterpret_cast<CYPaintEditDoc*>(m_pDocument); }
#endif

