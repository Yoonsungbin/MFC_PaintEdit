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

// YPaintEditDoc.h : CYPaintEditDoc 클래스의 인터페이스
//


#pragma once
#include "YObject.h"
#include "YLine.h"
#include "YPolyLine.h"
#include "YEllipse.h"
#include "YRectangle.h"
#include "YText.h"


class CYPaintEditDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CYPaintEditDoc();
	DECLARE_DYNCREATE(CYPaintEditDoc)

// 특성입니다.
public:
	YObject_Type yType;					// 현재 작업중인 도형의 타입을 나타내는 변수
	YObject* currentObj;				// 현재 작업중인 도형의 객체를 가리키는 포인터
	CPtrList obj_List;					// 작업이 완료된 도형들을 보관하는 리스트
	
	YLine* pLine;						// 선 작업을 위한 포인터
	YPolyLine* pPolyLine;				// 다각선 작업을 위한 포인터
	YEllipse* pEllipse;					// 타원 작업을 위한 포인터
	YRectangle* pRectangle;				// 사각형 작업을 위한 포인터
	YText* pText;						// 텍스트 작업을 위한 포인터
	
	BOOL drawing ;						// 그리기 상태 확인변수
	BOOL textEditing;					// 텍스트 편집 상태를 나타내는 변수
	CString tmp;						// 텍스트를 임시로 저장하는 변수
	BOOL clickPolyLine;					// PolyLine 선택 유무  true - > 클릭 false -> 초기생성
	int deletePosition;					// PolyLine 한점 지울 때 지울 위치 저장변수

	CPoint Original_Point;				// move를 위한 시작지점

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CYPaintEditDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};