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
#include "MainFrm.h"
#include "YPaintEditDoc.h"
#include "YPaintEditView.h"
#include "TextEditDialog.h"
#include "YGroup.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CYPaintEditView

IMPLEMENT_DYNCREATE(CYPaintEditView, CView)

BEGIN_MESSAGE_MAP(CYPaintEditView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_CHAR()	
	ON_COMMAND(ID_MENUDEFAULTTBUTTON, &CYPaintEditView::OnMenudefaulttbutton)
	ON_UPDATE_COMMAND_UI(ID_MENUDEFAULTTBUTTON, &CYPaintEditView::OnUpdateMenudefaulttbutton)
	ON_COMMAND(ID_MENULINEBUTTON, &CYPaintEditView::OnMenulinebutton)
	ON_UPDATE_COMMAND_UI(ID_MENULINEBUTTON, &CYPaintEditView::OnUpdateMenulinebutton)
	ON_COMMAND(ID_MENUPOLYLINEBUTTON, &CYPaintEditView::OnMenupolylinebutton)
	ON_UPDATE_COMMAND_UI(ID_MENUPOLYLINEBUTTON, &CYPaintEditView::OnUpdateMenupolylinebutton)
	ON_COMMAND(ID_MENURECTANGLEBUTTON, &CYPaintEditView::OnMenurectanglebutton)
	ON_UPDATE_COMMAND_UI(ID_MENURECTANGLEBUTTON, &CYPaintEditView::OnUpdateMenurectanglebutton)
	ON_COMMAND(ID_MENUELLIPSEBUTTON, &CYPaintEditView::OnMenuellipsebutton)
	ON_UPDATE_COMMAND_UI(ID_MENUELLIPSEBUTTON, &CYPaintEditView::OnUpdateMenuellipsebutton)
	ON_COMMAND(ID_TEXTEDITBUTTON, &CYPaintEditView::OnTexteditbutton)
	ON_UPDATE_COMMAND_UI(ID_TEXTEDITBUTTON, &CYPaintEditView::OnUpdateTexteditbutton)
	ON_COMMAND(ID_MENUFONTSIZE, &CYPaintEditView::OnMenufontsize)
	ON_COMMAND(ID_MENUFONT, &CYPaintEditView::OnMenufont)
	ON_COMMAND(ID_MENUTEXTBUTTON, &CYPaintEditView::OnMenutextbutton)
	ON_COMMAND(ID_MENUFONTCOLOR, &CYPaintEditView::OnMenufontcolor)
	ON_COMMAND(ID_MENUFONTBKCOLOR, &CYPaintEditView::OnMenufontbkcolor)
	ON_UPDATE_COMMAND_UI(ID_MENUFONTSIZE, &CYPaintEditView::OnUpdateMenufontsize)
	ON_UPDATE_COMMAND_UI(ID_MENUFONT, &CYPaintEditView::OnUpdateMenufont)
	ON_UPDATE_COMMAND_UI(ID_MENUTEXTBUTTON, &CYPaintEditView::OnUpdateMenutextbutton)
	ON_UPDATE_COMMAND_UI(ID_MENUFONTCOLOR, &CYPaintEditView::OnUpdateMenufontcolor)
	ON_UPDATE_COMMAND_UI(ID_MENUFONTBKCOLOR, &CYPaintEditView::OnUpdateMenufontbkcolor)
	ON_COMMAND(ID_MENULINETHICK, &CYPaintEditView::OnMenulinethick)
	ON_COMMAND(ID_MENULINEPATTERN, &CYPaintEditView::OnMenulinepattern)
	ON_COMMAND(ID_MENUSIDEPATTERN, &CYPaintEditView::OnMenusidepattern)
	ON_COMMAND(ID_MENULINECOLOR, &CYPaintEditView::OnMenulinecolor)
	ON_COMMAND(ID_MENUSIDECOLOR, &CYPaintEditView::OnMenusidecolor)
	ON_UPDATE_COMMAND_UI(ID_MENULINETHICK, &CYPaintEditView::OnUpdateMenulinethick)
	ON_UPDATE_COMMAND_UI(ID_MENULINEPATTERN, &CYPaintEditView::OnUpdateMenulinepattern)
	ON_UPDATE_COMMAND_UI(ID_MENUSIDEPATTERN, &CYPaintEditView::OnUpdateMenusidepattern)
	ON_COMMAND(ID_GROUPSBUTTON, &CYPaintEditView::OnGroupsbutton)
	ON_UPDATE_COMMAND_UI(ID_GROUPSBUTTON, &CYPaintEditView::OnUpdateGroupsbutton)
	ON_COMMAND(ID_DELETEGROUPBUTTON, &CYPaintEditView::OnDeletegroupbutton)
	ON_UPDATE_COMMAND_UI(ID_DELETEGROUPBUTTON, &CYPaintEditView::OnUpdateDeletegroupbutton)
	ON_COMMAND(ID_GROUPLINETHICK, &CYPaintEditView::OnGrouplinethick)
	ON_UPDATE_COMMAND_UI(ID_GROUPLINETHICK, &CYPaintEditView::OnUpdateGrouplinethick)
	ON_COMMAND(ID_GROUPLINEPATTERN, &CYPaintEditView::OnGrouplinepattern)
	ON_UPDATE_COMMAND_UI(ID_GROUPLINEPATTERN, &CYPaintEditView::OnUpdateGrouplinepattern)
	ON_COMMAND(ID_GROUPSIDEPATTERN, &CYPaintEditView::OnGroupsidepattern)
	ON_UPDATE_COMMAND_UI(ID_GROUPSIDEPATTERN, &CYPaintEditView::OnUpdateGroupsidepattern)
	ON_COMMAND(ID_EDIT_CUT, &CYPaintEditView::OnEditCut)
	ON_COMMAND(ID_EDIT_PASTE, &CYPaintEditView::OnEditPaste)
	ON_COMMAND(ID_EDIT_COPY, &CYPaintEditView::OnEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, &CYPaintEditView::OnUpdateEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, &CYPaintEditView::OnUpdateEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, &CYPaintEditView::OnUpdateEditPaste)
	ON_COMMAND(ID_EDIT_LINECOLOR, &CYPaintEditView::OnEditLinecolor)
	ON_COMMAND(ID_EDIT_FIGURESETTING, &CYPaintEditView::OnEditFiguresetting)
	ON_COMMAND(ID_EDIT_DELETE, &CYPaintEditView::OnEditDelete)
	ON_COMMAND(ID_EDIT_DELETEPOINT, &CYPaintEditView::OnEditDeletepoint)
	ON_COMMAND(ID_EDIT_SIDECOLOR, &CYPaintEditView::OnEditSidecolor)
	ON_UPDATE_COMMAND_UI(ID_EDIT_LINECOLOR, &CYPaintEditView::OnUpdateEditLinecolor)
	ON_UPDATE_COMMAND_UI(ID_EDIT_FIGURESETTING, &CYPaintEditView::OnUpdateEditFiguresetting)
	ON_UPDATE_COMMAND_UI(ID_EDIT_DELETE, &CYPaintEditView::OnUpdateEditDelete)
	ON_UPDATE_COMMAND_UI(ID_EDIT_DELETEPOINT, &CYPaintEditView::OnUpdateEditDeletepoint)
	ON_UPDATE_COMMAND_UI(ID_EDIT_SIDECOLOR, &CYPaintEditView::OnUpdateEditSidecolor)
	ON_COMMAND(ID_MENUFONTDIA, &CYPaintEditView::OnMenufontdia)
END_MESSAGE_MAP()

// CYPaintEditView ����/�Ҹ�

CYPaintEditView::CYPaintEditView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	// ���� �޴� �ʱ�ȭ //
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;

	texts = _T("");
	font = _T("����");
	fontColor = RGB(0, 0, 0);
	bkColor = RGB(255, 255, 255);
	fontSize = 10;

	lineThick = 1;
	linePattern = 0;
	sidePattern = 0;
	sidePatternflag2 = FALSE;

	lineColor = RGB(0, 0, 0);
	sideColor = RGB(255, 255, 255);


	// �˾� �޴� �ʱ�ȭ //
	/* �ʱ�ȭ ��Ű��
	menu_cut;
	menu_paste;
	menu_copy;
	menu_Color;
	menu_Figiure;
	menu_Delete;
	*/
	cutObj = NULL;
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
		if (pDoc->currentObj->checkRgn(point) == TRUE && pDoc->currentObj->getSelect() == TRUE){			//Ŭ���� ���� �����ȿ� �ְ� ��ü�� ���õǾ��� �ִ»�Ȳ������ �޴��� ����.
			//pDoc->currentObj->setSelect(TRUE);
			if (pDoc->currentObj->getType() == polyline){													//polyline �� ���� ��������Ⱑ �����Ƿ�
				for (int i = 0; i < pDoc->pPolyLine->getPolyList()->GetSize(); i++){
					if (pDoc->pPolyLine->getMRect()[i].PtInRect(point)){
						pDoc->deletePosition = i;															//������ ��ġ ����
						break;
					}
				}
			}
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


// ȭ�鿡 ����ϴ� �Լ��� //
void CYPaintEditView::OnPaint() // ��� : cdc��ü �����ؼ� �޸�dc�� �����ؼ� ����ϴ� �Լ�
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CBitmap bitmap;

	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);															//�޸� dc ����
	bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());						//��üȭ���� ������� bitmap ����
	dcmem.SelectObject(&bitmap);															//��Ʈ�� ����

	dcmem.SelectStockObject(NULL_PEN);
	dcmem.Rectangle(&rect);

	Paint(&dcmem);
	dc.BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &dcmem, 0, 0, SRCCOPY);		//�޸𸮿� �ִ� ��Ʈ���� �׸���.
	dcmem.DeleteDC();
	bitmap.DeleteObject();
}
void CYPaintEditView::Paint(CDC* dc) // ��� : � ������ �׸��� �Ǵ�
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.

	CYPaintEditDoc* pDoc = GetDocument();

	// ���� ����Ʈ�� �ִ� ������ �׸��� �κ�
	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		YObject* tmp = (YObject*)pDoc->obj_List.GetNext(pos);
		tmp->draw(dc);
	}

	// ���� �׸����ִ� ��,�ٰ���,Ÿ��,���簢���� �׸��� �κ�  
	if (pDoc->drawing){
		switch (pDoc->yType){
		case line:
			pDoc->pLine->draw(dc);
			break;
		case polyline:
			pDoc->pPolyLine->draw(dc);
			break;
		case ellipse:
			pDoc->pEllipse->draw(dc);
			break;
		case rectangle:
			pDoc->pRectangle->draw(dc);
			break;
		case choice:
			if (pDoc->currentObj == NULL) break;
			switch (pDoc->currentObj->getType()){
				case line:
					pDoc->pLine = (YLine*)pDoc->currentObj;
					pDoc->pLine->draw(dc);
					break;
				case polyline:
					pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
					pDoc->pPolyLine->draw(dc);
					break;
				case ellipse:
					pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
					pDoc->pEllipse->draw(dc);
					break;
				case rectangle:
					pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
					pDoc->pRectangle->draw(dc);
					break;
				default:
					break;
			}
			break;
		default:
			break;
		}
	}

	// ���� �׸����ִ� �ؽ�Ʈ�� �׸��� �κ�
	//////////////////////////////////////// Text //////////////////////////////////////////
	if (pDoc->textEditing){
		// ��Ʈ ���� �� ����
		CFont f;
		LOGFONT lf;
		//	f.CreatePointFont(pDoc->pText->getFontSize(), pDoc->pText->getFont());
		//f.CreatePointFont(fontSize, font);
		//���⼳��
		if (pDoc->pText->getBold()) lf.lfWeight = FW_BOLD;
		else lf.lfWeight = FW_NORMAL;
		lf.lfWidth = 0;
		lf.lfHeight = pDoc->pText->getFontSize();						//���� ����
		lf.lfStrikeOut = pDoc->pText->getStrikeOut();						//��Ҽ� ����
		lf.lfUnderline = pDoc->pText->getUnderLine();						//���ټ���
		lf.lfItalic = pDoc->pText->getItalic();							//�����
		lf.lfEscapement = 0;							//���� ���� �ʱ�ȭ
		lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
		lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
		lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
		lf.lfQuality = DEFAULT_QUALITY;
		lf.lfCharSet = DEFAULT_CHARSET;
		wcscpy_s((lf.lfFaceName), _countof(lf.lfFaceName), pDoc->pText->getFont());
		
		f.CreateFontIndirect(&lf);
		dc->SelectObject(f);
		dc->SetBkColor(pDoc->pText->getBkColor());
		dc->SetTextColor(pDoc->pText->getFontColor());

		// ��Ʈ�� �ݿ��� ���ڿ�(�ؽ�Ʈ)�� ���� ���� �� ����
		CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());

		// �ʱ� �ؽ�Ʈ �ڽ� ������ ���� �ڵ�
		CString cInitial = _T("t");
		CSize sInitial = dc->GetTextExtent(cInitial, cInitial.GetLength());

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
		CPen* oldPen = dc->SelectObject(&pen);
		dc->SelectObject(pen);
		CBrush brush(pDoc->pText->getBkColor());
		dc->SelectObject(brush);

		// ���� �� �ؽ�Ʈ ���
		dc->Rectangle(r);
		dc->DrawText(pDoc->pText->getText(), pDoc->pText->getRect(), NULL);
		dc->SelectObject(&oldPen);
		// ĳ�� ���� �� ���
		if (pDoc->pText->getText().GetLength() == 0)
			CreateSolidCaret(5, sInitial.cy);
		else
			CreateSolidCaret(5, s.cy);
		SetCaretPos(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y));
		ShowCaret();
	}
}
BOOL CYPaintEditView::OnEraseBkgnd(CDC* pDC)					
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	//������۸��ذ� ( ������ ũ�� ���� �� ��)
	return TRUE;
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
			pDoc->pText->setRgn();
			pDoc->pText->setSelect(FALSE);
			pDoc->obj_List.AddTail(pDoc->pText);
			pDoc->pText = NULL;
			pDoc->textEditing = FALSE;
			pDoc->tmp.Empty();
			HideCaret();
		}
		else{ // �Է�
			pDoc->tmp.AppendChar(nChar);
			pDoc->pText->setText(pDoc->tmp);
		}
		Invalidate(FALSE);
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}



