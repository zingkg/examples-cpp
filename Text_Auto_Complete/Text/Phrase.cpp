#include "Phrase.h"

#include <iomanip>
#include <iostream>

Phrase::Phrase(const std::string &input) {
  phraseString = input;   // Set phraseString to the input
  std::string phraseStringCopy = input;   // Make another copy
  std::string thisWord;

  std::size_t spaceVal = phraseString.find(" ");   // Find the index of ' '

  // If there is a ' ' character
  while (spaceVal != std::string::npos) {
    // thisWord is the string up till the space character
    thisWord = phraseStringCopy.substr(0, spaceVal);

    phraseStringBase.push_back(thisWord); // Add thisWord to the dictionary

    // phraseString1 is the string after the ' ' character
    phraseStringCopy.erase(0, spaceVal + 1);

    spaceVal = phraseStringCopy.find(" ");  // Find the next ' ' character
    thisWord.clear();                   // Clear thisWord
  }
  // thisWord is the substring of phraseString
  thisWord = phraseStringCopy.substr(0, phraseStringCopy.length());
  phraseStringBase.push_back(thisWord);           // Add to the dictionary
}

void Phrase::complete(const Dict &d) {
  const std::vector<std::string> &phraseDictionary = d.getPhraseDictionary();
  const std::size_t phraseDictionarySize = phraseDictionary.size();
  const std::size_t longestWordLength = d.getLongestWordLength();

  // Search, for the length of the phrase allowed
  for (std::size_t charLength = phraseString.length(); charLength < (longestWordLength * 5 + 5) && top10Complete.size() < 10; ++charLength) {
    // The word count allowed
    const std::size_t phraseStringBaseSize = phraseStringBase.size();
    for (std::size_t wordCount = phraseStringBaseSize; wordCount <= 5 && top10Complete.size() < 10; ++wordCount) {
      for (std::size_t i = 0; i < phraseDictionarySize && top10Complete.size() < 10; ++i) {
        std::size_t iPhrase = 0;
        if (phraseDictionary.at(i) == phraseStringBase[iPhrase]) {
          bool allMatch = true;
          for (iPhrase = 0; iPhrase < phraseStringBaseSize && (i + iPhrase) < phraseDictionarySize; iPhrase++) {
            const std::string phraseData = phraseDictionary.at(i + iPhrase);
            if (phraseData != phraseStringBase[iPhrase]) {
              allMatch = false;
              break;
            }
          }

          if (allMatch && top10Complete.size() < 10) {
            std::string tempPhrase;
            for (std::size_t j = 0; j < wordCount; ++j) {
              std::string phraseData = phraseDictionary.at(i + j);
              if (phraseData.find(".") == std::string::npos) {
                tempPhrase += phraseData + " ";
              } else {
                phraseData.erase(phraseData.find("."));
                tempPhrase += phraseData;
                break;
              }
            }

            if (tempPhrase.find_last_of(" ") + 1 == tempPhrase.length()) {
              tempPhrase.erase(tempPhrase.length() - 1);
            }

            if (!match(top10Complete, tempPhrase) && charLength == tempPhrase.length()) {
              top10Complete.push_back(tempPhrase);
            }
          }
        }
      }
    }
  }
}

void Phrase::check(const Dict &d) {
  const std::string phraseString2 = phraseString;
  const std::vector<std::string> &phraseDictionary = d.getPhraseDictionary();

  const std::size_t phraseDictionarySize = phraseDictionary.size();
  const std::size_t longestWordLength = d.getLongestWordLength();
  for (std::size_t iHam = 0; iHam < longestWordLength * 5 + 5 && top10Check.size() < 10; ++iHam) {
    for (std::size_t iPhrase = phraseStringBase.size(); iPhrase <= 5 && top10Check.size() < 10; ++iPhrase) {
      for (std::size_t i = 0; i < phraseDictionarySize && top10Check.size() < 10; i++) {
        std::string phraseAccu;
        for (std::size_t iPhrase2 = 0; iPhrase2 < iPhrase && i + iPhrase2 < phraseDictionarySize; ++iPhrase2) {
          if (phraseDictionary.at(i + iPhrase2).find(".") == std::string::npos) {
            phraseAccu += phraseDictionary.at(i + iPhrase2) + " ";
          }
        }

        if (!phraseAccu.empty()) {
          phraseAccu.erase(phraseAccu.length() - 1);
        }

        if (iHam == hamdist(phraseAccu, phraseString2) && top10Check.size() < 10 && !match(top10Check, phraseAccu)) {
          top10Check.push_back(phraseAccu);
        }
      }
    }
  }
}

void Phrase::show() const {
  std::cout << "Phrase Completion: " << std::endl;
  std::cout << std::endl;
  printVector(top10Complete);

  std::cout << "Phrase Correction: " << std::endl;
  std::cout << std::endl;
  printVector(top10Check);
}
