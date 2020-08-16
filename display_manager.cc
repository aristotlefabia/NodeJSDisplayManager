
#include <iostream>
#include <nan.h>
#include "display_device_manager_if.h"

using v8::FunctionTemplate;
using v8::Object;
using v8::String;
using Nan::GetFunction;
using Nan::New;
using Nan::Set;



NAN_MODULE_INIT(InitAll) {
  Set(target, New<String>("displaySleepRequest").ToLocalChecked(),
      GetFunction(New<FunctionTemplate>(DisplaySleepRequest)).ToLocalChecked());

  Set(target, New<String>("displayWakeupRequest").ToLocalChecked(),
      GetFunction(New<FunctionTemplate>(DisplayWakeupRequest)).ToLocalChecked());

  Set(target, New<String>("enumerateAttachedDisplay").ToLocalChecked(),
      GetFunction(New<FunctionTemplate>(EnumerateAttachedDisplay)).ToLocalChecked());

  Set(target, New<String>("lastInputTime").ToLocalChecked(),
      GetFunction(New<FunctionTemplate>(LastInputTime)).ToLocalChecked());
}

NODE_MODULE(addon, InitAll)
