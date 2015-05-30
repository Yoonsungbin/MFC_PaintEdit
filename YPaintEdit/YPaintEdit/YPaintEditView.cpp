// 이 MFC 샘플 소스 코드는 MFC Microsoft Office Fluent 사용자 인터페이스("Fluent UI")를 
// 사용하는 방법을 보여 주며, MFC C++ 라이브러리 소프트웨어에 포함된 
// Microsoft Foundation Classes Reference 및 관련 전자 문서에 대해 
// 추가적으로 제공되는 내용입니다.  
// Fluent UI를 복사, 사용 또는 배포하는 데 대한 사용 약관은 별도로 제공됩니다.  
// Fluent UI 라이선싱 프로그램에 대한 자세한 내용은 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// YPaintEditView.cpp : CYPaintEditView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// CYPaintEditView 생성/소멸

CYPaintEditView::CYPaintEditView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
}

CYPaintEditView::~CYPaintEditView()
{
}

BOOL CYPaintEditView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CYPaintEditView 그리기

void CYPaintEditView::OnDraw(CDC* /*pDC*/)
{
	CYPaintEditDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
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


// CYPaintEditView 진단

#ifdef _DEBUG
void CYPaintEditView::AssertValid() const
{
	CView::AssertValid();
}

void CYPaintEditView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CYPaintEditDoc* CYPaintEditView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYPaintEditDoc)));
	return (CYPaintEditDoc*)m_pDocument;
}
#endif //_DEBUG


// CYPaintEditView 메시지 처리기


