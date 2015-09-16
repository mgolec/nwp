// ListBoxEx.cpp : implementation file
//

#include "stdafx.h"
#include "FSearch.h"
#include "ListBoxEx.h"
#include <shlwapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListBoxEx

CListBoxEx::CListBoxEx()
{
}

CListBoxEx::~CListBoxEx()
{
}


BEGIN_MESSAGE_MAP(CListBoxEx, CListBox)
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListBoxEx message handlers

void CListBoxEx::OnOpen() 
{
	int nIndex = GetCurSel();
	CString strName;
	GetText(nIndex,strName);
	CWaitCursor Wait;
	//ShellExecute(NULL,"open","explorer.exe",strName,NULL,SW_SHOWMAXIMIZED);
	ShellExecute(NULL, _T("open"), _T("explorer.exe"), strName, NULL, 0);
	//ShellExecute(NULL, "open", <fully_qualified_path_to_folder>, NULL, NULL, SW_SHOWNORMAL);
	SetCurSel(-1);
	
}

