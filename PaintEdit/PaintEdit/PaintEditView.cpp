
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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPaintEditView

IMPLEMENT_DYNCREATE(CPaintEditView, CView)

BEGIN_MESSAGE_MAP(CPaintEditView, CView)
END_MESSAGE_MAP()

// CPaintEditView ����/�Ҹ�

CPaintEditView::CPaintEditView()
{
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
