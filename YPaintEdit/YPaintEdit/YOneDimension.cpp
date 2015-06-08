#include "stdafx.h"
#include "YOneDimension.h"


YOneDimension::YOneDimension()
{
}


YOneDimension::~YOneDimension()
{
}


IMPLEMENT_SERIAL(YOneDimension, CObject, 1)
void YOneDimension::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.

		ar << lineColor << lineThick << linePattern;
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
		ar >> lineColor >> lineThick >> linePattern;
	}
}