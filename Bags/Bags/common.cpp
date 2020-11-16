#include "common.hpp"

#include <sstream>

int64_t Common::parseInt(const std::string &string) {
  std::istringstream sStream(string);
  std::int64_t num;
  sStream >> num;
  return num;
}
