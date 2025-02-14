#include "stdafx.h"
#include "TriangleXY.h"


TriangleXY::TriangleXY(PointXY * startPoint, PointXY * endPoint) : ShapeXY(startPoint,endPoint)
{
}

TriangleXY::TriangleXY(int x1, int y1, int x2, int y2) : ShapeXY(x1,y1,x2,y2)
{
}

int TriangleXY::getType()
{
	return type;
}

TriangleXY::~TriangleXY()
{
}
