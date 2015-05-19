
// PaintEditDoc.h : CPaintEditDoc 클래스의 인터페이스
//
#include "MyObject.h"

#pragma once


class CPaintEditDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CPaintEditDoc();
	DECLARE_DYNCREATE(CPaintEditDoc)

// 특성입니다.
public:
	CPtrList ObjList; //  Graphic object를 저장해놓는 벡터
	CPtrList CurrentObj; //현재 객체 타입
	CPoint point_Start;
	CPoint point_End;
	int p_color;
	int p_thick;
	BOOL drawing;
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
	virtual ~CPaintEditDoc();
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
