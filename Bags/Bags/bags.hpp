#ifndef BAGS_HPP
#define BAGS_HPP

#include <fstream>
#include <iostream>
#include <memory>
#include <queue>
#include <sstream>
#include <stack>
#include <vector>
#include <cstdint>

#include "common.hpp"

class Bags {
public:
  static void weissBags(const std::string &fileName, const std::string &maxSizeStr);

  static void stlBags(const std::string &fileName, const std::string &maxSizeStr);

  static void stlFunctionalBags(const std::string &fileName, const std::string &maxSizeStr);
};

#include "../Weiss/QueueAr.cpp"
#include "../Weiss/StackLi.cpp"

#endif // BAGS_HPP