// ���콺 Ŭ��, �̺�Ʈ ó�� �Լ��� //
void CYPaintEditView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);


	switch (pDoc->yType){
		// ������ ���̽���  ������ �ʱ�ȭ , doc�� �� ��ü�����ͷ� ���� ,Ÿ�� ,���ð�(TRUE),drawing ,i
	case line:
	{
				 //�ʱ�ȭ
				 pDoc->pLine = new YLine(point, point, lineColor, lineThick, linePattern);
				 pDoc->pLine->setOrder(pDoc->allNum++);
				 pDoc->pLine->setType(line);
				 pDoc->pLine->setSelect(TRUE);
				 pDoc->drawing = TRUE;
				 break;
	}
	case polyline:
	{
					 if (pDoc->clickPolyLine == FALSE){   //���� ����
						 pDoc->pPolyLine = new YPolyLine(lineColor, lineThick, linePattern);
						 pDoc->pPolyLine->setOrder(pDoc->allNum++);
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
	case ellipse:
	{
					pDoc->pEllipse = new YEllipse(point, point, lineColor, lineThick, linePattern, sideColor, sidePattern, sidePatternflag2);
					pDoc->pEllipse->setOrder(pDoc->allNum++);
					pDoc->pEllipse->setSelect(TRUE);
					pDoc->pEllipse->setType(ellipse);
					pDoc->drawing = TRUE;
					break;
	}
	case rectangle:
	{
					  pDoc->pRectangle = new YRectangle(point, point, lineColor, lineThick, linePattern, sideColor,sidePattern, sidePatternflag2);
					  pDoc->pRectangle->setOrder(pDoc->allNum++);
					  pDoc->pRectangle->setSelect(TRUE);
					  pDoc->pRectangle->setType(rectangle);
					  pDoc->drawing = TRUE;
					  break;
	}
	case text:
	{
				 if (pDoc->textEditing == FALSE){
					 pDoc->pText = new YText(point,font,fontColor,bkColor,fontSize,underline,strikeout,bold,italic);
					 pDoc->pText->setOrder(pDoc->allNum++);
					 pDoc->pText->setType(text);
					 pDoc->pText->setSelect(TRUE);
					 pDoc->textEditing = TRUE;
				 }
				 else {
					 pDoc->pText->setRgn();
					 pDoc->pText->setSelect(FALSE);
					 pDoc->obj_List.AddTail(pDoc->pText);
					 pDoc->pText = NULL;
					 pDoc->textEditing = FALSE;
					 pDoc->tmp.Empty();
					 HideCaret();
				 }
				 break;
	}
	case choice:
	{

				   // 4 // (���õ� ������ �ִ� ��쿡��) �ٽ� ������ ��  - ������ ������ ������ �����Ҽ���, ���ο� ������ �����Ҽ���, ������� �����Ҽ��� �����Ƿ� currentObj�� �ʱ�ȭ�ϰ�, ��ǥ�� ����Ͽ� �ٽ� ����Ʈ Ž��
				   if (pDoc->grouping == FALSE && pDoc->currentObj != NULL)	{
					   pDoc->currentObj->setSelect(FALSE);
					   pDoc->currentObj = NULL;
				   }


				   // 0 // ����Ʈ���� ��ǥ�� �ش��ϴ� ������ ã�� �κ�
				   POSITION pos = pDoc->obj_List.GetTailPosition();
				   while (pos) {
					   pDoc->currentObj = (YObject*)pDoc->obj_List.GetPrev(pos);

					   // ��ǥ�� �ش��ϴ� ������ ���� ���
					   if (pDoc->currentObj->checkRgn(point) == TRUE){
						   pDoc->currentObj->setSelect(TRUE);
						   if (pDoc->grouping == TRUE){
							   YObject* tmp;
							   int flag = 0;
							   POSITION pos = pDoc->current_group.GetHeadPosition();
							   while (pos) {
								   tmp = (YObject*)pDoc->current_group.GetNext(pos);
								   if (tmp->getOrder() == pDoc->currentObj->getOrder()){
									   flag = 1;
									   break;
								   }
							   }
							   if (flag == 0)
								   pDoc->current_group.AddTail(pDoc->currentObj);
						   }
						   break;
					   }

					   // ������ ���õǾ� ������ ������ �׷��� ���, �ٽ� ���������� ������ �����ص� ���õǰ� �����ϴ� �κ�
					   if (pDoc->currentObj == pDoc->pLine){
						   if (pDoc->pLine->getMRect()[0].PtInRect(point) || pDoc->pLine->getMRect()[1].PtInRect(point)) {
							   pDoc->currentObj->setSelect(TRUE);
							   break;
						   }
					   }
					   else if (pDoc->currentObj == pDoc->pEllipse){
						   if (pDoc->pEllipse->getMRect()[0].PtInRect(point) || pDoc->pEllipse->getMRect()[1].PtInRect(point)||
							   pDoc->pEllipse->getMRect()[2].PtInRect(point)|| pDoc->pEllipse->getMRect()[3].PtInRect(point)) {
							   pDoc->currentObj->setSelect(TRUE);
							   break;
						   }
					   }
					   else if (pDoc->currentObj == pDoc->pRectangle){
						   if (pDoc->pRectangle->getMRect()[0].PtInRect(point) || pDoc->pRectangle->getMRect()[1].PtInRect(point)||
							   pDoc->pRectangle->getMRect()[2].PtInRect(point)|| pDoc->pRectangle->getMRect()[3].PtInRect(point)) {
							   pDoc->currentObj->setSelect(TRUE);
							   break;
						   }


					   }
				   }


				   // 1 // (����Ʈ�� ��� �ִ� ���) ������� ������ ���
				   if (pDoc->currentObj == NULL) // ����Ʈ Ž���� �������� �ʾ����Ƿ� currentObj�� NULL�̴�.
					   break;


				   // 2 // (����Ʈ�� �׸��� �ִ� ���) ������� �����Ͽ� ����Ʈ���� ������ ã�� ���ϴ� ���
				   else if (pDoc->currentObj->getSelect() == FALSE) // �ڿ������� ����Ʈ�� ������ ��Ұ� currnetObj�� �ǰ� �װ��� �׻� FALSE���� �̿�
					   pDoc->currentObj = NULL;


				   // 3 // (����Ʈ�� �׸��� �ִ� ���) ����Ʈ���� ������ ã�� ���  - ���õ� ���� ����
				   else if (pDoc->currentObj->getSelect() == TRUE){
					   pDoc->Original_Point = point;  //�� �̵��� �������� �Ǵ� ��ǥ
					   pDoc->drawing = TRUE;

					   switch (pDoc->currentObj->getType()){
					   case line:
					   {
									pDoc->pLine = (YLine*)pDoc->currentObj;
									if (pDoc->pLine->getMRect()[0].PtInRect(point)){  // ������ Ŭ��
										pDoc->pLine->setSPoint(point);
										pDoc->pLine->setMoveMode(-1);  //�������̵�
									}
									else if (pDoc->pLine->getMRect()[1].PtInRect(point)){	// ���� Ŭ��
										pDoc->pLine->setEPoint(point);
										pDoc->pLine->setMoveMode(1);  //�����̵�
										break;
									}
									else if (pDoc->pLine->checkRgn(point)) {		//�� �� ���� Ŭ��
										pDoc->pLine->setMoveMode(0); //��ü�̵�
									}
									break;
					   }
					   case polyline:
					   {
										pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
										for (int i = 0; i < pDoc->pPolyLine->getPolyList()->GetSize(); i++){
											if (pDoc->pPolyLine->getMRect()[i].PtInRect(point)){
												pDoc->pPolyLine->setIndex(i);
												pDoc->pPolyLine->setMoveMode(1);  //�����̵�
												break;
											}
											else pDoc->pPolyLine->setMoveMode(0);  //��ü�̵�
										}
										break;
					   }
					   case ellipse:
					   {
									   //LBUtton Down�̾�
									   pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
									   //1��и�
									   if (pDoc->pEllipse->getMRect()[0].PtInRect(point)){  // ������ Ŭ��
										   pDoc->pEllipse->setSPoint(point);
										   pDoc->pEllipse->setMoveMode(-1);  //������ �̵�üũ
									   }
									   else if (pDoc->pEllipse->getMRect()[1].PtInRect(point)){	// ���� Ŭ�� 4��и�
										   pDoc->pEllipse->setEPoint(point);
										   pDoc->pEllipse->setMoveMode(1);  //���� �̵�üũ
										   break;
									   }
									   else if (pDoc->pEllipse->getMRect()[2].PtInRect(point)){	//3��и�
										   pDoc->pEllipse->setMixPoint(point);

										   pDoc->pEllipse->setMoveMode(2);  //3��и� �̵�üũ
										   break;
									   }
									   else if (pDoc->pEllipse->getMRect()[3].PtInRect(point)){	// 2��и�

										   pDoc->pEllipse->setMixPoint(point);
										   pDoc->pEllipse->setMoveMode(3);  //2��и� �̵� üũ
										   break;
									   }
									   else if (pDoc->pEllipse->checkRgn(point)) {		//�� �� ���� Ŭ��
										   pDoc->pEllipse->setMoveMode(0); //��ü�̵�
									   }
									   break;
					   }
					   case rectangle:
					   {
										 pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
										 if (pDoc->pRectangle->getMRect()[0].PtInRect(point)){  // ������ Ŭ��
											 pDoc->pRectangle->setSPoint(point);
											 pDoc->pRectangle->setMoveMode(-1);  //������ �̵�üũ
										 }
										 else if (pDoc->pRectangle->getMRect()[1].PtInRect(point)){	// ���� Ŭ�� 4��и�
											 pDoc->pRectangle->setEPoint(point);
											 pDoc->pRectangle->setMoveMode(1);  //���� �̵�üũ
											 break;
										 }
										 else if (pDoc->pRectangle->getMRect()[2].PtInRect(point)){	//3��и�
											 pDoc->pRectangle->setMixPoint(point);

											 pDoc->pRectangle->setMoveMode(2);  //3��и� �̵�üũ
											 break;
										 }
										 else if (pDoc->pRectangle->getMRect()[3].PtInRect(point)){	// 2��и�

											 pDoc->pRectangle->setMixPoint(point);
											 pDoc->pRectangle->setMoveMode(3);  //2��и� �̵� üũ
											 break;
										 }
										 else if (pDoc->pRectangle->checkRgn(point)) {		//�� �� ���� Ŭ��
											 pDoc->pRectangle->setMoveMode(0); //��ü�̵�
										 }

										 break;
					   }
					   case text:
					   {
									pDoc->pText = (YText*)pDoc->currentObj;
									break;
					   }
					   case group:
						   pDoc->pGroup = (YGroup*)pDoc->currentObj;
					   default:
						   break;
					   }
				   }
				   // �׷�ȭ �� �̵� ���ϰ�
				   if (pDoc->grouping == TRUE)
					   pDoc->currentObj = NULL;

				   UpdateMenu();
				   Invalidate(FALSE);
				   break;
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
		case choice:
		{
					   if (pDoc->currentObj == NULL) break;  // ����� Ŭ�������� (���ܻ�Ȳ)

					   CPoint t_point = point - pDoc->Original_Point; // ��ǥ ������
					   pDoc->Original_Point = point;

					   switch (pDoc->currentObj->getType()){
					   case line:
					   {
									//pDoc->pLine = (YLine*)pDoc->currentObj;
									//���õǾ����� �̵� ���������� �ٸ� move����
									if (pDoc->pLine->getSelect()){
										if (pDoc->pLine->getMoveMode() == 0){  //��ü�̵�
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
										//pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
										if (pDoc->pPolyLine->getMoveMode() == 0){
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
									   //pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
									   //���õǾ����� �̵� ���������� �ٸ� move����
									   if (pDoc->pEllipse->getSelect()){
										   if (pDoc->pEllipse->getMoveMode() == 0){  //��ü�̵�
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
										 //pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
										 //���õǾ����� �̵� ���������� �ٸ� move����
										 if (pDoc->pRectangle->getSelect()){
											 if (pDoc->pRectangle->getMoveMode() == 0){  //��ü�̵�
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
					   case text:
					   {
									pDoc->pText->setSPoint(pDoc->pText->getSPoint() + t_point);
									pDoc->pText->setEPoint(pDoc->pText->getEPoint() + t_point);
									pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
									pDoc->pText->setRgn();
									break;
					   }
					   case group:
						   pDoc->pGroup->setORect(pDoc->pGroup->getSPoint().x, pDoc->pGroup->getSPoint().y, pDoc->pGroup->getEPoint().x, pDoc->pGroup->getEPoint().y);
						   pDoc->pGroup->moveAll(t_point.x,t_point.y);
						   break;
					   default:
						   break;
					   }
		}
		default:
			break;
		}
		Invalidate(FALSE);
	}
	CView::OnMouseMove(nFlags, point);
}
void CYPaintEditView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);

	switch (pDoc->yType){
	case line:
	{
				 pDoc->pLine->setRgn();
				 pDoc->pLine->setSelect(FALSE);
				 pDoc->obj_List.AddTail(pDoc->pLine);
				 pDoc->pLine = NULL;
				 pDoc->drawing = FALSE;
				 break;
	}
	case polyline:
	{
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
	Invalidate(FALSE);
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
		pDoc->pPolyLine = NULL;
		Invalidate(FALSE);
	}

	if (pDoc->grouping == TRUE){
			
		// obj_List���� �׷�ȭ�� ������ ������ �κ�
		YObject* search;
		POSITION tpos;
		POSITION pos = pDoc->current_group.GetHeadPosition();
		while (pos) {
			search = pDoc->current_group.GetNext(pos);
			POSITION pos2 = pDoc->obj_List.GetHeadPosition();
			while (pos2) {
				tpos = pos2;
				pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos2);
				if (pDoc->currentObj->getOrder() == search->getOrder()){
					pDoc->obj_List.RemoveAt(tpos);
					break;
				}
			}
		}

		// �׷� ��ü ���� �� obj_List�� �����ϴ� �κ�
		YGroup* tgroup = new YGroup(pDoc->current_group);
		tgroup->setRgn();
		tgroup->setType(group);
		tgroup->setOrder(pDoc->allNum++);
		tgroup->setSelect(TRUE);
		pDoc->currentObj = tgroup;
		pDoc->obj_List.AddTail(tgroup);

		// �׷�ȭ ���� �ʱ�ȭ
		pDoc->current_group.RemoveAll();
		pDoc->grouping = FALSE;

		Invalidate();
	}
	CView::OnLButtonDblClk(nFlags, point);
}



// ���� �޴� ���� �Լ��� //

// ���� �г�
void CYPaintEditView::UpdateMenu(){ //��� : ��ü Ŭ�� ������ �ش�Ǵ� �Ӽ����� �޴��� �ֽ�ȭ
	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CYPaintEditDoc* pDoc = GetDocument();

	CMFCRibbonEdit* lineThick = (CMFCRibbonEdit*)main->getRibbon()->FindByID(ID_MENULINETHICK);
	CMFCRibbonComboBox* sidePattern = (CMFCRibbonComboBox*)main->getRibbon()->FindByID(ID_MENUSIDEPATTERN);
	CMFCRibbonComboBox* linePattern = (CMFCRibbonComboBox*)main->getRibbon()->FindByID(ID_MENULINEPATTERN);

	if (pDoc->currentObj != NULL){
		switch (pDoc->currentObj->getType()){
		case line:
		{
			CString str;
			lineThick->SetEditText(str);
			linePattern->OnSelectItem(pDoc->pLine->getLinePattern());
			break;
		}
		case polyline:
		{
			CString str;
			str.Format(_T("%d"), pDoc->pPolyLine->getLineThick());
			lineThick->SetEditText(str);
			linePattern->OnSelectItem(pDoc->pPolyLine->getLinePattern());
			break;
		}
		case ellipse:
		{
			CString str;
			str.Format(_T("%d"), pDoc->pEllipse->getLineThick());
			lineThick->SetEditText(str);
			linePattern->OnSelectItem(pDoc->pEllipse->getLinePattern());
			sidePattern->OnSelectItem(pDoc->pEllipse->getSidePattern());

			break;
		}
		case rectangle:
		{
			CString str;
			str.Format(_T("%d"), pDoc->pRectangle->getLineThick());
			lineThick->SetEditText(str);
			linePattern->OnSelectItem(pDoc->pRectangle->getLinePattern());
			sidePattern->OnSelectItem(pDoc->pRectangle->getSidePattern());
			break;
		}
		case text:
		{
			break;
		}
		default:
			break;
		}
	}
}
void CYPaintEditView::OnMenudefaulttbutton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	menu_Select = TRUE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;

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
void CYPaintEditView::OnUpdateMenudefaulttbutton(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck(menu_Select);
}
void CYPaintEditView::OnMenulinebutton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	menu_Select = FALSE;
	menu_Line = TRUE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;

	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = line;

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->getSelect() == TRUE) pDoc->currentObj->setSelect(FALSE);
	}
	pDoc->currentObj = NULL;
}
void CYPaintEditView::OnUpdateMenulinebutton(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck(menu_Line);
}
void CYPaintEditView::OnMenupolylinebutton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = TRUE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;

	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = polyline;

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->getSelect() == TRUE) pDoc->currentObj->setSelect(FALSE);
	}
	pDoc->currentObj = NULL;
}
void CYPaintEditView::OnUpdateMenupolylinebutton(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck(menu_PolyLine);
}
void CYPaintEditView::OnMenurectanglebutton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = TRUE;
	menu_Text = FALSE;

	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = rectangle;

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->getSelect() == TRUE) pDoc->currentObj->setSelect(FALSE);
	}
	pDoc->currentObj = NULL;
}
void CYPaintEditView::OnUpdateMenurectanglebutton(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck(menu_Rectangle);
}
void CYPaintEditView::OnMenuellipsebutton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = TRUE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;

	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = ellipse;

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->getSelect() == TRUE) pDoc->currentObj->setSelect(FALSE);
	}
	pDoc->currentObj = NULL;
}
void CYPaintEditView::OnUpdateMenuellipsebutton(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck(menu_Ellipse);
}
void CYPaintEditView::OnMenutextbutton()
{
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = TRUE;

	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = text;

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->getSelect() == TRUE) pDoc->currentObj->setSelect(FALSE);
	}
	pDoc->currentObj = NULL;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

}
void CYPaintEditView::OnUpdateMenutextbutton(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�
	pCmdUI->SetCheck(menu_Text);
}

