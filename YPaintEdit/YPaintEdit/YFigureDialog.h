#pragma once
#include "afxcmn.h"
#include "afxwin.h"


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
	BOOL flag;
	CSpinButtonCtrl thick;
	CComboBox patternIndex;
	CComboBox SidePatternIndex;
	int linePattern;
	int SidePattern;
	int lineThick;

	
	virtual BOOL OnInitDialog();
};
