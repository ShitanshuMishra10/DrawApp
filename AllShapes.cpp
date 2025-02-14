#include "stdafx.h"
#include "Allshapes.h"


AllShapes::~AllShapes()
{
	for (int i = 0;i < counter;i++)
	{
		delete shapes[i]; shapes[i] = NULL;
	}
}

void AllShapes::Add(ShapeXY * shape)
{
	shapes[counter++] = shape;
}

ShapeXY** AllShapes::getAllShapes()
{
	return shapes;
}

int AllShapes::getCounter()
{
	return counter;
}

void AllShapes::Reset()
{
	for (int i = 0;i < counter;i++)
	{
		delete shapes[i]; shapes[i] = NULL;
	}

	counter = 0;
}


void AllShapes::Serialize(CArchive & ar)
{
	if (ar.IsStoring())
	{
		// Store the class members to the archive
		ar << counter;

		for (int i = 0; i < counter;i++)
		{
			int type = shapes[i]->getType();
			int startX, startY, endX, endY;
			startX = (shapes[i]->getStartPoint())->getX();
			startY = (shapes[i]->getStartPoint())->getY();
			endX = (shapes[i]->getEndPoint())->getX();
			endY = (shapes[i]->getEndPoint())->getY();

			ar << type;
			ar << startX;
			ar << startY;
			ar << endX;
			ar << endY;
		}
	}
	else
	{
		// Load the class members from the archive
		ar >> counter;

		for (int i = 0; i < counter;i++)
		{
			int type;
			int startX, startY, endX, endY;

			ShapeXY* shape = NULL;

			ar >> type;

			ar >> startX; ar >> startY; ar >> endX; ar >> endY;

			switch (type)
			{
			case 1: 
				shape = new RectXY(startX,startY,endX,endY);
				break;

			case 2:
				shape = new CircleXY(startX, startY, endX, endY);				
				break;

			case 3:
				shape = new LineXY(startX, startY, endX, endY);
				break;

			case 4:
				shape = new TriangleXY(startX, startY, endX, endY);
			}
			shapes[i] = shape;
			
		}

	}
}
