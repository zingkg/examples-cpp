#ifndef JSONVALUE_HPP
#define JSONVALUE_HPP

#include "Common.hpp"

#include <cstdint>
#include <memory>

class JSONObject;

class JSONValue {
public:
  JSONValue();
  JSONValue(const JSONValue &other);
  explicit JSONValue(const bool boolean);
  explicit JSONValue(const std::int32_t integer);
  explicit JSONValue(const std::int64_t longInt);
  explicit JSONValue(const std::string &string);
  explicit JSONValue(const char* string);
  explicit JSONValue(const JSONObject &jsonObject);
  ~JSONValue();

  JSONValue operator=(const JSONValue &rhs);

  std::string getValue() const;

private:
  enum JSON_TYPE {
    JSONTYPE_BOOLEAN,
    JSONTYPE_INTEGER,
    JSONTYPE_LONGINT,
    JSONTYPE_STRING,
    JSONTYPE_OBJECT,
    JSONTYPE_NULL
  };

  union {
    bool boolean;
    std::int32_t integer;
    std::int64_t longInt;
    char* string;
    JSONObject* jsonObject;
  } value;

  JSON_TYPE type = JSONTYPE_NULL;

  void deconstructValue();
};

#endif // JSONVALUE_HPP
