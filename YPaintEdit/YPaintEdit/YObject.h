#pragma once

// YObject ��� ����Դϴ�.

class YObject : public CObject
{
public:
	YObject();
	virtual ~YObject();

	virtual void moveAll() = 0;
	virtual void delteAll() = 0;
	virtual void draw(CDC*) = 0;

public:
	CRgn rgn;  //����
};


