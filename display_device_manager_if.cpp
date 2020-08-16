#include <nan.h>
#include "display_device_manager.h"
using v8::Object;
using v8::String;
using Nan::GetFunction;
using Nan::New;
using Nan::Set;


NAN_METHOD(DisplayWakeupRequest) {
	int ret = DisplayDeviceManager::getDisplayManager()->SetDisplayState(true);
	info.GetReturnValue().Set(ret);
}
NAN_METHOD(DisplaySleepRequest)
{
	int ret = DisplayDeviceManager::getDisplayManager()->SetDisplayState(false);
	info.GetReturnValue().Set(ret);
}
NAN_METHOD(EnumerateAttachedDisplay) {
	int ret = DisplayDeviceManager::getDisplayManager()->EnumerateDisplay();
	info.GetReturnValue().Set(ret);
}
void LastInputTime(const Nan::FunctionCallbackInfo<v8::Value>& info) {
	std::string str = MillisecondToTime(DisplayDeviceManager::getDisplayManager()->LastInputTime());
	info.GetReturnValue().Set(Nan::New(str).ToLocalChecked());
}

