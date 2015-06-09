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

// YPaintEditDoc.cpp : CYPaintEditDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "YPaintEdit.h"
#endif

#include "YPaintEditDoc.h"
#include<afxtempl.h>
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CYPaintEditDoc

IMPLEMENT_DYNCREATE(CYPaintEditDoc, CDocument)

BEGIN_MESSAGE_MAP(CYPaintEditDoc, CDocument)
END_MESSAGE_MAP()


// CYPaintEditDoc ����/�Ҹ�

CYPaintEditDoc::CYPaintEditDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
	currentObj = NULL;
	drawing = FALSE;
	textEditing = FALSE;
	clickPolyLine = FALSE;
	grouping = FALSE;

	deletePosition = -1;			// �������� ������ �� ��ġ ���庯�� �ʱ�ȭ
	allNum = 0;
}

CYPaintEditDoc::~CYPaintEditDoc()
{
}

BOOL CYPaintEditDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.
	obj_List.RemoveAll();
	return TRUE;
}




// CYPaintEditDoc serialization
void CYPaintEditDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
		POSITION pos = obj_List.GetHeadPosition();
		int count = obj_List.GetSize();
		ar << count;
		while (pos){
			YObject* temp = (YObject*)obj_List.GetNext(pos);
			temp->setSelect(FALSE);
			ar << temp->getType();
			switch (temp->getType()){
			case line:
			{
						 YLine* line = (YLine*)temp;
						 line->Serialize(ar);
						 break;
			}
			case polyline:
			{
							 YPolyLine* polyline = (YPolyLine*)temp;
							 polyline->Serialize(ar);
							 break;
			}
			case ellipse:
			{
							YEllipse* ellipse = (YEllipse*)temp;
							ellipse->Serialize(ar);
							break;
			}
			case rectangle:
			{
							  YRectangle* rectangle = (YRectangle*)temp;
							  rectangle->Serialize(ar);
							  break;
			}
			case text:
			{
						 YText* text = (YText*)temp;
						 text->Serialize(ar);
						 break;
			}
			case group:
			{
						  YGroup* group = (YGroup*)temp;
						  group->Serialize(ar);
						  break;
			}
			}
		}
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
		int count;
		int type;
		ar >> count;

		obj_List.RemoveAll();
		currentObj = NULL;
		for (int i = 0; i < count; i++){
			ar >> type;

			switch (type){
			case line:
			{
						 YLine* line = new YLine();
						 line->Serialize(ar);
						 obj_List.AddTail(line);
						 break;
			}
			case polyline:
			{
							 YPolyLine* polyline = new YPolyLine();
							 polyline->Serialize(ar);
							 obj_List.AddTail(polyline);
							 break;
			}
			case ellipse:
			{
							YEllipse* ellipse = new YEllipse();
							ellipse->Serialize(ar);
							obj_List.AddTail(ellipse);
							break;
			}
			case rectangle:
			{
							  YRectangle* rectangle = new YRectangle();
							  rectangle->Serialize(ar);
							  obj_List.AddTail(rectangle);
							  break;
			}
			case text:
			{
						 YText* text = new YText();
						 text->Serialize(ar);
						 obj_List.AddTail(text);
						 break;
			}
			case group:
			{
						  YGroup* group = new YGroup();
						  group->Serialize(ar);
						  obj_List.AddTail(group);
						  break;
			}
			}

		}
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CYPaintEditDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CYPaintEditDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CYPaintEditDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CYPaintEditDoc ����

#ifdef _DEBUG
void CYPaintEditDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CYPaintEditDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CYPaintEditDoc ���
