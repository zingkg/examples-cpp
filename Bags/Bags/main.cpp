#include <cstdint>

#include "bags.hpp"

int main(const int argc, const char* argv[]) {
  const std::string fileName(argv[1]);
  const std::string maxSize(argv[2]);
  std::cout << "Running Weiss Bags" << std::endl;
  Bags::weissBags(fileName, maxSize);
  std::cout << std::endl;

  std::cout << "Running STL Bags" << std::endl;
  Bags::stlBags(fileName, maxSize);
  std::cout << std::endl;

  std:: cout << "Running Functional STL Bags" << std::endl;
  Bags::stlFunctionalBags(fileName, maxSize);
  return 0;
}
