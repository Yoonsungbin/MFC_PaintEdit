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
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

		ar << lineColor << lineThick << linePattern;
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
		ar >> lineColor >> lineThick >> linePattern;
	}
}