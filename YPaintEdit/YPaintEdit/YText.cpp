#include "stdafx.h"
#include "YText.h"
#include "YObject.h"

// Constructors, Destructor
YText::YText()
{
}
YText::YText(CPoint point, CString f, COLORREF fc, COLORREF bkc, int s, BOOL under, BOOL stri, BOOL bo, BOOL ita){
	sPoint = point;					// �ؽ�Ʈ �ڽ��� ����,���� ���� �ʱ�ȭ
	font = f;						// ����ü �ʱ�ȭ
	fontColor = fc;					// ���ڻ� �ʱ�ȭ
	bkColor = bkc;					// ���� �ʱ�ȭ
	fontSize = s;					// ����ũ�� �ʱ�ȭ
	underline = under;				// ���� �ʱ�ȭ
	strikeout = stri;				// ��Ҽ� �ʱ�ȭ
	bold = bo;						// ���� �ʱ�ȭ
	italic = ita;					// ����� �ʱ�ȭ
}
YText::~YText()
{
}
YText::YText(YText* p){
	sPoint = p->getSPoint();					// �ؽ�Ʈ �ڽ��� ����,���� ���� �ʱ�ȭ
	ePoint = p->getEPoint();
	font = p->getFont();						// ����ü �ʱ�ȭ
	fontColor = p->getFontColor();					// ���ڻ� �ʱ�ȭ
	bkColor = p->getBkColor();					// ���� �ʱ�ȭ
	fontSize = p->getFontSize();					// ����ũ�� �ʱ�ȭ
	underline = p->getUnderLine();				// ���� �ʱ�ȭ
	strikeout = p->getStrikeOut();				// ��Ҽ� �ʱ�ȭ
	bold = p->getBold();						// ���� �ʱ�ȭ
	italic = p->getItalic();
	texts = p->getText();
	LOGFONT lf;
	CFont f;
	if (bold) lf.lfWeight = FW_BOLD;
	else lf.lfWeight = FW_NORMAL;
	lf.lfWidth = 0;
	lf.lfHeight = fontSize;						//���� ����
	lf.lfStrikeOut = strikeout;						//��Ҽ� ����
	lf.lfUnderline = underline;						//���ټ���
	lf.lfItalic = italic;							//�����
	lf.lfEscapement = 0;							//���� ���� �ʱ�ȭ
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

	//���⼳��
	if (bold) lf.lfWeight = FW_BOLD;
	else lf.lfWeight = FW_NORMAL;
	lf.lfWidth = 0;
	lf.lfHeight = fontSize;						//���� ����
	lf.lfStrikeOut = strikeout;						//��Ҽ� ����
	lf.lfUnderline = underline;						//���ټ���
	lf.lfItalic = italic;							//�����
	lf.lfEscapement = 0;							//���� ���� �ʱ�ȭ
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
	dc->FillSolidRect(rect, bkColor);					// �ؽ�Ʈ�ڽ� ũ�� ��ĥ
	dc->DrawText(texts, rect, NULL);

}
void YText::setRgn(){
	int left, top, right, bottom;

	// ��쿡 ���� ���� ���������Լ��� �Է��� ��ǥ ����
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
	// ���� ����
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
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
		ar << sPoint << ePoint << rect << texts << font << fontColor << bkColor << fontSize << underline << strikeout << bold << italic;
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
		ar >> sPoint >> ePoint >> rect >> texts >> font >> fontColor >> bkColor >> fontSize >> underline >> strikeout >> bold >> italic;
		setRgn();
	}
}