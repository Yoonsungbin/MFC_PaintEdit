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
	ON_COMMAND(ID_BUTTON6, &CYPaintEditView::MenuEllipseButton)
	ON_COMMAND(ID_32793, &CYPaintEditView::RMenuColorButton)
	ON_COMMAND(ID_32794, &CYPaintEditView::FigureSettingButton)
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

	switch (pDoc->yType){
	case line:
	{
			 //초기화
				 YLine* line = new YLine(point, point);
				 line->setLineColor(pDoc->lineColor);
				 line->SetLineThick(pDoc->lineThick);
				 line->SetLinePattern(pDoc->linePattern);
				 line->setSelect(TRUE);
				 pDoc->drawing = TRUE;
				 pDoc->isSelected = FALSE;
				 pDoc->currentObj = line;
				 break;
	}
	case text:
	{
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
				 break;

	}

	case ellipse:
	{
					YEllipse* ellipse = new YEllipse(point, point);
					pDoc->drawing = TRUE;
					pDoc->isSelected = FALSE;
					SetCapture();//마우스 캡쳐 시작
					pDoc->currentObj = ellipse;
					//dc.Ellipse(pDoc->sPoint.x, pDoc->sPoint.y, pDoc->sPoint.x, pDoc->sPoint.y);
	}
	case choice:
	{
				   POSITION pos = pDoc->obj_List.GetTailPosition();
				   while (pos) {
					   YObject* tmp = (YObject*)pDoc->obj_List.GetPrev(pos);
					   pDoc->currentObj = tmp;
					   pDoc->pLine = (YLine*)pDoc->currentObj;
					   if (pDoc->currentObj->checkRgn(point) || pDoc->pLine->getMRect()[0].PtInRect(point) ||pDoc->pLine->getMRect()[1].PtInRect(point) ){
						   pDoc->isExist = TRUE;
						   pDoc->isSelected = TRUE;
						   pDoc->drawing = TRUE;
						   pDoc->currentObj->setSelect(TRUE);
						   
						   pDoc->Original_Point = point;
						   
						   Invalidate();   //클릭했을떄 리젼을 보여주기위해서
						   break;
					   }
					   else {  //리젼안에 없다면
						   pDoc->isExist = FALSE;
						   pDoc->drawing = FALSE;
						   pDoc->currentObj->setSelect(FALSE);
						   pDoc->isSelected = FALSE;
					   }
				   }
				   // 어떤 이동인 지 먼지 선택함
				   for (int i = 0; i < 2; i++){
					   if (pDoc->pLine->getMRect()[i].PtInRect(point)){
						   if (i == 0) {
							   pDoc->sPoint = point;
							   pDoc->pLine->setSPoint(pDoc->sPoint);
							   pDoc->pLine->setMPoint(-1);  //시작점이동
						   }
						   else {
							   pDoc->ePoint = point;
							   pDoc->pLine->setEPoint(pDoc->ePoint);
							   pDoc->pLine->setMPoint(1);  //끝점이동
						   }
					   }
				   }
				   if (pDoc->currentObj->checkRgn(point)) {
					   pDoc->pLine->setMPoint(0); //전체이동
				   }
				   break;
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
		CPen *oldPen = dc.SelectObject(&pen);
		YObject* tmp = (YObject*)pDoc->currentObj;
		switch (pDoc->yType){
		case line:
		{

			pDoc->ePoint = point;  //마우스 이동할때 끝점 지속적으로 바꾸어줘야 그릴수있다.
			Invalidate();
			break;
		}
		case ellipse:
		{
			//	pDoc->currentObj->(point);
			/*
			dc.SetROP2(R2_XORPEN);;//선을 반전
			dc.SelectStockObject(NULL_BRUSH);
			CPen m_penDot(PS_DOT, 1, RGB(1, 1, 1));
			dc.SelectObject(&m_penDot);
			dc.SetROP2(R2_XORPEN);
			*/
			//dc.Ellipse(pDoc->sPoint.x, pDoc->sPoint.y, pDoc->ePoint.x, pDoc->ePoint.y);
			pDoc->ePoint = point;
			//dc.Ellipse(pDoc->sPoint.x, pDoc->sPoint.y, point.x, point.y);
			Invalidate();
			break;
		}
		case text:
		{
			break;
		}
		case choice:
		{

			//CPoint t_point = point - pDoc->ePoint; //좌표 움직임
			CPoint t_point = point - pDoc->Original_Point; //좌표 움직임
			pDoc->Original_Point = point;
			//pDoc->ePoint = point;

			pDoc->pLine = (YLine*)pDoc->currentObj;
			//선택되었을때 이동 변수에따라 다른 move실행
			if (pDoc->isSelected){
				if (pDoc->pLine->getMPoint() == 0){  //전체이동
					pDoc->currentObj->moveAll(t_point.x, t_point.y);
					pDoc->currentObj->setRgn();
				}
				else {
					pDoc->pLine->move(t_point.x, t_point.y);
					pDoc->currentObj->setRgn();
				}
			}
			else {
				//선택안됨
			}
			Invalidate();
			break;
		}
		}
	}
	CView::OnMouseMove(nFlags, point);
}

