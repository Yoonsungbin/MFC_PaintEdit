// �� MFC ���� �ҽ� �ڵ�� MFC Microsoft Office Fluent ����� �������̽�("Fluent UI")�� 
// ����ϴ� ����� ���� �ָ�, MFC C++ ���̺귯�� ����Ʈ��� ���Ե� 
// Microsoft Foundation Classes Reference �� ���� ���� ������ ���� 
// �߰������� �����Ǵ� �����Դϴ�.  
// Fluent UI�� ����, ��� �Ǵ� �����ϴ� �� ���� ��� ����� ������ �����˴ϴ�.  
// Fluent UI ���̼��� ���α׷��� ���� �ڼ��� ������ 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// YPaintEditDoc.h : CYPaintEditDoc Ŭ������ �������̽�
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
protected: // serialization������ ��������ϴ�.
	CYPaintEditDoc();
	DECLARE_DYNCREATE(CYPaintEditDoc)

// Ư���Դϴ�.
public:
	YObject_Type yType;					// ���� �۾����� ������ Ÿ���� ��Ÿ���� ����
	YObject* currentObj;				// ���� �۾����� ������ ��ü�� ����Ű�� ������
	CPtrList obj_List;					// �۾��� �Ϸ�� �������� �����ϴ� ����Ʈ
	
	YLine* pLine;						// �� �۾��� ���� ������
	YPolyLine* pPolyLine;				// �ٰ��� �۾��� ���� ������
	YEllipse* pEllipse;					// Ÿ�� �۾��� ���� ������
	YRectangle* pRectangle;				// �簢�� �۾��� ���� ������
	YText* pText;						// �ؽ�Ʈ �۾��� ���� ������
	
	BOOL drawing ;						// �׸��� ���� Ȯ�κ���
	BOOL textEditing;					// �ؽ�Ʈ ���� ���¸� ��Ÿ���� ����
	CString tmp;						// �ؽ�Ʈ�� �ӽ÷� �����ϴ� ����
	BOOL clickPolyLine;					// PolyLine ���� ����  true - > Ŭ�� false -> �ʱ����
	int deletePosition;					// PolyLine ���� ���� �� ���� ��ġ ���庯��

	CPoint Original_Point;				// move�� ���� ��������

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
	virtual ~CYPaintEditDoc();
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