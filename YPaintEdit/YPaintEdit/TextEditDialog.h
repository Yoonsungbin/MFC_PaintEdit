#pragma once


// TextEditDialog ��ȭ �����Դϴ�.

class TextEditDialog : public CDialog
{
	DECLARE_DYNAMIC(TextEditDialog)

public:
	TextEditDialog(CString& str, CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~TextEditDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TEXTEDITDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnEnChangeEdit1();
	CString& text;
};
