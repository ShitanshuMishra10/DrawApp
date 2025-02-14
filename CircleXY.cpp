#include "stdafx.h"
#include "CircleXY.h"


CircleXY::CircleXY(PointXY * startPoint, PointXY * endPoint) : ShapeXY(startPoint,endPoint)
{
}

CircleXY::CircleXY(int x1, int y1, int x2, int y2) : ShapeXY(x1,y1,x2,y2)
{
}

int CircleXY::getType()
{
	return type;
}

CircleXY::~CircleXY()
{
}
