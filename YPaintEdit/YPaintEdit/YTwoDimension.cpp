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
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
		ar << lineColor << lineThick << linePattern << sideColor << sidePattern << Patternflag;
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
		ar >> lineColor >> lineThick >> linePattern >> sideColor >> sidePattern >> Patternflag;
	}
}

