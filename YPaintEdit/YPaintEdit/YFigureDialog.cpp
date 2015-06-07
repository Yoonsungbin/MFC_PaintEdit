// YFigureDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "YPaintEdit.h"
#include "YFigureDialog.h"
#include "afxdialogex.h"


// YFigureDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(YFigureDialog, CDialog)

YFigureDialog::YFigureDialog(CWnd* pParent /*=NULL*/)
	: CDialog(YFigureDialog::IDD, pParent)
	, lineThick(0)
	, linePattern(0)
{

}

YFigureDialog::~YFigureDialog()
{
}

void YFigureDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DIALOGLINETHICK, lineThick);
	DDX_CBIndex(pDX, IDC_DIALOGLINEPATTERN, linePattern);
	DDX_Control(pDX, IDC_DIALOGLINEPATTERN, patternIndex);
	DDX_Control(pDX, IDC_SPIN1, thick);
}


BEGIN_MESSAGE_MAP(YFigureDialog, CDialog)
END_MESSAGE_MAP()


// YFigureDialog �޽��� ó�����Դϴ�.


BOOL YFigureDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	thick.SetRange(1, 20);  // �ʱⰪ ����
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
