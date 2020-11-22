#include <cstdint>
#include <iostream>

#include "../Common/JSONObject.hpp"
#include "../Common/JSONValue.hpp"

std::int32_t main() {
  // This is a simple main to utilize main to test things as needed.
  JSONObject strings;
  strings.putValue("str1", "blah");
  strings.putValue("str2", "pink");
  JSONObject full;
  full.putValue("obj1", strings);
  full.putValue("bool", true);
  full.putValue("num2", 123);

  JSONValue value(true);
  value = JSONValue(strings);
  value = JSONValue(full);
  value = JSONValue("asdf");
  value = JSONValue("fdsa");
  value = JSONValue(1);
  std::cout << "hi" << std::endl;
  return 0;
}
