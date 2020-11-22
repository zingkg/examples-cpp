#ifndef BAGS_HPP
#define BAGS_HPP

#include <fstream>
#include <memory>
#include <queue>
#include <sstream>
#include <stack>
#include <vector>
#include <cstdint>

#include "common.hpp"

class Bags {
public:
  static std::vector<uint16_t> weissBags(const std::vector<uint16_t> &bags, const uint16_t maxSize);

  static std::vector<uint16_t> stlBags(const std::vector<uint16_t> &bags, const uint16_t maxSize);

  static std::vector<uint16_t> stlFunctionalBags(
    const std::vector<uint16_t> &bags,
    const uint16_t maxSize
  );
};

#include "../Weiss/QueueAr.cpp"
#include "../Weiss/StackLi.cpp"

#endif // BAGS_HPP