// �ؽ�Ʈ�Ӽ� �г�
void CYPaintEditView::OnMenufontsize()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CMFCRibbonEdit* fontsize = (CMFCRibbonEdit*)main->getRibbon()->FindByID(ID_MENUFONTSIZE);
	fontSize = (_ttoi)(fontsize->GetEditText()) * 10;

	if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == text){
		pDoc->pText->setFontSize(fontSize);

		// ����ũ�⺯�� -> ���� ����,��Ʈ����,��������
		CDC* dc = GetDC();
		CFont f;
		f.CreatePointFont(pDoc->pText->getFontSize(), pDoc->pText->getFont());
		dc->SelectObject(f);
		CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());

		pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
		pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
		pDoc->pText->setRgn();

		Invalidate(FALSE);
	}	
}
void CYPaintEditView::OnMenufont()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CMFCRibbonComboBox* fonts = (CMFCRibbonComboBox*)main->getRibbon()->FindByID(ID_MENUFONT);
	font = fonts->GetEditText();

	if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == text){
		pDoc->pText->setFont(font);

		// ����ũ�⺯�� -> ���� ����,��Ʈ����,��������
		CDC* dc = GetDC();
		CFont f;
		f.CreatePointFont(pDoc->pText->getFontSize(), pDoc->pText->getFont());
		dc->SelectObject(f);
		CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());

		pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
		pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
		pDoc->pText->setRgn();

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnTexteditbutton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	if (pDoc->pText != NULL)
		texts = pDoc->pText->getText();

	TextEditDialog dlg(texts);
	int result = dlg.DoModal();

	if (result == IDOK){
		if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == text){
			pDoc->pText->setText(texts);

			// ����ũ�⺯�� -> ���� ����,��Ʈ����,��������
			CDC* dc = GetDC();
			CFont f;
			f.CreatePointFont(pDoc->pText->getFontSize(), pDoc->pText->getFont());
			dc->SelectObject(f);
			CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());

			pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
			pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
			pDoc->pText->setRgn();

			Invalidate(FALSE);
		}
	}
}
void CYPaintEditView::OnMenufontcolor()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CMFCRibbonColorButton* fontcolor = (CMFCRibbonColorButton*)main->getRibbon()->FindByID(ID_MENUFONTCOLOR);
	fontColor = fontcolor->GetColor();

	if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == text){
		pDoc->pText->setFontColor(fontColor);
		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnMenufontbkcolor()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CMFCRibbonColorButton* bkcolor = (CMFCRibbonColorButton*)main->getRibbon()->FindByID(ID_MENUFONTBKCOLOR);
	bkColor = bkcolor->GetColor();

	if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == text){
		pDoc->pText->setBkColor(bkColor);
		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnUpdateMenufontsize(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->yType == choice || pDoc->yType == text){
		pCmdUI->Enable(TRUE);
	}
	else
		pCmdUI->Enable(FALSE);
}
void CYPaintEditView::OnUpdateMenufont(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->yType == choice || pDoc->yType == text){
		pCmdUI->Enable(TRUE);
	}
	else
		pCmdUI->Enable(FALSE);
}
void CYPaintEditView::OnUpdateTexteditbutton(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->yType == choice || pDoc->yType == text){
		pCmdUI->Enable(TRUE);
	}
	else
		pCmdUI->Enable(FALSE);
}
void CYPaintEditView::OnUpdateMenufontcolor(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->yType == choice || pDoc->yType == text){
		pCmdUI->Enable(TRUE);
	}
	else
		pCmdUI->Enable(FALSE);
}
void CYPaintEditView::OnUpdateMenufontbkcolor(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->yType == choice || pDoc->yType == text){
		pCmdUI->Enable(TRUE);
	}
	else
		pCmdUI->Enable(FALSE);
}

