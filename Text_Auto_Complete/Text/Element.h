#ifndef ELEMENT_H_
#define ELEMENT_H_

#include "Dict.h"

#include <string>

/**
 * Element is a virtual class. The functions are abstract.
 */
class Element {
public:
  /**
   * The complete command for an element. This will generate the possible completions for the
   * element.
   *
   * @param d The dictionary to reference.
   */
  virtual void complete(const Dict &d) = 0;

  /**
   * The check command for an element. This will generate the possible spelling corrections for
   * the element.
   *
   * @param d The dictionary to reference.
   */
  virtual void check(const Dict &d) = 0;

  /**
   * Shows the element's vectors of strings.
   */
  virtual void show() const = 0;

  static std::size_t levenshteinDist(const char* a, const char* b);

protected:
  std::vector<std::string> top10Complete; // vector for the top10 complete searches
  std::vector<std::string> top10Check; // vector for the top10 correct searches

  /**
   * Element's hamming distance function.
   *
   * @param a The first string to compare.
   * @param b The second string to compare.
   * @return The number of hamming distance the two strings are away.
   */
  static std::size_t hamdist(std::string a, std::string b);

  /**
   * Element's max function for hamdist. Gets the longest string of two strings.
   *
   * @param a The first string to check.
   * @param b The second string to check.
   * @return The maximum length of two string.
   */
  static std::size_t max(const std::string &a, const std::string &b);

  /**
   * 
   * @param a
   * @param b
   * @param c
   */
  static std::size_t min(const std::size_t a, const std::size_t b, const std::size_t c);
  static bool match(const std::vector<std::string> &a, const std::string &b);
  static void printVector(const std::vector<std::string> &a);

  static const unsigned int MAX_SIZE = 10;
  static const unsigned int MAX_D_SIZE = 512;
};
#endif /* ELEMENT_H_ */
