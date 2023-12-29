
// DlgProxy.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "mfcdemo.h"
#include "DlgProxy.h"
#include "mfcdemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfcdemoDlgAutoProxy

IMPLEMENT_DYNCREATE(CmfcdemoDlgAutoProxy, CCmdTarget)

CmfcdemoDlgAutoProxy::CmfcdemoDlgAutoProxy()
{
	EnableAutomation();

	// To keep the application running as long as an automation
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CmfcdemoDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CmfcdemoDlg)))
		{
			m_pDialog = reinterpret_cast<CmfcdemoDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CmfcdemoDlgAutoProxy::~CmfcdemoDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != nullptr)
		m_pDialog->m_pAutoProxy = nullptr;
	AfxOleUnlockApp();
}

void CmfcdemoDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CmfcdemoDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CmfcdemoDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// Note: we add support for IID_Imfcdemo to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the
//  dispinterface in the .IDL file.

// {985fc6a1-2472-43cb-8ced-b2a1fed5ef74}
static const IID IID_Imfcdemo =
{0x985fc6a1,0x2472,0x43cb,{0x8c,0xed,0xb2,0xa1,0xfe,0xd5,0xef,0x74}};

BEGIN_INTERFACE_MAP(CmfcdemoDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CmfcdemoDlgAutoProxy, IID_Imfcdemo, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in pch.h of this project
// {3587f3da-e866-489c-88bf-ce66234b3c91}
IMPLEMENT_OLECREATE2(CmfcdemoDlgAutoProxy, "mfcdemo.Application", 0x3587f3da,0xe866,0x489c,0x88,0xbf,0xce,0x66,0x23,0x4b,0x3c,0x91)


// CmfcdemoDlgAutoProxy message handlers
