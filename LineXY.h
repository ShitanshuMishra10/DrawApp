#pragma once
#include "ShapeXY.h"

class LineXY :	public ShapeXY
{

private:
	const int type{ 3 };

public:
	LineXY(PointXY* startPoint, PointXY* endPoint);
	LineXY(int x1, int y1, int x2, int y2);

	int getType();

	virtual ~LineXY();
};

