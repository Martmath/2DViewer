#include "pch.h"
#include "ControllerInView.h"

void ControllerInView::PaintSquare(const SquareEB& data, const CPoint& pt, bool isS)
{
	if (isS) 
		m.SelectObject(&yellowBrush); 
	else 
		m.SelectObject(&whiteBrush);
	m.Rectangle(pt.x, pt.y, pt.x + data.L, pt.y + data.L);
}

void ControllerInView::PaintCircle(const CircleEB& data, const CPoint& pt, bool isS) 
{
	if (isS) 
		m.SelectObject(&yellowBrush); 
	else 
		m.SelectObject(&whiteBrush);
	m.Ellipse(pt.x - data.L / 2, pt.y - data.L / 2, pt.x + data.L / 2, pt.y + data.L / 2);
}