// �����Ӽ� �г�
void CYPaintEditView::OnMenulinethick() //��� : �� ����
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();

	CMFCRibbonEdit* thick = (CMFCRibbonEdit*)main->getRibbon()->FindByID(ID_MENULINETHICK);
	lineThick = (_ttoi)(thick->GetEditText());

	if (pDoc->currentObj != NULL){							//��ü�� �������� �� 
		switch (pDoc->currentObj->getType()){
		case line:
		{
					 pDoc->pLine = (YLine*)pDoc->currentObj;
					 pDoc->pLine->setLineThick(lineThick);
					 break;
		}
		case polyline:
		{
						 pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
						 pDoc->pPolyLine->setLineThick(lineThick);
						 break;
		}
		case ellipse:
		{
						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->pEllipse->setLineThick(lineThick);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setLineThick(lineThick);
						  break;
		}
		default:
			break;
		}

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnUpdateMenulinethick(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == text) pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == text) pCmdUI->Enable(FALSE);
	}
}
void CYPaintEditView::OnMenulinepattern() //��� : �� ����
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CYPaintEditDoc* pDoc = GetDocument();
	CMFCRibbonComboBox* pattern = (CMFCRibbonComboBox*)main->getRibbon()->FindByID(ID_MENULINEPATTERN);

	linePattern = pattern->GetCurSel();

	if (pDoc->currentObj != NULL){											//��ü�� �������� �� 
		switch (pDoc->currentObj->getType()){
		case line:
		{
					 pDoc->pLine = (YLine*)pDoc->currentObj;
					 pDoc->pLine->setLinePattern(linePattern);
					 break;
		}
		case polyline:
		{
						 pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
						 pDoc->pPolyLine->setLinePattern(linePattern);
						 break;
		}
		case ellipse:
		{
						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->pEllipse->setLinePattern(linePattern);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setLinePattern(linePattern);
						  break;
		}
		default:
			break;
		}

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnUpdateMenulinepattern(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == text) pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == text) pCmdUI->Enable(FALSE);
	}
}
void CYPaintEditView::OnMenusidepattern() //��� : �� ����
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CYPaintEditDoc* pDoc = GetDocument();
	CMFCRibbonComboBox* pattern = (CMFCRibbonComboBox*)main->getRibbon()->FindByID(ID_MENUSIDEPATTERN);

	sidePattern = pattern->GetCurSel();

	if (sidePattern == 0) sidePatternflag2 = FALSE;										//DEFAULT�� ���õǾ����� flag�� ����
	else sidePatternflag2 = TRUE;

	if (pDoc->currentObj != NULL){																//��ü�� �������� �� 
		switch (pDoc->currentObj->getType()){
		case ellipse:
		{
						if (sidePatternflag2) pDoc->pEllipse->setPatternflag(TRUE);							//default�϶� ellipse�� flag������ ����
						else pDoc->pEllipse->setPatternflag(FALSE);

						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->pEllipse->setSidePattern(sidePattern);
						break;
		}
		case rectangle:
		{
						  if (sidePatternflag2) pDoc->pRectangle->setPatternflag(TRUE);						//default�϶� rectangle�� flag������ ����
						  else pDoc->pRectangle->setPatternflag(FALSE);

						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setSidePattern(sidePattern);
						  break;
		}
		default:
			break;
		}

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnUpdateMenusidepattern(CCmdUI *pCmdUI) //��� : �� ���� Update
{
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == ellipse || pDoc->currentObj->getType() == rectangle)pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == ellipse || pDoc->yType == rectangle)pCmdUI->Enable(TRUE);
		else  pCmdUI->Enable(FALSE);
	}

}

