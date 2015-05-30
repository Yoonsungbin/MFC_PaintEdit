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
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_BUTTON5, &CYPaintEditView::MenuPolyLineButton)
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
	case polyline:
	{
					 if (pDoc->clickPolyLine == FALSE){   //���� ����
						 YPolyLine* polyline = new YPolyLine();
						 polyline->setLineColor(pDoc->lineColor);
						 polyline->SetLineThick(pDoc->lineThick);
						 polyline->SetLinePattern(pDoc->linePattern);
						 polyline->setSelect(TRUE);
						 polyline->addPoint(point);
						 pDoc->drawing = TRUE;
						 pDoc->isSelected = FALSE;
						 pDoc->currentObj = polyline;
						 pDoc->clickPolyLine = TRUE;
						 pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
						 pDoc->pPolyLine->setDrawPolyLine(TRUE);
					 }
					 else{   //������������ Ŭ���Ҷ� ����
						 pDoc->drawing = TRUE;
						 pDoc->pPolyLine->addPoint(point);
					 }
					 break;

	}
	case text: // Text
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
					   HideCaret();
				   }
				   break;
	}

	case ellipse:
	{

					YEllipse* ellipse = new YEllipse(point, point);

					ellipse->setLineColor(pDoc->lineColor);
					ellipse->SetLineThick(pDoc->lineThick);
					ellipse->SetLinePattern(pDoc->linePattern);
					ellipse->setSelect(TRUE);
					pDoc->drawing = TRUE;
					pDoc->isSelected = FALSE;
					pDoc->currentObj = ellipse;
					break;
				
	
	}
	case choice:
	{
				   //List���� ���õ� ��ü �ϳ��� ������ TRUE�ιٲٰ� ���� (�׷�ȭ�ϰԵǸ� �迭�Ǵ� ����Ʈ �μ����ؾ��Ҳ�����)
				   if (pDoc->currentObj != NULL)	{
					   pDoc->currentObj->setSelect(FALSE);
					   pDoc->isSelected = FALSE;
					   pDoc->currentObj = NULL;
				   }

				   //���� ������ ��ü ã��
				   POSITION pos = pDoc->obj_List.GetTailPosition();
				   while (pos) {
					   pDoc->currentObj = (YObject*)pDoc->obj_List.GetPrev(pos);
					   if (pDoc->currentObj->checkRgn(point) == TRUE){
						   pDoc->currentObj->setSelect(TRUE);
						   break;
					   }
					   //������ ������ ���� ���� �ۿ� �����Ƿ� �ѹ��� �˻�������Ѵ�.
					   if (pDoc->currentObj == pDoc->pLine){
						   if (pDoc->pLine->getMRect()[0].PtInRect(point) || pDoc->pLine->getMRect()[1].PtInRect(point)) {
							   pDoc->currentObj->setSelect(TRUE);
							   break;
						   }
					   }
				   }

				   //���õ� ��ü�����ؼ� ���� �ൿ�� ����
				   if (pDoc->currentObj->getSelect() == TRUE){
					   pDoc->isSelected = TRUE;
					   pDoc->drawing = TRUE;
					   pDoc->Original_Point = point;  //�� �̵��� �������� �Ǵ� ��ǥ
					   switch (pDoc->currentObj->getType()){
					   case line:
					   {
									pDoc->pLine = (YLine*)pDoc->currentObj;
									if (pDoc->pLine->getMRect()[0].PtInRect(point)){  // ������ Ŭ��
										pDoc->sPoint = point;
										pDoc->pLine->setSPoint(pDoc->sPoint);
										pDoc->pLine->setMPoint(-1);  //�������̵�
									}
									else if (pDoc->pLine->getMRect()[1].PtInRect(point)){	// ���� Ŭ��
										pDoc->ePoint = point;
										pDoc->pLine->setEPoint(pDoc->ePoint);
										pDoc->pLine->setMPoint(1);  //�����̵�
										break;
									}
									else if (pDoc->pLine->checkRgn(point)) {		//�� �� ���� Ŭ��
										pDoc->pLine->setMPoint(0); //��ü�̵�
									}
									Invalidate();
									break;
					   }
					   case polyline:
					   {
										pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
										pDoc->pPolyLine->drawCircle(&dc);

										for (int i = 0; i < pDoc->pPolyLine->getPolyList()->GetSize(); i++){
											if (pDoc->pPolyLine->getMRect()[i].PtInRect(point)){
												//pDoc->pPolyLine->setMRect(i, point);
												pDoc->pPolyLine->setIndex(i);
												pDoc->pPolyLine->setMoveSetting(1);  //�����̵�
												break;
											}
											else pDoc->pPolyLine->setMoveSetting(0);  //��ü�̵�
										}
										Invalidate();
										break;
					   }
					   case ellipse:
					   {
									   //Ÿ�� ���� �ϱ�
									   pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
									   if (pDoc->pLine->getMRect()[0].PtInRect(point)){  // ������ Ŭ��
										   pDoc->sPoint = point;
										   pDoc->pEllipse->setSPoint(pDoc->sPoint);
										   pDoc->pEllipse->setMPoint(-1);  //�������̵�
									   }
									   else if (pDoc->pEllipse->getMRect()[1].PtInRect(point)){	// ���� Ŭ��
										   pDoc->ePoint = point;
										   pDoc->pEllipse->setEPoint(pDoc->ePoint);
										   pDoc->pEllipse->setMPoint(1);  //�����̵�
										   break;
									   }
									   else if (pDoc->pEllipse->checkRgn(point)) {		//�� �� ���� Ŭ��
										   pDoc->pEllipse->setMPoint(0); //��ü�̵�
									   }
									   Invalidate();
									   break;

					   }
					   case text:
					   {
									break;
					   }
					   case choice:
					   {
									  break;
					   }
					   }
				   }
	}
	}
	CView::OnLButtonDown(nFlags, point);
}

