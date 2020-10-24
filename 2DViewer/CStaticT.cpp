#include "pch.h"
#include "CStaticT.h"

BEGIN_MESSAGE_MAP(CStaticT, CStatic) 
	ON_WM_MOUSEMOVE() 
	ON_WM_PAINT() 
	ON_WM_LBUTTONUP() 
	ON_WM_LBUTTONDOWN()   
END_MESSAGE_MAP()

void CStaticT::PreSubclassWindow()
{ 
	DWORD dwStyle = GetStyle(); 
	::SetWindowLong(GetSafeHwnd(), 
	GWL_STYLE,dwStyle|SS_NOTIFY);
	CStatic::PreSubclassWindow();
}

void CStaticT::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (LBPressed) 
		OnLButtonClumpBegin(nFlags, point);
	pModel->updateMousePlace(nFlags, point);
}

void CStaticT::OnLButtonClumpBegin(UINT nFlags, CPoint point)
{
	if (nFlags == 5) 
	{ 
		if (pModel->setActiveToInWork()) 
			pModel->setWorkStrategyMoveOne(); 
	}
	else if (pModel->setActiveBorderToInWork()) 
	{ 
		pModel->setWorkStrategyChangeBorder(); 
	}
	else { 
		pModel->setWorkStrategyMoveSelected(); 
		pModel->setDXDYToSelected();
	} 
	LBPressed = false;
}

void CStaticT::OnPaint()
{
	CPaintDC dc(this); 
	CRect Rect; 
	GetClientRect(&Rect);
	CDC dcMem;
	CBitmap bmpMem; 
	dcMem.CreateCompatibleDC(&dc);
	bmpMem.CreateCompatibleBitmap(&dc, Rect.Width(), Rect.Height());
	dcMem.SelectObject(&bmpMem); 
	dcMem.FillSolidRect(Rect, RGB(255, 255, 255));
	//todo: refactory to"static"class 1197106/staticconstructors 
	CPen penBlack(PS_SOLID, 3, RGB(0, 100, 0));
	/*CPen*pOldP=*/dcMem.SelectObject(&penBlack);
	IControllerInView* outHelper = new ControllerInView(dcMem);
	pModel->setController(outHelper); 
	pModel->updateView(); 
	pModel->mainDo();
	penBlack.DeleteObject(); 
	dcMem.SelectObject(&bmpMem);
	dc.BitBlt(0, 0, Rect.Width(), Rect.Height(), &dcMem, 0, 0, SRCCOPY);
	delete outHelper; 
	dcMem.DeleteDC();
	DeleteObject(bmpMem);
}
		 
void CStaticT::OnLButtonUp(UINT nFlags, CPoint point)
{
	pModel->mainEnd();
	pModel->setWorkStrategyBase();
	LBPressed = false;
	Invalidate();
}

void CStaticT::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (nFlags == 9)
		pModel->setActiveToSelected(); /*должно быть 8*/
	LBPressed = true;
}