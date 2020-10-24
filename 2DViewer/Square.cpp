#include "pch.h"
#include "Square.h"

std::function<void(SquareEB&)> Square::getDataFromView;

void Square::getData()
{
	getDataFromView(this->data_);
}

void Square::outToView(IControllerInView* outHelper)
{
	outHelper->PaintSquare(data_, point_, isSelected());
}

bool Square::checkInside(const CPoint& point)
{
	return ((point.x > point_.x) && 
		(point.y > point_.y) &&
		(point.x < (point_.x + data_.L)) &&
		(point.y < (point_.y + data_.L)));
}

bool Square::isInBorder(const CPoint& point)
{
	return isLeftHorizontal(point) || isUpVertical(point) || 
		isRightHorizontal(point) || isDownVertical(point);
}

void Square::setDataBorder(CPoint oldPoint, CPoint newPoint)
{
	if (isLeftHorizontal(oldPoint))
	{
		int dx = newPoint.x - oldPoint.x;
		data_.L = data_.L - dx; 
		point_.x = point_.x + dx; 
		point_.y = point_.y + dx;
	}
	else if (isUpVertical(oldPoint))
	{
		int dy = newPoint.y - oldPoint.y;
		data_.L = data_.L - dy;
		point_.x = point_.x + dy;
		point_.y = point_.y + dy;
	}
	else if (isRightHorizontal(oldPoint))
	{
		int dx = newPoint.x - oldPoint.x;
		data_.L = data_.L + dx;
	}
	else if (isDownVertical(oldPoint))
	{
		int dy = newPoint.y - oldPoint.y;
		data_.L = data_.L + dy;
	}
}

bool Square::isLeftHorizontal(const CPoint& point)
{
	return ((abs(point.x - point_.x) <= THB)&&
		(point.y > (point_.y - THB))&&
		(point.y < (point_.y + data_.L + THB)));
}

bool Square::isUpVertical(const CPoint& point)
{
	return ((abs(point.y - point_.y) <= THB)&&
		(point.x >(point_.x - THB))&&
		(point.x < (point_.x + data_.L + THB)));
}

bool Square::isRightHorizontal(const CPoint& point)
{
	return ((abs(point.x - (data_.L + point_.x)) <= THB)&&
		(point.y >(point_.y - THB))&&
		(point.y < (point_.y + data_.L + THB)));
}

bool Square::isDownVertical(const CPoint& point)
{
	return ((abs(point_.y + data_.L - point.y) <= THB)&&
		(point.x >(point_.x - THB))&&
		(point.x < (point_.x + data_.L + THB)));
}