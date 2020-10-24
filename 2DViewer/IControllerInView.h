#pragma once
#include <afxwin.h>
#include "EntityBean.h"

//use for out data
struct IControllerInView
{
	///<summary>Draw square use view</summary>
	virtual void PaintSquare(const SquareEB& data, const CPoint& pt, bool isSelected = false) = 0;

	///<summary>Draw circle use view</summary>
	virtual void PaintCircle(const CircleEB& data, const CPoint& pt, bool isSelected = false) = 0;
	virtual ~IControllerInView() = default;
};