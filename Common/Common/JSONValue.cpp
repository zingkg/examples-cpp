#include "JSONValue.hpp"

#include "JSONObject.hpp"

#include <cstring>

JSONValue::JSONValue(): type(JSONValue::JSONTYPE_NULL) {
}

JSONValue::JSONValue(const JSONValue &other) {
  deconstructValue();
  if (other.type == JSONValue::JSONTYPE_STRING) {
    value.string = new char[strlen(other.value.string) + 1];
    strcpy(value.string, other.value.string);
  } else if (other.type == JSONValue::JSONTYPE_OBJECT) {
    value.jsonObject = new JSONObject(*other.value.jsonObject);
  } else {
    value = other.value;
  }
  this->type = other.type;
}

JSONValue::JSONValue(const bool boolean) {
  deconstructValue();
  value.boolean = boolean;
  type = JSONValue::JSONTYPE_BOOLEAN;
}

JSONValue::JSONValue(const int32_t integer) {
  deconstructValue();
  value.integer = integer;
  type = JSONValue::JSONTYPE_INTEGER;
}

JSONValue::JSONValue(const int64_t longInt) {
  deconstructValue();
  value.longInt = longInt;
  type = JSONValue::JSONTYPE_LONGINT;
}

JSONValue::JSONValue(const std::string &string): JSONValue(string.c_str()) {
}

JSONValue::JSONValue(const char* string) {
  deconstructValue();
  value.string = new char[strlen(string) + 1];
  strcpy(value.string, string);
  type = JSONValue::JSONTYPE_STRING;
}

JSONValue::JSONValue(const JSONObject &jsonObject) {
  deconstructValue();
  value.jsonObject = new JSONObject(jsonObject);
  type = JSONValue::JSONTYPE_OBJECT;
}

JSONValue::~JSONValue() {
  deconstructValue();
}

JSONValue JSONValue::operator=(const JSONValue &rhs) {
  deconstructValue();
  JSONValue temp(rhs);
  std::swap(value, temp.value);
  std::swap(type, temp.type);
  return *this;
}

std::string JSONValue::getValue() const {
  switch (type) {
    case JSONValue::JSONTYPE_BOOLEAN:
      return value.boolean ? "true" : "false";
    case JSONValue::JSONTYPE_INTEGER:
      return Common::toString(value.integer);
    case JSONValue::JSONTYPE_LONGINT:
      return Common::toString(value.longInt);
    case JSONValue::JSONTYPE_STRING:
      return '\"' + std::string(value.string) + '\"';
    case JSONValue::JSONTYPE_OBJECT:
      return value.jsonObject->toString();
    case JSONValue::JSONTYPE_NULL:
      return "null";
  }
  return "";
}

void JSONValue::deconstructValue() {
  switch (type) {
    case JSONValue::JSONTYPE_BOOLEAN:
      break;
    case JSONValue::JSONTYPE_INTEGER:
      break;
    case JSONValue::JSONTYPE_LONGINT:
      break;
    case JSONValue::JSONTYPE_STRING:
      if (value.string != nullptr) {
        delete[] value.string;
        value.string = nullptr;
      }
    case JSONValue::JSONTYPE_OBJECT:
      if (value.jsonObject != nullptr) {
        delete value.jsonObject;
        value.jsonObject = nullptr;
      }
    case JSONValue::JSONTYPE_NULL:
      break;
  }
  type = JSONValue::JSONTYPE_NULL;
}
