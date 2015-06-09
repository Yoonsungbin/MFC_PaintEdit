// YFigureDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "YPaintEdit.h"
#include "YFigureDialog.h"
#include "afxdialogex.h"


// YFigureDialog 대화 상자입니다.

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

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	if (flag == FALSE)
	{
		SidePatternIndex.EnableWindow(FALSE);

	}
	
	thick.SetRange(1, 20);  // 초기값 설정
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
