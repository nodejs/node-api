#include <cfloat>

#include "napi.h"

using namespace Napi;

Value ToInt32(const CallbackInfo& info) {
  return Number::New(info.Env(), info[0].As<Number>().Int32Value());
}

Value ToUint32(const CallbackInfo& info) {
  return Number::New(info.Env(), info[0].As<Number>().Uint32Value());
}

Value ToInt64(const CallbackInfo& info) {
  return Number::New(info.Env(),
                     static_cast<double>(info[0].As<Number>().Int64Value()));
}

Value ToFloat(const CallbackInfo& info) {
  return Number::New(info.Env(), info[0].As<Number>().FloatValue());
}

Value ToDouble(const CallbackInfo& info) {
  return Number::New(info.Env(), info[0].As<Number>().DoubleValue());
}

Value MinFloat(const CallbackInfo& info) {
  return Number::New(info.Env(), FLT_MIN);
}

Value MaxFloat(const CallbackInfo& info) {
  return Number::New(info.Env(), FLT_MAX);
}

Value MinDouble(const CallbackInfo& info) {
  return Number::New(info.Env(), DBL_MIN);
}

Value MaxDouble(const CallbackInfo& info) {
  return Number::New(info.Env(), DBL_MAX);
}

Value OperatorInt32(const CallbackInfo& info) {
  Number jsValue = info[0].As<Number>();
  return Boolean::New(info.Env(), jsValue.Int32Value() == static_cast<int32_t>(jsValue));
}

Value OperatorUint32(const CallbackInfo& info) {
  Number jsValue = info[0].As<Number>();
  return Boolean::New(info.Env(), jsValue.Uint32Value() == static_cast<uint32_t>(jsValue));
}

Value OperatorInt64(const CallbackInfo& info) {
  Number jsValue = info[0].As<Number>();
  return Boolean::New(info.Env(), jsValue.Int64Value() == static_cast<int64_t>(jsValue));
}

Value OperatorFloat(const CallbackInfo& info) {
  Number jsValue = info[0].As<Number>();
  return Boolean::New(info.Env(), jsValue.FloatValue() == static_cast<float>(jsValue));
}

Value OperatorDouble(const CallbackInfo& info) {
  Number jsValue = info[0].As<Number>();
  return Boolean::New(info.Env(), jsValue.DoubleValue() == static_cast<double>(jsValue));
}

Object InitBasicTypesNumber(Env env) {
  Object exports = Object::New(env);

  exports["toInt32"] = Function::New(env, ToInt32);
  exports["toUint32"] = Function::New(env, ToUint32);
  exports["toInt64"] = Function::New(env, ToInt64);
  exports["toFloat"] = Function::New(env, ToFloat);
  exports["toDouble"] = Function::New(env, ToDouble);
  exports["minFloat"] = Function::New(env, MinFloat);
  exports["maxFloat"] = Function::New(env, MaxFloat);
  exports["minDouble"] = Function::New(env, MinDouble);
  exports["maxDouble"] = Function::New(env, MaxDouble);
  exports["operatorInt32"] = Function::New(env, OperatorInt32);
  exports["operatorUint32"] = Function::New(env, OperatorUint32);
  exports["operatorInt64"] = Function::New(env, OperatorInt64);
  exports["operatorFloat"] = Function::New(env, OperatorFloat);
  exports["operatorDouble"] = Function::New(env, OperatorDouble);

  return exports;
}
