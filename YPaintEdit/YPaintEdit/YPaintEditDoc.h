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
	YObject_Type yType;
	CPtrList obj_List;
	YObject* currentObj;
	YLine* pLine;
	YPolyLine* pPolyLine;
	YEllipse* pEllipse;
	YRectangle* pRectangle;
	YText *ptext;

	CPoint sPoint;
	CPoint ePoint;
	BOOL drawing = FALSE; //�׸��� ���� Ȯ�κ���
	BOOL isExist = FALSE; //�����ȿ� �����ϴ���
	BOOL isSelected =FALSE;
	COLORREF lineColor;  //����
	int lineThick;
	int linePattern;
	BOOL textEditing; // Text
	CString tmp; // Text

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
