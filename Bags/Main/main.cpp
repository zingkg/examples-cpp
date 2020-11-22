#include <cstdint>

#include "../Bags/bags.hpp"

std::vector<uint16_t> readFile(const std::string &fileName) {
  std::vector<uint16_t> bags;
  std::ifstream file;
  file.open(fileName, std::ios::in);
  uint16_t bag;
  while (file >> bag) {
    bags.push_back(bag);
  }
  return bags;
}

void printVector(const std::vector<uint16_t> &result) {
  for (auto it = result.cbegin(); it != result.cend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int main(const int argc, const char* argv[]) {
  const std::vector<uint16_t> bags = readFile(std::string(argv[1]));
  const uint16_t maxSize = Common::parseInt(std::string(argv[2]));
  std::cout << "Running Weiss Bags" << std::endl;
  printVector(Bags::weissBags(bags, maxSize));
  std::cout << std::endl;

  std::cout << "Running STL Bags" << std::endl;
  printVector(Bags::stlBags(bags, maxSize));
  std::cout << std::endl;

  std:: cout << "Running Functional STL Bags" << std::endl;
  printVector(Bags::stlFunctionalBags(bags, maxSize));
  return 0;
}
