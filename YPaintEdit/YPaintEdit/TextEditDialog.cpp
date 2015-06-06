// TextEditDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "YPaintEdit.h"
#include "TextEditDialog.h"
#include "afxdialogex.h"


// TextEditDialog ��ȭ �����Դϴ�.

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
