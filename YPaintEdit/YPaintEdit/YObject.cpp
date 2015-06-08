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
		// TODO: 여기에 저장 코드를 추가합니다.
		ar << (int)yType << rect << isSelected << order;
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
		int tempType;
		ar >> tempType >> rect >> isSelected >> order;
		yType = (YObject_Type)tempType;
	}
}