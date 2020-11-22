#include "bags.hpp"

std::vector<uint16_t> Bags::weissBags(const std::vector<uint16_t> &bags, const uint16_t maxSize) {
  typedef Queue<short>* QueuePtr;
  QueuePtr qPtr = new Queue<short>(maxSize);
  StackLi<QueuePtr> bagLi;

  for (auto it = bags.cbegin(); it != bags.cend(); ++it) {
    qPtr -> enqueue(*it);

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

  std::vector<uint16_t> result;
  while (!bagLi.isEmpty()) {
    const QueuePtr topQueuePtr = bagLi.topAndPop();
    while (!topQueuePtr->isEmpty()) {
      result.push_back(topQueuePtr->dequeue());
    }
    delete topQueuePtr;
  }

  return result;
}

std::vector<uint16_t> Bags::stlBags(const std::vector<uint16_t> &bags, const uint16_t maxSize) {
  uint16_t count = 0;
  std::unique_ptr<std::queue<uint16_t> > qPtr(new std::queue<uint16_t>());
  std::stack<std::unique_ptr<std::queue<uint16_t> > > bagLi;

  for (auto it = bags.cbegin(); it != bags.cend(); ++it) {
    qPtr->push(*it);
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

  std::vector<uint16_t> result;
  while (!bagLi.empty()) {
    while (!bagLi.top()->empty()) {
      result.push_back(bagLi.top()->front());
      bagLi.top()->pop();
    }
    bagLi.pop();
  }
  return result;
}

std::vector<uint16_t> Bags::stlFunctionalBags(
  const std::vector<uint16_t> &bags,
  const uint16_t maxSize
) {
  std::unique_ptr<std::vector<uint16_t> > qPtr(new std::vector<uint16_t>());
  std::vector<std::unique_ptr<const std::vector<uint16_t> > > bagList;

  uint16_t count = 0;
  for (auto it = bags.cbegin(); it != bags.cend(); ++it) {
    qPtr->push_back(*it);
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

  std::vector<uint16_t> result;
  for (auto crIt = bagList.crbegin(); crIt != bagList.crend(); crIt++) {
    for (auto cIt = (*crIt)->cbegin(); cIt != (*crIt)->cend(); cIt++) {
      result.push_back(*cIt);
    }
  }
  return result;
}