void CYPaintEditView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);

	if (nFlags & MK_LBUTTON || pDoc->clickPolyLine){

		CPen pen(PS_SOLID, 1, RGB(0, 0, 255));
		CPen *oldPen = dc.SelectObject(&pen);
		switch (pDoc->yType){
		case line:
		{
					 pDoc->pLine = (YLine*)pDoc->currentObj;
					 pDoc->ePoint = point;  //���콺 �̵��Ҷ� ���� ���������� �ٲپ���� �׸����ִ�.
					 pDoc->pLine->setEPoint(point);
					 break;
		}
		case polyline:
		{
						 pDoc->ePoint = point;
						 pDoc->pPolyLine->setEPoint(pDoc->ePoint);
						 break;
		}
		case ellipse:
		{
						//���콺 �����϶�
						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->ePoint = point;
						pDoc->pEllipse->setEPoint(point);
						break;
		}
		case text:
		{
					 break;
		}

			//���� �ϋ� �̵� ��Ű����
		case choice:
		{
					   CPoint t_point = point - pDoc->Original_Point; //��ǥ ������
					   pDoc->Original_Point = point;
					   switch (pDoc->currentObj->getType()){
					   case line:
					   {
									pDoc->pLine = (YLine*)pDoc->currentObj;
									//���õǾ����� �̵� ���������� �ٸ� move����
									if (pDoc->isSelected){
										if (pDoc->pLine->getMPoint() == 0){  //��ü�̵�
											pDoc->pLine->moveAll(t_point.x, t_point.y);
											pDoc->pLine->setRgn();
										}
										else {
											pDoc->pLine->move(t_point.x, t_point.y);
											pDoc->pLine->setRgn();
										}
									}
									break;
					   }
					   case polyline:
					   {
										pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
										if (pDoc->pPolyLine->getMoveSetting() == 0){
											if (pDoc->pPolyLine->getSelect()){
												pDoc->pPolyLine->moveAll(t_point.x, t_point.y);
												pDoc->pPolyLine->setRgn();
											}
										}
										else {
											pDoc->pPolyLine->move(t_point.x, t_point.y);
											pDoc->pPolyLine->setRgn();
										}
										break;
					   }

					   case ellipse:
					   {
									   pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
									   //���õǾ����� �̵� ���������� �ٸ� move����
									   if (pDoc->isSelected){
										   if (pDoc->pEllipse->getMPoint() == 0){  //��ü�̵�
											   pDoc->pEllipse->moveAll(t_point.x, t_point.y);
											   pDoc->pEllipse->setRgn();
										   }
										   else {
											   pDoc->pEllipse->move(t_point.x, t_point.y);
											   pDoc->pEllipse->setRgn();
										   }
									   }
									   break;
					   }


					   }

					   break;
		}
		}
		Invalidate();
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
				 YLine* pline = new YLine(pDoc->sPoint, pDoc->ePoint);
				 pDoc->currentObj = pline;
				 pDoc->pLine = (YLine*)pDoc->currentObj;
				 pDoc->pLine->setLineColor(pDoc->lineColor);
				 pDoc->pLine->SetLineThick(pDoc->lineThick);
				 pDoc->pLine->SetLinePattern(pDoc->linePattern);
				 pDoc->pLine->setRgn();
				 pDoc->pLine->setSelect(FALSE);
				 pDoc->pLine->setType(line);
				 pDoc->obj_List.AddTail(pDoc->pLine);
				 pDoc->currentObj = NULL;
				 pDoc->drawing = FALSE;
				 break;

	}
	case polyline:
	{
					 //	pDoc->currentObj->setType(polyline);

					 break;
	}
	case text:
	{
				 pDoc->currentObj->setType(text);
				 break;
	}

	case ellipse:
	{/*
	 //���콺 ����
	 dc.Ellipse(pDoc->sPoint.x, pDoc->sPoint.y, point.x, point.y);
	 ReleaseCapture();
	 pDoc->yType = choice;
	 */
					YEllipse* ellipse = new YEllipse(pDoc->sPoint, pDoc->ePoint);
					pDoc->currentObj = ellipse;
					pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
					pDoc->pEllipse->setLineColor(pDoc->lineColor);
					pDoc->pEllipse->SetLineThick(pDoc->lineThick);
					ellipse->SetLinePattern(pDoc->linePattern);
					pDoc->pEllipse->setRgn();
					pDoc->pEllipse->setSelect(FALSE);
					//pDoc->pEllipse->setType(ellipse);//�̰� �� �ȵǳ�???����
					pDoc->obj_List.AddTail(pDoc->currentObj);
					pDoc->currentObj = NULL;
					pDoc->drawing = FALSE;
					//	pDoc->yType = choice;
					//	dc.Ellipse(pDoc->sPoint.x, pDoc->sPoint.y, point.x, point.y);
					ReleaseCapture();
					break;
	}
	case choice:
	{
				   break;
	}
	}
	Invalidate();
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
		switch (pDoc->yType){
		case line:
		{
					 pDoc->pLine->setSPoint(pDoc->pLine->getSPoint());
					 pDoc->pLine->setEPoint(pDoc->pLine->getEPoint());
					 pDoc->pLine->drawCircle(&dc);
					 break;
		}
		case polyline:
		{
						 pDoc->pPolyLine->setEPoint(pDoc->ePoint);
						 pDoc->pPolyLine->drawCircle(&dc);
						 break;
		}
		case ellipse:
		{
						pDoc->pEllipse->setSPoint(pDoc->sPoint);
						pDoc->pEllipse->setEPoint(pDoc->ePoint);
						pDoc->pEllipse->drawCircle(&dc);
						break;

		}
		case choice:
		{
					   switch (pDoc->currentObj->getType()){
					   case line:
					   {
									pDoc->pLine = (YLine*)pDoc->currentObj;
									pDoc->pLine->drawCircle(&dc);
									break;
					   }
					   case polyline:
					   {
										pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
										pDoc->pPolyLine->drawCircle(&dc);
										break;
					   }
					   }
					   break;
		}
		}
		pDoc->currentObj->draw(&dc);

	}

	//////////////////////////////////////// Text //////////////////////////////////////////
	if (pDoc->textEditing){
		// ��Ʈ ���� �� ����
		CFont f;
		f.CreatePointFont(pDoc->ptext->getFontSize(), pDoc->ptext->getFont());
		dc.SelectObject(f);
		dc.SetBkColor(pDoc->ptext->getBkColor());
		dc.SetTextColor(pDoc->ptext->getFontColor());

		// ��Ʈ�� �ݿ��� ���ڿ�(�ؽ�Ʈ)�� ���� ���� �� ����
		CSize s = dc.GetTextExtent(pDoc->ptext->getText(), pDoc->ptext->getText().GetLength());

		// �ʱ� �ؽ�Ʈ �ڽ� ������ ���� �ڵ�
		CString cInitial = _T("t");
		CSize sInitial = dc.GetTextExtent(cInitial, cInitial.GetLength());

		// ePoint �� rect ����
		if (pDoc->ptext->getText().GetLength() == 0)
			pDoc->ptext->setEPoint(CPoint(pDoc->ptext->getSPoint().x + sInitial.cx, pDoc->ptext->getSPoint().y + sInitial.cy));
		else
			pDoc->ptext->setEPoint(CPoint(pDoc->ptext->getSPoint().x + s.cx, pDoc->ptext->getSPoint().y + s.cy));
		pDoc->ptext->setRect(pDoc->ptext->getSPoint(), pDoc->ptext->getEPoint());

		// ��¿� ���� ����
		CRect r(pDoc->ptext->getSPoint().x - 1, pDoc->ptext->getSPoint().y - 1, pDoc->ptext->getEPoint().x + 1, pDoc->ptext->getEPoint().y + 1);
		// ��¿� ������ ���� �� �� �귯�� ���� �� ����
		CPen pen(PS_DOT, 1, RGB(0, 0, 0));
		dc.SelectObject(pen);
		CBrush brush(pDoc->ptext->getBkColor());
		dc.SelectObject(brush);

		// ���� �� �ؽ�Ʈ ���
		dc.Rectangle(r);
		dc.DrawText(pDoc->ptext->getText(), pDoc->ptext->getRect(), NULL);

		// ĳ�� ���� �� ���
		if (pDoc->ptext->getText().GetLength() == 0)
			CreateSolidCaret(5, sInitial.cy);
		else
			CreateSolidCaret(5, s.cy);
		SetCaretPos(CPoint(pDoc->ptext->getSPoint().x + s.cx, pDoc->ptext->getSPoint().y));
		ShowCaret();
	}
	////////////////////////////////////////////////////////////////////////////////////////
}

