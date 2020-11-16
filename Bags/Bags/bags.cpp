#include "bags.hpp"

void Bags::weissBags(const std::string &fileName, const std::string &maxSizeStr) {
  std::ifstream file;
  file.open(fileName, std::ios::in);
  
  typedef Queue<short>* QueuePtr;
  const int maxSize = atoi(maxSizeStr.data());
  short bags;
  QueuePtr qPtr = new Queue<short>(maxSize);
  StackLi<QueuePtr> bagLi;

  while (file >> bags) {
    qPtr->enqueue(bags);
    
    if (qPtr->isFull()) {
      bagLi.push(qPtr);
      qPtr = new Queue<short>(maxSize);
    }
  }

  if (!qPtr->isEmpty()) {
    bagLi.push(qPtr);
  } else {
    delete qPtr;
  }

  while (!bagLi.isEmpty()) {
    const QueuePtr topQueuePtr = bagLi.topAndPop();
    while (!topQueuePtr->isEmpty()) {
      std::cout << topQueuePtr->dequeue() << " ";
    }
    delete topQueuePtr;
  }

  std::cout << std::endl;
}

void Bags::stlBags(const std::string &fileName, const std::string &maxSizeStr) {
  const uint16_t maxSize = Common::parseInt(maxSizeStr);
  std::ifstream file;
  file.open(fileName, std::ios::in);

  uint16_t count = 0;
  uint16_t bags;
  std::unique_ptr<std::queue<uint16_t> > qPtr(new std::queue<uint16_t>());
  std::stack<std::unique_ptr<std::queue<uint16_t> > > bagLi;

  while (file >> bags) {
    qPtr->push(bags);
    count++;

    if (count == maxSize) {
      bagLi.push(std::move(qPtr));
      qPtr.reset(new std::queue<uint16_t>());
      count = 0;
    }
  }

  if (!qPtr->empty()) {
    bagLi.push(std::move(qPtr));
  }

  do {
    do {
      std::cout << bagLi.top()->front() << " ";
      bagLi.top()->pop();
    } while (!bagLi.top()->empty());
    bagLi.pop();
  } while (!bagLi.empty());

  std::cout << std::endl;
}

void Bags::stlFunctionalBags(const std::string &fileName, const std::string &maxSizeStr) {
  const uint16_t maxSize = Common::parseInt(maxSizeStr);
  std::ifstream file;
  file.open(fileName, std::ios::in);

  uint16_t bags;
  std::unique_ptr<std::vector<uint16_t> > qPtr(new std::vector<uint16_t>());
  std::vector<std::unique_ptr<const std::vector<uint16_t> > > bagList;

  uint16_t count = 0;
  while (file >> bags) {
    qPtr->push_back(bags);
    count++;

    if (count == maxSize) {
      bagList.push_back(std::move(qPtr));
      qPtr.reset(new std::vector<uint16_t>());
      count = 0;
    }
  }

  if (!qPtr->empty()) {
    bagList.push_back(std::move(qPtr));
  }

  for (auto crIt = bagList.crbegin(); crIt != bagList.crend(); crIt++) {
    for (auto cIt = (*crIt)->cbegin(); cIt != (*crIt)->cend(); cIt++) {
      std::cout << *cIt << " ";
    }
  }
  std::cout << std::endl;
}
