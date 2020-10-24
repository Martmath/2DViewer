#include "pch.h"
#include "framework.h"
#include "2DViewer.h"
#include "2DViewerDlg.h"
#include "afxdialogex.h"
#include <string>
#include <functional>
#include "Square.h"
#include "Circle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CMy2DViewerDlg::CMy2DViewerDlg(IModel* Model, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY2DVIEWER_DIALOG, pParent), staticT(Model), pModel(Model)
{
	Model->notifyView =
		std::bind(&CMy2DViewerDlg::Redraw, this);
	Square::getDataFromView =
		std::bind(&ViewerHelper::setDataSquare, (ViewerHelper*)this, std::placeholders::_1);
	Circle::getDataFromView =
		std::bind(&ViewerHelper::setDataCircle, (ViewerHelper*)this, std::placeholders::_1);
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy2DViewerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_, staticT);
	DDX_Text(pDX, IDC_EDIT1, QX);
	DDX_Text(pDX, IDC_EDIT2, QY);
	DDX_Text(pDX, IDC_EDIT3, QL);
}

void CMy2DViewerDlg::Redraw() {/*lnvalidate();*/RedrawWindow(); }

BEGIN_MESSAGE_MAP(CMy2DViewerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy2DViewerDlg::OnBnClickedAddSquare)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy2DViewerDlg::OnBnClickedDeleteSelected)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy2DViewerDlg::OnBnClickedSetNewData)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy2DViewerDlg::OnBnClickedAddCircle)
	ON_BN_CLICKED(IDC_BUTTON5, &CMy2DViewerDlg::OnBnClickedUpFigures)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDCANCEL, &CMy2DViewerDlg::OnBnClickedCancel)
END_MESSAGE_MAP()

BOOL CMy2DViewerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);
	outStr.Format(FORMAT, 70);
	theApp.m_pMainWnd->SetDlgItemText(IDC_EDIT3, outStr);
	return TRUE;
}

void CMy2DViewerDlg::PreSubclassWindow()
{
	DWORD dwStyle = GetStyle();
	//::SetWindowLong(GetSafeHwnd(),GWL_STYLE,dwStyle | WS_CLIPCHILDREN | WS_CLIPSIBLINGS);//|SS_NOTIFY
	CDialogEx::PreSubclassWindow();
}

BOOL CMy2DViewerDlg::PreCreateWindow(CREATESTRUCT& cs)
{
	//cs.style |=WS_CLIPSIBLINGS|WS_CLIPCHILDREN;//cs.style |= WS_CLIPCHILDREN;
	return CDialogEx::PreCreateWindow(cs);
}

void CMy2DViewerDlg::OnPaint()
{
	outStr.Format(FORMAT, pModel->getPoint().x);
	theApp.m_pMainWnd->SetDlgItemText(IDC_EDIT1, outStr);
	outStr.Format(FORMAT, pModel->getPoint().y);
	theApp.m_pMainWnd->SetDlgItemText(IDC_EDIT2, outStr);

	if (IsIconic())
	{
		CPaintDC dc(this);
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CMy2DViewerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMy2DViewerDlg::OnBnClickedAddSquare()
{
	UpdateData();
	pModel->addNewFiguretoBase(new Square(getSquare(), getPtMouse()));
	pModel->setWorkStrategyNew();
}

void CMy2DViewerDlg::OnBnClickedDeleteSelected()
{
	pModel->setWorkStrategyBase();
	pModel->deleteSelected();
	Invalidate();
}

void CMy2DViewerDlg::OnBnClickedSetNewData()
{
	pModel->setWorkStrategyBase();
	UpdateData();
	pModel->updateSelected();
	Invalidate();
}

void CMy2DViewerDlg::OnBnClickedAddCircle()
{
	UpdateData();
	pModel->addNewFiguretoBase(new Circle(getCircle(), getPtMouse()));
	pModel->setWorkStrategyNew();
}

void CMy2DViewerDlg::OnBnClickedUpFigures()
{
	pModel->setWorkStrategyBase();
	pModel->selectToDownInBase();
	Invalidate();
}

BOOL CMy2DViewerDlg::OnEraseBkgnd(CDC* pDC)
{
	//return __super::OnEraseBkgnd(pDC);
	return FALSE;
}

void CMy2DViewerDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}
