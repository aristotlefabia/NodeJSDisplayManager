

#ifndef DISPLAY_DEVICE_MANAGER_IF_H
#define DISPLAY_DEVICE_MANAGER_IF_H

#include <nan.h>

NAN_METHOD(CalculateSync);

NAN_METHOD(DisplaySleepRequest);
NAN_METHOD(DisplayWakeupRequest);
NAN_METHOD(EnumerateAttachedDisplay);
void LastInputTime(const Nan::FunctionCallbackInfo<v8::Value>& info);

#endif  // DISPLAY_DEVICE_MANAGER_IF_H
