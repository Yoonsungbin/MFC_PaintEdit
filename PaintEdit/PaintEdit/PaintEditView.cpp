
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

void CPaintEditView::OnDraw(CDC* /*pDC*/)
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
	if (type == line){
		MyLine* line = new MyLine();
		line->setpoint(point.x, point.y, point.x, point.y);
		pDoc->current = line;
		pDoc->list.AddTail(line);
		//AfxMessageBox(_T("rectangle"), MB_YESNO);
	}
	else {
		AfxMessageBox(_T("ni hao"), MB_YESNO);
	}

	CView::OnLButtonDown(nFlags, point);
}


void CPaintEditView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	AfxMessageBox(_T("rectangle"), MB_YESNO);
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void CPaintEditView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CPaintEditDoc* pDoc = (CPaintEditDoc*)GetDocument();
	CClientDC dc(this);
	if (nFlags & MK_LBUTTON){
		MyObject* my = pDoc->current;
		my->draw(&dc);

		my->setpoint(point.x, point.y, 0, 0);
		my->draw(&dc);
	}
	
	CView::OnMouseMove(nFlags, point);
}


void CPaintEditView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	CPaintEditDoc* pDoc = (CPaintEditDoc*)GetDocument();
	POSITION pos = pDoc->list.GetHeadPosition();

	while (pos != NULL){
		MyObject* my = (MyObject*)pDoc->list.GetNext(pos);

		CPen pen(PS_SOLID, my->GetThick(), my->GetColor());

		my->draw(&dc);
	}




	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.
}
