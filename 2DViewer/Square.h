#pragma once
#include "IFigure.h"

struct Square :public IFigure
{
	SquareEB data_;
	static TDataFromView<SquareEB> getDataFromView;
	Square(SquareEB& data, CPoint point) :data_(data)
	{
		init(point);
	};
	virtual void getData();
	virtual void outToView(IControllerInView* outHelper);
	virtual bool checkInside(const CPoint& point);
	virtual bool isInBorder(const CPoint& point);
	virtual void setDataBorder(CPoint oldPoint, CPoint newPoint);
	virtual ~Square() = default;
private:
	bool isLeftHorizontal(const CPoint& point);
	bool isUpVertical(const CPoint& point);
	bool isRightHorizontal(const CPoint& point);
	bool isDownVertical(const CPoint& point);	
};

