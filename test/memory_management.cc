#include "napi.h"

using namespace Napi;

Value externalAllocatedMemory(const CallbackInfo& info) {
    int64_t kSize = 1024 * 1024;
    int64_t baseline = AdjustExternalMemory(info.Env(), 0);
    int64_t tmp = AdjustExternalMemory(info.Env(), kSize);
    tmp = AdjustExternalMemory(info.Env(), -kSize);
    return Boolean::New(info.Env(), tmp == baseline);
}

Object InitMemoryManagement(Env env) {
    Object exports = Object::New(env);
    exports["externalAllocatedMemory"] = Function::New(env, externalAllocatedMemory);
    return exports;
}