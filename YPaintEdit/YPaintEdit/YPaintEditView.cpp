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
	ON_COMMAND(ID_32797, &CYPaintEditView::OnDeleteClick)
	ON_COMMAND(ID_BUTTON4, &CYPaintEditView::OnRectangleButton)
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
	CYPaintEditDoc* pDoc = GetDocument();
	// Ŭ���� ������ ��ü�� ���ٸ� �˾��޴��� �ȶ��
	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->checkRgn(point) == TRUE){
			pDoc->currentObj->setSelect(TRUE);
			ClientToScreen(&point);
			OnContextMenu(this, point);
			break;
		}
	}

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










////////////////////////////// CYPaintEditView �޽��� ó���� //////////////////////////////


// ������ �׸��� �Լ� //
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
			pDoc->pLine->draw(&dc);
			break;
		}
		case polyline:
		{
			pDoc->pPolyLine->setEPoint(pDoc->pPolyLine->getEPoint());
			pDoc->pPolyLine->drawCircle(&dc);
			pDoc->pPolyLine->draw(&dc);
			break;
		}
		case ellipse:
		{
			pDoc->pEllipse->setSPoint(pDoc->pEllipse->getSPoint());
			pDoc->pEllipse->setEPoint(pDoc->pEllipse->getEPoint());
			pDoc->pEllipse->drawCircle(&dc);
			pDoc->pEllipse->draw(&dc);
			break;
		}

		case rectangle:
		{
			pDoc->pRectangle->setSPoint(pDoc->pRectangle->getSPoint());
			pDoc->pRectangle->setEPoint(pDoc->pRectangle->getEPoint());
			pDoc->pRectangle->drawCircle(&dc);
			pDoc->pRectangle->draw(&dc);
			break;


		}
		case choice:
		{
			switch (pDoc->currentObj->getType()){
			case line:
			{
				pDoc->pLine = (YLine*)pDoc->currentObj;
				pDoc->pLine->drawCircle(&dc);
				pDoc->pLine->draw(&dc);
				break;
			}
			case polyline:
			{
				pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
				pDoc->pPolyLine->drawCircle(&dc);
				pDoc->pPolyLine->draw(&dc);
				break;
			}
			///////////////////////////////////
			/////��� �߰���   ///////////////////////////////////
			/////��� �߰���   ///////////////////////////////////
			/////��� �߰���   ///////////////////////////////////
			/////��� �߰���   ///////////////////////////////////
			/////��� �߰���   ///////////////////////////////////
			/////��� �߰���   ///////////////////////////////////
			/////��� �߰���   ///////////////////////////////////
			/////��� �߰���   ///////////////////////////////////
			/////��� �߰���
			case ellipse:
			{
				pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
				pDoc->pEllipse->drawCircle(&dc);
				pDoc->pEllipse->draw(&dc);
				break;
			}
			case rectangle:
			{
				pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
				pDoc->pRectangle->drawCircle(&dc);
				pDoc->pRectangle->draw(&dc);
				break;
			}


			default:
				break;
			}
			break;
		}
		default:
			break;
		}
		//	pDoc->currentObj->draw(&dc);

	}

	//////////////////////////////////////// Text //////////////////////////////////////////
	if (pDoc->textEditing){
		// ��Ʈ ���� �� ����
		CFont f;
		f.CreatePointFont(pDoc->pText->getFontSize(), pDoc->pText->getFont());
		dc.SelectObject(f);
		dc.SetBkColor(pDoc->pText->getBkColor());
		dc.SetTextColor(pDoc->pText->getFontColor());

		// ��Ʈ�� �ݿ��� ���ڿ�(�ؽ�Ʈ)�� ���� ���� �� ����
		CSize s = dc.GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());

		// �ʱ� �ؽ�Ʈ �ڽ� ������ ���� �ڵ�
		CString cInitial = _T("t");
		CSize sInitial = dc.GetTextExtent(cInitial, cInitial.GetLength());

		// ePoint �� rect ����
		if (pDoc->pText->getText().GetLength() == 0)
			pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + sInitial.cx, pDoc->pText->getSPoint().y + sInitial.cy));
		else
			pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
		pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());

		// ��¿� ���� ����
		CRect r(pDoc->pText->getSPoint().x - 1, pDoc->pText->getSPoint().y - 1, pDoc->pText->getEPoint().x + 1, pDoc->pText->getEPoint().y + 1);
		// ��¿� ������ ���� �� �� �귯�� ���� �� ����
		CPen pen(PS_DOT, 1, RGB(0, 0, 0));
		dc.SelectObject(pen);
		CBrush brush(pDoc->pText->getBkColor());
		dc.SelectObject(brush);

		// ���� �� �ؽ�Ʈ ���
		dc.Rectangle(r);
		dc.DrawText(pDoc->pText->getText(), pDoc->pText->getRect(), NULL);

		// ĳ�� ���� �� ���
		if (pDoc->pText->getText().GetLength() == 0)
			CreateSolidCaret(5, sInitial.cy);
		else
			CreateSolidCaret(5, s.cy);
		SetCaretPos(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y));
		ShowCaret();
	}
	////////////////////////////////////////////////////////////////////////////////////////
}


