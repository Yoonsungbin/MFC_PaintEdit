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

// YPaintEditView.cpp : CYPaintEditView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "YPaintEdit.h"
#endif

#include "YPaintEditDoc.h"
#include "YPaintEditView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CYPaintEditView

IMPLEMENT_DYNCREATE(CYPaintEditView, CView)

BEGIN_MESSAGE_MAP(CYPaintEditView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CYPaintEditView 생성/소멸

CYPaintEditView::CYPaintEditView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
}

CYPaintEditView::~CYPaintEditView()
{
}

BOOL CYPaintEditView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CYPaintEditView 그리기

void CYPaintEditView::OnDraw(CDC* /*pDC*/)
{
	CYPaintEditDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CYPaintEditView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CYPaintEditView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CYPaintEditView 진단

#ifdef _DEBUG
void CYPaintEditView::AssertValid() const
{
	CView::AssertValid();
}

void CYPaintEditView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CYPaintEditDoc* CYPaintEditView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYPaintEditDoc)));
	return (CYPaintEditDoc*)m_pDocument;
}
#endif //_DEBUG


// CYPaintEditView 메시지 처리기


void CYPaintEditView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);
	//초기값 설정
	pDoc->sPoint = point;
	pDoc->ePoint = point;
	pDoc->drawing = FALSE;
	//pDoc->isExist = FALSE;
	//pDoc->isSelected = FALSE;
	if (pDoc->yType == line){
		YLine* line = new YLine(point, point);
		line->setLineColor(RGB(0, 0, 255));
		line->SetThick(1);
		line->setSelect(TRUE);
		pDoc->drawing = TRUE;
		pDoc->currentObj = line;
		//SetCapture();
	}
	
	////////////////////////// Text ///////////////////////////
	else if (pDoc->yType == text){
		if (pDoc->textEditing == FALSE){
			YText* text = new YText(point);
			pDoc->ptext = text;
			pDoc->textEditing = TRUE;
		}
		else {
			pDoc->obj_List.AddTail(pDoc->ptext);
			pDoc->tmp.Empty();
			pDoc->textEditing = FALSE;
		}
	}
	///////////////////////////////////////////////////////////
	
	else if (pDoc->yType == ellipse)
	{
		YEllipse* ellipse = new YEllipse(point, point);
		
		SetCapture();//마우스 캡쳐 시작
		dc.Ellipse(pDoc->sPoint.x, pDoc->sPoint.y, pDoc->sPoint.x, pDoc->sPoint.y);



	}

	else if (pDoc->yType == default){
	//	pDoc->drawing = FALSE;
	//	pDoc->isSelected = FALSE;

		POSITION pos = pDoc->obj_List.GetTailPosition();
		while (pos) {
			YObject* tmp = (YObject*)pDoc->obj_List.GetPrev(pos);
			//tmp->setSelect(TRUE);
			
			if (tmp->checkRgn(point)){
				pDoc->isExist = TRUE;
				if (tmp->getSelect()){
					//MessageBox(_T("ASD"));
					tmp->setSelect(FALSE);
				}
				else{
					//MessageBox(_T("v"));
					tmp->setSelect(TRUE);
				}
				pDoc->currentObj = tmp;
				pDoc->currentObj->drawRgn(tmp->getSPoint(), tmp->getEPoint());
				break;
			}
			pDoc->isExist = FALSE;
		}
	}
	CView::OnLButtonDown(nFlags, point);
}

void CYPaintEditView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);

	if (nFlags & MK_LBUTTON){

		CPen pen(PS_SOLID, 1, RGB(0, 0, 255));
		CPen *oldpen = dc.SelectObject(&pen);

		if (pDoc->yType == line){
			pDoc->currentObj->setEPoint(point);
			// 이전에 그린 직선을 지운다.
			dc.SetROP2(R2_NOT);
			dc.MoveTo(pDoc->sPoint);
			dc.LineTo(pDoc->ePoint);

			// 새로운 직선을 그린다.
			dc.SetROP2(R2_NOT);
			dc.MoveTo(pDoc->sPoint);
			dc.LineTo(point);
			pDoc->ePoint = point;

			//리젼
			//pDoc->currentObj->setRgn();
			pDoc->currentObj->drawRgn(pDoc->sPoint, pDoc->ePoint);
			
	
		}

		else if (pDoc->yType == ellipse){
		
			
		//	pDoc->currentObj->(point);

			dc.SetROP2(R2_XORPEN);;//선을 반전
			dc.SelectStockObject(NULL_BRUSH);
			CPen m_penDot(PS_DOT, 1, RGB(1, 1, 1));
			dc.SelectObject(&m_penDot);
			dc.SetROP2(R2_XORPEN);

		
			dc.Ellipse(pDoc->sPoint.x, pDoc->sPoint.y, pDoc->ePoint.x, pDoc->ePoint.y);
			pDoc->ePoint = point;
			dc.Ellipse(pDoc->sPoint.x, pDoc->sPoint.y, point.x, point.y);
		
			

			//pDoc->currentObj->drawRgn(pDoc->sPoint, pDoc->ePoint);
			
			
		}



		Invalidate();  // 적용 & 적용x 보여지는 방식다름 (첫 시작점)
	}
	
	CView::OnMouseMove(nFlags, point);
}

