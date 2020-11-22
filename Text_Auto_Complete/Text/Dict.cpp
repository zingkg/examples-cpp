#include "Dict.h"

#include <fstream>

Dict::Dict(const std::string &f) {
  longestWordLength = 0;
  longestPhraseLength = 0;
  longestSentenceLength = 0;

  std::ifstream readFile(f.c_str());
  // Word
  if (readFile.is_open()) {
    std::string word;
    while (readFile >> word) {
      wordDictionary.push_back(word);    // Add a word to the dictionary
    }
  }
  readFile.close();   // Close the read file

  // Converting the wordDictionary to lowercase.
  for (std::vector<std::string>::iterator it = wordDictionary.begin(); it != wordDictionary.end(); ++it) {
    // Changes all words to lower case
    it->assign(toLowerCase(*it));
  }

  // Constructing the sentenceDictionary.
  std::vector<std::string> thisSentence;
  for (auto it = wordDictionary.cbegin(); it != wordDictionary.cend(); ++it) {
    thisSentence.push_back(*it);      // Sentence
    // If word has a '.'
    if (it->find(".") != std::string::npos) {
      // Concatenate the string then put it in the sentenceDictionary
      const std::string concacted = concatenateStrings(thisSentence);
      sentenceDictionary.push_back(concacted);
      thisSentence.clear();   // Clear the sentence when done
    }
  }
  // Determining the longest sentence
  for (auto it = sentenceDictionary.cbegin(); it != sentenceDictionary.cend(); ++it) {
    if (it->length() > longestSentenceLength) {
      longestSentenceLength = it->length();
    }
  }

  // Copy of wordDictionary, and erase the punctuations in wordDictionary
  for (auto it = wordDictionary.begin(); it != wordDictionary.end(); ++it) {
    phraseDictionary.push_back(*it);
    // Erase all punctuations in wordDictionary
    *it = puncErase(*it);
  }

  // Determining the longest word
  for (auto it = wordDictionary.cbegin(); it != wordDictionary.cend(); ++it) {
    if (it->length() > longestWordLength) {
      longestWordLength = it->length();
    }
  }
}

Dict::~Dict() {
}

std::size_t Dict::getLongestWordLength() const {
  return longestWordLength;
}

std::size_t Dict::getLongestPhraseLength() const {
  return longestPhraseLength;
}

std::size_t Dict::getLongestSentenceLength() const {
  return longestSentenceLength;
}

std::vector<std::string> Dict::getWordDictionary() const {
  return wordDictionary;
}

std::vector<std::string> Dict::getPhraseDictionary() const {
  return phraseDictionary;
}

std::vector<std::string> Dict::getSentenceDictionary() const {
  return sentenceDictionary;
}

std::string Dict::puncErase(const std::string &read) {
  std::string noPunc = read;
  std::size_t found = noPunc.find_first_of("!()-[]|:\"',./;");  // Check for chars
  while (found != std::string::npos) {
    if (found == 0) {
      noPunc = noPunc.substr(found + 1, noPunc.length());
      found = noPunc.find_first_of("!()-[]|:\"',./;", found);
    } else {
      noPunc.erase(found);
      found = noPunc.find_first_of("!()-[]|:\"',./;", found);
    }
  }
  return noPunc;
}

std::string Dict::concatenateStrings(const std::vector<std::string> &strVector) {
  std::string strings;
  for (auto it = strVector.cbegin(); it != strVector.cend(); ++it) {
    strings.append(*it + ' ');
  }

  return strings;
}

std::string Dict::toLowerCase(const std::string &str) {
  std::string lowered;
  for (auto it = str.cbegin(); it != str.cend(); ++it) {
    lowered += tolower(*it);
  }

  return lowered;
}
