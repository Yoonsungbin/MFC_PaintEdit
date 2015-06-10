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
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CYPaintEditView

IMPLEMENT_DYNCREATE(CYPaintEditView, CView)

BEGIN_MESSAGE_MAP(CYPaintEditView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
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
	ON_COMMAND(ID_MENUTEXTBUTTON, &CYPaintEditView::OnMenutextbutton)
	ON_UPDATE_COMMAND_UI(ID_MENUTEXTBUTTON, &CYPaintEditView::OnUpdateMenutextbutton)
	ON_COMMAND(ID_MENUFONTSIZE, &CYPaintEditView::OnMenufontsize)
	ON_UPDATE_COMMAND_UI(ID_MENUFONTSIZE, &CYPaintEditView::OnUpdateMenufontsize)
	ON_COMMAND(ID_MENUFONT, &CYPaintEditView::OnMenufont)
	ON_UPDATE_COMMAND_UI(ID_MENUFONT, &CYPaintEditView::OnUpdateMenufont)
	ON_COMMAND(ID_TEXTEDITBUTTON, &CYPaintEditView::OnTexteditbutton)
	ON_UPDATE_COMMAND_UI(ID_TEXTEDITBUTTON, &CYPaintEditView::OnUpdateTexteditbutton)
	ON_COMMAND(ID_MENUFONTCOLOR, &CYPaintEditView::OnMenufontcolor)
	ON_UPDATE_COMMAND_UI(ID_MENUFONTCOLOR, &CYPaintEditView::OnUpdateMenufontcolor)
	ON_COMMAND(ID_MENUFONTBKCOLOR, &CYPaintEditView::OnMenufontbkcolor)
	ON_UPDATE_COMMAND_UI(ID_MENUFONTBKCOLOR, &CYPaintEditView::OnUpdateMenufontbkcolor)
	ON_COMMAND(ID_MENULINETHICK, &CYPaintEditView::OnMenulinethick)
	ON_UPDATE_COMMAND_UI(ID_MENULINETHICK, &CYPaintEditView::OnUpdateMenulinethick)
	ON_COMMAND(ID_MENULINEPATTERN, &CYPaintEditView::OnMenulinepattern)
	ON_UPDATE_COMMAND_UI(ID_MENULINEPATTERN, &CYPaintEditView::OnUpdateMenulinepattern)
	ON_COMMAND(ID_MENUSIDEPATTERN, &CYPaintEditView::OnMenusidepattern)
	ON_UPDATE_COMMAND_UI(ID_MENUSIDEPATTERN, &CYPaintEditView::OnUpdateMenusidepattern)
	ON_COMMAND(ID_MENULINECOLOR, &CYPaintEditView::OnMenulinecolor)
	ON_COMMAND(ID_MENUSIDECOLOR, &CYPaintEditView::OnMenusidecolor)
	ON_COMMAND(ID_GROUPSBUTTON, &CYPaintEditView::OnGroupsbutton)
	ON_UPDATE_COMMAND_UI(ID_GROUPSBUTTON, &CYPaintEditView::OnUpdateGroupsbutton)
	ON_COMMAND(ID_DELETEGROUPBUTTON, &CYPaintEditView::OnDeletegroupbutton)
	ON_UPDATE_COMMAND_UI(ID_DELETEGROUPBUTTON, &CYPaintEditView::OnUpdateDeletegroupbutton)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_EDIT_CUT, &CYPaintEditView::OnEditCut)
	ON_COMMAND(ID_EDIT_COPY, &CYPaintEditView::OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, &CYPaintEditView::OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, &CYPaintEditView::OnUpdateEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, &CYPaintEditView::OnUpdateEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, &CYPaintEditView::OnUpdateEditPaste)
	ON_COMMAND(ID_EDIT_LINECOLOR, &CYPaintEditView::OnEditLinecolor)
	ON_UPDATE_COMMAND_UI(ID_EDIT_LINECOLOR, &CYPaintEditView::OnUpdateEditLinecolor)
	ON_COMMAND(ID_EDIT_SIDECOLOR, &CYPaintEditView::OnEditSidecolor)
	ON_UPDATE_COMMAND_UI(ID_EDIT_SIDECOLOR, &CYPaintEditView::OnUpdateEditSidecolor)
	ON_COMMAND(ID_EDIT_FIGURESETTING, &CYPaintEditView::OnEditFiguresetting)
	ON_UPDATE_COMMAND_UI(ID_EDIT_FIGURESETTING, &CYPaintEditView::OnUpdateEditFiguresetting)
	ON_COMMAND(ID_EDIT_DELETE, &CYPaintEditView::OnEditDelete)
	ON_UPDATE_COMMAND_UI(ID_EDIT_DELETE, &CYPaintEditView::OnUpdateEditDelete)
	ON_COMMAND(ID_EDIT_DELETEPOINT, &CYPaintEditView::OnEditDeletepoint)
	ON_UPDATE_COMMAND_UI(ID_EDIT_DELETEPOINT, &CYPaintEditView::OnUpdateEditDeletepoint)
	ON_COMMAND(ID_EDITGROUP, &CYPaintEditView::OnEditgroup)
	ON_UPDATE_COMMAND_UI(ID_EDITGROUP, &CYPaintEditView::OnUpdateEditgroup)
	ON_COMMAND(ID_EDITDELETEGROUP, &CYPaintEditView::OnEditdeletegroup)
	ON_UPDATE_COMMAND_UI(ID_EDITDELETEGROUP, &CYPaintEditView::OnUpdateEditdeletegroup)
	ON_COMMAND(ID_BACK, &CYPaintEditView::OnBack)
	ON_COMMAND(ID_FRONTBACK, &CYPaintEditView::OnFrontback)
	ON_UPDATE_COMMAND_UI(ID_BACK, &CYPaintEditView::OnUpdateBack)
	ON_UPDATE_COMMAND_UI(ID_FRONTBACK, &CYPaintEditView::OnUpdateFrontback)
	ON_COMMAND(ID_MENUFONTDIA, &CYPaintEditView::OnMenufontdia)
	ON_UPDATE_COMMAND_UI(ID_MENUFONTDIA, &CYPaintEditView::OnUpdateMenufontdia)
	ON_UPDATE_COMMAND_UI(ID_MENULINECOLOR, &CYPaintEditView::OnUpdateMenulinecolor)
	ON_UPDATE_COMMAND_UI(ID_MENUSIDECOLOR, &CYPaintEditView::OnUpdateMenusidecolor)
	ON_COMMAND(ID_GROUPSIZECHANGEBUTTON, &CYPaintEditView::OnGroupsizechangebutton)
	ON_UPDATE_COMMAND_UI(ID_GROUPSIZECHANGEBUTTON, &CYPaintEditView::OnUpdateGroupsizechangebutton)
	ON_COMMAND(ID_EDIT_SELECT_ALL, &CYPaintEditView::OnEditSelectAll)

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
	fontSize = 100;

	lineThick = 1;
	linePattern = 0;
	sidePattern = 0;
	sidePatternflag2 = FALSE;

	lineColor = RGB(0, 0, 0);
	sideColor = RGB(255, 255, 255);


	// �˾� �޴� �ʱ�ȭ //
	menu_Cut = FALSE;
	menu_Paste = FALSE;
	menu_Copy = FALSE;
	menu_CutCopyflag = FALSE;
	menu_CutPaste = FALSE;
	menu_LineColor = TRUE;
	menu_SideColor = TRUE;
	menu_Figure = FALSE;
	menu_Delete = FALSE;
	menu_DeletePoint = FALSE;
	menu_Group = FALSE;
	menu_DeleteGroup = FALSE;
	menu_FontDialog = FALSE;
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
	
	POSITION pos;
	if (pDoc->grouping == TRUE){
		menu_LineColor = FALSE;
		menu_SideColor = FALSE;
		menu_Figure = FALSE;
		menu_Delete = FALSE;
		menu_DeletePoint = FALSE;
		menu_Group = TRUE;
		menu_DeleteGroup = FALSE;
	}
	else {
		if (pDoc->currentObj != NULL){

			switch (pDoc->currentObj->getType()){
			case line:
				menu_LineColor = TRUE;
				menu_SideColor = FALSE;
				menu_Figure = TRUE;
				menu_Delete = TRUE;
				menu_DeletePoint = FALSE;
				menu_Group = TRUE;
				menu_DeleteGroup = FALSE;
				break;
			case polyline:
				menu_LineColor = TRUE;
				menu_SideColor = FALSE;
				menu_Figure = TRUE;
				menu_Delete = TRUE;
				menu_DeletePoint = TRUE;
				menu_Group = TRUE;
				menu_DeleteGroup = FALSE;

				pos = pDoc->obj_List.GetHeadPosition();
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
						break;
					}
				}
				break;
			case ellipse:
				menu_LineColor = TRUE;
				menu_SideColor = TRUE;
				menu_Figure = TRUE;
				menu_Delete = TRUE;
				menu_DeletePoint = FALSE;
				menu_Group = TRUE;
				menu_DeleteGroup = FALSE;
				break;
			case rectangle:
				menu_LineColor = TRUE;
				menu_SideColor = TRUE;
				menu_Figure = TRUE;
				menu_Delete = TRUE;
				menu_DeletePoint = FALSE;
				menu_Group = TRUE;
				menu_DeleteGroup = FALSE;
				break;
			case text:
				menu_LineColor = FALSE;
				menu_SideColor = FALSE;
				menu_Figure = FALSE;
				menu_Delete = TRUE;
				menu_DeletePoint = FALSE;
				menu_Group = TRUE;
				menu_DeleteGroup = FALSE;
				break;
			case group:
				menu_LineColor = FALSE;
				menu_SideColor = FALSE;
				menu_Figure = FALSE;
				menu_Delete = TRUE;
				menu_DeletePoint = FALSE;
				menu_Group = TRUE;
				menu_DeleteGroup = TRUE;
				break;
			default:
				break;
			}

		}
		else {
			menu_Cut = FALSE;
			menu_Copy = FALSE;
			menu_LineColor = FALSE;
			menu_SideColor = FALSE;
			menu_Figure = FALSE;
			menu_Delete = FALSE;
			menu_DeletePoint = FALSE;
			menu_Group = FALSE;
			menu_DeleteGroup = FALSE;
		}
	}
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
		undoredoFlag = TRUE;
		pDoc->temp_AllList.RemoveAll();
		POSITION pos = pDoc->allList.GetHeadPosition();
		while (pos){
			YObject* temp = (YObject*)pDoc->allList.GetNext(pos);
			pDoc->temp_AllList.AddTail(temp);
		}
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
		dc->SelectObject(&f);
		dc->SetBkColor(pDoc->pText->getBkColor());
		dc->SetTextColor(pDoc->pText->getFontColor());
		// ��Ʈ�� �ݿ��� ���ڿ�(�ؽ�Ʈ)�� ���� ���� �� ����
		CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());
		if (lf.lfWeight == FW_BOLD){
			s.cx += 50;
		}
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
		dc->SelectObject(&pen);
		CBrush brush(pDoc->pText->getBkColor());
		dc->SelectObject(&brush);

		// ���� �� �ؽ�Ʈ ���
		dc->Rectangle(r);
		dc->DrawText(pDoc->pText->getText(), pDoc->pText->getRect(), NULL);

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
			YText* text = new YText(pDoc->pText);
			pDoc->allList.AddTail(text);
			pDoc->temp_AllList.AddTail(text);
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
						 YPolyLine* polyline = new YPolyLine(pDoc->pPolyLine);
						 pDoc->allList.AddTail(polyline);
						 pDoc->temp_AllList.AddTail(polyline);
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
					  pDoc->pRectangle = new YRectangle(point, point, lineColor, lineThick, linePattern, sideColor, sidePattern, sidePatternflag2);
					  pDoc->pRectangle->setOrder(pDoc->allNum++);
					  pDoc->pRectangle->setSelect(TRUE);
					  pDoc->pRectangle->setType(rectangle);
					  pDoc->drawing = TRUE;
					  break;
	}
	case text:
	{
				 if (pDoc->textEditing == FALSE){
					 pDoc->pText = new YText(point, font, fontColor, bkColor, fontSize, underline, strikeout, bold, italic);
					 pDoc->pText->setOrder(pDoc->allNum++);
					 pDoc->pText->setType(text);
					 pDoc->pText->setSelect(TRUE);
					 pDoc->textEditing = TRUE;
				 }
				 else {
					 if (pDoc->pText->getText().GetLength() != 0){
						 pDoc->pText->setRgn();
						 pDoc->pText->setSelect(FALSE);
						 pDoc->obj_List.AddTail(pDoc->pText);
					 }
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
					   
					   //��� ���� �� ������� Ŭ�� ������ ������ �� ������ ����Ѵ�.
					   POSITION pos = pDoc->obj_List.GetHeadPosition();
					  
						   while (pos){
							   YObject* temp = (YObject*)pDoc->obj_List.GetNext(pos);
							   temp->setSelect(FALSE);
						   }
						 

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
						   if (pDoc->pEllipse->getMRect()[0].PtInRect(point) || pDoc->pEllipse->getMRect()[1].PtInRect(point) ||
							   pDoc->pEllipse->getMRect()[2].PtInRect(point) || pDoc->pEllipse->getMRect()[3].PtInRect(point)) {
							   pDoc->currentObj->setSelect(TRUE);
							   break;
						   }
					   }
					   else if (pDoc->currentObj == pDoc->pRectangle){
						   if (pDoc->pRectangle->getMRect()[0].PtInRect(point) || pDoc->pRectangle->getMRect()[1].PtInRect(point) ||
							   pDoc->pRectangle->getMRect()[2].PtInRect(point) || pDoc->pRectangle->getMRect()[3].PtInRect(point)) {
							   pDoc->currentObj->setSelect(TRUE);
							   break;
						   }
					   }
					   else if (pDoc->currentObj == pDoc->pGroup){
						   if (pDoc->resizing == TRUE){
							   if (pDoc->pGroup->getMRect()[0].PtInRect(point) || pDoc->pGroup->getMRect()[1].PtInRect(point) ||
								   pDoc->pGroup->getMRect()[2].PtInRect(point) || pDoc->pGroup->getMRect()[3].PtInRect(point)) {
								   pDoc->currentObj->setSelect(TRUE);
							   }
							   break;
						   }
					   }
				   }


				   // 1 // (����Ʈ�� ��� �ִ� ���) ������� ������ ���
				   if (pDoc->currentObj == NULL){ // ����Ʈ Ž���� �������� �ʾ����Ƿ� currentObj�� NULL�̴�.
					   menu_Cut = FALSE;
					   menu_Copy = FALSE;
					   break;
				   }


				   // 2 // (����Ʈ�� �׸��� �ִ� ���) ������� �����Ͽ� ����Ʈ���� ������ ã�� ���ϴ� ���
				   else if (pDoc->currentObj->getSelect() == FALSE){ // �ڿ������� ����Ʈ�� ������ ��Ұ� currnetObj�� �ǰ� �װ��� �׻� FALSE���� �̿�
					   pDoc->currentObj = NULL;
					   menu_Cut = FALSE;
					   menu_Copy = FALSE;
				   }


				   // 3 // (����Ʈ�� �׸��� �ִ� ���) ����Ʈ���� ������ ã�� ���  - ���õ� ���� ����
				   else if (pDoc->currentObj->getSelect() == TRUE){
					   pDoc->Original_Point = point;  //�� �̵��� �������� �Ǵ� ��ǥ
					   pDoc->drawing = TRUE;
					   //�޴� �ʱ�ȭ (�߶󳻱� , �����ϱ� , �ٿ��ֱ�)
					   menu_Cut = TRUE;
					   menu_Copy = TRUE;
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
						   if (pDoc->pGroup->getMRect()[0].PtInRect(point)){
							   pDoc->pGroup->setSPoint(point);
							   pDoc->pGroup->setMoveMode(-1);  //������ 2
						   }
						   else if (pDoc->pGroup->getMRect()[1].PtInRect(point)){
							   pDoc->pGroup->setEPoint(point);
							   pDoc->pGroup->setMoveMode(1);  //���� 4
							   break;
						   }
						   else if (pDoc->pGroup->getMRect()[2].PtInRect(point)){
							   pDoc->pGroup->setMixPoint(point);

							   pDoc->pGroup->setMoveMode(2);  // 1
							   break;
						   }
						   else if (pDoc->pGroup->getMRect()[3].PtInRect(point)){

							   pDoc->pGroup->setMixPoint(point);
							   pDoc->pGroup->setMoveMode(3);  // 3
							   break;
						   }
						   else if (pDoc->pGroup->checkRgn(point)) {
							   pDoc->pGroup->setMoveMode(0); //��ü�̵�
						   }
						   break;
					   default:
						   break;
					   }
				   }
				   // �׷�ȭ �� �̵� ���ϰ�
				   if (pDoc->grouping == TRUE)
					   pDoc->currentObj = NULL;


				   Invalidate(FALSE);
				   UpdateMenu();
				   break;
	}
	default:
		break;
	}

	if (pDoc->resizing == TRUE){
		pDoc->Original_Point = point;
		YObject* tmp;
		POSITION pos = pDoc->current_group.GetHeadPosition();
		while (pos){
			tmp = pDoc->current_group.GetNext(pos);
			switch (tmp->getType()){
			case line:{
						  YLine* tmp2 = (YLine*)tmp;
						  if (tmp2->getMRect()[0].PtInRect(point))
							  pDoc->flag = 0; // ������
						  else if (tmp2->getMRect()[1].PtInRect(point))
							  pDoc->flag = 1; // ����
						  break;
			}
			case rectangle:{
							   YRectangle* tmp2 = (YRectangle*)tmp;
							   if (tmp2->getMRect()[0].PtInRect(point))
								   pDoc->flag = 0;
							   else if (tmp2->getMRect()[1].PtInRect(point))
								   pDoc->flag = 1;
							   else if (tmp2->getMRect()[2].PtInRect(point))
								   pDoc->flag = 2;
							   else if (tmp2->getMRect()[3].PtInRect(point))
								   pDoc->flag = 3;
							   break;
			}
			case ellipse:{
							 YEllipse* tmp2 = (YEllipse*)tmp;
							 if (tmp2->getMRect()[0].PtInRect(point))
								 pDoc->flag = 0; // 2��и�
							 else if (tmp2->getMRect()[1].PtInRect(point))
								 pDoc->flag = 1; // 4��и�
							 else if (tmp2->getMRect()[2].PtInRect(point))
								 pDoc->flag = 2; // 3��и�
							 else if (tmp2->getMRect()[3].PtInRect(point))
								 pDoc->flag = 3; // 1��и�
							 break;
			}
			default:
				break;
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
					   CPoint t_point = point - pDoc->Original_Point; // ��ǥ ������
					   pDoc->Original_Point = point;
					   
					   if (pDoc->currentObj != NULL){
						   
						   switch (pDoc->currentObj->getType()){
						   case line:
						   {
										//pDoc->pLine = (YLine*)pDoc->currentObj;
										//���õǾ����� �̵� ���������� �ٸ� move����
										lineMove = TRUE;
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
											polylineMove = TRUE;
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
										   ellipseMove = TRUE;
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
											 rectangleMove = TRUE;
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
										textMove = TRUE;
										pDoc->pText->setSPoint(pDoc->pText->getSPoint() + t_point);
										pDoc->pText->setEPoint(pDoc->pText->getEPoint() + t_point);
										pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
										pDoc->pText->setRgn();
										break;
						   }
						   case group:
							   groupMove = TRUE;
							   if (pDoc->resizing == FALSE){
								   if (pDoc->pGroup->getSelect()){
									   if (pDoc->pGroup->getMoveMode() == 0){  //��ü�̵�
										   pDoc->pGroup->moveAll(t_point.x, t_point.y);
										   pDoc->pGroup->setORect(pDoc->pGroup->getSPoint().x, pDoc->pGroup->getSPoint().y, pDoc->pGroup->getEPoint().x, pDoc->pGroup->getEPoint().y);
									   }
									   else {
										   pDoc->pGroup->move(t_point.x, t_point.y);
										   pDoc->pGroup->setORect(pDoc->pGroup->getSPoint().x, pDoc->pGroup->getSPoint().y, pDoc->pGroup->getEPoint().x, pDoc->pGroup->getEPoint().y);
									   }
									   pDoc->pGroup->setRgn();
								   }
							   }
							   else{ // �׷�ũ�� ������ ��
								   
							   }


							   break;
						   default:
							   break;
						   }
					   }
					   else if (pDoc->resizing){
						   if (pDoc->flag == 0){ // 2
							   POSITION pos = pDoc->current_group.GetHeadPosition();
							   YObject* tmp;
							   while (pos){
								   tmp = pDoc->current_group.GetNext(pos);
								   switch (tmp->getType()){
								   case line:{
												 YLine* p = (YLine*)tmp;
												 p->setMoveMode(-1);
												 p->move(t_point.x, t_point.y);
												 break;
								   }
								   case rectangle:{
													  YRectangle* p = (YRectangle*)tmp;
													  p->setMoveMode(-1);
													  p->move(t_point.x, t_point.y);
													  break;
								   }
								   case ellipse:{
													YEllipse* p = (YEllipse*)tmp;
													p->setMoveMode(-1);
													p->move(t_point.x, t_point.y);
													break;
								   }
								   }
							   }
						   }
						   else if (pDoc->flag == 1){ // 4
							   POSITION pos = pDoc->current_group.GetHeadPosition();
							   YObject* tmp;
							   while (pos){
								   tmp = pDoc->current_group.GetNext(pos);
								   
								   switch (tmp->getType()){
								   case line:{
												 YLine* p = (YLine*)tmp;
												 p->setMoveMode(1);
												 p->move(t_point.x, t_point.y);
												 break;
								   }
								   case rectangle:{
													  YRectangle* p = (YRectangle*)tmp;
													  p->setMoveMode(1);
													  p->move(t_point.x, t_point.y);
													  break;
								   }
								   case ellipse:{
													YEllipse* p = (YEllipse*)tmp;
													p->setMoveMode(1);
													p->move(t_point.x, t_point.y);
													break;
								   }
								   }
							   }
						   }
						   else if (pDoc->flag == 2){ // 3
							   POSITION pos = pDoc->current_group.GetHeadPosition();
							   YObject* tmp;
							   while (pos){
								   tmp = pDoc->current_group.GetNext(pos);
								   switch (tmp->getType()){
								   case rectangle:{
													  YRectangle* p = (YRectangle*)tmp;
													  p->setMoveMode(2);
													  p->move(t_point.x, t_point.y);
													  break;
								   }
								   case ellipse:{
													YEllipse* p = (YEllipse*)tmp;
													p->setMoveMode(2);
													p->move(t_point.x, t_point.y);
													break;
								   }
								   }
							   }
						   }
						   else if (pDoc->flag == 3){ // 1
							   POSITION pos = pDoc->current_group.GetHeadPosition();
							   YObject* tmp;
							   while (pos){
								   tmp = pDoc->current_group.GetNext(pos);
								   switch (tmp->getType()){
								   case rectangle:{
													  YRectangle* p = (YRectangle*)tmp;
													  p->setMoveMode(3);
													  p->move(t_point.x, t_point.y);
													  break;
								   }
								   case ellipse:{
													YEllipse* p = (YEllipse*)tmp;
													p->setMoveMode(3);
													p->move(t_point.x, t_point.y);
													break;
								   }
								   }
							   }
						   }
					   } 
					   else // ����� Ŭ�������� (���ܻ�Ȳ)
						   break;
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
				 YLine* line = new YLine(pDoc->pLine);
				 pDoc->allList.AddTail(line);
				 pDoc->temp_AllList.AddTail(line);
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
					YEllipse* ellipse = new YEllipse(pDoc->pEllipse);
					pDoc->allList.AddTail(ellipse);
					pDoc->temp_AllList.AddTail(ellipse);
					pDoc->drawing = FALSE;
					ReleaseCapture();
					break;
	}
	case rectangle:
	{
					  pDoc->pRectangle->setRgn();
					  pDoc->pRectangle->setSelect(FALSE);
					  pDoc->obj_List.AddTail(pDoc->pRectangle);
					  YRectangle* rectangle = new YRectangle(pDoc->pRectangle);
					  pDoc->allList.AddTail(rectangle);
					  pDoc->temp_AllList.AddTail(rectangle);
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
				   if (pDoc->currentObj != NULL){
					   switch (pDoc->currentObj->getType()){
					   case line:
					   {
									if (lineMove){
										YLine* line = new YLine(pDoc->pLine);
										pDoc->allList.AddTail(line);
										pDoc->temp_AllList.AddTail(line);
										lineMove = FALSE;
									}
									break;

					   }
					   case polyline:
					   {
										if (polylineMove){
											YPolyLine* polyline = new YPolyLine(pDoc->pPolyLine);
											pDoc->allList.AddTail(polyline);
											pDoc->temp_AllList.AddTail(polyline);
											polylineMove = FALSE;
										}
										break;
					   }
					   case ellipse:
					   {
									   if (ellipseMove){
										   YEllipse* ellipse = new YEllipse(pDoc->pEllipse);
										   pDoc->allList.AddTail(ellipse);
										   pDoc->temp_AllList.AddTail(ellipse);
										   ellipseMove = FALSE;
									   }
					   }
					   case rectangle:
					   {
										 if (rectangleMove){
											 YRectangle* rectangle = new YRectangle(pDoc->pRectangle);
											 pDoc->allList.AddTail(rectangle);
											 pDoc->temp_AllList.AddTail(rectangle);
											 rectangleMove = FALSE;
										 }
										 break;
					   }
					   case text:
					   {
									if (textMove){
										YText* text = new YText(pDoc->pText);
										pDoc->allList.AddTail(text);
										pDoc->temp_AllList.AddTail(text);
										textMove = FALSE;
									}
									break;
					   }
					   case group:
					   {
									 if (groupMove){
										 YGroup* group = new YGroup(pDoc->pGroup);
										 pDoc->allList.AddTail(group);
										 pDoc->temp_AllList.AddTail(group);
										 groupMove = FALSE;
									 }
									 break;
					   }
					   }
				   }
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
		if (pDoc->resizing){
			pDoc->resizing = FALSE;

			YObject* tmp;
			POSITION pos = pDoc->current_group.GetHeadPosition();
			while (pos) {
				tmp = (YObject*)pDoc->obj_List.GetNext(pos);
				tmp->setSelect(FALSE);
				tmp->setRgn();
			}

			pDoc->pGroup->setSelect(TRUE);
			pDoc->pGroup->setRgn();
			pDoc->pGroup->dsetResizing();

			pDoc->current_group.RemoveAll();
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
	CMFCRibbonComboBox* fonts = (CMFCRibbonComboBox*)main->getRibbon()->FindByID(ID_MENUFONT);
	CMFCRibbonEdit* fontsize = (CMFCRibbonEdit*)main->getRibbon()->FindByID(ID_MENUFONTSIZE);
	CMFCRibbonColorButton* fontcolor = (CMFCRibbonColorButton*)main->getRibbon()->FindByID(ID_MENUFONTCOLOR);

	if (pDoc->currentObj != NULL){
		switch (pDoc->currentObj->getType()){
		case line:
		{
					 CString str;
					 str.Format(_T("%d"), pDoc->pLine->getLineThick());
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
					 CString str;
					 str.Format(_T("%d"), pDoc->pText->getFontSize() / 10);
					 fontsize->SetEditText(str);
					 fonts->SetEditText(pDoc->pText->getFont());
					 fontcolor->SetColor(pDoc->pText->getFontColor());
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
	menu_FontDialog = TRUE;
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
	menu_Cut = FALSE;
	menu_Copy = FALSE;
	menu_Select = FALSE;
	menu_Line = TRUE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;
	menu_FontDialog = FALSE;
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
	menu_Cut = FALSE;
	menu_Copy = FALSE;
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = TRUE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;
	menu_FontDialog = FALSE;
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
	menu_Cut = FALSE;
	menu_Copy = FALSE;
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = TRUE;
	menu_Text = FALSE;
	menu_FontDialog = FALSE;
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
	menu_Cut = FALSE;
	menu_Copy = FALSE;
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = TRUE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;
	menu_FontDialog = FALSE;
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
	menu_Cut = FALSE;
	menu_Copy = FALSE;
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = TRUE;
	menu_FontDialog = TRUE;
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
		LOGFONT lf;
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
		CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());
		if (lf.lfWeight == FW_BOLD){
			s.cx += 50;
		}
		pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
		pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
		pDoc->pText->setRgn();
		YText* text = new YText(pDoc->pText);
		pDoc->allList.AddTail(text);
		pDoc->temp_AllList.AddTail(text);
		ReleaseDC(dc);
		Invalidate(FALSE);
	}
	else if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == group){

		pDoc->pGroup = (YGroup*)pDoc->currentObj;
		CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

		POSITION pos = (*pL).GetHeadPosition();
		while (pos) {
			YObject* tmp = (YObject*)(*pL).GetNext(pos);
			if (tmp->getType() == text){
				pDoc->pText = (YText*)tmp;
				pDoc->pText->setFontSize(fontSize);

				// ����ũ�⺯�� -> ���� ����,��Ʈ����,��������
				CDC* dc = GetDC();
				CFont f;
				LOGFONT lf;
				if (pDoc->pText->getBold()) lf.lfWeight = FW_BOLD;
				else lf.lfWeight = FW_NORMAL;
				lf.lfWidth = 0;
				lf.lfHeight = pDoc->pText->getFontSize();                        //���� ����
				lf.lfStrikeOut = pDoc->pText->getStrikeOut();                        //��Ҽ� ����
				lf.lfUnderline = pDoc->pText->getUnderLine();                        //���ټ���
				lf.lfItalic = pDoc->pText->getItalic();                            //�����
				lf.lfEscapement = 0;                            //���� ���� �ʱ�ȭ
				lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
				lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
				lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
				lf.lfQuality = DEFAULT_QUALITY;
				lf.lfCharSet = DEFAULT_CHARSET;
				wcscpy_s((lf.lfFaceName), _countof(lf.lfFaceName), pDoc->pText->getFont());

				f.CreateFontIndirect(&lf);
				dc->SelectObject(f);
				CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());
				if (lf.lfWeight == FW_BOLD){
					s.cx += 40;
				}
				pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
				pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
				pDoc->pText->setRgn();

				pDoc->pGroup->setRgn();

				ReleaseDC(dc);
				Invalidate(FALSE);
			}
			else if (tmp->getType() == group){
				YObject* tmp2;
				tmp2 = pDoc->currentObj;
				pDoc->currentObj = tmp;
				OnMenufontsize();
				pDoc->currentObj = tmp2;
				pDoc->currentObj->setRgn();
				Invalidate(FALSE);
			}
		}
		pDoc->currentObj->setRgn();
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
		LOGFONT lf;
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
		CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());
		if (lf.lfWeight == FW_BOLD){
			s.cx += 50;
		}
		pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
		pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
		pDoc->pText->setRgn();
		YText* text = new YText(pDoc->pText);
		pDoc->allList.AddTail(text);
		pDoc->temp_AllList.AddTail(text);
		ReleaseDC(dc);
		Invalidate(FALSE);
	}
	else if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == group){

		pDoc->pGroup = (YGroup*)pDoc->currentObj;
		CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

		POSITION pos = (*pL).GetHeadPosition();
		while (pos) {
			YObject* tmp = (YObject*)(*pL).GetNext(pos);
			if (tmp->getType() == text){
				pDoc->pText = (YText*)tmp;
				pDoc->pText->setFont(font);

				// ����ũ�⺯�� -> ���� ����,��Ʈ����,��������
				CDC* dc = GetDC();
				CFont f;
				LOGFONT lf;
				if (pDoc->pText->getBold()) lf.lfWeight = FW_BOLD;
				else lf.lfWeight = FW_NORMAL;
				lf.lfWidth = 0;
				lf.lfHeight = pDoc->pText->getFontSize();                        //���� ����
				lf.lfStrikeOut = pDoc->pText->getStrikeOut();                        //��Ҽ� ����
				lf.lfUnderline = pDoc->pText->getUnderLine();                        //���ټ���
				lf.lfItalic = pDoc->pText->getItalic();                            //�����
				lf.lfEscapement = 0;                            //���� ���� �ʱ�ȭ
				lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
				lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
				lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
				lf.lfQuality = DEFAULT_QUALITY;
				lf.lfCharSet = DEFAULT_CHARSET;
				wcscpy_s((lf.lfFaceName), _countof(lf.lfFaceName), pDoc->pText->getFont());

				f.CreateFontIndirect(&lf);
				dc->SelectObject(f);
				CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());

				pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
				pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
				pDoc->pText->setRgn();
				ReleaseDC(dc);
				Invalidate(FALSE);
			}
			else if (tmp->getType() == group){
				YObject* tmp2;
				tmp2 = pDoc->currentObj;
				pDoc->currentObj = tmp;
				OnMenufont();
				pDoc->currentObj = tmp2;
				pDoc->currentObj->setRgn();
				Invalidate(FALSE);
			}
		}
		pDoc->currentObj->setRgn();
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
			LOGFONT lf;
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
			CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());
			if (lf.lfWeight == FW_BOLD){
				s.cx += 50;
			}
			pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
			pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
			pDoc->pText->setRgn();
			YText* text = new YText(pDoc->pText);
			pDoc->allList.AddTail(text);
			pDoc->temp_AllList.AddTail(text);
			ReleaseDC(dc);
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
		YText* text = new YText(pDoc->pText);
		pDoc->allList.AddTail(text);
		pDoc->temp_AllList.AddTail(text);
		Invalidate(FALSE);
	}
	else if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == group){
		pDoc->pGroup = (YGroup*)pDoc->currentObj;
		CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

		POSITION pos = (*pL).GetHeadPosition();
		while (pos) {
			YObject* tmp = (YObject*)(*pL).GetNext(pos);
			if (tmp->getType() == text){
				pDoc->pText = (YText*)tmp;
				pDoc->pText->setFontColor(fontColor);
			}
			else if (tmp->getType() == group){
				YObject* tmp2;
				tmp2 = pDoc->currentObj;
				pDoc->currentObj = tmp;
				OnMenufontcolor();
				Invalidate(FALSE);
				pDoc->currentObj = tmp2;
			}
		}
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
		YText* text = new YText(pDoc->pText);
		pDoc->allList.AddTail(text);
		pDoc->temp_AllList.AddTail(text);
		Invalidate(FALSE);
	}
	else if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == group){
		pDoc->pGroup = (YGroup*)pDoc->currentObj;
		CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

		POSITION pos = (*pL).GetHeadPosition();
		while (pos) {
			YObject* tmp = (YObject*)(*pL).GetNext(pos);
			if (tmp->getType() == text){
				pDoc->pText = (YText*)tmp;
				pDoc->pText->setBkColor(bkColor);
			}
			else if (tmp->getType() == group){
				YObject* tmp2;
				tmp2 = pDoc->currentObj;
				pDoc->currentObj = tmp;
				OnMenufontbkcolor();
				Invalidate(FALSE);
				pDoc->currentObj = tmp2;
			}
		}
		Invalidate(FALSE);
	}

}
void CYPaintEditView::OnMenufontdia()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	LOGFONT lf;
	int dialogFontSize;
	if (pDoc->currentObj != NULL && pDoc->currentObj->getType() == text){

		if (pDoc->pText->getBold()) lf.lfWeight = FW_BOLD;
		else lf.lfWeight = FW_NORMAL;

		if (pDoc->pText->getFontSize() >= 300) dialogFontSize = pDoc->pText->getFontSize() / 3.8 + 1;
		else dialogFontSize = pDoc->pText->getFontSize() / 3.8;

		lf.lfHeight = dialogFontSize;						//���� ����
		lf.lfStrikeOut = pDoc->pText->getStrikeOut();						//��Ҽ� ����
		lf.lfUnderline = pDoc->pText->getUnderLine();						//���ټ���
		lf.lfItalic = pDoc->pText->getItalic();							//�����
		lf.lfWidth = 0;
		lf.lfEscapement = 0;							//���� ���� �ʱ�ȭ
		lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
		lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
		lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
		lf.lfQuality = DEFAULT_QUALITY;
		lf.lfCharSet = DEFAULT_CHARSET;
		wcscpy_s((lf.lfFaceName), _countof(lf.lfFaceName), pDoc->pText->getFont());

		CFontDialog dlg(&lf);

		int result = dlg.DoModal();
		if (result == IDOK){

			LOGFONT lf;
			//���̾�α׿��� ����������
			dlg.GetCurrentFont(&lf);
			underline = dlg.IsUnderline();
			bold = dlg.IsBold();
			italic = dlg.IsItalic();
			strikeout = dlg.IsStrikeOut();
			font = lf.lfFaceName;
			fontSize = dlg.GetSize();
			fontColor = dlg.GetColor();

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
				dc->SelectObject(f);

				CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());
				if (lf.lfWeight == FW_BOLD){
					s.cx += 50;
				}
				pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
				pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
				pDoc->pText->setRgn();

				pDoc->pText->setFontColor(fontColor);
				YText* text = new YText(pDoc->pText);
				pDoc->allList.AddTail(text);
				ReleaseDC(dc);
				Invalidate(FALSE);
			}
		}
	}
}
void CYPaintEditView::OnUpdateMenufontsize(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == text || pDoc->currentObj->getType() == group) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == text || pDoc->yType == choice) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}

}
void CYPaintEditView::OnUpdateMenufont(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == text || pDoc->currentObj->getType() == group) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == text || pDoc->yType == choice) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
}
void CYPaintEditView::OnUpdateTexteditbutton(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == text) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == text || pDoc->yType == choice) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
}
void CYPaintEditView::OnUpdateMenufontcolor(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == text || pDoc->currentObj->getType() == group) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == text || pDoc->yType == choice) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
}
void CYPaintEditView::OnUpdateMenufontbkcolor(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == text || pDoc->currentObj->getType() == group) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == text || pDoc->yType == choice) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
}
void CYPaintEditView::OnUpdateMenufontdia(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == text) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == text || pDoc->yType == choice) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
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
					 YLine* line = new YLine(pDoc->pLine);
					 pDoc->allList.AddTail(line);
					 pDoc->temp_AllList.AddTail(line);
					 break;
		}
		case polyline:
		{
						 pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
						 pDoc->pPolyLine->setLineThick(lineThick);
						 YPolyLine* polyline = new YPolyLine(pDoc->pPolyLine);
						 pDoc->allList.AddTail(polyline);
						 pDoc->temp_AllList.AddTail(polyline);
						 break;
		}
		case ellipse:
		{
						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->pEllipse->setLineThick(lineThick);
						YEllipse* ellipse = new YEllipse(pDoc->pEllipse);
						pDoc->allList.AddTail(ellipse);
						pDoc->temp_AllList.AddTail(ellipse);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setLineThick(lineThick);
						  YRectangle* rectangle = new YRectangle(pDoc->pRectangle);
						  pDoc->allList.AddTail(rectangle);
						  pDoc->temp_AllList.AddTail(rectangle);
						  break;
		}
		case group:
		{
					  pDoc->pGroup = (YGroup*)pDoc->currentObj;
					  CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

					  POSITION pos = (*pL).GetHeadPosition();
					  while (pos) {
						  YObject* tmp = (YObject*)(*pL).GetNext(pos);
						  if (tmp->getType() == line){
							  pDoc->pLine = (YLine*)tmp;
							  pDoc->pLine->setLineThick(lineThick);
						  }
						  else if (tmp->getType() == polyline){
							  pDoc->pPolyLine = (YPolyLine*)tmp;
							  pDoc->pPolyLine->setLineThick(lineThick);
						  }
						  else if (tmp->getType() == ellipse){
							  pDoc->pEllipse = (YEllipse*)tmp;
							  pDoc->pEllipse->setLineThick(lineThick);
						  }
						  else if (tmp->getType() == rectangle){
							  pDoc->pRectangle = (YRectangle*)tmp;
							  pDoc->pRectangle->setLineThick(lineThick);
						  }
						  else if (tmp->getType() == group){
							  YObject* tmp2;
							  tmp2 = pDoc->currentObj;
							  pDoc->currentObj = tmp;
							  OnMenulinethick();
							  Invalidate(FALSE);
							  pDoc->currentObj = tmp2;
						  }

					  }
					  YGroup* group = new YGroup(pDoc->pGroup);
					  pDoc->allList.AddTail(group);
					  pDoc->temp_AllList.AddTail(group);
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
		if (pDoc->currentObj->getType() == line || pDoc->currentObj->getType() == polyline || pDoc->currentObj->getType() == ellipse || pDoc->currentObj->getType() == rectangle || pDoc->currentObj->getType() == group)pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == line || pDoc->yType == polyline || pDoc->yType == ellipse || pDoc->yType == rectangle || pDoc->yType == choice)pCmdUI->Enable(TRUE);
		else  pCmdUI->Enable(FALSE);
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
					 YLine* line = new YLine(pDoc->pLine);
					 pDoc->allList.AddTail(line);
					 pDoc->temp_AllList.AddTail(line);
					 break;
		}
		case polyline:
		{
						 pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
						 pDoc->pPolyLine->setLinePattern(linePattern);
						 YPolyLine* polyline = new YPolyLine(pDoc->pPolyLine);
						 pDoc->allList.AddTail(polyline);
						 pDoc->temp_AllList.AddTail(polyline);
						 break;
		}
		case ellipse:
		{
						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->pEllipse->setLinePattern(linePattern);
						YEllipse* ellipse = new YEllipse(pDoc->pEllipse);
						pDoc->allList.AddTail(ellipse);
						pDoc->temp_AllList.AddTail(ellipse);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setLinePattern(linePattern);
						  YRectangle* rectangle = new YRectangle(pDoc->pRectangle);
						  pDoc->allList.AddTail(rectangle);
						  pDoc->temp_AllList.AddTail(rectangle);
						  break;
		}
		case group:
		{
					  pDoc->pGroup = (YGroup*)pDoc->currentObj;
					  CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

					  POSITION pos = (*pL).GetHeadPosition();
					  while (pos) {
						  YObject* tmp = (YObject*)(*pL).GetNext(pos);
						  if (tmp->getType() == line){
							  pDoc->pLine = (YLine*)tmp;
							  pDoc->pLine->setLinePattern(linePattern);
						  }
						  else if (tmp->getType() == polyline){
							  pDoc->pPolyLine = (YPolyLine*)tmp;
							  pDoc->pPolyLine->setLinePattern(linePattern);
						  }
						  else if (tmp->getType() == ellipse){
							  pDoc->pEllipse = (YEllipse*)tmp;
							  pDoc->pEllipse->setLinePattern(linePattern);
						  }
						  else if (tmp->getType() == rectangle){
							  pDoc->pRectangle = (YRectangle*)tmp;
							  pDoc->pRectangle->setLinePattern(linePattern);
						  }
						  else if (tmp->getType() == group){
							  YObject* tmp2;
							  tmp2 = pDoc->currentObj;
							  pDoc->currentObj = tmp;
							  OnMenulinepattern();
							  Invalidate(FALSE);
							  pDoc->currentObj = tmp2;
						  }

					  }

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
		if (pDoc->currentObj->getType() == line || pDoc->currentObj->getType() == polyline || pDoc->currentObj->getType() == ellipse || pDoc->currentObj->getType() == rectangle || pDoc->currentObj->getType() == group)pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == line || pDoc->yType == polyline || pDoc->yType == ellipse || pDoc->yType == rectangle || pDoc->yType == choice)pCmdUI->Enable(TRUE);
		else  pCmdUI->Enable(FALSE);
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
						YEllipse* ellipse = new YEllipse(pDoc->pEllipse);
						pDoc->allList.AddTail(ellipse);
						pDoc->temp_AllList.AddTail(ellipse);
						break;
		}
		case rectangle:
		{
						  if (sidePatternflag2) pDoc->pRectangle->setPatternflag(TRUE);						//default�϶� rectangle�� flag������ ����
						  else pDoc->pRectangle->setPatternflag(FALSE);

						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setSidePattern(sidePattern);
						  YRectangle* rectangle = new YRectangle(pDoc->pRectangle);
						  pDoc->allList.AddTail(rectangle);
						  pDoc->temp_AllList.AddTail(rectangle);
						  break;
		}

		case group:
		{


					  pDoc->pGroup = (YGroup*)pDoc->currentObj;
					  CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

					  POSITION pos = (*pL).GetHeadPosition();
					  while (pos) {
						  YObject* tmp = (YObject*)(*pL).GetNext(pos);
						  if (tmp->getType() == ellipse){
							  pDoc->pEllipse = (YEllipse*)tmp;
							  if (sidePatternflag2) pDoc->pEllipse->setPatternflag(TRUE);							//default�϶� ellipse�� flag������ ����
							  else pDoc->pEllipse->setPatternflag(FALSE);

							  pDoc->pEllipse->setSidePattern(sidePattern);
						  }
						  else if (tmp->getType() == rectangle){
							  pDoc->pRectangle = (YRectangle*)tmp;
							  if (sidePatternflag2) pDoc->pRectangle->setPatternflag(TRUE);						//default�϶� rectangle�� flag������ ����
							  else pDoc->pRectangle->setPatternflag(FALSE);

							  pDoc->pRectangle->setSidePattern(sidePattern);
						  }
						  else if (tmp->getType() == group){
							  YObject* tmp2;
							  tmp2 = pDoc->currentObj;
							  pDoc->currentObj = tmp;
							  OnMenusidepattern();
							  Invalidate(FALSE);
							  pDoc->currentObj = tmp2;
						  }

					  }

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
		if (pDoc->currentObj->getType() == ellipse || pDoc->currentObj->getType() == rectangle || pDoc->currentObj->getType() == group)pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == ellipse || pDoc->yType == rectangle || pDoc->yType == choice)pCmdUI->Enable(TRUE);
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
					 YLine* line = new YLine(pDoc->pLine);
					 pDoc->allList.AddTail(line);
					 pDoc->temp_AllList.AddTail(line);
					 break;
		}
		case polyline:
		{
						 pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
						 pDoc->pPolyLine->setLineColor(lineColor);
						 YPolyLine* polyline = new YPolyLine(pDoc->pPolyLine);
						 pDoc->allList.AddTail(polyline);
						 pDoc->temp_AllList.AddTail(polyline);
						 break;
		}
		case ellipse:
		{
						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->pEllipse->setLineColor(lineColor);
						YEllipse* ellipse = new YEllipse(pDoc->pEllipse);
						pDoc->allList.AddTail(ellipse);
						pDoc->temp_AllList.AddTail(ellipse);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setLineColor(lineColor);
						  YRectangle* rectangle = new YRectangle(pDoc->pRectangle);
						  pDoc->allList.AddTail(rectangle);
						  pDoc->temp_AllList.AddTail(rectangle);
						  break;
		}
		case group:
		{
					  pDoc->pGroup = (YGroup*)pDoc->currentObj;
					  CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

					  POSITION pos = (*pL).GetHeadPosition();
					  while (pos) {
						  YObject* tmp = (YObject*)(*pL).GetNext(pos);
						  if (tmp->getType() == line){
							  pDoc->pLine = (YLine*)tmp;
							  pDoc->pLine->setLineColor(lineColor);
						  }
						  else if (tmp->getType() == polyline){
							  pDoc->pPolyLine = (YPolyLine*)tmp;
							  pDoc->pPolyLine->setLineColor(lineColor);
						  }
						  else if (tmp->getType() == ellipse){
							  pDoc->pEllipse = (YEllipse*)tmp;
							  pDoc->pEllipse->setLineColor(lineColor);
						  }
						  else if (tmp->getType() == rectangle){
							  pDoc->pRectangle = (YRectangle*)tmp;
							  pDoc->pRectangle->setLineColor(lineColor);
						  }
						  else if (tmp->getType() == group){
							  YObject* tmp2;
							  tmp2 = pDoc->currentObj;
							  pDoc->currentObj = tmp;
							  OnMenulinecolor();
							  Invalidate(FALSE);
							  pDoc->currentObj = tmp2;
						  }

					  }

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
						YEllipse* ellipse = new YEllipse(pDoc->pEllipse);
						pDoc->allList.AddTail(ellipse);
						pDoc->temp_AllList.AddTail(ellipse);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setSideColor(sideColor);
						  YRectangle* rectangle = new YRectangle(pDoc->pRectangle);
						  pDoc->allList.AddTail(rectangle);
						  pDoc->temp_AllList.AddTail(rectangle);
						  break;
		}
		case group:
		{
					  pDoc->pGroup = (YGroup*)pDoc->currentObj;
					  CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

					  POSITION pos = (*pL).GetHeadPosition();
					  while (pos) {
						  YObject* tmp = (YObject*)(*pL).GetNext(pos);
						  if (tmp->getType() == ellipse){
							  pDoc->pEllipse = (YEllipse*)tmp;
							  pDoc->pEllipse->setSideColor(sideColor);
						  }
						  else if (tmp->getType() == rectangle){
							  pDoc->pRectangle = (YRectangle*)tmp;
							  pDoc->pRectangle->setSideColor(sideColor);
						  }
						  else if (tmp->getType() == group){
							  YObject* tmp2;
							  tmp2 = pDoc->currentObj;
							  pDoc->currentObj = tmp;
							  OnMenusidecolor();
							  Invalidate(FALSE);
							  pDoc->currentObj = tmp2;
						  }

					  }

					  break;
		}
		default:
			break;
		}

		Invalidate(FALSE);
	}

}
void CYPaintEditView::OnUpdateMenulinecolor(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == line || pDoc->currentObj->getType() == polyline || pDoc->currentObj->getType() == ellipse || pDoc->currentObj->getType() == rectangle || pDoc->currentObj->getType() == group)pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == line || pDoc->yType == polyline || pDoc->yType == ellipse || pDoc->yType == rectangle || pDoc->yType == choice)pCmdUI->Enable(TRUE);
		else  pCmdUI->Enable(FALSE);
	}
}
void CYPaintEditView::OnUpdateMenusidecolor(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == ellipse || pDoc->currentObj->getType() == rectangle || pDoc->currentObj->getType() == group)pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == ellipse || pDoc->yType == rectangle || pDoc->yType == choice)pCmdUI->Enable(TRUE);
		else  pCmdUI->Enable(FALSE);
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
		POSITION tpos=NULL;
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

	if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == group){
		pCmdUI->Enable(TRUE);
	}
	else
		pCmdUI->Enable(FALSE);
}
void CYPaintEditView::OnGroupsizechangebutton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->resizing == FALSE){ // ����
		pDoc->resizing = TRUE;

		pDoc->pGroup = (YGroup*)pDoc->currentObj;
		pDoc->pGroup->setSelect(FALSE);
		pDoc->pGroup->dsetRgn();
		pDoc->pGroup->setResizing();

		CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();
		POSITION pos = (*pL).GetHeadPosition();
		while (pos) {
			YObject* tmp = (*pL).GetNext(pos);
			tmp->setSelect(TRUE);
			pDoc->current_group.AddTail(tmp);
		}
		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnUpdateGroupsizechangebutton(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == group){
		pCmdUI->Enable(TRUE);
		pCmdUI->SetCheck(pDoc->resizing);
	}
	else
		pCmdUI->Enable(FALSE);
}

