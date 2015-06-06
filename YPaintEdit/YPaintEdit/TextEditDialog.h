#pragma once


// TextEditDialog 대화 상자입니다.

class TextEditDialog : public CDialog
{
	DECLARE_DYNAMIC(TextEditDialog)

public:
	TextEditDialog(CString& str, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~TextEditDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_TEXTEDITDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnEnChangeEdit1();
	CString& text;
};
