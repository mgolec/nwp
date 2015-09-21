
// FSearchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FSearch.h"
#include "FSearchDlg.h"
#include "afxdialogex.h"
#include "tchar.h"
#include "cstringt.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFSearchDlg dialog



CFSearchDlg::CFSearchDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CFSearchDlg::IDD, pParent)
, text(_T(""))
	
{
	
	Count = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST1, list);
	DDX_Control(pDX, IDC_COMBO1, drive);
	DDX_Text(pDX, IDC_POJAM, text);
}

BEGIN_MESSAGE_MAP(CFSearchDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEARCH, &CFSearchDlg::OnBnClickedSearch)
	ON_EN_CHANGE(IDC_POJAM, &CFSearchDlg::OnEnChangePojam)
	ON_LBN_SELCHANGE(IDC_LIST1, &CFSearchDlg::OnLbnSelchangeList1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CFSearchDlg::OnCbnSelchangeCombo1)
	ON_LBN_DBLCLK(IDC_LIST1, &CFSearchDlg::DoubleClickOnRez)
	ON_BN_CLICKED(IDC_OPEN, &CFSearchDlg::OnBnClickedOpen)
END_MESSAGE_MAP()


// CFSearchDlg message handlers

BOOL CFSearchDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//pretraga driveova	
	DWORD dwSize = MAX_PATH;
	char szLogicalDrives[MAX_PATH] = { 0 };
	DWORD dwResult = GetLogicalDriveStringsW(dwSize, (LPWSTR)szLogicalDrives);
	
	if (dwResult > 0 && dwResult < MAX_PATH)
	{
		char* szSingleDrive = szLogicalDrives;
		while (*szSingleDrive)
		{
			drive.AddString(LPCTSTR(szSingleDrive));
			drive.SetIcon(NULL, TRUE);

		//	 get the next drive
			szSingleDrive += 8;
		}
	}
//kraj


	


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFSearchDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFSearchDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFSearchDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFSearchDlg::OnBnClickedSearch()
{
	UpdateData(TRUE);

	list.ResetContent();

	text.TrimLeft('*');
	text.TrimLeft();
	text.TrimRight();
	text.MakeLower();

	text.TrimLeft('*');
	CString temp, temp2;

	if (text.IsEmpty())
	{
		//MessageBox("Enter the File Name to Search");
		temp.LoadString(IDS_ENTER_FILE);
		temp2.LoadString(IDS_ERROR);
		MessageBox(temp, temp2, MB_ICONERROR | MB_OK);
		
		return;
	}


	int nIndex = drive.GetCurSel();
	CString strName;
	drive.GetLBText(nIndex, strName);

	CStatic* pWndStc = (CStatic*)GetDlgItem(IDC_REPORT);
		if (pWndStc)
		{
			temp.LoadString(IDS_SEARCHING);
			temp2.LoadString(IDS_DRIVE);
			pWndStc->SetWindowText(temp + strName + temp2);

		}

		CWnd *button = GetDlgItem(IDC_SEARCH);
		button->EnableWindow(FALSE);

		SearchFile(strName);
		CString strCount("");
		if (pWndStc)
		{
			int nCount = list.GetCount();
			CString strCount;

			if (1 == nCount)
			{
				temp.LoadString(IDS_FOUND);
				strCount.Format(temp, nCount);
			}
			else if (0 == nCount)
			{
				temp.LoadString(IDS_NO_MATCHES);
				strCount.Format(temp);
			}
			else
			{
				temp.LoadString(IDS_MATCHES);
				strCount.Format(temp, nCount);
			}

			temp.LoadString(IDS_COMPLETE);
			pWndStc->SetWindowText(temp + strCount);
			
			button->EnableWindow(TRUE);

	}
}

void CFSearchDlg::SearchFile(CString strPath)
{
	CFileFind oFileFind;
	strPath += "\\*.*";

	BOOL bSucess = oFileFind.FindFile(strPath);
	
	//Button_Enable((BOOL*)GetDlgItem(NULL,IDC_SEARCH), TRUE);

	MSG Msg = { 0 };
	while (bSucess)
	{

		while (PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
		bSucess = oFileFind.FindNextFile();

		if (oFileFind.IsDots())
			continue;

		else if (oFileFind.IsDirectory())
		{
			CString strName = oFileFind.GetFileName();

			strName.TrimLeft();
			strName.TrimRight();
			strName.MakeLower();

			if (-1 != strName.Find(text))
			{
				list.AddString(oFileFind.GetFilePath());
			}

			SearchFile(oFileFind.GetFilePath());
		}

		else
		{
			CString strName = oFileFind.GetFileName();
			strName.TrimLeft();
			strName.TrimRight();
			strName.MakeLower();

			if (-1 != strName.Find(text))
			{
				list.AddString(oFileFind.GetFilePath());
			}
		}
	}
}

void CFSearchDlg::OnEnChangePojam()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CFSearchDlg::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here

	
}


void CFSearchDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}


void CFSearchDlg::DoubleClickOnRez()
{
	// message box sa putanjom
	int nIndex = list.GetCurSel();
	CString strName;
	list.GetText(nIndex, strName);
	MessageBox(strName);
	
}



void CFSearchDlg::OnBnClickedOpen()
{
	// otvaranje u defaultnom programu
	int nIndex = list.GetCurSel();
	CString strName;
	if (nIndex != LB_ERR){
		list.GetText(nIndex, strName);
		ShellExecute(NULL, _T("open"), _T("explorer.exe"), strName, NULL, SW_SHOWDEFAULT);
	}
	else
	{

		CString temp;
		temp.LoadString(IDS_VALID);
			MessageBox(temp);
	}
	}
