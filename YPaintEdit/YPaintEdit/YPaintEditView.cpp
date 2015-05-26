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

// YPaintEditView.cpp : CYPaintEditView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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

// CYPaintEditView ����/�Ҹ�

CYPaintEditView::CYPaintEditView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
}

CYPaintEditView::~CYPaintEditView()
{
}

BOOL CYPaintEditView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CYPaintEditView �׸���

void CYPaintEditView::OnDraw(CDC* /*pDC*/)
{
	CYPaintEditDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
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


// CYPaintEditView ����

#ifdef _DEBUG
void CYPaintEditView::AssertValid() const
{
	CView::AssertValid();
}

void CYPaintEditView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CYPaintEditDoc* CYPaintEditView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYPaintEditDoc)));
	return (CYPaintEditDoc*)m_pDocument;
}
#endif //_DEBUG


// CYPaintEditView �޽��� ó����


void CYPaintEditView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);
	//�ʱⰪ ����
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
		
		SetCapture();//���콺 ĸ�� ����
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);

	if (nFlags & MK_LBUTTON){

		CPen pen(PS_SOLID, 1, RGB(0, 0, 255));
		CPen *oldpen = dc.SelectObject(&pen);

		if (pDoc->yType == line){
			pDoc->currentObj->setEPoint(point);
			// ������ �׸� ������ �����.
			dc.SetROP2(R2_NOT);
			dc.MoveTo(pDoc->sPoint);
			dc.LineTo(pDoc->ePoint);

			// ���ο� ������ �׸���.
			dc.SetROP2(R2_NOT);
			dc.MoveTo(pDoc->sPoint);
			dc.LineTo(point);
			pDoc->ePoint = point;

			//����
			//pDoc->currentObj->setRgn();
			pDoc->currentObj->drawRgn(pDoc->sPoint, pDoc->ePoint);
			
	
		}

		else if (pDoc->yType == ellipse){
		
			
		//	pDoc->currentObj->(point);

			dc.SetROP2(R2_XORPEN);;//���� ����
			dc.SelectStockObject(NULL_BRUSH);
			CPen m_penDot(PS_DOT, 1, RGB(1, 1, 1));
			dc.SelectObject(&m_penDot);
			dc.SetROP2(R2_XORPEN);

		
			dc.Ellipse(pDoc->sPoint.x, pDoc->sPoint.y, pDoc->ePoint.x, pDoc->ePoint.y);
			pDoc->ePoint = point;
			dc.Ellipse(pDoc->sPoint.x, pDoc->sPoint.y, point.x, point.y);
		
			

			//pDoc->currentObj->drawRgn(pDoc->sPoint, pDoc->ePoint);
			
			
		}



		Invalidate();  // ���� & ����x �������� ��Ĵٸ� (ù ������)
	}
	
	CView::OnMouseMove(nFlags, point);
}

void CYPaintEditView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.

	CYPaintEditDoc* pDoc = GetDocument();
	
	POSITION pos = pDoc->obj_List.GetHeadPosition();

	while (pos) {
		YObject* tmp = (YObject*)pDoc->obj_List.GetNext(pos);
		CPen pen(PS_SOLID, 1, RGB(0, 0, 255));
		CPen *oldPen = dc.SelectObject(&pen);
		tmp->draw(&dc);
		dc.SelectObject(&oldPen);
		
	}
	if (pDoc->drawing){			// ���콺 �����̴� ���� ��� ����Ǵ� �Լ�
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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