void CYPaintEditView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) // Text
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->textEditing == TRUE){
		if (nChar == _T('\b')){ // ����� (delete Ű)
			if (pDoc->ptext->getText().GetLength() > 0){
				pDoc->tmp.GetBufferSetLength(pDoc->tmp.GetLength() - 1);
				pDoc->ptext->setText(pDoc->tmp);
			}
		}
		else if (nChar == VK_RETURN){ // �Է� ���� (enter Ű)
			pDoc->textEditing = FALSE;
			pDoc->obj_List.AddTail(pDoc->ptext);
			pDoc->tmp.Empty();
			HideCaret();
		}
		else{ // �Է�
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

	//������ �������ν� ��� ��ü ���ÿ��θ� FALSE��
	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos){
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		pDoc->currentObj->setSelect(FALSE);
	}
	pDoc->currentObj = NULL;
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

	CColorDialog dlg(RGB(255, 0, 0), CC_FULLOPEN);
	int result = dlg.DoModal();
	if (result == IDOK){
		pDoc->lineColor = dlg.GetColor();
		pDoc->pLine = (YLine*)pDoc->currentObj;
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
		pDoc->pLine->SetLineThick(pDoc->lineThick);
		pDoc->pLine->SetLinePattern(pDoc->linePattern);
		Invalidate();
	}

}


void CYPaintEditView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	if (pDoc->yType == polyline){
		pDoc->clickPolyLine = FALSE;
		pDoc->drawing = FALSE;
		pDoc->pPolyLine->setDrawPolyLine(FALSE);
		pDoc->pPolyLine->setRgn(); // ��������
		pDoc->pPolyLine->setSelect(FALSE);
		pDoc->pPolyLine->setType(polyline);
		pDoc->obj_List.AddTail(pDoc->pPolyLine);

		Invalidate();
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CYPaintEditView::MenuPolyLineButton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->yType = polyline;
}
