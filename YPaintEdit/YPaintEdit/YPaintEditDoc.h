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
	CPtrList obj_List;					// �۾��� �Ϸ�� �������� �����ϴ� ����Ʈ
	YObject_Type yType;					// ���� �۾����� ������ Ÿ���� ��Ÿ���� ����
	YObject* currentObj;				// ���� �۾����� ������ ��ü�� ����Ű�� ������
	YLine* pLine;						// �� �۾��� ���� ������
	YPolyLine* pPolyLine;				// �ٰ��� �۾��� ���� ������
	YEllipse* pEllipse;					// Ÿ�� �۾��� ���� ������
	YRectangle* pRectangle;				// �簢�� �۾��� ���� ������
	YText* pText;						// �ؽ�Ʈ �۾��� ���� ������


	//////////////////////////////////////////////////////////////////////////////////
	//////////////     �ʿ���� ���� ���ְ�, �� �ʿ��Ѱ͸� ����~~!!!     /////////////
	//////////////////////////////////////////////////////////////////////////////////
	CPoint sPoint;
	CPoint ePoint;
	CPoint Original_Point; // move������ ��������
	BOOL drawing ; //�׸��� ���� Ȯ�κ���
	BOOL isSelected ;
	COLORREF lineColor;  //����
	int lineThick;
	int linePattern;

	BOOL textEditing;	// Text
	CString tmp;		// Text

	BOOL clickPolyLine;  //PolyLine���� ����  true - > Ŭ�� false -> �ʱ����
	/////////////////////////////////////////////////////////////////////////////////

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