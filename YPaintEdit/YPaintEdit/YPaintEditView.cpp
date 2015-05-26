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
	ON_COMMAND(ID_BUTTON3, &CYPaintEditView::MenuLineButton)
	ON_COMMAND(ID_BUTTON2, &CYPaintEditView::MenuDefaultButton)
	ON_COMMAND(ID_BUTTON7, &CYPaintEditView::MenuTextButton)
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

	if (pDoc->yType == line){
		//초기화
		YLine* line = new YLine(point, point);
		line->setLineColor(RGB(0, 0, 255));
		line->SetThick(1);
		line->setSelect(TRUE);
		pDoc->drawing = TRUE;
		pDoc->isSelected = FALSE;
		pDoc->currentObj = line;

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
	else if (pDoc->yType == default){
		if (pDoc->isSelected){
			dx_sPoint = point;
		}

		POSITION pos = pDoc->obj_List.GetTailPosition();
		while (pos) {
			YObject* tmp = (YObject*)pDoc->obj_List.GetPrev(pos);
			if (tmp->checkRgn(point)){
				pDoc->isExist = TRUE;
				/*
				//리젼반전을 위해서
				if (tmp->getSelect()){
				tmp->setSelect(FALSE);
				pDoc->isSelected = FALSE;
				}
				else{
				tmp->setSelect(TRUE);
				pDoc->isSelected = TRUE;
				}
				*/
				tmp->setSelect(TRUE);
				pDoc->isSelected = TRUE;
				pDoc->currentObj = tmp;
				pDoc->currentObj->drawRgn(tmp->getSPoint(), tmp->getEPoint());
				//pDoc->currentObj->draw(&dc);
				break;
			}
			pDoc->isExist = FALSE;
		}

	}
	//SetCapture();
	CView::OnLButtonDown(nFlags, point);
}

void CYPaintEditView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);

	if (nFlags & MK_LBUTTON){

		CPen pen(PS_SOLID, 1, RGB(0, 0, 255));
		CPen *oldPen = dc.SelectObject(&pen);
		YObject* tmp = (YObject*)pDoc->currentObj;

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
			pDoc->currentObj->drawRgn(pDoc->sPoint, pDoc->ePoint);


		}
		else if (pDoc->yType == default){
			CPoint t_point = point - pDoc->ePoint;
			pDoc->ePoint = point;
			if (pDoc->isSelected){
				//선택 됨
				pDoc->currentObj->moveAll(t_point.x, t_point.y);
				pDoc->currentObj->drawRgn(pDoc->currentObj->getSPoint(), pDoc->currentObj->getEPoint());
			}
			else {
				//선택안됨
			}
		}

		dc.SelectObject(&oldPen);


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

	}
	else if (pDoc->yType == default){
		//type = line;
		/*
		POSITION pos = pDoc->obj_List.GetHeadPosition();
		while (pos){
		YObject* tmp = (YObject*)pDoc->obj_List.GetNext(pos);
		//pDoc->currentObj->drawRgn(pDoc->sPoint, pDoc->ePoint);
		tmp->draw(&dc);

		}
		*/
		//pDoc->currentObj->reRgn();
		//pDoc->currentObj->setRgn();
		POSITION pos = pDoc->obj_List.GetTailPosition();

		while (pos) {
			YObject* tmp = (YObject*)pDoc->obj_List.GetPrev(pos);
			tmp->setSelect(FALSE);
			pDoc->isSelected = FALSE;
			pDoc->isExist = FALSE;
		}

		//	pDoc->yType = line;
	}
	//	ReleaseCapture();
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
		pDoc->currentObj->setSPoint(pDoc->sPoint);
		pDoc->currentObj->setEPoint(pDoc->ePoint);
		pDoc->currentObj->draw(&dc);
	}

	////////////////////////////// Text ////////////////////////////////
	if (pDoc->textEditing){
		CFont f;
		f.CreatePointFont(pDoc->ptext->getFontSize(), pDoc->ptext->getFont());
		dc.SelectObject(f);
		dc.SetBkColor(pDoc->ptext->getBkColor());
		dc.SetTextColor(pDoc->ptext->getFontColor());
		CPoint p;
		p.x = pDoc->ptext->getEPoint().x + pDoc->ptext->getFontSize() + pDoc->ptext->getText().GetLength() * 100;
		p.y = pDoc->ptext->getEPoint().y + pDoc->ptext->getFontSize() + pDoc->ptext->getText().GetLength() * 100;
		pDoc->ptext->setEPoint(p);
		pDoc->ptext->drawRgn(pDoc->ptext->getSPoint(), pDoc->ptext->getEPoint());

		//CPen m_penDot(PS_DOT, 1, RGB(255, 1, 1));
		//dc.SelectObject(&m_penDot);
		//dc.SetROP2(R2_XORPEN);

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


void CYPaintEditView::MenuLineButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->yType = line;
	
}


void CYPaintEditView::MenuDefaultButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->yType = default;
}


void CYPaintEditView::MenuTextButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->yType = text;
}