// Ű���� �Է��� �޴� �Լ� // 
void CYPaintEditView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) // Text
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->textEditing == TRUE){
		if (nChar == _T('\b')){ // ����� (delete Ű)
			if (pDoc->pText->getText().GetLength() > 0){
				pDoc->tmp.GetBufferSetLength(pDoc->tmp.GetLength() - 1);
				pDoc->pText->setText(pDoc->tmp);
			}
		}
		else if (nChar == VK_RETURN){ // �Է� ���� (enter Ű)
			pDoc->textEditing = FALSE;
			pDoc->obj_List.AddTail(pDoc->pText);
			pDoc->tmp.Empty();
			HideCaret();
		}
		else{ // �Է�
			pDoc->tmp.AppendChar(nChar);
			pDoc->pText->setText(pDoc->tmp);
		}
		Invalidate();
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


// ���콺 Ŭ��, �̺�Ʈ ó�� �Լ��� //
void CYPaintEditView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);

	pDoc->drawing = FALSE;

	switch (pDoc->yType){
		// ������ ���̽���  ������ �ʱ�ȭ , doc�� �� ��ü�����ͷ� ���� ,Ÿ�� ,���ð�(TRUE),drawing ,i
	case line:
	{
		//�ʱ�ȭ
		pDoc->pLine = new YLine(point, point, 1, 1, PS_SOLID);
		pDoc->pLine->setType(line);
		pDoc->pLine->setSelect(TRUE);
		pDoc->drawing = TRUE;
		break;
	}
	case polyline:
	{
		if (pDoc->clickPolyLine == FALSE){   //���� ����
			pDoc->pPolyLine = new YPolyLine(1, 1, PS_SOLID);
			pDoc->pPolyLine->setSelect(TRUE);
			pDoc->pPolyLine->addPoint(point);
			pDoc->pPolyLine->setType(polyline);
			pDoc->pPolyLine->setEPoint(point);
			pDoc->pPolyLine->setDrawPolyLine(TRUE);
			pDoc->drawing = TRUE;
			pDoc->clickPolyLine = TRUE;

		}
		else{   //������������ Ŭ���Ҷ� ����
			pDoc->drawing = TRUE;
			pDoc->pPolyLine->addPoint(point);
		}
		break;
	}
	case text:
	{
		if (pDoc->textEditing == FALSE){
			pDoc->pText = new YText(point);
			pDoc->pText->setType(text);
			pDoc->textEditing = TRUE;
		}
		else {
			pDoc->obj_List.AddTail(pDoc->pText);
			pDoc->tmp.Empty();
			pDoc->textEditing = FALSE;
			HideCaret();
		}
		break;
	}
	case ellipse:
	{
		pDoc->pEllipse = new YEllipse(point, point, 1, 1, PS_SOLID);
		pDoc->pEllipse->setSelect(TRUE);
		pDoc->pEllipse->setType(ellipse);
		pDoc->drawing = TRUE;
		break;
	}

	case rectangle:
	{
		pDoc->pRectangle = new YRectangle(point, point, 1, 1, PS_SOLID);
		pDoc->pRectangle->setSelect(TRUE);
		pDoc->pRectangle->setType(rectangle);
		pDoc->drawing = TRUE;
		break;

	}
	case choice:
	{
		
				   //List���� ���õ� ��ü �ϳ��� ������ TRUE�ιٲٰ� ���� (�׷�ȭ�ϰԵǸ� �迭�Ǵ� ����Ʈ �μ����ؾ��Ҳ�����)
					//�������ִ� �ܰ�
				   if (pDoc->currentObj != NULL)	{
				   pDoc->currentObj->setSelect(FALSE);
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

		if (pDoc->currentObj == NULL) break;   //���� ���õ� ��ü�� ã�Ҵµ��� ��ü�� ������ �ƹ��͵� ����ȵǰ� �������� (����ó��)

		//���õ� ��ü�����ؼ� ���� �ൿ�� ����
		if (pDoc->currentObj->getSelect() == TRUE){
			pDoc->drawing = TRUE;
			pDoc->Original_Point = point;  //�� �̵��� �������� �Ǵ� ��ǥ
			switch (pDoc->currentObj->getType()){
			case line:
			{
				pDoc->pLine = (YLine*)pDoc->currentObj;
				if (pDoc->pLine->getMRect()[0].PtInRect(point)){  // ������ Ŭ��
					pDoc->pLine->setSPoint(point);
					pDoc->pLine->setMPoint(-1);  //�������̵�
				}
				else if (pDoc->pLine->getMRect()[1].PtInRect(point)){	// ���� Ŭ��
					pDoc->pLine->setEPoint(point);
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
				//pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
				pDoc->pPolyLine->drawCircle(&dc);

				for (int i = 0; i < pDoc->pPolyLine->getPolyList()->GetSize(); i++){
					if (pDoc->pPolyLine->getMRect()[i].PtInRect(point)){
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
					pDoc->pEllipse->setSPoint(point);
					pDoc->pEllipse->setMPoint(-1);  //�������̵�
				}
				else if (pDoc->pEllipse->getMRect()[1].PtInRect(point)){	// ���� Ŭ��
					pDoc->pEllipse->setEPoint(point);
					pDoc->pEllipse->setMPoint(1);  //�����̵�
					break;
				}
				else if (pDoc->pEllipse->checkRgn(point)) {		//�� �� ���� Ŭ��
					pDoc->pEllipse->setMPoint(0); //��ü�̵�
				}
				Invalidate();
				break;

			}


			case rectangle:
			{

				pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
				if (pDoc->pLine->getMRect()[0].PtInRect(point)){  // ������ Ŭ��
					pDoc->pRectangle->setSPoint(point);
					pDoc->pRectangle->setMPoint(-1);  //�������̵�
				}
				else if (pDoc->pRectangle->getMRect()[1].PtInRect(point)){	// ���� Ŭ��
					pDoc->pRectangle->setEPoint(point);
					pDoc->pRectangle->setMPoint(1);  //�����̵�
					break;
				}
				else if (pDoc->pRectangle->checkRgn(point)) {		//�� �� ���� Ŭ��
					pDoc->pRectangle->setMPoint(0); //��ü�̵�
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
			default:
				break;
			}

		}
	}
	default:
		break;
	}
	
	CView::OnLButtonDown(nFlags, point);
}
void CYPaintEditView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);

	if (nFlags & MK_LBUTTON || pDoc->clickPolyLine){

		switch (pDoc->yType){
		case line:
		{
			pDoc->pLine->setEPoint(point);
			break;
		}
		case polyline:
		{
			pDoc->pPolyLine->setEPoint(point);
			break;
		}
		case ellipse:
		{
			pDoc->pEllipse->setEPoint(point);
			break;
		}

		case rectangle:
		{

			pDoc->pRectangle->setEPoint(point);
			break;

		}
		case text:
		{
			break;
		}

		//���� �ϋ� �̵� ��Ű����
		case choice:
		{
			if (pDoc->currentObj == NULL) break;  //����� Ŭ�������� (���ܻ�Ȳ)


			CPoint t_point = point - pDoc->Original_Point; //��ǥ ������
			pDoc->Original_Point = point;
			switch (pDoc->currentObj->getType()){
			case line:
			{
				pDoc->pLine = (YLine*)pDoc->currentObj;
				//���õǾ����� �̵� ���������� �ٸ� move����
				if (pDoc->pLine->getSelect()){
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
				if (pDoc->pEllipse->getSelect()){
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

			case rectangle:
			{
				pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
				//���õǾ����� �̵� ���������� �ٸ� move����
				if (pDoc->pRectangle->getSelect()){
					if (pDoc->pRectangle->getMPoint() == 0){  //��ü�̵�
						pDoc->pRectangle->moveAll(t_point.x, t_point.y);
						pDoc->pRectangle->setRgn();
					}
					else {
						pDoc->pRectangle->move(t_point.x, t_point.y);
						pDoc->pRectangle->setRgn();
					}
				}
				break;

			}
			default:
				break;
			}
		}
		default:
			break;
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
	//pDoc->ePoint = point;

	switch (pDoc->yType){
	case line:
	{
		pDoc->pLine->setRgn();
		pDoc->pLine->setSelect(FALSE);
		pDoc->obj_List.AddTail(pDoc->pLine);
		pDoc->drawing = FALSE;
		break;

	}
	case polyline:
	{
		break;
	}
	case text:
	{
		//pDoc->currentObj->setType(text);
		break;
	}

	case ellipse:
	{
		pDoc->pEllipse->setRgn();
		pDoc->pEllipse->setSelect(FALSE);
		pDoc->obj_List.AddTail(pDoc->pEllipse);
		pDoc->drawing = FALSE;
		ReleaseCapture();
		break;
	}
	case rectangle:
	{
		pDoc->pRectangle->setRgn();
		pDoc->pRectangle->setSelect(FALSE);
		pDoc->obj_List.AddTail(pDoc->pRectangle);
		pDoc->drawing = FALSE;
		ReleaseCapture();
		break;


	}

	case choice:
	{
		break;
	}
	default:
		break;
	}
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
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


// ���� �޴�, ����Ʈ ó�� �Լ��� //
void CYPaintEditView::MenuLineButton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = line;

	//pDoc->lineColor = RGB(0, 0, 0);
	//pDoc->lineThick = 1;
	//pDoc->linePattern = 0;

	/*
	�޴� ���� Ŭ�� -> ��ü Ŭ�� -> �޴� �� Ŭ��-> �׸��� �� ��� ������ü�� ������ �����ִ� ������ �߻��߾���
	�޴��� Ŭ���ϸ� obj_List�� �ִ� select������ ���� FALSE�� ��ȯ
	*/
	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->getSelect() == TRUE) pDoc->currentObj->setSelect(FALSE);

	}
}
void CYPaintEditView::MenuPolyLineButton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = polyline;
	/*
	�޴� ���� Ŭ�� -> ��ü Ŭ�� -> �޴� �� Ŭ��-> �׸��� �� ��� ������ü�� ������ �����ִ� ������ �߻��߾���
	�޴��� Ŭ���ϸ� obj_List�� �ִ� select������ ���� FALSE�� ��ȯ
	*/
	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->getSelect() == TRUE) pDoc->currentObj->setSelect(FALSE);

	}
	//Invalidate();
}
void CYPaintEditView::MenuEllipseButton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = ellipse;
}
void CYPaintEditView::OnRectangleButton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = rectangle;
}

