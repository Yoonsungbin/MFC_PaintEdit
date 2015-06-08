#include "stdafx.h"
#include "YObject.h"

ULONG_PTR gdiplusToken; 

YObject::YObject()
{
	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
}


YObject::~YObject()
{
	GdiplusShutdown(gdiplusToken);
}

IMPLEMENT_SERIAL(YObject, CObject, 1)

void YObject::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
		ar << (int)yType << rect << isSelected << order;
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
		int tempType;
		ar >> tempType >> rect >> isSelected >> order;
		yType = (YObject_Type)tempType;
	}
}