#if !defined(AFX_LISTBOXEX_H__13B6A0E1_7EEF_4871_9915_617429226B47__INCLUDED_)
#define AFX_LISTBOXEX_H__13B6A0E1_7EEF_4871_9915_617429226B47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListBoxEx.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CListBoxEx window

class CListBoxEx : public CListBox
{
// Construction
public:
	CListBoxEx();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListBoxEx)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CListBoxEx();

	// Generated message map functions
protected:
	//{{AFX_MSG(CListBoxEx)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnOpen();
	afx_msg void OnDelete();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTBOXEX_H__13B6A0E1_7EEF_4871_9915_617429226B47__INCLUDED_)
