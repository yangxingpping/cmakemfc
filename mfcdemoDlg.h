
// mfcdemoDlg.h : header file
//

#pragma once

class CmfcdemoDlgAutoProxy;


// CmfcdemoDlg dialog
class CmfcdemoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CmfcdemoDlg);
	friend class CmfcdemoDlgAutoProxy;

// Construction
public:
	CmfcdemoDlg(CWnd* pParent = nullptr);	// standard constructor
	virtual ~CmfcdemoDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	CmfcdemoDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
};
