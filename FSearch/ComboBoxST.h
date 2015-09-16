#if !defined(AFX_COMBOBOXST_H__5410DA06_C1D1_4C6C_8C2C_DE3744E38DBD__INCLUDED_)
#define AFX_COMBOBOXST_H__5410DA06_C1D1_4C6C_8C2C_DE3744E38DBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ComboBoxST.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CComboBoxST window
#include <afxtempl.h>
struct STHICON
{

	HICON m_hIcon;
};
class CComboBoxST : public CComboBox
{
// Construction
public:
	CComboBoxST();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboBoxST)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CComboBoxST();
	void SetIcon(int iItem, int iconId);
	// Generated message map functions
protected:
	//{{AFX_MSG(CComboBoxST)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	
	DECLARE_MESSAGE_MAP()
	CMap<int,int,STHICON,STHICON> myMap;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOBOXST_H__5410DA06_C1D1_4C6C_8C2C_DE3744E38DBD__INCLUDED_)
