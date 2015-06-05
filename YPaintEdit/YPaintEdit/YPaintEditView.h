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
	//리본메뉴 비활성화를 위하여
	BOOL menu_Select;
	BOOL menu_Line;
	BOOL menu_PolyLine;
	BOOL menu_Ellipse;
	BOOL menu_Rectangle;
	BOOL menu_Text;

	//팝업메뉴를 비활성화 하기 위해서
	BOOL menu_Color;
	BOOL menu_Figiure;
	BOOL menu_Delete;

	//메뉴에서 정하는 값들을 저장할 변수 (보여지는 view객체의 속성값들을 제어함)
	COLORREF lineColor = RGB(0,0,0);													//검은색
	int lineThick = 1;																	//두께 : 1	
	int linePattern = 0;																// PS_SOLID
	COLORREF sideColor = RGB(255,255,255);												//흰색
	int sidePattern = NULL;																//HS_BDIAGONAL	
	BOOL sidePatternflag2=FALSE;
	int fontSize;
	int fontPattern;

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
	afx_msg void OnMenusidepattern();//면패턴
	afx_msg void OnMenusidecolor();
	afx_msg void OnUpdateMenusidepattern(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // YPaintEditView.cpp의 디버그 버전
inline CYPaintEditDoc* CYPaintEditView::GetDocument() const
   { return reinterpret_cast<CYPaintEditDoc*>(m_pDocument); }
#endif
