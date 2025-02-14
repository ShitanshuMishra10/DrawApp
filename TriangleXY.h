#pragma once
#include "ShapeXY.h"
class TriangleXY :	public ShapeXY
{
private:
	const int type{ 4 };

public:
	TriangleXY(PointXY* startPoint, PointXY* endPoint);
	TriangleXY(int x1, int y1, int x2, int y2);

	int getType();

	virtual ~TriangleXY();
};

