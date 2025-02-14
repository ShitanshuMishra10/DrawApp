#include "stdafx.h"
#include "PointXY.h"


PointXY::PointXY()
{
	x = y = 0;
}

PointXY::PointXY(int x,int y)
{
	this->x = x;
	this->y = y;
}

int PointXY::getX()
{
	return x;
}

int PointXY::getY()
{
	return y;
}

void PointXY::setPoint(int x, int y)
{
	this->x = x; this->y = y;
}

PointXY::~PointXY()
{
}
