#include "Word.h"

#include <iostream>

Word::Word(const std::string &input) {
  wordString = input;
}

void Word::complete(const Dict &d) {
  const std::string wordStringCopy = wordString;
  const std::size_t wordStringLength = wordStringCopy.length();
  const std::vector<std::string> &wordDictionary = d.getWordDictionary();
  const std::size_t longestWordLength = d.getLongestWordLength();

  for (std::size_t iWordLength = wordStringLength; iWordLength < longestWordLength && top10Complete.size() < MAX_SIZE; iWordLength++) {
    for (auto it = wordDictionary.cbegin(); it != wordDictionary.cend() && top10Complete.size() < MAX_SIZE; ++it) {
      if (iWordLength == it->length()) {
        bool wordMatch = true;
        for (std::size_t j = 0; j < wordStringLength; j++) {
          if (wordStringCopy[j] != it->at(j)) {
            wordMatch = false;
            break;
          }
        }

        if (wordMatch && top10Complete.size() < MAX_SIZE && !match(top10Complete, *it)) {
          top10Complete.push_back(*it);
        }
      }
    }
  }
}

void Word::check(const Dict &d) {
  const std::string wordStringCopy = wordString;
  const std::size_t longestWordLength = d.getLongestWordLength();
  const std::vector<std::string> &wordDictionary = d.getWordDictionary();

  for (std::size_t iHam = 0; iHam < longestWordLength && top10Check.size() < 10; iHam++) {
    for (auto it = wordDictionary.cbegin(); it != wordDictionary.cend() && top10Check.size() < MAX_SIZE; it++) {
      if (iHam == hamdist(*it, wordStringCopy) && top10Check.size() < 10 && !match(top10Check, *it)) {
          top10Check.push_back(*it);
      }
    }
  }
}

void Word::show() const {
  std::cout << "Word Completion: " << std::endl;
  std::cout << std::endl;
  printVector(top10Complete);

  std::cout << "Word Correction: " << std::endl;
  std::cout << std::endl;
  printVector(top10Check);
}
