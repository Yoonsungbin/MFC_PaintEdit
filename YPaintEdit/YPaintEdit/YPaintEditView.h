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
	// ���� �޴� //
	// ���� �޴� (���� �г�) : ��ư���� ��/Ȱ��ȭ�� ���� ����
	BOOL menu_Select;
	BOOL menu_Line;
	BOOL menu_PolyLine;
	BOOL menu_Rectangle;
	BOOL menu_Ellipse;
	BOOL menu_Text;

	// �ؽ�Ʈ �ʱⰪ ���� �� �޴� ������ ����� ����
	// ���� �޴� (�ؽ�Ʈ�Ӽ� �г�) : �޴����� �ʱⰪ ���� �� ������ �ӽ� ������ ���� ����
	CString font;
	CString texts;
	int fontSize;
	COLORREF fontColor;
	COLORREF bkColor;
	BOOL underline = FALSE;
	BOOL strikeout = FALSE;
	BOOL bold;
	BOOL italic;
	// ���� �޴� (�����Ӽ� �г�) : �޴����� �ʱⰪ ���� �� ������ �ӽ� ������ ���� ���� 
	int lineThick = 1;
	int linePattern = 0;
	int sidePattern = 0;
	BOOL sidePatternflag2 = FALSE;

	// ���� �޴� (�� �г�) : �޴����� �ʱⰪ ���� �� ������ �ӽ� ������ ���� ����
	COLORREF lineColor = RGB(0, 0, 0);
	COLORREF sideColor = RGB(255, 255, 255);


	// �˾� �޴� //
	// �˾� �޴� : �޴����� ��/Ȱ��ȭ�� ���� ����
	BOOL menu_cut;
	BOOL menu_paste;
	BOOL menu_copy;
	BOOL menu_cutcopyflag;			//�߶󳻱����� �����ϱ����� �����ϴ� ���� TRUE - cut  FALSE - copy
	BOOL menu_cutpaste;				//�߶󳻱��϶� �ѹ� �ٿ��ֱ��ϱ����� ���� 
	BOOL menu_Color;
	BOOL menu_Figiure;
	BOOL menu_Delete;
	
	YObject* cutObj = NULL;			// �߶󳻱�, �ٿ��ֱ⸦ ���� ���� ����

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
	void Paint(CDC* dc);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);

	void UpdateMenu();
	afx_msg void OnMenudefaulttbutton();
	afx_msg void OnUpdateMenudefaulttbutton(CCmdUI *pCmdUI);
	afx_msg void OnMenulinebutton();
	afx_msg void OnUpdateMenulinebutton(CCmdUI *pCmdUI);
	afx_msg void OnMenupolylinebutton();
	afx_msg void OnUpdateMenupolylinebutton(CCmdUI *pCmdUI);
	afx_msg void OnMenurectanglebutton();
	afx_msg void OnUpdateMenurectanglebutton(CCmdUI *pCmdUI);
	afx_msg void OnMenuellipsebutton();
	afx_msg void OnUpdateMenuellipsebutton(CCmdUI *pCmdUI);
	afx_msg void OnTexteditbutton();
	afx_msg void OnUpdateTexteditbutton(CCmdUI *pCmdUI);
	afx_msg void OnMenufontsize();
	afx_msg void OnMenufont();
	afx_msg void OnMenutextbutton();
	afx_msg void OnMenufontcolor();
	afx_msg void OnMenufontbkcolor();
	afx_msg void OnUpdateMenufontsize(CCmdUI *pCmdUI);
	afx_msg void OnUpdateMenufont(CCmdUI *pCmdUI);
	afx_msg void OnUpdateMenutextbutton(CCmdUI *pCmdUI);
	afx_msg void OnUpdateMenufontcolor(CCmdUI *pCmdUI);
	afx_msg void OnUpdateMenufontbkcolor(CCmdUI *pCmdUI);
	afx_msg void OnMenulinethick();
	afx_msg void OnMenulinepattern();
	afx_msg void OnMenusidepattern();
	afx_msg void OnUpdateMenulinethick(CCmdUI *pCmdUI);
	afx_msg void OnUpdateMenulinepattern(CCmdUI *pCmdUI);
	afx_msg void OnUpdateMenusidepattern(CCmdUI *pCmdUI);
	afx_msg void OnMenulinecolor();
	afx_msg void OnMenusidecolor();
	afx_msg void OnGroupsbutton();
	afx_msg void OnUpdateGroupsbutton(CCmdUI *pCmdUI);
	afx_msg void OnDeletegroupbutton();
	afx_msg void OnUpdateDeletegroupbutton(CCmdUI *pCmdUI);
	afx_msg void OnGrouplinethick();
	afx_msg void OnUpdateGrouplinethick(CCmdUI *pCmdUI);
	afx_msg void OnGrouplinepattern();
	afx_msg void OnUpdateGrouplinepattern(CCmdUI *pCmdUI);
	afx_msg void OnGroupsidepattern();
	afx_msg void OnUpdateGroupsidepattern(CCmdUI *pCmdUI);
	afx_msg void OnEditCut();
	afx_msg void OnEditPaste();
	afx_msg void OnEditCopy();
	afx_msg void OnUpdateEditCut(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEditCopy(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEditPaste(CCmdUI *pCmdUI);
	afx_msg void OnEditLinecolor();
	afx_msg void OnUpdateEditLinecolor(CCmdUI *pCmdUI);
	afx_msg void OnEditFiguresetting();
	afx_msg void OnUpdateEditFiguresetting(CCmdUI *pCmdUI);
	afx_msg void OnEditDelete();
	afx_msg void OnUpdateEditDelete(CCmdUI *pCmdUI);
	afx_msg void OnEditDeletepoint();
	afx_msg void OnUpdateEditDeletepoint(CCmdUI *pCmdUI);
	afx_msg void OnEditSidecolor();
	afx_msg void OnUpdateEditSidecolor(CCmdUI *pCmdUI);
	afx_msg void OnMenufontdia();

};

#ifndef _DEBUG  // YPaintEditView.cpp�� ����� ����
inline CYPaintEditDoc* CYPaintEditView::GetDocument() const
   { return reinterpret_cast<CYPaintEditDoc*>(m_pDocument); }
#endif
