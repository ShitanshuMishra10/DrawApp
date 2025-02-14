#pragma once
#include "ShapeXY.h"

class RectXY :	public ShapeXY
{
private:
	const int type{ 1 };

public:
	RectXY(PointXY* startPoint, PointXY* endPoint);
	RectXY(int x1, int y1, int x2, int y2);

	int getType();

	virtual ~RectXY();

};