void CYPaintEditView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->ePoint = point;

	switch (pDoc->yType){
	case line:
	{
		
				 YLine* line = new YLine(pDoc->sPoint, pDoc->ePoint);
				 pDoc->currentObj = line;
				 pDoc->pLine = (YLine*)pDoc->currentObj;
				 pDoc->pLine->setLineColor(pDoc->lineColor);
				 pDoc->pLine->SetLineThick(pDoc->lineThick);
				 line->SetLinePattern(pDoc->linePattern);
				 pDoc->pLine->setRgn();
				 pDoc->pLine->setSelect(FALSE);
				 pDoc->obj_List.AddTail(pDoc->currentObj);
				 pDoc->currentObj = NULL;
				 pDoc->drawing = FALSE;
				 pDoc->yType = choice;
				 break;
				 /*
				 pDoc->currentObj->setLineColor(pDoc->lineColor);
				 pDoc->currentObj->SetLineThick(pDoc->lineThick);
				 line->SetLinePattern(pDoc->linePattern);
				 pDoc->currentObj->setRgn();
				 pDoc->currentObj->setSelect(FALSE);
				 pDoc->obj_List.AddTail(pDoc->currentObj);
				 pDoc->currentObj = NULL;
				 pDoc->drawing = FALSE;
				 pDoc->yType = choice;
				 break;
				 */
	}
	case text:
	{
		pDoc->yType = choice;
				 break;
	}

	case ellipse:
	{
		dc.Ellipse(pDoc->sPoint.x, pDoc->sPoint.y, point.x, point.y);
		ReleaseCapture();
		pDoc->yType = choice;
		break;
	
	}
	case choice:
	{
				   break;
	}
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
		switch (pDoc->yType)
		{
		case line:
		{
			pDoc->pLine = (YLine*)pDoc->currentObj;
			pDoc->pLine->setSPoint(pDoc->sPoint);
			pDoc->pLine->setEPoint(pDoc->ePoint);
			pDoc->pLine->drawCircle(&dc);
			break;
		}
		default:
			pDoc->pLine->drawCircle(&dc);
			break;
		}
	//	pDoc->currentObj->setSPoint(pDoc->sPoint);
	//	pDoc->currentObj->setEPoint(pDoc->ePoint);
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
		p.x = pDoc->ptext->getSPoint().x + pDoc->ptext->getText().GetLength() * 100;
		p.y = pDoc->ptext->getSPoint().y + pDoc->ptext->getFontSize() / 7;
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


void CYPaintEditView::MenuLineButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->yType = line;
	pDoc->lineColor = RGB(0, 0, 0);
	pDoc->lineThick = 1;
	pDoc->linePattern = 0;
}


void CYPaintEditView::MenuDefaultButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->yType = choice;
}


void CYPaintEditView::MenuTextButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->yType = text;
}


void CYPaintEditView::MenuEllipseButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->yType = ellipse;
}

//마우스 오른쪽버튼 클릭후 -> 선 클릭시
void CYPaintEditView::RMenuColorButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	CColorDialog dlg(RGB(255,0,0),CC_FULLOPEN);
	int result = dlg.DoModal();
	if (result == IDOK){
		pDoc->lineColor = dlg.GetColor();
		pDoc->pLine = (YLine*)pDoc->currentObj;
	//	pDoc->currentObj->setLineColor(pDoc->lineColor);
		pDoc->pLine->setLineColor(pDoc->lineColor);
		Invalidate();
	}
}

//마우스 오른쪽 버튼 클릭후 -> 도형 서식 바꾸기
void CYPaintEditView::FigureSettingButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	YFigureDialog dlg;
	dlg.lineThick = pDoc->lineThick;
	dlg.linePattern = pDoc->linePattern;
	int result = dlg.DoModal();
	if (result == IDOK){
		pDoc->lineThick = dlg.lineThick;
		pDoc->linePattern = dlg.linePattern;
		//int index = dlg.patternIndex.GetCurSel();
		//CString str;
		//str.Format(_T("%d"), index);
		//MessageBox(str);
		
		//pDoc->currentObj->SetLineThick(pDoc->lineThick);
		//pDoc->currentObj->SetLinePattern(pDoc->linePattern);
		pDoc->pLine->SetLineThick(pDoc->lineThick);
		pDoc->pLine->SetLinePattern(pDoc->linePattern);
		Invalidate();
	}

}
