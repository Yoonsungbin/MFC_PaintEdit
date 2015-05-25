#pragma once

// YObject 명령 대상입니다.

class YObject : public CObject
{
public:
	YObject();
	virtual ~YObject();

	virtual void moveAll() = 0;
	virtual void delteAll() = 0;
	virtual void draw(CDC*) = 0;

public:
	CRgn rgn;  //리젼
};


