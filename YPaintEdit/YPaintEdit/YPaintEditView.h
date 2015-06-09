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
#include "TextEditDialog.h"

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

	// ���� �޴� (�ؽ�Ʈ�Ӽ� �г�) : �޴����� �ʱⰪ ���� �� ������ �ӽ� ������ ���� ����
	CString font;
	CString texts;
	int fontSize;
	COLORREF fontColor;
	COLORREF bkColor;
	BOOL underline = FALSE;
	BOOL strikeout = FALSE;
	BOOL bold = FALSE;
	BOOL italic = FALSE;

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
	BOOL menu_Cut;
	BOOL menu_Paste;
	BOOL menu_Copy;
	BOOL menu_CutCopyflag;			//�߶󳻱����� �����ϱ����� �����ϴ� ���� TRUE - cut  FALSE - copy
	BOOL menu_CutPaste;				//�߶󳻱��϶� �ѹ� �ٿ��ֱ��ϱ����� ���� 
	BOOL menu_LineColor;
	BOOL menu_SideColor;
	BOOL menu_Figure;
	BOOL menu_Delete;
	BOOL menu_DeletePoint;
	BOOL menu_Group;
	BOOL menu_DeleteGroup;
	BOOL menu_FontDialog;

	YObject* cutObj = NULL;			// �߶󳻱�, �ٿ��ֱ⸦ ���� ���� ����
	BOOL undoredoFlag = FALSE;


	BOOL lineMove = FALSE;
	BOOL polylineMove = FALSE;
	BOOL ellipseMove = FALSE;
	BOOL rectangleMove = FALSE;
	BOOL textMove = FALSE;
	BOOL groupMove = FALSE;

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
	afx_msg void OnMenutextbutton();
	afx_msg void OnUpdateMenutextbutton(CCmdUI *pCmdUI);
	afx_msg void OnMenufontsize();
	afx_msg void OnUpdateMenufontsize(CCmdUI *pCmdUI);
	afx_msg void OnMenufont();
	afx_msg void OnUpdateMenufont(CCmdUI *pCmdUI);
	afx_msg void OnTexteditbutton();
	afx_msg void OnUpdateTexteditbutton(CCmdUI *pCmdUI);
	afx_msg void OnMenufontcolor();
	afx_msg void OnUpdateMenufontcolor(CCmdUI *pCmdUI);
	afx_msg void OnMenufontbkcolor();
	afx_msg void OnUpdateMenufontbkcolor(CCmdUI *pCmdUI);
	afx_msg void OnMenulinethick();
	afx_msg void OnUpdateMenulinethick(CCmdUI *pCmdUI);
	afx_msg void OnMenulinepattern();
	afx_msg void OnUpdateMenulinepattern(CCmdUI *pCmdUI);
	afx_msg void OnMenusidepattern();
	afx_msg void OnUpdateMenusidepattern(CCmdUI *pCmdUI);
	afx_msg void OnMenulinecolor();
	afx_msg void OnMenusidecolor();
	afx_msg void OnGroupsbutton();
	afx_msg void OnUpdateGroupsbutton(CCmdUI *pCmdUI);
	afx_msg void OnDeletegroupbutton();
	afx_msg void OnUpdateDeletegroupbutton(CCmdUI *pCmdUI);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnEditCut();
	afx_msg void OnEditCopy();
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditCut(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEditCopy(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEditPaste(CCmdUI *pCmdUI);
	afx_msg void OnEditLinecolor();
	afx_msg void OnUpdateEditLinecolor(CCmdUI *pCmdUI);
	afx_msg void OnEditSidecolor();
	afx_msg void OnUpdateEditSidecolor(CCmdUI *pCmdUI);
	afx_msg void OnEditFiguresetting();
	afx_msg void OnUpdateEditFiguresetting(CCmdUI *pCmdUI);
	afx_msg void OnEditDelete();
	afx_msg void OnUpdateEditDelete(CCmdUI *pCmdUI);
	afx_msg void OnEditDeletepoint();
	afx_msg void OnUpdateEditDeletepoint(CCmdUI *pCmdUI);
	afx_msg void OnEditgroup();
	afx_msg void OnUpdateEditgroup(CCmdUI *pCmdUI);
	afx_msg void OnEditdeletegroup();
	afx_msg void OnUpdateEditdeletegroup(CCmdUI *pCmdUI);
	afx_msg void OnBack();
	afx_msg void OnFrontback();
	afx_msg void OnUpdateBack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFrontback(CCmdUI *pCmdUI);
	afx_msg void OnMenufontdia();
	afx_msg void OnUpdateMenufontdia(CCmdUI *pCmdUI);
	afx_msg void OnUpdateMenulinecolor(CCmdUI *pCmdUI);
	afx_msg void OnUpdateMenusidecolor(CCmdUI *pCmdUI);
	

	afx_msg void OnGroupsizechangebutton();
	afx_msg void OnUpdateGroupsizechangebutton(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // YPaintEditView.cpp�� ����� ����
inline CYPaintEditDoc* CYPaintEditView::GetDocument() const
   { return reinterpret_cast<CYPaintEditDoc*>(m_pDocument); }
#endif