// �� �г�
void CYPaintEditView::OnMenulinecolor() //��� : �� ��
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CYPaintEditDoc* pDoc = GetDocument();
	CMFCRibbonColorButton* color = (CMFCRibbonColorButton*)main->getRibbon()->FindByID(ID_MENULINECOLOR);

	lineColor = color->GetColor();
	if (pDoc->currentObj != NULL){											//��ü�� �������� �� 
		switch (pDoc->currentObj->getType()){
		case line:
		{
					 pDoc->pLine = (YLine*)pDoc->currentObj;
					 pDoc->pLine->setLineColor(lineColor);
					 break;
		}
		case polyline:
		{
						 pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
						 pDoc->pPolyLine->setLineColor(lineColor);
						 break;
		}
		case ellipse:
		{
						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->pEllipse->setLineColor(lineColor);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setLineColor(lineColor);
						  break;
		}
		default:
			break;
		}

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnMenusidecolor() //��� : �� ��
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CYPaintEditDoc* pDoc = GetDocument();
	CMFCRibbonColorButton* color = (CMFCRibbonColorButton*)main->getRibbon()->FindByID(ID_MENUSIDECOLOR);

	sideColor = color->GetColor();

	if (pDoc->currentObj != NULL){										//��ü�� ����������
		switch (pDoc->currentObj->getType()){
		case ellipse:
		{
						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->pEllipse->setSideColor(sideColor);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setSideColor(sideColor);
						  break;
		}
		default:
			break;
		}

		Invalidate(FALSE);
	}

}

