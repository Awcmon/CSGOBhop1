
// Because the SendInput function is only supported in
// Windows 2000 and later, WINVER needs to be set as
// follows so that SendInput gets defined when windows.h
// is included below.
#define WINVER 0x0500
#include <windows.h>
#include <iostream>

int main()
{
	INPUT ip;

	ip.type = INPUT_KEYBOARD;
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;
	ip.ki.wVk = 0;
	ip.ki.wScan = 0x39;
	while (1)
	{
		if (GetAsyncKeyState(VK_CONTROL))
		{
			ip.ki.dwFlags = KEYEVENTF_SCANCODE; // 0 for key press
			SendInput(1, &ip, sizeof(INPUT));

			ip.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
			SendInput(1, &ip, sizeof(INPUT));

			Sleep(25);
		}
	}

	return 0;
}
