
#ifndef DISPLAY_DEVICE_MANAGER_H
#define DISPLAY_DEVICE_MANAGER_H

#include <string>

class DisplayDeviceManager
{
	static DisplayDeviceManager displayManager;	
public:
	DisplayDeviceManager() {}
	static DisplayDeviceManager* getDisplayManager()
	{
		return &displayManager;
	}
	int SetDisplayState(bool turnON = true);
	int EnumerateDisplay();
	unsigned long long LastInputTime();
};

std::string MillisecondToTime(unsigned long long totalMillisecond);


#endif  // DISPLAY_DEVICE_MANAGER_H