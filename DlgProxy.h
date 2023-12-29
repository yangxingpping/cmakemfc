
// DlgProxy.h: header file
//

#pragma once

class CmfcdemoDlg;


// CmfcdemoDlgAutoProxy command target

class CmfcdemoDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CmfcdemoDlgAutoProxy)

	CmfcdemoDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CmfcdemoDlg* m_pDialog;

// Operations
public:

// Overrides
	public:
	virtual void OnFinalRelease();

// Implementation
protected:
	virtual ~CmfcdemoDlgAutoProxy();

	// Generated message map functions

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CmfcdemoDlgAutoProxy)

	// Generated OLE dispatch map functions

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

