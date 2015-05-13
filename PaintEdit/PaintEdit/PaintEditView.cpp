
// PaintEditView.cpp : CPaintEditView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// CPaintEditView 생성/소멸

CPaintEditView::CPaintEditView()
{
	type = line;
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPaintEditView::~CPaintEditView()
{
}

BOOL CPaintEditView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPaintEditView 그리기

void CPaintEditView::OnDraw(CDC* /*pDC*/)
{
	CPaintEditDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CPaintEditView 진단

#ifdef _DEBUG
void CPaintEditView::AssertValid() const
{
	CView::AssertValid();
}

void CPaintEditView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaintEditDoc* CPaintEditView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaintEditDoc)));
	return (CPaintEditDoc*)m_pDocument;
}
#endif //_DEBUG


// CPaintEditView 메시지 처리기


void CPaintEditView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	AfxMessageBox(_T("rectangle"), MB_YESNO);
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void CPaintEditView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	CPaintEditDoc* pDoc = (CPaintEditDoc*)GetDocument();
	POSITION pos = pDoc->list.GetHeadPosition();

	while (pos != NULL){
		MyObject* my = (MyObject*)pDoc->list.GetNext(pos);

		CPen pen(PS_SOLID, my->GetThick(), my->GetColor());

		my->draw(&dc);
	}




	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
}
