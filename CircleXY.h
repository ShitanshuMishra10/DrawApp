#pragma once
#include "ShapeXY.h"



class CircleXY : public ShapeXY
{

private:
	const int type{ 2 };

public:
	CircleXY(PointXY* startPoint, PointXY* endPoint);
	CircleXY(int x1, int y1, int x2, int y2);

	int getType();

	virtual ~CircleXY();
};

