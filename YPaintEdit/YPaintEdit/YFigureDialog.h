
#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// YFigureDialog ��ȭ �����Դϴ�.

class YFigureDialog : public CDialog
{
	DECLARE_DYNAMIC(YFigureDialog)

public:
	YFigureDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~YFigureDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int lineThick;
	int linePattern;
	CComboBox patternIndex;
	CSpinButtonCtrl thick;
	virtual BOOL OnInitDialog();
};
