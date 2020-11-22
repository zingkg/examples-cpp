#include "Sentence.h"

#include <iostream>

Sentence::Sentence(const std::string &input) {
  sentenceString = input;
}

void Sentence::complete(const Dict &d) {
  const std::string sentenceString1 = sentenceString;
  const std::size_t sentenceString1Length = sentenceString1.length();
  const std::vector<std::string> &sentenceDictionary = d.getSentenceDictionary();
  const std::size_t longestSentenceLength = d.getLongestSentenceLength();

  // The search
  for (std::size_t sentenceLength = sentenceString1Length; sentenceLength < longestSentenceLength && top10Complete.size() < 10; ++sentenceLength) {
    for (auto it = sentenceDictionary.cbegin(); it != sentenceDictionary.cend() && top10Complete.size() < 10; ++it) {
        if (sentenceLength == it->length()) {
          bool sentenceMatch = true;
          for (std::size_t j = 0; j < sentenceString1Length; ++j) {
            if (sentenceString1[j] != it->at(j)) {
              sentenceMatch = false;
              break;
            }
          }

          if (sentenceMatch && !match(top10Complete, *it) && top10Complete.size() < 10) {
            top10Complete.push_back(*it);
          }
        }
    }
  }
}

void Sentence::check(const Dict &d) {
  const std::vector<std::string> &sentenceDictionary = d.getSentenceDictionary();
  const std::size_t longestSentenceLength = d.getLongestSentenceLength();

  for (std::size_t iHam = 0; iHam < longestSentenceLength && top10Check.size() < 10; ++iHam) {
    for (auto it = sentenceDictionary.cbegin(); it != sentenceDictionary.cend() && top10Check.size() < 10; ++it) {
      if (iHam == hamdist(*it, sentenceString) && top10Check.size() < 10 && !match(top10Check, *it)) {
        top10Check.push_back(*it);
      }
    }
  }
}

void Sentence::show() const {
  std::cout << "Sentence Completion: " << std::endl;
  std::cout << std::endl;
  printVector(top10Complete);

  std::cout << "Sentence Correction: " << std::endl;
  std::cout << std::endl;
  printVector(top10Check);
}
