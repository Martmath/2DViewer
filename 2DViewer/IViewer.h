#pragma once
#include "EntityBean.h"
#include <atltypes.h>

//can be used for view(mfc) extend
struct IViewer
{
	//create Square using view data
	virtual SquareEB getSquare() = 0;

	//return mouse coordinates from view
	virtual CPoint getPtMouse() = 0;

	//set data to square from view
	virtual void setDataSquare(SquareEB& s) = 0;

	//create Circle using view data
	virtual CircleEB getCircle() = 0;

	//set data to Circle from view
	virtual void setDataCircle(CircleEB& s) = 0;

	virtual ~IViewer() = default;
};