// �׷� �г�
void CYPaintEditView::OnGroupsbutton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->grouping = TRUE;
	if (pDoc->currentObj != NULL)
		pDoc->current_group.AddTail(pDoc->currentObj);
}
void CYPaintEditView::OnUpdateGroupsbutton(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->yType == choice)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);

	if (pDoc->grouping == TRUE)
		pCmdUI->SetCheck(TRUE);
	else 
		pCmdUI->SetCheck(FALSE);
}
void CYPaintEditView::OnDeletegroupbutton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj->getType() == group){
		// obj_List���� �׷��� ��ġ�� ã�� �κ�
		YObject* to;
		POSITION tpos;
		POSITION pos = pDoc->obj_List.GetHeadPosition();
		while (pos){
			tpos = pos;
			to = (YObject*)pDoc->obj_List.GetNext(pos);
			if (to->getOrder() == pDoc->currentObj->getOrder())
				break;
		}

		// �׷쿡�� ������ obj_List�� �����ϴ� �κ�
		CList<YObject*, YObject*>* tmp = ((YGroup*)pDoc->currentObj)->getList();
		pos = tmp->GetHeadPosition();
		while (pos){
			pDoc->obj_List.AddTail(tmp->GetNext(pos));
		}

		// obj_List���� �׷��� �����ϴ� �κ�
		pDoc->obj_List.RemoveAt(tpos);
		
		pDoc->currentObj = NULL;

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnUpdateDeletegroupbutton(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->yType == choice){
		pCmdUI->Enable(TRUE);
	}
	else
		pCmdUI->Enable(FALSE);
}
void CYPaintEditView::OnGrouplinethick()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}
void CYPaintEditView::OnUpdateGrouplinethick(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}
void CYPaintEditView::OnGrouplinepattern()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}
void CYPaintEditView::OnUpdateGrouplinepattern(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}
void CYPaintEditView::OnGroupsidepattern()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}
void CYPaintEditView::OnUpdateGroupsidepattern(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}

