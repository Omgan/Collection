Sometimes we need to display message boxes with customized or user defined button caption. There are two ways to implement the same :
 

HHOOK hMsgBoxHook;
 
LRESULT CALLBACK MsgBoxProc(int nCode, WPARAM wParam, LPARAM lParam)
{
TCHAR ach[140];
HWND hwnd;
HWND YES;
HWND NO;
HWND CANCEL;
 
if(nCode < 0)
return CallNextHookEx(hMsgBoxHook, nCode, wParam, lParam);
 
switch(nCode)
{
case HCBT_ACTIVATE:
 
// Get handle to the message box!
hwnd = (HWND)wParam;
 
//Set the window title
SetWindowText(hwnd, _T("Activator"));
 
//Get IDYES button handle
YES = GetDlgItem(hwnd, IDYES);
SetWindowText(YES, _T("Full License"));
 
//Get IDNO button handle
NO = GetDlgItem(hwnd, IDNO);
              
 
               //Set Button position, width and height
MoveWindow(NO, 185, 60, 100, 23, TRUE);
SetWindowText(NO, _T("Cancel"));
 
//Get IDCANCEL button handle
CANCEL = GetDlgItem(hwnd, IDCANCEL);
               
                 //Set Button position, width and height
MoveWindow(CANCEL, 290, 60, 100, 23, TRUE);
SetWindowText(CANCEL, _T("Cancel"));
return 0;
 
}
 
return CallNextHookEx(hMsgBoxHook, nCode, wParam, lParam);
}
 
 
int MsgBoxEx(HWND hwnd, TCHAR *szText, TCHAR *szCaption, UINT uType)
{
int retval;
 
// Install a window hook, so we can intercept the message-box
// creation, and customize it
hMsgBoxHook = SetWindowsHookEx(
WH_CBT,
MsgBoxProc,
NULL,
GetCurrentThreadId()
);
 
// Display a standard message box
retval = MessageBox(hwnd, szText, szCaption, uType);
 
// remove the window hook
UnhookWindowsHookEx(hMsgBoxHook);
 
return retval;
}
 
The function will be called as follows :
 
MsgBoxEx(hWnd, "Message test" , "title",  MB_YESNOCANCEL | MB_ICONINFORMATION);
