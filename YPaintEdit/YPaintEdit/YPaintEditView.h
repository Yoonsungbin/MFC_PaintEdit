// 이 MFC 샘플 소스 코드는 MFC Microsoft Office Fluent 사용자 인터페이스("Fluent UI")를 
// 사용하는 방법을 보여 주며, MFC C++ 라이브러리 소프트웨어에 포함된 
// Microsoft Foundation Classes Reference 및 관련 전자 문서에 대해 
// 추가적으로 제공되는 내용입니다.  
// Fluent UI를 복사, 사용 또는 배포하는 데 대한 사용 약관은 별도로 제공됩니다.  
// Fluent UI 라이선싱 프로그램에 대한 자세한 내용은 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// YPaintEditView.h : CYPaintEditView 클래스의 인터페이스
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
protected: // serialization에서만 만들어집니다.
	CYPaintEditView();
	DECLARE_DYNCREATE(CYPaintEditView)

// 특성입니다.
public:
	CYPaintEditDoc* GetDocument() const;

// 작업입니다.
public:
	// 리본 메뉴 //
	// 리본 메뉴 (도형 패널) : 버튼들의 비/활성화를 위해 선언
	BOOL menu_Select;
	BOOL menu_Line;
	BOOL menu_PolyLine;
	BOOL menu_Rectangle;
	BOOL menu_Ellipse;
	BOOL menu_Text;

	// 텍스트 초기값 변수 및 메뉴 설정시 사용할 변수
	// 리본 메뉴 (텍스트속성 패널) : 메뉴들의 초기값 설정 및 값들의 임시 저장을 위해 선언
	CString font;
	CString texts;
	int fontSize;
	COLORREF fontColor;
	COLORREF bkColor;
	BOOL underline = FALSE;
	BOOL strikeout = FALSE;
	BOOL bold;
	BOOL italic;
	// 리본 메뉴 (도형속성 패널) : 메뉴들의 초기값 설정 및 값들의 임시 저장을 위해 선언 
	int lineThick = 1;
	int linePattern = 0;
	int sidePattern = 0;
	BOOL sidePatternflag2 = FALSE;

	// 리본 메뉴 (색 패널) : 메뉴들의 초기값 설정 및 값들의 임시 저장을 위해 선언
	COLORREF lineColor = RGB(0, 0, 0);
	COLORREF sideColor = RGB(255, 255, 255);


	// 팝업 메뉴 //
	// 팝업 메뉴 : 메뉴들의 비/활성화를 위해 선언
	BOOL menu_cut;
	BOOL menu_paste;
	BOOL menu_copy;
	BOOL menu_cutcopyflag;			//잘라내기인지 복사하기인지 선택하는 변수 TRUE - cut  FALSE - copy
	BOOL menu_cutpaste;				//잘라내기일때 한번 붙여넣기하기위한 변수 
	BOOL menu_Color;
	BOOL menu_Figiure;
	BOOL menu_Delete;
	
	YObject* cutObj = NULL;			// 잘라내기, 붙여넣기를 위한 변수 선언

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CYPaintEditView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
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

#ifndef _DEBUG  // YPaintEditView.cpp의 디버그 버전
inline CYPaintEditDoc* CYPaintEditView::GetDocument() const
   { return reinterpret_cast<CYPaintEditDoc*>(m_pDocument); }
#endif
