#include "stdafx.h"
#include "ShapeXY.h"



ShapeXY::ShapeXY(PointXY* startPoint, PointXY* endPoint)
{
	this->startPoint = startPoint;
	this->endPoint = endPoint;
}

ShapeXY::ShapeXY(int x1, int y1, int x2, int y2)
{
	startPoint = new PointXY(x1, y1);
	endPoint = new PointXY(x2, y2);
}

PointXY * ShapeXY::getStartPoint()
{
	return startPoint;
}

PointXY * ShapeXY::getEndPoint()
{
	return endPoint;
}

int ShapeXY::getType()
{
	return type;
}



ShapeXY::~ShapeXY()
{
	delete startPoint; startPoint = NULL;
	delete endPoint; endPoint = NULL;
}