void CYPaintEditView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);
	//초기값 설정
	pDoc->sPoint = point;
	pDoc->ePoint = point;
	pDoc->drawing = FALSE;

	switch (pDoc->yType){
	case line:
	{
				 //초기화
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
					 if (pDoc->clickPolyLine == FALSE){   //시작 생성
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
					 else{   //시작점생성후 클릭할때 마다
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
				   //List에서 선택된 객체 하나가 나오면 TRUE로바꾸고 끝냄 (그룹화하게되면 배열또는 리스트 로설정해야할꺼같음)
				   if (pDoc->currentObj != NULL)	{
					   pDoc->currentObj->setSelect(FALSE);
					   pDoc->isSelected = FALSE;
					   pDoc->currentObj = NULL;
				   }

				   //현재 선택한 객체 찾기
				   POSITION pos = pDoc->obj_List.GetTailPosition();
				   while (pos) {
					   pDoc->currentObj = (YObject*)pDoc->obj_List.GetPrev(pos);
					   if (pDoc->currentObj->checkRgn(point) == TRUE){
						   pDoc->currentObj->setSelect(TRUE);
						   break;
					   }
					   //라인의 끝점은 라인 영역 밖에 있으므로 한번더 검색해줘야한다.
					   if (pDoc->currentObj == pDoc->pLine){
						   if (pDoc->pLine->getMRect()[0].PtInRect(point) || pDoc->pLine->getMRect()[1].PtInRect(point)) {
							   pDoc->currentObj->setSelect(TRUE);
							   break;
						   }
					   }
				   }

				   //선택된 객체에대해서 행할 행동의 정의
				   if (pDoc->currentObj->getSelect() == TRUE){
					   pDoc->isSelected = TRUE;
					   pDoc->drawing = TRUE;
					   pDoc->Original_Point = point;  //선 이동시 기준점이 되는 좌표
					   switch (pDoc->currentObj->getType()){
					   case line:
					   {
									pDoc->pLine = (YLine*)pDoc->currentObj;
									if (pDoc->pLine->getMRect()[0].PtInRect(point)){  // 시작점 클릭
										pDoc->sPoint = point;
										pDoc->pLine->setSPoint(pDoc->sPoint);
										pDoc->pLine->setMPoint(-1);  //시작점이동
									}
									else if (pDoc->pLine->getMRect()[1].PtInRect(point)){	// 끝점 클릭
										pDoc->ePoint = point;
										pDoc->pLine->setEPoint(pDoc->ePoint);
										pDoc->pLine->setMPoint(1);  //끝점이동
										break;
									}
									else if (pDoc->pLine->checkRgn(point)) {		//그 외 영역 클릭
										pDoc->pLine->setMPoint(0); //전체이동
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
												pDoc->pPolyLine->setMoveSetting(1);  //한점이동
												break;
											}
											else pDoc->pPolyLine->setMoveSetting(0);  //전체이동
										}
										Invalidate();
										break;
					   }
					   case ellipse:
					   {
									   //타원 연장 하기
									   pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
									   if (pDoc->pLine->getMRect()[0].PtInRect(point)){  // 시작점 클릭
										   pDoc->sPoint = point;
										   pDoc->pEllipse->setSPoint(pDoc->sPoint);
										   pDoc->pEllipse->setMPoint(-1);  //시작점이동
									   }
									   else if (pDoc->pEllipse->getMRect()[1].PtInRect(point)){	// 끝점 클릭
										   pDoc->ePoint = point;
										   pDoc->pEllipse->setEPoint(pDoc->ePoint);
										   pDoc->pEllipse->setMPoint(1);  //끝점이동
										   break;
									   }
									   else if (pDoc->pEllipse->checkRgn(point)) {		//그 외 영역 클릭
										   pDoc->pEllipse->setMPoint(0); //전체이동
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);

	if (nFlags & MK_LBUTTON || pDoc->clickPolyLine){

		CPen pen(PS_SOLID, 1, RGB(0, 0, 255));
		CPen *oldPen = dc.SelectObject(&pen);
		switch (pDoc->yType){
		case line:
		{
					 pDoc->pLine = (YLine*)pDoc->currentObj;
					 pDoc->ePoint = point;  //마우스 이동할때 끝점 지속적으로 바꾸어줘야 그릴수있다.
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
						//마우스 움직일때
						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->ePoint = point;
						pDoc->pEllipse->setEPoint(point);
						break;
		}
		case text:
		{
					 break;
		}

			//선택 일떄 이동 시키려구
		case choice:
		{
					   CPoint t_point = point - pDoc->Original_Point; //좌표 움직임
					   pDoc->Original_Point = point;
					   switch (pDoc->currentObj->getType()){
					   case line:
					   {
									pDoc->pLine = (YLine*)pDoc->currentObj;
									//선택되었을때 이동 변수에따라 다른 move실행
									if (pDoc->isSelected){
										if (pDoc->pLine->getMPoint() == 0){  //전체이동
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
									   //선택되었을때 이동 변수에따라 다른 move실행
									   if (pDoc->isSelected){
										   if (pDoc->pEllipse->getMPoint() == 0){  //전체이동
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	 //마우스 땔때
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
					//pDoc->pEllipse->setType(ellipse);//이거 왜 안되냐???ㅅㅂ
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
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.

	CYPaintEditDoc* pDoc = GetDocument();
	POSITION pos = pDoc->obj_List.GetHeadPosition();

	while (pos) {
		YObject* tmp = (YObject*)pDoc->obj_List.GetNext(pos);
		CPen pen(PS_SOLID, 1, RGB(0, 0, 255));
		CPen *oldPen = dc.SelectObject(&pen);
		tmp->draw(&dc);
		dc.SelectObject(&oldPen);
	}

	if (pDoc->drawing){			// 마우스 움직이는 도중 계속 실행되는 함수
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
		// 폰트 생성 및 적용
		CFont f;
		f.CreatePointFont(pDoc->ptext->getFontSize(), pDoc->ptext->getFont());
		dc.SelectObject(f);
		dc.SetBkColor(pDoc->ptext->getBkColor());
		dc.SetTextColor(pDoc->ptext->getFontColor());

		// 폰트를 반영한 문자열(텍스트)의 길이 생성 및 저장
		CSize s = dc.GetTextExtent(pDoc->ptext->getText(), pDoc->ptext->getText().GetLength());

		// 초기 텍스트 박스 모형을 위한 코드
		CString cInitial = _T("t");
		CSize sInitial = dc.GetTextExtent(cInitial, cInitial.GetLength());

		// ePoint 및 rect 설정
		if (pDoc->ptext->getText().GetLength() == 0)
			pDoc->ptext->setEPoint(CPoint(pDoc->ptext->getSPoint().x + sInitial.cx, pDoc->ptext->getSPoint().y + sInitial.cy));
		else
			pDoc->ptext->setEPoint(CPoint(pDoc->ptext->getSPoint().x + s.cx, pDoc->ptext->getSPoint().y + s.cy));
		pDoc->ptext->setRect(pDoc->ptext->getSPoint(), pDoc->ptext->getEPoint());

		// 출력용 리젼 생성
		CRect r(pDoc->ptext->getSPoint().x - 1, pDoc->ptext->getSPoint().y - 1, pDoc->ptext->getEPoint().x + 1, pDoc->ptext->getEPoint().y + 1);
		// 출력용 리젼을 위한 펜 및 브러시 생성 및 적용
		CPen pen(PS_DOT, 1, RGB(0, 0, 0));
		dc.SelectObject(pen);
		CBrush brush(pDoc->ptext->getBkColor());
		dc.SelectObject(brush);

		// 리젼 및 텍스트 출력
		dc.Rectangle(r);
		dc.DrawText(pDoc->ptext->getText(), pDoc->ptext->getRect(), NULL);

		// 캐럿 생성 및 출력
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->textEditing == TRUE){
		if (nChar == _T('\b')){ // 지우기 (delete 키)
			if (pDoc->ptext->getText().GetLength() > 0){
				pDoc->tmp.GetBufferSetLength(pDoc->tmp.GetLength() - 1);
				pDoc->ptext->setText(pDoc->tmp);
			}
		}
		else if (nChar == VK_RETURN){ // 입력 종료 (enter 키)
			pDoc->textEditing = FALSE;
			pDoc->obj_List.AddTail(pDoc->ptext);
			pDoc->tmp.Empty();
			HideCaret();
		}
		else{ // 입력
			pDoc->tmp.AppendChar(nChar);
			pDoc->ptext->setText(pDoc->tmp);
		}
		Invalidate();
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CYPaintEditView::MenuLineButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->yType = line;
	pDoc->lineColor = RGB(0, 0, 0);
	pDoc->lineThick = 1;
	pDoc->linePattern = 0;
}


void CYPaintEditView::MenuDefaultButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = choice;

	//선택을 누름으로써 모든 객체 선택여부를 FALSE로
	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos){
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		pDoc->currentObj->setSelect(FALSE);
	}
	pDoc->currentObj = NULL;
}


void CYPaintEditView::MenuTextButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->yType = text;
}


void CYPaintEditView::MenuEllipseButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->yType = ellipse;
}

//마우스 오른쪽버튼 클릭후 -> 선 클릭시
void CYPaintEditView::RMenuColorButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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

//마우스 오른쪽 버튼 클릭후 -> 도형 서식 바꾸기
void CYPaintEditView::FigureSettingButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	if (pDoc->yType == polyline){
		pDoc->clickPolyLine = FALSE;
		pDoc->drawing = FALSE;
		pDoc->pPolyLine->setDrawPolyLine(FALSE);
		pDoc->pPolyLine->setRgn(); // 리젼설정
		pDoc->pPolyLine->setSelect(FALSE);
		pDoc->pPolyLine->setType(polyline);
		pDoc->obj_List.AddTail(pDoc->pPolyLine);

		Invalidate();
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CYPaintEditView::MenuPolyLineButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->yType = polyline;
}
