#pragma once
#include "PointXY.h"
#include <afx.h>

class ShapeXY : public CObject
{

private:
	PointXY* startPoint;
	PointXY* endPoint;
	const int type{ 0 };

public:

	ShapeXY(PointXY* startPoint,PointXY* endPoint);

	ShapeXY(int x1, int y1, int x2, int y2);

	PointXY* getStartPoint();

	PointXY* getEndPoint();

	virtual int getType();

	virtual ~ShapeXY();

};

