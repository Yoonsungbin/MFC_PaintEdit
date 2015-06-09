#include "stdafx.h"
#include "YText.h"
#include "YObject.h"

// Constructors, Destructor
YText::YText()
{
}
YText::YText(CPoint point, CString f, COLORREF fc, COLORREF bkc, int s, BOOL under, BOOL stri, BOOL bo, BOOL ita){
	sPoint = point;					// 텍스트 박스의 왼쪽,위의 점을 초기화
	font = f;						// 글자체 초기화
	fontColor = fc;					// 글자색 초기화
	bkColor = bkc;					// 배경색 초기화
	fontSize = s;					// 글자크기 초기화
	underline = under;				// 및줄 초기화
	strikeout = stri;				// 취소선 초기화
	bold = bo;						// 굵기 초기화
	italic = ita;					// 기울임 초기화
}
YText::~YText()
{
}
YText::YText(YText* p){
	sPoint = p->getSPoint();					// 텍스트 박스의 왼쪽,위의 점을 초기화
	ePoint = p->getEPoint();
	font = p->getFont();						// 글자체 초기화
	fontColor = p->getFontColor();					// 글자색 초기화
	bkColor = p->getBkColor();					// 배경색 초기화
	fontSize = p->getFontSize();					// 글자크기 초기화
	underline = p->getUnderLine();				// 및줄 초기화
	strikeout = p->getStrikeOut();				// 취소선 초기화
	bold = p->getBold();						// 굵기 초기화
	italic = p->getItalic();
	texts = p->getText();
	LOGFONT lf;
	CFont f;
	if (bold) lf.lfWeight = FW_BOLD;
	else lf.lfWeight = FW_NORMAL;
	lf.lfWidth = 0;
	lf.lfHeight = fontSize;						//높이 설정
	lf.lfStrikeOut = strikeout;						//취소선 설정
	lf.lfUnderline = underline;						//밑줄설정
	lf.lfItalic = italic;							//기울임
	lf.lfEscapement = 0;							//글자 각도 초기화
	wcscpy_s((lf.lfFaceName), _countof(lf.lfFaceName), font);
	lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
	lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
	lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
	lf.lfQuality = DEFAULT_QUALITY;
	lf.lfCharSet = DEFAULT_CHARSET;
	f.CreateFontIndirect(&lf);

	setOrder(p->getOrder());
	setSelect(p->getSelect());
	setType(p->getType());
	setRgn();
}

IMPLEMENT_SERIAL(YText, CObject, 1)
// Virtual
void YText::moveAll(int s, int e){
	sPoint.x += s;
	sPoint.y += e;
	ePoint.x += s;
	ePoint.y += e;
	setRect(sPoint, ePoint);
	setRgn();
}
void YText::deleteAll(){

}
void YText::draw(CDC* dc){
	if (isSelected == TRUE){
		CPen pen(PS_DOT, 1, RGB(0, 0, 0));
		CPen* oldPen = dc->SelectObject(&pen);
		dc->SelectObject(pen);
		dc->Rectangle(sPoint.x - 1, sPoint.y - 1, ePoint.x + 1, ePoint.y + 1);
		dc->SelectObject(&oldPen);
	}

	CFont f;
	LOGFONT lf;
	//f.CreatePointFont(fontSize, font);

	//굵기설정
	if (bold) lf.lfWeight = FW_BOLD;
	else lf.lfWeight = FW_NORMAL;
	lf.lfWidth = 0;
	lf.lfHeight = fontSize;						//높이 설정
	lf.lfStrikeOut = strikeout;						//취소선 설정
	lf.lfUnderline = underline;						//밑줄설정
	lf.lfItalic = italic;							//기울임
	lf.lfEscapement = 0;							//글자 각도 초기화
	wcscpy_s((lf.lfFaceName), _countof(lf.lfFaceName), font);
	lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
	lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
	lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
	lf.lfQuality = DEFAULT_QUALITY;
	lf.lfCharSet = DEFAULT_CHARSET;
	f.CreateFontIndirect(&lf);
	
	dc->SelectObject(&f);

	dc->SetBkColor(bkColor);
	dc->SetBkMode(TRANSPARENT);
	dc->SetTextColor(fontColor);
	dc->FillSolidRect(rect, bkColor);					// 텍스트박스 크기 색칠
	dc->DrawText(texts, rect, NULL);

}
void YText::setRgn(){
	int left, top, right, bottom;

	// 경우에 수에 따라 리젼생성함수에 입력할 좌표 설정
	if (sPoint.x < ePoint.x && sPoint.y < ePoint.y){
		left = sPoint.x;
		top = sPoint.y;
		right = ePoint.x;
		bottom = ePoint.y;
	}
	else if (sPoint.x < ePoint.x && sPoint.y > ePoint.y){
		left = sPoint.x;
		top = ePoint.y;
		right = ePoint.x;
		bottom = sPoint.y;
	}
	else if (sPoint.x > ePoint.x && sPoint.y < ePoint.y){
		left = ePoint.x;
		top = sPoint.y;
		right = sPoint.x;
		bottom = ePoint.y;
	}
	else {
		left = ePoint.x;
		top = ePoint.y;
		right = sPoint.x;
		bottom = sPoint.y;
	}
	YObject::setORect(left - 1, top - 1, right + 1, bottom + 1);
	// 리젼 생성
	rgn.DeleteObject();
	rgn.CreateRectRgn(left, top, right, bottom);
}
BOOL YText::checkRgn(CPoint point)
{
	if (rgn.PtInRegion(point))
		return TRUE;

	return FALSE;
}


void YText::Serialize(CArchive& ar)
{
	YObject::Serialize(ar);
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
		ar << sPoint << ePoint << rect << texts << font << fontColor << bkColor << fontSize << underline << strikeout << bold << italic;
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
		ar >> sPoint >> ePoint >> rect >> texts >> font >> fontColor >> bkColor >> fontSize >> underline >> strikeout >> bold >> italic;
		setRgn();
	}
}