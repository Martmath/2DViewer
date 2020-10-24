#pragma once
#include "IModel.h"
#include "ControllerInView.h"
struct CStaticT : public CStatic
{
	CStaticT(IModel* model)
	{
		pModel = model;
	};
	IModel* pModel = nullptr;
	virtual ~CStaticT() {};
	virtual void PreSubclassWindow();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	bool LBPressed = false;
	bool BoderChange = false;
	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	void OnLButtonClumpBegin(UINT nFlags, CPoint point);
};

