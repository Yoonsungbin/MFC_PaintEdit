
// PaintEdit.h : PaintEdit ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CPaintEditApp:
// �� Ŭ������ ������ ���ؼ��� PaintEdit.cpp�� �����Ͻʽÿ�.
//

class CPaintEditApp : public CWinApp
{
public:
	CPaintEditApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPaintEditApp theApp;