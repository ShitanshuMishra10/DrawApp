#pragma once
#include <afx.h>
#include "AllTypesHeader.h"


class AllShapes : public CObject
{

private:
	ShapeXY* shapes[1000];
	int counter{0};
		

public:
	virtual ~AllShapes();

	void Add(ShapeXY* shape);

	ShapeXY** getAllShapes();

	int getCounter();

	void Reset();
	
	virtual void Serialize(CArchive& ar);
};