void CYPaintEditView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->ePoint = point;
	if (pDoc->yType == line) {

		YLine* line = new YLine(pDoc->sPoint, pDoc->ePoint);
		pDoc->currentObj = line;
		
		pDoc->currentObj->setRgn();
		pDoc->currentObj->setSelect(FALSE);
		pDoc->obj_List.AddTail(pDoc->currentObj);
		pDoc->currentObj = NULL;
		pDoc->drawing = FALSE;
		pDoc->yType = default;
		//ReleaseCapture();
		
	}


	else if (pDoc->yType == ellipse)
	{
		dc.Ellipse(pDoc->sPoint.x, pDoc->sPoint.y, point.x, point.y);
		ReleaseCapture();

	}

	else if (pDoc->yType == default){
		//type = line;
		POSITION pos = pDoc->obj_List.GetHeadPosition();
		while (pos){
			YObject* tmp = (YObject*)pDoc->obj_List.GetNext(pos);
		//pDoc->currentObj->drawRgn(pDoc->sPoint, pDoc->ePoint);
			tmp->draw(&dc);
			tmp->setSelect(TRUE);
			
		}
		pDoc->yType = line;
	}
	Invalidate(FALSE);
	CView::OnLButtonUp(nFlags, point);
}

void CYPaintEditView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.

	CYPaintEditDoc* pDoc = GetDocument();
	
	POSITION pos = pDoc->obj_List.GetHeadPosition();

	while (pos) {
		YObject* tmp = (YObject*)pDoc->obj_List.GetNext(pos);
		CPen pen(PS_SOLID, 1, RGB(0, 0, 255));
		CPen *oldPen = dc.SelectObject(&pen);
		tmp->draw(&dc);
		dc.SelectObject(&oldPen);
		
	}
	if (pDoc->drawing){			// 마우스 움직이는 도중 계속 실행되는 함수
		//CPen pen(PS_SOLID, 4, RGB(200, 0, 0));
		//CPen *oldPen = dc.SelectObject(&pen);
		pDoc->currentObj->draw(&dc);
		//dc.SelectObject(&oldPen);
	}

	////////////////////////////// Text ////////////////////////////////
	if (pDoc->textEditing){
		CFont f;
		f.CreatePointFont(pDoc->ptext->getFontSize(),pDoc->ptext->getFont());
		dc.SelectObject(f);
		dc.SetBkColor(pDoc->ptext->getBkColor());
		dc.SetTextColor(pDoc->ptext->getFontColor());
		CPoint p;
		p.x = pDoc->ptext->getSPoint().x + pDoc->ptext->getText().GetLength() * 100;
		p.y = pDoc->ptext->getSPoint().y + pDoc->ptext->getFontSize()/7;
		pDoc->ptext->setEPoint(p);
		pDoc->ptext->drawRgn(pDoc->ptext->getSPoint(), pDoc->ptext->getEPoint());
		dc.DrawText(pDoc->ptext->getText(), pDoc->ptext->getRect(), NULL);
	}
	////////////////////////////////////////////////////////////////////
}

void CYPaintEditView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) // Text
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	if (pDoc->textEditing == TRUE){
		if (nChar == _T('\b')){
			if (pDoc->ptext->getText().GetLength() > 0){
				pDoc->tmp.GetBufferSetLength(pDoc->tmp.GetLength() - 1);
				pDoc->ptext->setText(pDoc->tmp);
			}
		}
		else if (nChar == VK_RETURN){
			pDoc->textEditing = FALSE;
			pDoc->obj_List.AddTail(pDoc->ptext);
			pDoc->tmp.Empty();
		}
		else{
			pDoc->tmp.AppendChar(nChar);
			pDoc->ptext->setText(pDoc->tmp);
		}
		Invalidate();
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}