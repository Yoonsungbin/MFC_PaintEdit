#include "stdafx.h"
#include "YTwoDimension.h"


YTwoDimension::YTwoDimension()
{
}


YTwoDimension::~YTwoDimension()
{
}

IMPLEMENT_SERIAL(YTwoDimension, CObject, 1)

void YTwoDimension::Serialize(CArchive& ar)
{
	YObject::Serialize(ar);
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
		ar << lineColor << lineThick << linePattern << sideColor << sidePattern << Patternflag;
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
		ar >> lineColor >> lineThick >> linePattern >> sideColor >> sidePattern >> Patternflag;
	}
}

