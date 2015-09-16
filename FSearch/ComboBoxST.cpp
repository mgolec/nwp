// ComboBoxST.cpp : implementation file
//

#include "stdafx.h"
#include "FSearch.h"
#include "ComboBoxST.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComboBoxST

CComboBoxST::CComboBoxST()
{
}

CComboBoxST::~CComboBoxST()
{
}


BEGIN_MESSAGE_MAP(CComboBoxST, CComboBox)
	//{{AFX_MSG_MAP(CComboBoxST)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComboBoxST message handlers

void CComboBoxST::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
   if (GetCount() == 0)
	   return;
   CString str;
   GetLBText(lpDrawItemStruct->itemID,str);
   CDC dc;

   dc.Attach(lpDrawItemStruct->hDC);

   // Save these value to restore them when done drawing.
   COLORREF crOldTextColor = dc.GetTextColor();
   COLORREF crOldBkColor = dc.GetBkColor();

   // If this item is selected, set the background color 
   // and the text color to appropriate values. Erase
   // the rect by filling it with the background color.
   if ((lpDrawItemStruct->itemAction | ODA_SELECT) &&
      (lpDrawItemStruct->itemState  & ODS_SELECTED))
   {
      dc.SetTextColor(::GetSysColor(COLOR_HIGHLIGHTTEXT));
      dc.SetBkColor(::GetSysColor(COLOR_HIGHLIGHT));
      dc.FillSolidRect(&lpDrawItemStruct->rcItem, ::GetSysColor(COLOR_HIGHLIGHT));
   }
   else
      dc.FillSolidRect(&lpDrawItemStruct->rcItem, crOldBkColor);

   CRect rect(lpDrawItemStruct->rcItem);
   rect.DeflateRect(1,0);

   HICON hIcon = NULL;
   BOOL bold = FALSE;
   STHICON iData;
   if (myMap.Lookup(lpDrawItemStruct->itemID,iData))
   {
	   hIcon = iData.m_hIcon;

   }

   DrawIconEx(dc.GetSafeHdc(),rect.left,rect.top,hIcon,0, 0, 0, NULL, DI_NORMAL);

   rect.left += 17;

   CFont *curFont = dc.GetCurrentFont();
   CFont boldFont,*oldFont;
   LOGFONT lf;
   curFont->GetLogFont(&lf);
   lf.lfWeight = FW_BOLD;
   boldFont.CreateFontIndirect(&lf);
   if (bold)
	oldFont = dc.SelectObject(&boldFont);

   // Draw the text.
   dc.DrawText(
      str,
      -1,
      &rect,
      DT_LEFT|DT_SINGLELINE|DT_VCENTER);

   if (bold)
		dc.SelectObject(oldFont);
   boldFont.DeleteObject();
   // Reset the background color and the text color back to their
   // original values.
   dc.SetTextColor(crOldTextColor);
   dc.SetBkColor(crOldBkColor);

   dc.Detach();

}


void CComboBoxST::SetIcon(int iItem, int iconId)
{
	HICON hIcon = (HICON)::LoadImage(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(iconId),IMAGE_ICON,16,16,0);
	
	STHICON iData;
	if (myMap.Lookup(iItem,iData))
		iData.m_hIcon = hIcon;
	else
	{
		iData.m_hIcon = hIcon;
	}
	myMap.SetAt(iItem,iData);
	Invalidate();
}