#pragma once
#ifndef __AFXWIN_H__
#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"	
#include "Model.h"
#ifdef _UNICODE
constexpr auto FORMAT = L"%d";
#else
constexpr auto FORMAT = "%d";
#endif
class CMy2DViewerApp : public CWinApp
{
public:
	CMy2DViewerApp();
public:
	virtual BOOL InitInstance();
	IModel* pModel = new Model();
	DECLARE_MESSAGE_MAP()
};

extern CMy2DViewerApp theApp;

