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
#include "YFigureDialog.h"

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
	//�����޴� ��Ȱ��ȭ�� ���Ͽ�
	BOOL menu_Select;
	BOOL menu_Line;
	BOOL menu_PolyLine;
	BOOL menu_Ellipse;
	BOOL menu_Rectangle;
	BOOL menu_Text;

	//�˾��޴��� ��Ȱ��ȭ �ϱ� ���ؼ�
	BOOL menu_Color;
	BOOL menu_Figiure;
	BOOL menu_Delete;

	//�޴����� ���ϴ� ������ ������ ���� (�������� view��ü�� �Ӽ������� ������)
	COLORREF lineColor = RGB(0,0,0);													//������
	int lineThick = 1;																	//�β� : 1	
	int linePattern = 0;																// PS_SOLID
	COLORREF sideColor = RGB(255,255,255);												//���
	int sidePattern = NULL;																//HS_BDIAGONAL	
	BOOL sidePatternflag2=FALSE;
	int fontSize;
	int fontPattern;

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
	afx_msg void MenuEllipseButton();
	afx_msg void RMenuColorButton();
	afx_msg void FigureSettingButton();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void MenuPolyLineButton();
	afx_msg void OnDeleteClick();
	afx_msg void OnRectangleButton();
	afx_msg void UpdateMenuDefaultButton(CCmdUI *pCmdUI);
	afx_msg void UpdateMenuLineButton(CCmdUI *pCmdUI);
	afx_msg void UpdateMenuPolyLineButton(CCmdUI *pCmdUI);
	afx_msg void UpdateOnRectangleButton(CCmdUI *pCmdUI);
	afx_msg void UpdateMenuEllipseButton(CCmdUI *pCmdUI);
	afx_msg void UpdateMenuTextButton(CCmdUI *pCmdUI);
	afx_msg void UpdateOnDeleteClick(CCmdUI *pCmdUI);
	afx_msg void UpdateFigureSettingButton(CCmdUI *pCmdUI);
	afx_msg void UpdateRMenuColorButton(CCmdUI *pCmdUI);
	afx_msg void DeletePointButton();
	afx_msg void UpdateDeletePointButton(CCmdUI *pCmdUI);
	afx_msg void RMenuInColorButton();
	void Paint(CDC* dc);
	afx_msg void OnMenulinethick();
	afx_msg void OnMenulinecolor();
	afx_msg void OnMenulinepattern();
	afx_msg void OnMenusidepattern();//������
	afx_msg void OnMenusidecolor();
	afx_msg void OnUpdateMenusidepattern(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // YPaintEditView.cpp�� ����� ����
inline CYPaintEditDoc* CYPaintEditView::GetDocument() const
   { return reinterpret_cast<CYPaintEditDoc*>(m_pDocument); }
#endif
