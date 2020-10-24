#pragma once
#include "IViewer.h"
struct ViewerHelper :public IViewer
{
	virtual CPoint getPtMouse() { return CPoint(QX, QY); };
	virtual SquareEB getSquare() { return SquareEB(QL);  };
	virtual void setDataSquare(SquareEB& s) { s.L = QL;  };
	virtual CircleEB getCircle() { return CircleEB(QL);  };
	virtual void setDataCircle(CircleEB& s) { s.L = QL;  };
	virtual ~ViewerHelper() = default;
protected:
	int QL; int QX; int QY;
};
