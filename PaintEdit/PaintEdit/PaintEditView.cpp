
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

void CPaintEditView::OnDraw(CDC* pDC)
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
	
	//초기값 설정
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
		// 캐럿 생성
		// 텍스트 입력받기 및 출력
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CPaintEditDoc* pDoc = (CPaintEditDoc*)GetDocument();
	CClientDC dc(this);

	if (pDoc->CurrentObj.IsEmpty())	return;

	if (nFlags & MK_LBUTTON){
		

		CPen pen(PS_SOLID, 5, RGB(0,0,255));
		CPen *oldpen = dc.SelectObject(&pen);

		// 이전에 그린 직선을 지운다.
		dc.SetROP2(R2_NOT);
		dc.MoveTo(pDoc->point_Start);
		dc.LineTo(pDoc->point_End);

		// 새로운 직선을 그린다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.



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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
 