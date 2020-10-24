#pragma once
#include "IFigure.h"

struct Circle :public IFigure
{
	CircleEB data_;
	static TDataFromView<CircleEB> getDataFromView;
	Circle(CircleEB& data, CPoint point) :data_(data)
	{
		init(point);
	};
	virtual void getData();
	virtual void outToView(IControllerInView* outHelper);
	virtual bool checkInside(const CPoint& point);
	virtual bool isInBorder(const CPoint& point);
	virtual void setDataBorder(CPoint oldPoint, CPoint newPoint);
	virtual ~Circle() = default;
};






