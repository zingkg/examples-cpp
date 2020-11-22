#ifndef SENTENCE_H_
#define SENTENCE_H_

#include "Element.h"

class Sentence: public Element {
public:
  /**
   * Constructor, sets the sentenceString to input
   *
   * @param input The sentence to check against the dictionary
   */
  Sentence(const std::string &input);

  // Override
  void complete(const Dict &d);

  // Override
  void check(const Dict &d);

  // Override
  void show() const;

private:
  std::string sentenceString;                 // the user input.
};
#endif /* SENTENCE_H_ */
