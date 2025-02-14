#pragma once
#include <afx.h>

class PointXY :public CObject
{
private:
	int x;
	int y;

public:
	PointXY();
	PointXY(int x,int y);
	virtual ~PointXY();

	int getX();
	int getY();
	void setPoint(int x, int y);


};

