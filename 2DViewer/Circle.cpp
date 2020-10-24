#include "pch.h"
#include "Circle.h"

std::function<void(CircleEB&)> Circle::getDataFromView;

void Circle::getData()
{
	getDataFromView(data_);
}

void Circle::outToView(IControllerInView* outHelper)
{
	outHelper->PaintCircle(data_, point_, isSelected());
}

bool Circle::checkInside(const CPoint& point)
{
	return pow(pow(point.x - point_.x, 2.0) +
		pow(point.y - point_.y, 2.0), 0.5) < (data_.L / 2);
}

bool Circle::isInBorder(const CPoint& point)
{
	return abs(pow((pow((point.x - point_.x), 2.0) +
		pow((point.y - point_.y), 2.0)), 0.5) - (data_.L / 2)) < 3.0;
}

void Circle::setDataBorder(CPoint oldPoint, CPoint newPoint)
{
	data_.L = pow((pow((point_.x - newPoint.x), 2) +
		pow((point_.y - newPoint.y), 2)), 0.5) * 2;
}
