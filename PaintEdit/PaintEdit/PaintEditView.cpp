
// PaintEditView.cpp : CPaintEditView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "PaintEdit.h"
#endif

#include "PaintEditDoc.h"
#include "PaintEditView.h"
#include "MyObject.h"
#include "MyLine.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPaintEditView

IMPLEMENT_DYNCREATE(CPaintEditView, CView)

BEGIN_MESSAGE_MAP(CPaintEditView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CPaintEditView ����/�Ҹ�

CPaintEditView::CPaintEditView()
{
	type = line;
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CPaintEditView::~CPaintEditView()
{
	
}

BOOL CPaintEditView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CPaintEditView �׸���

void CPaintEditView::OnDraw(CDC* pDC)
{
	CPaintEditDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	
}


// CPaintEditView ����

#ifdef _DEBUG
void CPaintEditView::AssertValid() const
{
	CView::AssertValid();
}

void CPaintEditView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaintEditDoc* CPaintEditView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaintEditDoc)));
	return (CPaintEditDoc*)m_pDocument;
}
#endif //_DEBUG


// CPaintEditView �޽��� ó����


void CPaintEditView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CPaintEditDoc* pDoc = GetDocument();
	
	//�ʱⰪ ����
	pDoc->point_Start = point;
	pDoc->point_End = point;
	pDoc->drawing = FALSE;
	if (type == line){
		
		MyLine* line = new MyLine();
		line->setpoint(point.x, point.y, point.x, point.y);
		line->SetColor(pDoc->p_color);
		line->SetThick(pDoc->p_thick);
		pDoc->drawing = TRUE;
		pDoc->CurrentObj.RemoveAll();
		pDoc->CurrentObj.AddTail(line);
		
		
	}
	/////////////////////////// Text ////////////////////////////
	else if (type == text){
		// ĳ�� ����
		// �ؽ�Ʈ �Է¹ޱ� �� ���
		pDoc->textEditing = TRUE;
	}
	////////////////////////////////////////////////////////////
	else {
		AfxMessageBox(_T("ni hao"), MB_YESNO);
	}

	CView::OnLButtonDown(nFlags, point);
}


void CPaintEditView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CPaintEditDoc* pDoc = GetDocument();

	if (type == line) {
		CClientDC dc(this);
		pDoc->point_End = point;
		MyObject* curr_obj = (MyObject*)pDoc->CurrentObj.GetHead();
	
		pDoc->ObjList.AddTail(curr_obj);
		pDoc->CurrentObj.RemoveAll();
		pDoc->CurrentObj.AddTail(curr_obj);
		pDoc->drawing = FALSE;
				
	}
	Invalidate(FALSE);
	CView::OnLButtonUp(nFlags, point);
}


void CPaintEditView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CPaintEditDoc* pDoc = (CPaintEditDoc*)GetDocument();
	CClientDC dc(this);

	if (pDoc->CurrentObj.IsEmpty())	return;

	if (nFlags & MK_LBUTTON){
		

		CPen pen(PS_SOLID, 5, RGB(0,0,255));
		CPen *oldpen = dc.SelectObject(&pen);

		// ������ �׸� ������ �����.
		dc.SetROP2(R2_NOT);
		dc.MoveTo(pDoc->point_Start);
		dc.LineTo(pDoc->point_End);

		// ���ο� ������ �׸���.
		dc.SetROP2(R2_NOT);
		dc.MoveTo(pDoc->point_Start);
		dc.LineTo(point);
		pDoc->point_End = point;
		//Invalidate(FALSE);
	}

	CView::OnMouseMove(nFlags, point);
}


void CPaintEditView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.



	CPaintEditDoc* pDoc = GetDocument();

	POSITION pos = pDoc->ObjList.GetHeadPosition();
	while (pos)
	{
		MyObject* tmp = (MyObject*)pDoc->ObjList.GetNext(pos);

		CPen pen(PS_SOLID, tmp->GetThick(), tmp->GetColor());
		CPen *oldpen = dc.SelectObject(&pen);
		tmp->setpoint(pDoc->point_Start.x, pDoc->point_Start.y, pDoc->point_End.x, pDoc->point_End.y);
		tmp->draw(&dc);
		dc.SelectObject(&oldpen);
	}

	///////////////////// Text ////////////////////////
	//dc.DrawText(pDoc->textChar.GetData(), pDoc->textChar.GetSize(), CRect(textPoint.x, textPoint.y, textPoint.x + 300, textPoint.y + 50), DT_LEFT);
	///////////////////////////////////////////////////
}


void CPaintEditView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) // Text
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CPaintEditDoc* pDoc = GetDocument();
	if (pDoc->textEditing == 1){
		if (nChar == _T('\b')){
			if (pDoc->textChar.GetSize() > 0){
				pDoc->textChar.RemoveAt(pDoc->textChar.GetSize() - 1);
			}
		}
		else if (nChar == VK_RETURN){
			pDoc->textEditing = FALSE;
		}
		else{
			pDoc->textChar.Add(nChar);
		}
		Invalidate();
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}
 