// Ŭ������ �г�
void CYPaintEditView::OnEditCut()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	 menu_cut = FALSE;
	 menu_copy = FALSE;
	 menu_paste = TRUE;
	 menu_cutcopyflag = TRUE;
	 menu_cutpaste = TRUE;
	CYPaintEditDoc* pDoc = GetDocument();

	cutObj = NULL;

	if (pDoc->currentObj != NULL){
		cutObj = pDoc->currentObj;

		POSITION pos = pDoc->obj_List.GetHeadPosition();
		POSITION tpos;
		if (pDoc->obj_List.GetSize() == 1){									//��ü�� �ϳ��� ����������
			pDoc->obj_List.RemoveAll();

		}
		else {
			while (pos) {
				tpos = pos;													//��ġ�� ������ �� �� ���� ���� �Ѿ��.
				YObject* tmp = (YObject*)pDoc->obj_List.GetNext(pos);
				if (tmp == pDoc->currentObj) break;
			}
			pDoc->obj_List.RemoveAt(tpos);
		}
		pDoc->currentObj = NULL;

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnEditPaste()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	

	if (cutObj != NULL && menu_cutpaste == TRUE){
		menu_cut = TRUE;
		menu_copy = TRUE;
		menu_paste = TRUE;
		if (menu_cutcopyflag == TRUE) menu_cutpaste = FALSE;
		CYPaintEditDoc* pDoc = GetDocument();
		cutObj->setSelect(FALSE);
		
		switch (cutObj->getType()){
		case line:
		{
			YLine* temp = (YLine*)cutObj;
			pDoc->pLine = new YLine(temp->getSPoint(), temp->getEPoint(), temp->getLineColor(), temp->getLineThick(), temp->getLinePattern());
			pDoc->pLine->setType(line);
			pDoc->pLine->setSelect(TRUE);
			if (menu_cutcopyflag == FALSE) pDoc->pLine->moveAll(20, 20);
			pDoc->pLine->setRgn();
			pDoc->drawing = FALSE;
			pDoc->obj_List.AddTail(pDoc->pLine);
			cutObj = pDoc->pLine;
			pDoc->currentObj = cutObj;
			break;
		}
		case polyline:
		{
			YPolyLine* temp = (YPolyLine*)cutObj;
			pDoc->pPolyLine = new YPolyLine(temp->getLineColor(), temp->getLineThick(), temp->getLinePattern());

			POSITION pos = temp->getPolyList()->GetHeadPosition();
			while (pos){
				CPoint point = temp->getPolyList()->GetNext(pos);
				pDoc->pPolyLine->addPoint(point);
			}
			pDoc->pPolyLine->setType(polyline);
			pDoc->pPolyLine->setSelect(TRUE);
			if (menu_cutcopyflag == FALSE) pDoc->pPolyLine->moveAll(20, 20);
			pDoc->pPolyLine->setRgn();
			pDoc->drawing = FALSE;
			pDoc->obj_List.AddTail(pDoc->pPolyLine);
			cutObj = pDoc->pPolyLine;
			pDoc->currentObj = cutObj;
			break;
		}
		case ellipse:
		{

			YEllipse* temp = (YEllipse*)cutObj;
			pDoc->pEllipse = new YEllipse(temp->getSPoint(), temp->getEPoint(), temp->getLineColor(), temp->getLineThick(), temp->getLinePattern(), temp->getSideColor(), temp->getSidePattern(), temp->getPatternflag());
			pDoc->pEllipse->setType(ellipse);
			pDoc->pEllipse->setSelect(TRUE);
			if (menu_cutcopyflag == FALSE) pDoc->pEllipse->moveAll(20, 20);
			pDoc->pEllipse->setRgn();
			pDoc->obj_List.AddTail(pDoc->pEllipse); 
			pDoc->drawing = FALSE;
			cutObj = pDoc->pEllipse;
			pDoc->currentObj = cutObj;
			break;
		}
		case rectangle:
		{
			YRectangle* temp = (YRectangle*)cutObj;
			pDoc->pRectangle = new YRectangle(temp->getSPoint(), temp->getEPoint(), temp->getLineColor(), temp->getLineThick(), temp->getLinePattern(), temp->getSideColor(), temp->getSidePattern(), temp->getPatternflag());
			pDoc->pRectangle->setType(rectangle);
			pDoc->pRectangle->setSelect(TRUE);
			if (menu_cutcopyflag == FALSE) pDoc->pRectangle->moveAll(20, 20);
			pDoc->pRectangle->setRgn();
			pDoc->drawing = FALSE;
			pDoc->obj_List.AddTail(pDoc->pRectangle);
			cutObj = pDoc->pRectangle;
			pDoc->currentObj = cutObj;
			break;
		}
		case text:
		{
			YText* temp = (YText*)cutObj;
			pDoc->pText = new YText(temp->getSPoint(), temp->getText(), temp->getFontColor(), temp->getBkColor(), temp->getFontSize(),temp->getUnderLine(),temp->getStrikeOut(),temp->getBold(),temp->getItalic());
			pDoc->pText->setType(text);
			pDoc->pText->setSelect(TRUE);
			if (menu_cutcopyflag == FALSE) pDoc->pText->moveAll(20, 20);
			pDoc->pText->setRgn();
			pDoc->drawing = FALSE;
			pDoc->obj_List.AddTail(pDoc->pText);
			cutObj = pDoc->pText;
			pDoc->currentObj = cutObj;
			break;
		}
		default:
			break;
		}
		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnEditCopy()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
		menu_cut = TRUE;
		menu_copy = TRUE;
		menu_paste = TRUE;
		menu_cutcopyflag = FALSE;
		menu_cutpaste = TRUE;
		CYPaintEditDoc* pDoc = GetDocument();

		cutObj = NULL;

		if (pDoc->currentObj != NULL){
			cutObj = pDoc->currentObj;
		}
}
void CYPaintEditView::OnUpdateEditCut(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(menu_cut);
}
void CYPaintEditView::OnUpdateEditPaste(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(menu_paste);
}
void CYPaintEditView::OnUpdateEditCopy(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(menu_copy);
}



// ���콺 ��Ŭ�� �޴� �Լ��� //
void CYPaintEditView::OnEditLinecolor()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	CColorDialog dlg(RGB(255, 0, 0), CC_FULLOPEN);
	int result = dlg.DoModal();
	if (result == IDOK){
		lineColor = dlg.GetColor();

		switch (pDoc->currentObj->getType()){
		case line:
		{
			pDoc->pLine = (YLine*)pDoc->currentObj;
			pDoc->pLine->setLineColor(lineColor);
			break;
		}
		case polyline:
		{
			pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
			pDoc->pPolyLine->setLineColor(lineColor);
			break;
		}

		case ellipse:
		{
			pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
			pDoc->pEllipse->setLineColor(lineColor);
			break;
		}
		case rectangle:
		{
			pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
			pDoc->pRectangle->setLineColor(lineColor);
			break;
		}
		default:
			break;
		}

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnUpdateEditLinecolor(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}
void CYPaintEditView::OnEditFiguresetting()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	menu_Figiure = FALSE;

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
	case ellipse:
	{
		pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
		dlg.lineThick = pDoc->pEllipse->getLineThick();
		dlg.linePattern = pDoc->pEllipse->getLinePattern();
		break;
	}
	case rectangle:
	{
		pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
		dlg.lineThick = pDoc->pRectangle->getLineThick();
		dlg.linePattern = pDoc->pRectangle->getLinePattern();
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
		case ellipse:
		{
			pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
			pDoc->pEllipse->setLineThick(dlg.lineThick);
			pDoc->pEllipse->setLinePattern(dlg.linePattern);
			break;
		}
		case rectangle:
		{
			pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
			pDoc->pRectangle->setLineThick(dlg.lineThick);
			pDoc->pRectangle->setLinePattern(dlg.linePattern);
			break;
		}


		default:
			break;
		}

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnUpdateEditFiguresetting(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(FALSE);  //�˾� ��Ȱ�� �ϴ� ���
}
void CYPaintEditView::OnEditDelete()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	POSITION tpos;
	if (pDoc->obj_List.GetSize() == 1){									//��ü�� �ϳ��� ����������
		pDoc->obj_List.RemoveAll();

	}
	else {
		while (pos) {
			tpos = pos;													//��ġ�� ������ �� �� ���� ���� �Ѿ��.
			YObject* tmp = (YObject*)pDoc->obj_List.GetNext(pos);
			if (tmp->getSelect() == TRUE) break;						//���õ� ��ü�� ������ �ݺ��� �����ϰ� ��������
		}
		pDoc->obj_List.RemoveAt(tpos);
	}
	pDoc->currentObj = NULL;
	Invalidate(FALSE);
}
void CYPaintEditView::OnUpdateEditDelete(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}
void CYPaintEditView::OnEditDeletepoint()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);
	if (pDoc->deletePosition != -1) {

		if (pDoc->pPolyLine->getPolyList()->GetSize() == 2){				// ���� 2���ִµ� ������� ���� ������� �Ҷ� ��ü�� ����� ����Ʈ������ ���� ��Ų��.
			pDoc->pPolyLine->getPolyList()->RemoveAll();

			POSITION pos = pDoc->obj_List.GetHeadPosition();
			POSITION tpos;

			while (pos) {
				tpos = pos;													//��ġ�� ������ �� �� ���� ���� �Ѿ��.
				YObject* tmp = (YObject*)pDoc->obj_List.GetNext(pos);
				if (tmp->getSelect() == TRUE) break;						//���õ� ��ü�� ������ �ݺ��� �����ϰ� ��������
			}
			pDoc->obj_List.RemoveAt(tpos);
			pDoc->currentObj = NULL;
		}
		else {
			pDoc->pPolyLine->getPolyList()->RemoveAt(pDoc->pPolyLine->getPolyList()->FindIndex(pDoc->deletePosition));
			pDoc->deletePosition = -1;
			pDoc->pPolyLine->setRgn();
		}
		Invalidate(FALSE);
	}

}
void CYPaintEditView::OnUpdateEditDeletepoint(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}
void CYPaintEditView::OnEditSidecolor()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	CColorDialog dlg(RGB(255, 0, 0), CC_FULLOPEN);
	int result = dlg.DoModal();
	if (result == IDOK){
		sideColor = dlg.GetColor();

		switch (pDoc->currentObj->getType()){
		case ellipse:
		{
			pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
			pDoc->pEllipse->setSideColor(sideColor);
			break;
		}
		case rectangle:
		{
			pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
			pDoc->pRectangle->setSideColor(sideColor);
			break;
		}
		default:
			break;
		}

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnUpdateEditSidecolor(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}




void CYPaintEditView::OnMenufontdia()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	CFontDialog dlg;
	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CMFCRibbonComboBox* fonts = (CMFCRibbonComboBox*)main->getRibbon()->FindByID(ID_MENUFONT);
	CMFCRibbonEdit* fontsize = (CMFCRibbonEdit*)main->getRibbon()->FindByID(ID_MENUFONTSIZE);
	CMFCRibbonColorButton* fontcolor = (CMFCRibbonColorButton*)main->getRibbon()->FindByID(ID_MENUFONTCOLOR);
	
	
	int result = dlg.DoModal();
//	dlg.SetFont();
	if (result == IDOK){
		LOGFONT lf;
		//���̾�α׿��� ����������
		dlg.GetCurrentFont(&lf);
		//COLORREF color = dlg.GetColor();
		underline = dlg.IsUnderline();
		bold = dlg.IsBold();
		italic = dlg.IsItalic();
		strikeout = dlg.IsStrikeOut();
		font = lf.lfFaceName;
		fontSize = dlg.GetSize();
		fontColor = dlg.GetColor();
		/*
		//���̾�α׿��� ����� �� �޴��� �ٽ� �����ֱ�
		fonts->SetEditText(lf.lfFaceName);
		CString str;
		str.Format(_T("%d"), fontSize);
		fontsize->SetEditText(str);
		fontcolor->SetColor(fontColor);
		*/
		//����� ���� ������ͼ� �ؽ�Ʈ �����Ű��
		//font = fonts->GetEditText();
		//fontSize = (_ttoi)(fontsize->GetEditText()) * 10;
		//fontColor = fontcolor->GetColor();
		
		pDoc->pText->setFont(font);
		pDoc->pText->setFontSize(fontSize);
		pDoc->pText->setFontColor(fontColor);
		pDoc->pText->setItalic(italic);
		pDoc->pText->setBold(bold);
		pDoc->pText->setUnderLine(underline);
		pDoc->pText->setStrikeOut(strikeout);

		if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == text){
			pDoc->pText->setFont(font);

			// ����ũ�⺯�� -> ���� ����,��Ʈ����,��������
			CDC* dc = GetDC();
			CFont f;
			if (bold) lf.lfWeight = FW_BOLD;
			else lf.lfWeight = FW_NORMAL;
			lf.lfWidth = 0;
			lf.lfHeight = fontSize;						//���� ����
			lf.lfStrikeOut = strikeout;						//��Ҽ� ����
			lf.lfUnderline = underline;						//���ټ���
			lf.lfItalic = italic;							//�����
			lf.lfEscapement = 0;							//���� ���� �ʱ�ȭ
			lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
			lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
			lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
			lf.lfQuality = DEFAULT_QUALITY;
			lf.lfCharSet = DEFAULT_CHARSET;
			wcscpy_s((lf.lfFaceName), _countof(lf.lfFaceName), font);
			f.CreateFontIndirect(&lf);
			//f.CreatePointFont(pDoc->pText->getFontSize(), pDoc->pText->getFont());
			dc->SelectObject(f);
			CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());

			pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
			pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
			pDoc->pText->setRgn();
			pDoc->pText->setFontColor(fontColor);
			Invalidate(FALSE);
		}
	}
}
