
// PaintEditDoc.h : CPaintEditDoc Ŭ������ �������̽�
//
#include "MyObject.h"

#pragma once


class CPaintEditDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CPaintEditDoc();
	DECLARE_DYNCREATE(CPaintEditDoc)

// Ư���Դϴ�.
public:
	CPtrList ObjList; //  Graphic object�� �����س��� ����
	CPtrList CurrentObj; //���� ��ü Ÿ��
	CPoint point_Start;
	CPoint point_End;
	int p_color;
	int p_thick;
	BOOL drawing;
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CPaintEditDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
