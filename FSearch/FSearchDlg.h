
// FSearchDlg.h : header file
//

#pragma once
#include "afxwin.h"


#define BUFSIZE 512

// CFSearchDlg dialog
class CFSearchDlg : public CDialogEx
{
// Construction
public:
	CFSearchDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_FSEARCH_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	

	DECLARE_MESSAGE_MAP()
private: 
	void SearchFile(CString strPath); 
	int Count;

public:
	afx_msg void OnBnClickedSearch();
	afx_msg void OnEnChangePojam();
	afx_msg void OnLbnSelchangeList1();
	CListBox list;
	//CEdit FileName;
	CComboBox drive;
	afx_msg void OnCbnSelchangeCombo1();
	CString text;
	afx_msg void DoubleClickOnRez();
};
