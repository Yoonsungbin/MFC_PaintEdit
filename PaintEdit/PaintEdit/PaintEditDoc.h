
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
	CPtrList list;		// void*  형으로 위치들 저장할까 ? or  <Point,Point&> 형으로 할까 고민중
	MyObject* current; //어떤 타입의 객체인지 정하기위해서 오브젝트 포인터 변수하나설정
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
