#include "stdafx.h"
#include "LineXY.h"


LineXY::LineXY(PointXY * startPoint, PointXY * endPoint) : ShapeXY(startPoint,endPoint)
{
}

LineXY::LineXY(int x1, int y1, int x2, int y2) : ShapeXY(x1,y1,x2,y2)
{
}

int LineXY::getType()
{
	return type;
}

LineXY::~LineXY()
{
}
