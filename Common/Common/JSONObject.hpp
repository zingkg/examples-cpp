#ifndef JSONOBJECT_HPP
#define JSONOBJECT_HPP

#include "JSONValue.hpp"

#include <list>
#include <map>
#include <string>

class JSONObject
{
public:
  JSONObject();

  JSONObject(const JSONObject &other);

  ~JSONObject();

  JSONObject operator=(const JSONObject &rhs);

  std::string toString() const;

  void putValue(const std::string &key, const bool value);

  void putValue(const std::string &key, const int32_t value);

  void putValue(const std::string &key, const int64_t value);

  void putValue(const std::string &key, const char* value);

  void putValue(const std::string &key, const JSONValue &value);

  void putValue(const std::string &key, const JSONObject &value);

private:
  std::map<std::string, std::list<JSONValue> > json;

  static std::string buildJSONString(
    const std::pair<std::string, std::list<JSONValue> > &jsonPair
  );
};

#endif // JSONOBJECT_HPP