void CYPaintEditView::MenuTextButton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = text;
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


// ���콺 ��Ŭ�� �޴�, �̺�Ʈ ó�� �Լ��� //
void CYPaintEditView::RMenuColorButton() //���콺 �����ʹ�ư Ŭ���� -> �� Ŭ����
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	CColorDialog dlg(RGB(255, 0, 0), CC_FULLOPEN);
	int color; // ���̾�α׿��� ������ ������ ������ ����
	int result = dlg.DoModal();
	if (result == IDOK){
		color = dlg.GetColor();

		switch (pDoc->currentObj->getType()){
		case line:
		{
			pDoc->pLine = (YLine*)pDoc->currentObj;
			pDoc->pLine->setLineColor(color);
			break;
		}
		case polyline:
		{
			pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
			pDoc->pPolyLine->setLineColor(color);
			break;
		}
		default:
			break;
		}

		Invalidate();
	}
}
void CYPaintEditView::FigureSettingButton() //���콺 ������ ��ư Ŭ���� -> ���� ���� �ٲٱ�
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	YFigureDialog dlg;
	//��ü�� ���β� ���������� �������� �ܰ� (���̾�α׸� ��������)
	switch (pDoc->currentObj->getType()){
	case line:
	{
		pDoc->pLine = (YLine*)pDoc->currentObj;
		dlg.lineThick = pDoc->pLine->getLineThick();
		dlg.linePattern = pDoc->pLine->getLinePattern();
		break;
	}
	case polyline:
	{
		pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
		dlg.lineThick = pDoc->pPolyLine->getLineThick();
		dlg.linePattern = pDoc->pPolyLine->getLinePattern();
		break;
	}
	default:
		break;
	}

	int result = dlg.DoModal();  //��޶���
	if (result == IDOK){

		switch (pDoc->currentObj->getType()){
		case line:
		{
			pDoc->pLine = (YLine*)pDoc->currentObj;
			pDoc->pLine->setLineThick(dlg.lineThick);
			pDoc->pLine->setLinePattern(dlg.linePattern);
			break;
		}
		case polyline:
		{
			pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
			pDoc->pPolyLine->setLineThick(dlg.lineThick);
			pDoc->pPolyLine->setLinePattern(dlg.linePattern);
			break;
		}
		default:
			break;
		}

		Invalidate();
	}

}

/*
��� : �����Լ�
������ ��ưŬ���� �˾� -> ���� Ŭ���� ����Ǵ� �޼ҵ�
*/

void CYPaintEditView::OnDeleteClick()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	CPtrList tempList;

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	POSITION pos2 = tempList.GetHeadPosition();
	while (pos) {													//tempList�� ���õ������� ��ü�鸸 ����
		YObject* tmp = (YObject*)pDoc->obj_List.GetNext(pos);
		if (tmp->getSelect() == FALSE){
			tempList.AddTail(tmp);
		}
	}
	//�ٽ� obj_List�� �������ش�.
	if (tempList.IsEmpty() != 1){  // �׸� ��ü�� ������
		pDoc->obj_List.RemoveAll();
		pos = pDoc->obj_List.GetHeadPosition();
		pos2 = tempList.GetHeadPosition();
		while (pos2){
			YObject* tmp = (YObject*)tempList.GetNext(pos2);
			if (tmp->getSelect() == FALSE){
				pDoc->obj_List.AddTail(tmp);
			}
		}
		tempList.RemoveAll();
	}
	else {
		pDoc->obj_List.RemoveAll();
		pDoc->yType = default;
	}

	Invalidate();
}


