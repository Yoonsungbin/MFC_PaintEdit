#pragma once
#include "YObject.h"
class YText : public YObject
{
public:
	// Constructors, Destructor
	YText();													// �⺻ ������
	YText(CPoint point);										// CPoint ��ü �ϳ��� �޴� ������
	~YText();													// �⺻ �Ҹ���
	

	// Virtual
	void setType(YObject_Type t) { yType = t; }					// ��ü�� Ÿ���� �ؽ�Ʈ Ÿ������ �����ϴ� �Լ�
	void moveAll(int s, int e);									// �ؽ�Ʈ ��ü�� �̵���Ű�� �Լ�
	void deleteAll();											// �ؽ�Ʈ ��ü�� �����ϴ� �Լ�
	void draw(CDC* dc);											// �ؽ�Ʈ ��ü�� �׸��� �Լ�

	void setSPoint(CPoint point) { sPoint = point; }			// �ؽ�Ʈ �ڽ��� ����,���� ���� �����ϴ� �Լ�
	void setEPoint(CPoint point) { ePoint = point; }			// �ؽ�Ʈ �ڽ��� ������,�Ʒ��� ���� �����ϴ� �Լ�
	CPoint getSPoint() { return sPoint; }						// �ؽ�Ʈ �ڽ��� ����,���� ���� ��� �Լ�
	CPoint getEPoint() { return ePoint; }						// �ؽ�Ʈ �ڽ��� ������,�Ʒ��� ���� ��� �Լ�
	virtual void setRgn();										// ������ �����ϴ� �Լ�
	BOOL checkRgn(CPoint point);								// ��ǥ�� �����ȿ� �����ϴ��� Ȯ���ϴ� �Լ�
	void setSelect(BOOL select) { isSelected = select; }		// 
	

	// Accessor
	void setRect(CPoint sPoint, CPoint ePoint)					// �ؽ�Ʈ �ڽ��� �����ϴ� �Լ�
		{ rect.SetRect(sPoint.x, sPoint.y, ePoint.x, ePoint.y); }
	void setText(CString nText) { text = nText;  }				// �ؽ�Ʈ�� �����ϴ� �Լ�
	void setFont(CString nFont) { font = nFont; }				// ����ü�� �����ϴ� �Լ�
	void setFontColor(COLORREF nColor) { fontColor = nColor; }	// ���ڻ��� �����ϴ� �Լ�
	void setBkColor(COLORREF nColor) { bkColor = nColor; }		// ������ �����ϴ� �Լ�
	void setFontSize(int nFontSize) { fontSize = nFontSize; }	// ����ũ�⸦ �����ϴ� �Լ�

	
	// Mutator
	CRect getRect() { return rect; }							// �ؽ�Ʈ �ڽ��� ��� �Լ�
	CString getText() { return text; }							// �ؽ�Ʈ�� ��� �Լ�
	CString getFont() { return font; }							// ����ü�� ��� �Լ�
	COLORREF getFontColor() { return fontColor; }				// ���ڻ��� ��� �Լ� 
	COLORREF getBkColor() { return bkColor; }					// ������ ��� �Լ�
	int getFontSize() { return fontSize; }						// ����ũ�⸦ ��� �Լ�


	// Variables
private:
	CPoint sPoint;			// �ؽ�Ʈ �ڽ��� ����,���� ��
	CPoint ePoint;			// �ؽ�Ʈ �ڽ��� ������,�Ʒ��� ��
	CRect rect;				// �ؽ�Ʈ �ڽ�
	CString text;			// �ؽ�Ʈ
	CString font;			// ����ü
	COLORREF fontColor;		// ���ڻ�
	COLORREF bkColor;		// ����
	int fontSize;			// ����ũ��
};