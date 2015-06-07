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


// YFigureDialog 메시지 처리기입니다.


BOOL YFigureDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	thick.SetRange(1, 20);  // 초기값 설정
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
