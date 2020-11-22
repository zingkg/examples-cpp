#ifndef WORD_H_
#define WORD_H_

#include "Element.h"

class Word : public Element {
public:
  /**
   * Constructor that takes a string as input
   *
   * @param input The string to check for completion and spell checking.
   */
  Word(const std::string &input);

  // Override
  void complete(const Dict &d);

  // Override
  void check(const Dict &d);

  // Override
  void show() const;

private:
  std::string wordString;                 // user input
};
#endif /* WORD_H_ */
