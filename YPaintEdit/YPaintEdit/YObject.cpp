#include "stdafx.h"
#include "YObject.h"
ULONG_PTR gdiplusToken;  //gdi++

YObject::YObject()
{
	GdiplusStartupInput gdiplusStartupInput;	//gdi++
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);	//gdi++
}


YObject::~YObject()
{
	GdiplusShutdown(gdiplusToken);	//gdi++
}
