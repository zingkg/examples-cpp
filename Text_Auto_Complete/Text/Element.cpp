#include "Element.h"

#include <cstring>
#include <iostream>

std::size_t Element::hamdist(std::string a, std::string b) {
  const std::size_t maxlength = max(a, b); // Max length of two strings
  std::size_t padding = 0; // Size of padding
  if (b.length() > a.length()) {
      padding = (b.length() - a.length());
      a.append(padding, '_');
  }

  if (a.length() > b.length()) {
      padding = (a.length() - b.length());
      b.append(padding, '_');
  }

  std::size_t sameChar = 0;        // Number of the same characters
  for (std::size_t i = 0; i < maxlength; i++) {
      if(a[i] == b[i])
          sameChar++;
  }
  return maxlength - sameChar;
}

std::size_t Element::levenshteinDist(const char* a, const char* b) {
  const std::size_t aLength = strlen(a);
  const std::size_t bLength = strlen(b);

  if (aLength == 0)
    return bLength;

  if (bLength == 0)
    return aLength;

  std::size_t *v0 = new std::size_t[bLength + 1];
  std::size_t *v1 = new std::size_t[bLength + 1];

  for (std::size_t i = 0; i < bLength + 1; i++) {
    v0[i] = i;
  }

  for (std::size_t i = 0; i < aLength; i++) {
    v1[0] = i + 1;

    for (std::size_t j = 0; j < bLength; j++) {
      std::size_t cost = 1;
      if (a[i] == b[j]) {
        cost = 0;
      }

      v1[j + 1] = min(v1[j] + 1, v0[j + 1] + 1, v0[j] + cost);
    }

    for (std::size_t j = 0; j < aLength; j++) {
      v0[j] = v1[j];
    }
  }

  const std::size_t dist = v1[bLength];
  delete v0;
  delete v1;

  return dist;
}

std::size_t Element::max(const std::string &a, const std::string &b) {
  std::size_t maxlength = a.size();
  if (a.size() < b.size()) {
    maxlength = b.size();
  }

  return maxlength;
}

std::size_t Element::min(const std::size_t a, const std::size_t b, const std::size_t c) {
  std::size_t min = a;
  if (b < a) {
    min = b;
  }

  if (c < b) {
    min = c;
  }

  return min;
}

bool Element::match(const std::vector<std::string> &a, const std::string &b) {
  std::size_t aSize = a.size();
  for (std::size_t i = 0; i < aSize; i++) {
    if (a[i].empty())
      break;

    if (b == a[i])
      return true;
  }
  return false;
}

void Element::printVector(const std::vector<std::string> &a) {
  for (auto it = a.cbegin(); it != a.cend(); ++it) {
    std::cout << *it << std::endl;
  }

  std::cout << std::endl;
}
