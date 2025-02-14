#include "stdafx.h"
#include "RectXY.h"


RectXY::RectXY(PointXY * startPoint, PointXY * endPoint) : ShapeXY(startPoint,endPoint)
{
}

RectXY::RectXY(int x1, int y1, int x2, int y2) : ShapeXY(x1,y1,x2,y2)
{
}

int RectXY::getType()
{
	return type;
}

RectXY::~RectXY()
{
}

