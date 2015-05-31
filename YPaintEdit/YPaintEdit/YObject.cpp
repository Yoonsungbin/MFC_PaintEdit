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