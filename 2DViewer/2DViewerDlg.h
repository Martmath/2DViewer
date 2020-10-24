#pragma once
#include "CStaticT.h"
#include "ViewerHelper.h"

class CMy2DViewerDlg : public CDialogEx, ViewerHelper
{
public: CString outStr;
	  CMy2DViewerDlg(IModel* Controller, CWnd* pParent = nullptr);
#ifdef AFX_DESIGN_TIME
	  enum { IDD = IDD_GEOMCREATOR_DIALOG };
#endif
	  DECLARE_MESSAGE_MAP()
	  CStaticT staticT;
	  IModel* pModel;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	void Redraw();
	HICON m_hIcon;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	virtual void PreSubclassWindow();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
public:
	afx_msg void OnBnClickedAddSquare();
	afx_msg void OnBnClickedDeleteSelected();
	afx_msg void OnBnClickedSetNewData();
	afx_msg void OnBnClickedAddCircle();
	afx_msg void OnBnClickedUpFigures();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual ~CMy2DViewerDlg() = default;
	afx_msg void OnBnClickedCancel();
};
