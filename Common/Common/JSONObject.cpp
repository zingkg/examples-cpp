#include "JSONObject.hpp"

JSONObject::JSONObject() {
}

JSONObject::JSONObject(const JSONObject &other) {
  json = other.json;
}

JSONObject::~JSONObject() {
}

JSONObject JSONObject::operator=(const JSONObject &rhs) {
  JSONObject temp(rhs);
  std::swap(json, temp.json);
  return *this;
}

std::string JSONObject::toString() const {
  std::string jsonDoc = "{";
  for (const auto &it : json) {
    jsonDoc.append(buildJSONString(it));
    jsonDoc.append(",");
  }

  if (jsonDoc.size() > 0) {
    jsonDoc.erase(jsonDoc.size() - 1, 1);
  }

  if (!jsonDoc.empty()) {
    jsonDoc.append("}");
  }

  return jsonDoc;
}

void JSONObject::putValue(const std::string &key, const bool value) {
  putValue(key, JSONValue(value));
}

void JSONObject::putValue(const std::string &key, const int32_t value) {
  putValue(key, JSONValue(value));
}

void JSONObject::putValue(const std::string &key, const int64_t value) {
  putValue(key, JSONValue(value));
}

void JSONObject::putValue(const std::string &key, const char* value) {
  putValue(key, JSONValue(value));
}

void JSONObject::putValue(const std::string &key, const JSONValue &value) {
  std::map<std::string, std::list<JSONValue> >::iterator it = json.find(key);
  if (it == json.end()) {
    json.insert(
      std::pair<std::string, std::list<JSONValue> >(key, std::list<JSONValue>(1, value))
    );
  } else {
    it->second.insert(it->second.end(), value);
  }
}

void JSONObject::putValue(const std::string &key, const JSONObject &value) {
  putValue(key, JSONValue(value));
}

std::string JSONObject::buildJSONString(
  const std::pair<std::string, std::list<JSONValue> > &jsonPair
) {
  std::string jsonDoc = "\"" + jsonPair.first + "\":";

  if (jsonPair.second.size() > 1) {
    jsonDoc.append("[");
  }

  for (const auto &it : jsonPair.second) {
    jsonDoc.append(it.getValue() + ",");
  }

  jsonDoc.erase(jsonDoc.size() - 1, 2);
  if (jsonPair.second.size() > 1) {
    jsonDoc.append("]");
  }

  return jsonDoc;
}
