
// mfcdemo.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CmfcdemoApp:
// See mfcdemo.cpp for the implementation of this class
//

class CmfcdemoApp : public CWinApp
{
public:
	CmfcdemoApp();

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CmfcdemoApp theApp;
