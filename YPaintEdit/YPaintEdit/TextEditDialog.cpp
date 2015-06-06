// TextEditDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "YPaintEdit.h"
#include "TextEditDialog.h"
#include "afxdialogex.h"


// TextEditDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(TextEditDialog, CDialog)

TextEditDialog::TextEditDialog(CString& str, CWnd* pParent /*=NULL*/)
: CDialog(TextEditDialog::IDD, pParent)
, text(str)
{

}

TextEditDialog::~TextEditDialog()
{
}

void TextEditDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, text);
}


BEGIN_MESSAGE_MAP(TextEditDialog, CDialog)
END_MESSAGE_MAP()
