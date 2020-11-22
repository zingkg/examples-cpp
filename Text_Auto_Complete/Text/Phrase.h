#ifndef PHRASE_H_
#define PHRASE_H_

#include "Element.h"

/**
 * Phrase inherits from Element, and implements Element's virtual functions
 */
class Phrase: public Element {
public:
  /**
   * Constructor that takes in a string and adds it to the dictionary
   *
   * @param input The string to add to its phrase dictionary.
   */
  Phrase(const std::string &input);

  // Override
  void complete(const Dict &d);

  // Override
  void check(const Dict &d);

  // Override
  void show() const;

private:
  std::string phraseString;               // User input.
  std::vector<std::string> phraseStringBase;  // the base string to help searches
};
#endif /* PHRASE_H_ */
