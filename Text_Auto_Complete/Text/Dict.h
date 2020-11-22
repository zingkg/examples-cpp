#ifndef	DICT_H_
#define	DICT_H_

#include <string>
#include <vector>

class Dict {
public:
  /**
   * Constructor
   *
   * @param f The file name.
   */
  Dict(const std::string &f);
  virtual ~Dict();

  std::size_t getLongestWordLength() const;
  std::size_t getLongestPhraseLength() const;
  std::size_t getLongestSentenceLength() const;
  std::vector<std::string> getWordDictionary() const;
  std::vector<std::string> getPhraseDictionary() const;
  std::vector<std::string> getSentenceDictionary() const;

private:
  std::size_t longestWordLength;      // the longest word in the wordDictionary
  std::size_t longestPhraseLength;    // the longest phrase
  std::size_t longestSentenceLength;  // the longest sentence
  std::vector<std::string> wordDictionary;
  std::vector<std::string> phraseDictionary;
  std::vector<std::string> sentenceDictionary;

  /**
   * Erases the punctuation in a string, changes the inputted string.
   *
   * @param read a string to erase its punctuation.
   */
  static std::string puncErase(const std::string &read);

  /**
   * Constructs and returns a string constructed from a vector of strings
   *
   * @param strVector
   *     A vector of strings passed by reference
   * @return a string constructed from the sequence of strings
   */
  static std::string concatenateStrings(const std::vector<std::string> &strVector);

  static std::string toLowerCase(const std::string &str);
};
#endif /* DICT_H_ */
