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
	ON_COMMAND(ID_BUTTON3, &CYPaintEditView::MenuLineButton)
	ON_COMMAND(ID_BUTTON2, &CYPaintEditView::MenuDefaultButton)
	ON_COMMAND(ID_BUTTON7, &CYPaintEditView::MenuTextButton)
	ON_COMMAND(ID_BUTTON6, &CYPaintEditView::MenuEllipseButton)
	ON_COMMAND(ID_32793, &CYPaintEditView::RMenuColorButton)
	ON_COMMAND(ID_32794, &CYPaintEditView::FigureSettingButton)
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

	switch (pDoc->yType){
	case line:
	{
			 //�ʱ�ȭ
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
					SetCapture();//���콺 ĸ�� ����
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
						   
						   Invalidate();   //Ŭ�������� ������ �����ֱ����ؼ�
						   break;
					   }
					   else {  //�����ȿ� ���ٸ�
						   pDoc->isExist = FALSE;
						   pDoc->drawing = FALSE;
						   pDoc->currentObj->setSelect(FALSE);
						   pDoc->isSelected = FALSE;
					   }
				   }
				   // � �̵��� �� ���� ������
				   for (int i = 0; i < 2; i++){
					   if (pDoc->pLine->getMRect()[i].PtInRect(point)){
						   if (i == 0) {
							   pDoc->sPoint = point;
							   pDoc->pLine->setSPoint(pDoc->sPoint);
							   pDoc->pLine->setMPoint(-1);  //�������̵�
						   }
						   else {
							   pDoc->ePoint = point;
							   pDoc->pLine->setEPoint(pDoc->ePoint);
							   pDoc->pLine->setMPoint(1);  //�����̵�
						   }
					   }
				   }
				   if (pDoc->currentObj->checkRgn(point)) {
					   pDoc->pLine->setMPoint(0); //��ü�̵�
				   }
				   break;
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
		CPen *oldPen = dc.SelectObject(&pen);
		YObject* tmp = (YObject*)pDoc->currentObj;
		switch (pDoc->yType){
		case line:
		{

			pDoc->ePoint = point;  //���콺 �̵��Ҷ� ���� ���������� �ٲپ���� �׸����ִ�.
			Invalidate();
			break;
		}
		case ellipse:
		{
			//	pDoc->currentObj->(point);
			/*
			dc.SetROP2(R2_XORPEN);;//���� ����
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

			//CPoint t_point = point - pDoc->ePoint; //��ǥ ������
			CPoint t_point = point - pDoc->Original_Point; //��ǥ ������
			pDoc->Original_Point = point;
			//pDoc->ePoint = point;

			pDoc->pLine = (YLine*)pDoc->currentObj;
			//���õǾ����� �̵� ���������� �ٸ� move����
			if (pDoc->isSelected){
				if (pDoc->pLine->getMPoint() == 0){  //��ü�̵�
					pDoc->currentObj->moveAll(t_point.x, t_point.y);
					pDoc->currentObj->setRgn();
				}
				else {
					pDoc->pLine->move(t_point.x, t_point.y);
					pDoc->currentObj->setRgn();
				}
			}
			else {
				//���þȵ�
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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


void CYPaintEditView::MenuLineButton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->yType = line;
	pDoc->lineColor = RGB(0, 0, 0);
	pDoc->lineThick = 1;
	pDoc->linePattern = 0;
}


void CYPaintEditView::MenuDefaultButton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->yType = choice;
}


void CYPaintEditView::MenuTextButton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->yType = text;
}


void CYPaintEditView::MenuEllipseButton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->yType = ellipse;
}

//���콺 �����ʹ�ư Ŭ���� -> �� Ŭ����
void CYPaintEditView::RMenuColorButton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
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

//���콺 ������ ��ư Ŭ���� -> ���� ���� �ٲٱ�
void CYPaintEditView::FigureSettingButton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
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
