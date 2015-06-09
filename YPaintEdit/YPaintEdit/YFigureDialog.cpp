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
	, linePattern(0)
	, SidePattern(0)
	, lineThick(0)
{

}

YFigureDialog::~YFigureDialog()
{
}

void YFigureDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN1, thick);
	DDX_Control(pDX, IDC_DIALOGLINEPATTERN, patternIndex);
	DDX_Control(pDX, IDC_DIALOGSIDEPATTERN, SidePatternIndex);
	DDX_CBIndex(pDX, IDC_DIALOGLINEPATTERN, linePattern);
	DDX_CBIndex(pDX, IDC_DIALOGSIDEPATTERN, SidePattern);
	DDX_Text(pDX, IDC_DIALOGLINETHICK, lineThick);
}


BEGIN_MESSAGE_MAP(YFigureDialog, CDialog)
END_MESSAGE_MAP()




BOOL YFigureDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	if (flag == FALSE)
	{
		SidePatternIndex.EnableWindow(FALSE);

	}
	
	thick.SetRange(1, 20);  // �ʱⰪ ����
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
