#pragma once
#include "YObject.h"
class YText : public YObject
{
public:
	// Constructors, Destructor
	YText();													// �⺻ ������
	YText(CPoint point, CString f, COLORREF fc,					// �ʱⰪ�� �޴� ������
		COLORREF bkc, int s,BOOL underline,BOOL stri,BOOL bo,BOOL ita);										
	~YText();													// �⺻ �Ҹ���
	

	// Virtual
	void setType(YObject_Type t) { yType = t; }					// ��ü�� Ÿ���� �ؽ�Ʈ Ÿ������ �����ϴ� �Լ�
	void moveAll(int s, int e);									// �ؽ�Ʈ ��ü�� �̵���Ű�� �Լ�
	void deleteAll();											// �ؽ�Ʈ ��ü�� �����ϴ� �Լ�
	void draw(CDC* dc);											// �ؽ�Ʈ ��ü�� �׸��� �Լ�

	virtual void setRgn();										// ������ �����ϴ� �Լ�
	BOOL checkRgn(CPoint point);								// ��ǥ�� �����ȿ� �����ϴ��� Ȯ���ϴ� �Լ�
	void setSelect(BOOL select) { isSelected = select; }		// ��ü�� ���õǾ����� ��Ÿ���� �Լ�
	

	// Mutator
	void setSPoint(CPoint point) { sPoint = point; }			// �ؽ�Ʈ �ڽ��� ����,���� ���� �����ϴ� �Լ�
	void setEPoint(CPoint point) { ePoint = point; }			// �ؽ�Ʈ �ڽ��� ������,�Ʒ��� ���� �����ϴ� �Լ�
	void setRect(CPoint sPoint, CPoint ePoint)					// �ؽ�Ʈ �ڽ��� �����ϴ� �Լ�
		{ rect.SetRect(sPoint.x, sPoint.y, ePoint.x, ePoint.y); }
	void setText(CString nText) { texts = nText;  }				// �ؽ�Ʈ�� �����ϴ� �Լ�
	void setFont(CString nFont) { font = nFont; }				// ����ü�� �����ϴ� �Լ�
	void setFontColor(COLORREF nColor) { fontColor = nColor; }	// ���ڻ��� �����ϴ� �Լ�
	void setBkColor(COLORREF nColor) { bkColor = nColor; }		// ������ �����ϴ� �Լ�
	void setFontSize(int nFontSize) { fontSize = nFontSize; }	// ����ũ�⸦ �����ϴ� �Լ�
	void setUnderLine(BOOL under) { underline = under; }
	void setStrikeOut(BOOL stri) { strikeout = stri; }
	void setBold(BOOL bo) { bold = bo; }
	void setItalic(BOOL ita) { italic = ita; }
	
	// Accessor
	CPoint getSPoint() { return sPoint; }						// �ؽ�Ʈ �ڽ��� ����,���� ���� ��� �Լ�
	CPoint getEPoint() { return ePoint; }						// �ؽ�Ʈ �ڽ��� ������,�Ʒ��� ���� ��� �Լ�
	CRect getRect() { return rect; }							// �ؽ�Ʈ �ڽ��� ��� �Լ�
	CString getText() { return texts; }							// �ؽ�Ʈ�� ��� �Լ�
	CString getFont() { return font; }							// ����ü�� ��� �Լ�
	COLORREF getFontColor() { return fontColor; }				// ���ڻ��� ��� �Լ� 
	COLORREF getBkColor() { return bkColor; }					// ������ ��� �Լ�
	int getFontSize() { return fontSize; }						// ����ũ�⸦ ��� �Լ�
	BOOL getUnderLine() { return underline; }
	BOOL getStrikeOut() { return strikeout; }
	BOOL getBold() { return bold; }
	BOOL getItalic() { return italic; }

	// Variables
private:
	CPoint sPoint;			// �ؽ�Ʈ �ڽ��� ����,���� ��
	CPoint ePoint;			// �ؽ�Ʈ �ڽ��� ������,�Ʒ��� ��
	CRect rect;				// �ؽ�Ʈ �ڽ�
	CString texts;			// ���ڿ�
	CString font;			// ����ü
	COLORREF fontColor;		// ���ڻ�
	COLORREF bkColor;		// ����
	int fontSize;			// ����ũ��
	BOOL underline;
	BOOL strikeout;
	BOOL bold;
	BOOL italic;

};