// Ŭ������ �г�
void CYPaintEditView::OnEditCut()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	menu_Cut = FALSE;
	menu_Copy = FALSE;
	menu_Paste = TRUE;
	menu_CutCopyflag = TRUE;
	menu_CutPaste = TRUE;
	CYPaintEditDoc* pDoc = GetDocument();

	cutObj = NULL;

	if (pDoc->currentObj != NULL){
		cutObj = pDoc->currentObj;

		POSITION pos = pDoc->obj_List.GetHeadPosition();
		POSITION tpos=NULL;
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


	if (cutObj != NULL && menu_CutPaste == TRUE){
		menu_Cut = TRUE;
		menu_Copy = TRUE;
		menu_Paste = FALSE;
		if (menu_CutCopyflag == TRUE) menu_CutPaste = FALSE;
		CYPaintEditDoc* pDoc = GetDocument();
		cutObj->setSelect(FALSE);

		switch (cutObj->getType()){
		case line:
		{
					 YLine* temp = (YLine*)cutObj;
					 pDoc->pLine = new YLine(temp->getSPoint(), temp->getEPoint(), temp->getLineColor(), temp->getLineThick(), temp->getLinePattern());
					 pDoc->pLine->setType(line);
					 pDoc->pLine->setSelect(TRUE);
					 if (menu_CutCopyflag == FALSE){			//�����ϱ� �϶� -> �̵��ϰ� �ٿ��ֱ� �� Ȱ��ȭ
						 pDoc->pLine->moveAll(20, 20);
						 menu_Paste = TRUE;
					 }
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
							 YPolyLine* polyline = new YPolyLine(pDoc->pPolyLine);
							 pDoc->allList.AddTail(polyline);
							 pDoc->temp_AllList.AddTail(polyline);
						 }
						 pDoc->pPolyLine->setType(polyline);
						 pDoc->pPolyLine->setSelect(TRUE);
						 if (menu_CutCopyflag == FALSE) {			//�����ϱ� �϶� -> �̵��ϰ� �ٿ��ֱ� �� Ȱ��ȭ
							 pDoc->pPolyLine->moveAll(20, 20);
							 menu_Paste = TRUE;
						 }
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
						if (menu_CutCopyflag == FALSE){				//�����ϱ� �϶� -> �̵��ϰ� �ٿ��ֱ� �� Ȱ��ȭ
							pDoc->pEllipse->moveAll(20, 20);
							menu_Paste = TRUE;
						}
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
						  if (menu_CutCopyflag == FALSE){						//�����ϱ� �϶� -> �̵��ϰ� �ٿ��ֱ� �� Ȱ��ȭ
							  pDoc->pRectangle->moveAll(20, 20);
							  menu_Paste = TRUE;
						  }
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
					 pDoc->pText = new YText(temp->getSPoint(), temp->getFont(), temp->getFontColor(), temp->getBkColor(), temp->getFontSize(), temp->getUnderLine(), temp->getStrikeOut(), temp->getBold(), temp->getItalic());
					 pDoc->pText->setText(temp->getText());
					 pDoc->pText->setType(text);
					 pDoc->pText->setSelect(TRUE);
					 pDoc->pText->setEPoint(temp->getEPoint());

					 CFont f;
					 LOGFONT lf;

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

					 pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
					 pDoc->pText->setRgn();
					 pDoc->pText->setFontColor(fontColor);

					 if (menu_CutCopyflag == FALSE){								//�����ϱ� �϶� -> �̵��ϰ� �ٿ��ֱ� �� Ȱ��ȭ
						 pDoc->pText->moveAll(20, 20);
						 menu_Paste = TRUE;
					 }
					 pDoc->textEditing = FALSE;
					 pDoc->obj_List.AddTail(pDoc->pText);
					 cutObj = pDoc->pText;
					 pDoc->currentObj = cutObj;
					 break;
		}
		case group:
		{



					  YGroup* groups = (YGroup*)cutObj;
					  CList<YObject*, YObject*>* pL = groups->getList();
					  POSITION pos = (*pL).GetHeadPosition();

					  while (pos){
						  YObject* parent = (*pL).GetNext(pos);
						  switch (parent->getType())
						  {
						  case line:
						  {
									   YLine* temp = (YLine*)parent;
									   pDoc->pLine = new YLine(temp->getSPoint(), temp->getEPoint(), temp->getLineColor(), temp->getLineThick(), temp->getLinePattern());
									   pDoc->pLine->setType(line);
									   pDoc->pLine->setSelect(FALSE);
									   if (menu_CutCopyflag == FALSE){			//�����ϱ� �϶� -> �̵��ϰ� �ٿ��ֱ� �� Ȱ��ȭ
										   pDoc->pLine->moveAll(20, 20);
										   menu_Paste = TRUE;
									   }
									   pDoc->pLine->setRgn();
									   pDoc->drawing = FALSE;
									   pDoc->current_group.AddTail(pDoc->pLine);

									   break;
						  }
						  case polyline:
						  {
										   YPolyLine* temp = (YPolyLine*)parent;
										   pDoc->pPolyLine = new YPolyLine(temp->getLineColor(), temp->getLineThick(), temp->getLinePattern());

										   POSITION pos = temp->getPolyList()->GetHeadPosition();
										   while (pos){
											   CPoint point = temp->getPolyList()->GetNext(pos);
											   pDoc->pPolyLine->addPoint(point);
											   YPolyLine* polyline = new YPolyLine(pDoc->pPolyLine);
											   pDoc->allList.AddTail(polyline);
											   pDoc->temp_AllList.AddTail(polyline);
										   }
										   pDoc->pPolyLine->setType(polyline);
										   pDoc->pPolyLine->setSelect(FALSE);
										   if (menu_CutCopyflag == FALSE) {			//�����ϱ� �϶� -> �̵��ϰ� �ٿ��ֱ� �� Ȱ��ȭ
											   pDoc->pPolyLine->moveAll(20, 20);
											   menu_Paste = TRUE;
										   }
										   pDoc->pPolyLine->setRgn();
										   pDoc->drawing = FALSE;
										   pDoc->current_group.AddTail(pDoc->pPolyLine);
										   break;
						  }
						  case ellipse:
						  {

										  YEllipse* temp = (YEllipse*)parent;
										  pDoc->pEllipse = new YEllipse(temp->getSPoint(), temp->getEPoint(), temp->getLineColor(), temp->getLineThick(), temp->getLinePattern(), temp->getSideColor(), temp->getSidePattern(), temp->getPatternflag());
										  pDoc->pEllipse->setType(ellipse);
										  pDoc->pEllipse->setSelect(FALSE);
										  if (menu_CutCopyflag == FALSE){				//�����ϱ� �϶� -> �̵��ϰ� �ٿ��ֱ� �� Ȱ��ȭ
											  pDoc->pEllipse->moveAll(20, 20);
											  menu_Paste = TRUE;
										  }
										  pDoc->pEllipse->setRgn();
										  pDoc->drawing = FALSE;
										  pDoc->current_group.AddTail(pDoc->pEllipse);
										  break;
						  }
						  case rectangle:
						  {
											YRectangle* temp = (YRectangle*)parent;
											pDoc->pRectangle = new YRectangle(temp->getSPoint(), temp->getEPoint(), temp->getLineColor(), temp->getLineThick(), temp->getLinePattern(), temp->getSideColor(), temp->getSidePattern(), temp->getPatternflag());
											pDoc->pRectangle->setType(rectangle);
											pDoc->pRectangle->setSelect(FALSE);
											if (menu_CutCopyflag == FALSE){						//�����ϱ� �϶� -> �̵��ϰ� �ٿ��ֱ� �� Ȱ��ȭ
												pDoc->pRectangle->moveAll(20, 20);
												menu_Paste = TRUE;
											}
											pDoc->pRectangle->setRgn();
											pDoc->drawing = FALSE;
											pDoc->current_group.AddTail(pDoc->pRectangle);
											break;
						  }
						  case text:
						  {
									   YText* temp = (YText*)parent;
									   pDoc->pText = new YText(temp->getSPoint(), temp->getFont(), temp->getFontColor(), temp->getBkColor(), temp->getFontSize(), temp->getUnderLine(), temp->getStrikeOut(), temp->getBold(), temp->getItalic());
									   pDoc->pText->setText(temp->getText());
									   pDoc->pText->setType(text);
									   pDoc->pText->setSelect(FALSE);
									   pDoc->pText->setEPoint(temp->getEPoint());

									   CFont f;
									   LOGFONT lf;

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

									   pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
									   pDoc->pText->setRgn();
									   pDoc->pText->setFontColor(fontColor);

									   if (menu_CutCopyflag == FALSE){								//�����ϱ� �϶� -> �̵��ϰ� �ٿ��ֱ� �� Ȱ��ȭ
										   pDoc->pText->moveAll(20, 20);
										   menu_Paste = TRUE;
									   }
									   pDoc->textEditing = FALSE;
									   pDoc->current_group.AddTail(pDoc->pText);
									   break;
						  }
						  case group:
						  {
										YObject* tmp2;
										CList<YObject*, YObject*> pgroup;
										tmp2 = cutObj;
										cutObj = parent;
										//pgroup = pDoc->current_group;
										OnEditPaste();
										cutObj = tmp2;
										break;
						  }
						  default:
							  break;
						  }
					  }

					  YGroup* newgroup = new YGroup(pDoc->current_group);
					  newgroup->setRgn();
					  newgroup->setType(group);
					  newgroup->setOrder(pDoc->allNum++);
					  newgroup->setSelect(TRUE);
					  pDoc->currentObj = newgroup;
					  pDoc->obj_List.AddTail(newgroup);
					  // �׷�ȭ ���� �ʱ�ȭ
					  pDoc->current_group.RemoveAll();
					  pDoc->grouping = FALSE;

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
	menu_Cut = TRUE;
	menu_Copy = TRUE;
	menu_Paste = TRUE;
	menu_CutCopyflag = FALSE;
	menu_CutPaste = TRUE;
	CYPaintEditDoc* pDoc = GetDocument();

	cutObj = NULL;

	if (pDoc->currentObj != NULL){
		cutObj = pDoc->currentObj;
	}
}
void CYPaintEditView::OnUpdateEditCut(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(menu_Cut);
}
void CYPaintEditView::OnUpdateEditPaste(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(menu_Paste);
}
void CYPaintEditView::OnUpdateEditCopy(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(menu_Copy);
}
void CYPaintEditView::OnEditSelectAll()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CYPaintEditDoc* pDoc = GetDocument();

	CMFCRibbonButton* selectAll = (CMFCRibbonButton*)main->getRibbon()->FindByID(ID_EDIT_SELECT_ALL);
	POSITION pos = pDoc->obj_List.GetHeadPosition();
	if (!selectAll->IsFocused()){
		while (pos){
			YObject* temp = (YObject*)pDoc->obj_List.GetNext(pos);
			temp->setSelect(TRUE);
		}
		Invalidate(FALSE);
	}
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
					 YLine* line = new YLine(pDoc->pLine);
					 pDoc->allList.AddTail(line);
					 pDoc->temp_AllList.AddTail(line);
					 break;
		}
		case polyline:
		{
						 pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
						 pDoc->pPolyLine->setLineColor(lineColor);
						 YPolyLine* polyline = new YPolyLine(pDoc->pPolyLine);
						 pDoc->allList.AddTail(polyline);
						 pDoc->temp_AllList.AddTail(polyline);
						 break;
		}

		case ellipse:
		{
						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->pEllipse->setLineColor(lineColor);
						YEllipse* ellipse = new YEllipse(pDoc->pEllipse);
						pDoc->allList.AddTail(ellipse);
						pDoc->temp_AllList.AddTail(ellipse);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setLineColor(lineColor);
						  YRectangle* rectangle = new YRectangle(pDoc->pRectangle);
						  pDoc->allList.AddTail(rectangle);
						  pDoc->temp_AllList.AddTail(rectangle);
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
	pCmdUI->Enable(menu_LineColor);
}
void CYPaintEditView::OnEditFiguresetting()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	menu_Figure = FALSE;

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
				 dlg.flag = FALSE;
				 break;
	}
	case polyline:
	{
					 pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
					 dlg.lineThick = pDoc->pPolyLine->getLineThick();
					 dlg.linePattern = pDoc->pPolyLine->getLinePattern();
					 dlg.flag = FALSE;
					 break;
	}
	case ellipse:
	{
					pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
					dlg.lineThick = pDoc->pEllipse->getLineThick();
					dlg.linePattern = pDoc->pEllipse->getLinePattern();
					dlg.flag = TRUE;
					break;
	}
	case rectangle:
	{
					  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
					  dlg.flag = TRUE;
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
						pDoc->pEllipse->setSidePattern(dlg.SidePattern);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setLineThick(dlg.lineThick);
						  pDoc->pRectangle->setLinePattern(dlg.linePattern);
						  pDoc->pRectangle->setSidePattern(dlg.SidePattern);
						  break;
		}


		default:
			break;
		}

		Invalidate(FALSE);
		UpdateMenu();
	}
}
void CYPaintEditView::OnUpdateEditFiguresetting(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(menu_Figure);
}
void CYPaintEditView::OnEditDelete()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	POSITION tpos=NULL;
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
	pCmdUI->Enable(menu_Delete);
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
			POSITION tpos=NULL;

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
	pCmdUI->Enable(menu_DeletePoint);
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
	pCmdUI->Enable(menu_SideColor);
}
void CYPaintEditView::OnEditgroup()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�
	CYPaintEditDoc* pDoc = GetDocument();
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
}
void CYPaintEditView::OnUpdateEditgroup(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(menu_Group);
}
void CYPaintEditView::OnEditdeletegroup()
{
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj->getType() == group){
		// obj_List���� �׷��� ��ġ�� ã�� �κ�
		YObject* to;
		POSITION tpos=NULL;
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
void CYPaintEditView::OnUpdateEditdeletegroup(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(menu_DeleteGroup);
}


// Undo, Redo //
void CYPaintEditView::OnBack()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	POSITION pos;
	YObject* temp;
	YObject* lastObject=NULL;
	YObject* original;
	BOOL find;																		//obj_List�� ���� ��ü�� �ִ� �Ǻ��ϴ� flag����
	undoredoFlag = FALSE;
	pos = pDoc->allList.GetTailPosition();
	if (pDoc->currentObj == NULL){													//��ü�� Ŭ�� �ȵǾ����� ���۰����ϵ��� ����
		if (pos != NULL && pDoc->allList.GetSize() > 1){
			temp = (YObject*)pDoc->allList.GetTail();								//�������� �����
			pDoc->allList.RemoveTail();

			POSITION rpos = pDoc->allList.GetTailPosition();						//�������� ����� �ٽ�Ž��
			while (rpos) {
				lastObject = (YObject*)pDoc->allList.GetPrev(rpos);
				if (temp->getOrder() == lastObject->getOrder()){
					find = TRUE;
					break;
				}
				find = FALSE;
			}
			if (find){																// order�� �Ȱ��� ���� obj_List�� ���� ���
				POSITION opos = pDoc->obj_List.GetTailPosition();
				while (opos) {
					POSITION t;
					t = opos;
					original = (YObject*)pDoc->obj_List.GetPrev(opos);
					if (lastObject->getOrder() == original->getOrder()){
						pDoc->obj_List.SetAt(t, lastObject);
						break;
					}
				}
			}
			else {																	// �������� ������ obj_List���� ������ �־�Ѵ�.
				POSITION opos = pDoc->obj_List.GetTailPosition();
				while (opos) {
					POSITION t;
					t = opos;
					original = (YObject*)pDoc->obj_List.GetPrev(opos);
					if (temp->getOrder() == original->getOrder()){
						pDoc->obj_List.RemoveAt(t);
						break;
					}
				}
			}
		}
		else {
			pDoc->allList.RemoveAll();
			pDoc->obj_List.RemoveAll();
		}
		Invalidate(FALSE);
	}

}
void CYPaintEditView::OnFrontback()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	POSITION pos;				//allList�� position
	YObject* temp;				//�ٽ� ������ ��ü�� ������ ����
	if (!undoredoFlag){  // �ڷΰ��⸦ ������쿡�� ����

		int count = pDoc->allList.GetSize();
		pos = pDoc->temp_AllList.GetHeadPosition();
		for (int i = 0; i < count; i++){
			pDoc->temp_AllList.GetNext(pos);
		}
		temp = (YObject*)pDoc->temp_AllList.GetNext(pos);
		switch (temp->getType()){
		case line:
		{
					 YLine* line = new YLine((YLine*)temp);
					 pDoc->allList.AddTail(line);
					 break;
		}
		case polyline:
		{
						 YPolyLine* polyline = new YPolyLine((YPolyLine*)temp);
						 pDoc->allList.AddTail(polyline);
						 break;
		}
		case ellipse:
		{
						YEllipse* ellipse = new YEllipse((YEllipse*)temp);
						pDoc->allList.AddTail(ellipse);
						break;
		}
		case rectangle:
		{
						  YRectangle* rectangle = new YRectangle((YRectangle*)temp);
						  pDoc->allList.AddTail(rectangle);
						  break;
		}
		case text:
		{
					 YText* text = new YText((YText*)temp);
					 pDoc->allList.AddTail(text);
					 break;
		}
		}
		//obj_List�� ��ü�� �ٽ� �߰��ϴ� ����
		POSITION tpos = pDoc->obj_List.GetTailPosition();
		POSITION changepos;
		BOOL check = FALSE;
		while (tpos){
			changepos = tpos;
			YObject* original = (YObject*)pDoc->obj_List.GetPrev(tpos);

			if (temp->getOrder() == original->getOrder()){
				pDoc->obj_List.SetAt(changepos, temp);
				check = TRUE;
				break;
			}
		}
		if (!check){ // Ž���� ���ߴµ� ���� ��ü�� ������ ��ü�� �߰����־���Ѵ�.
			pDoc->obj_List.AddTail(temp);
		}

		Invalidate(FALSE);
	}

}
void CYPaintEditView::OnUpdateBack(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->allList.GetCount() == 0) pCmdUI->Enable(FALSE);
	else pCmdUI->Enable(TRUE);
}
void CYPaintEditView::OnUpdateFrontback(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CYPaintEditDoc* pDoc = GetDocument();
	if (pDoc->allList.GetCount() == pDoc->temp_AllList.GetCount()) pCmdUI->Enable(FALSE);
	else pCmdUI->Enable(TRUE);

}

