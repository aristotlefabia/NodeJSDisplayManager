#include <Windows.h>
#include <string>
#include <sstream>
#include <iomanip>

#include "display_device_manager.h"

#define X 100
#define Y 100
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

const int OFF = 2;
const int ON = -1;

DisplayDeviceManager DisplayDeviceManager::displayManager;


std::string MillisecondToTime(ULONGLONG totalMillisecond)
{
    unsigned int ms = totalMillisecond % 1000;
    unsigned int totalSecond = (totalMillisecond - ms) / 1000;
    unsigned int sec = totalSecond % 60;
    unsigned int totalMinutes = (totalSecond - sec) / 60;
    unsigned int min = totalMinutes % 60;
    unsigned int totalHours = (totalMinutes - min) / 60;

    std::ostringstream stringStream;
    stringStream << std::setfill('0') << std::setw(2) << totalHours << ":"
        << std::setfill('0') << std::setw(2) << min << ":"
        << std::setfill('0') << std::setw(2) << sec << " "
        << std::setfill('0') << std::setw(3) << ms;
    std::string time = stringStream.str();
    return time;
}

int DisplayDeviceManager::SetDisplayState(bool turnON /*= true*/)
{
    int state = OFF;
    if (turnON == true) {
        state = ON;
		//Workaround for Win 8 above
		Sleep(100);
    }
   
    bool result = SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)state);
	
    
    if (turnON == true) {	
        //simulate keypress
	    //Workaround for Win 8 above
		INPUT ip;
		Sleep(100);
		ip.type = INPUT_KEYBOARD;
		ip.ki.wScan = 0; 
		ip.ki.time = 0;
		ip.ki.dwExtraInfo = 0;
		ip.ki.wVk = 0x41; 
		ip.ki.dwFlags = 0; 
		SendInput(1, &ip, sizeof(INPUT));
    }
    return result;
}

int DisplayDeviceManager::EnumerateDisplay()
{
    return GetSystemMetrics(SM_CMONITORS);
}

ULONGLONG DisplayDeviceManager::LastInputTime()
{
    LASTINPUTINFO lii;
    lii.cbSize = sizeof(LASTINPUTINFO);
    GetLastInputInfo(&lii);
    ULONGLONG currentTime = GetTickCount64();
    ULONGLONG timeElapsed = currentTime - lii.dwTime;
    return timeElapsed;
}
