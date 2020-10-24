#pragma once
#include "IControllerInView.h"
struct ControllerInView :public IControllerInView
{
	ControllerInView(CDC& dcMem) :m(dcMem) {};
	
	virtual ~ControllerInView()
	{
		yellowBrush.DeleteObject(); whiteBrush.DeleteObject();
	};
	virtual void PaintSquare(const SquareEB& data, const CPoint& pt, bool isS = false);
	virtual void PaintCircle(const CircleEB& data, const CPoint& pt, bool isS = false);
protected:
	CDC& m;
	CBrush yellowBrush{ RGB(0,255,0) };
	CBrush whiteBrush{ RGB(255,255,255) };
};