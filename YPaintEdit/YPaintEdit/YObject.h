#pragma once
#include "afx.h"
class YObject :
	public CObject
{
public:
	YObject();
	~YObject();

	virtual void moveAll() = 0;
	virtual void deleteAll() = 0;
	virtual void draw(CDC*) = 0;

public:
	CRgn rgn; //¸®Á¯
};

