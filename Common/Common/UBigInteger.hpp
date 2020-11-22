#ifndef UBIGINTEGER_HPP
#define UBIGINTEGER_HPP

#include <cstdint>
#include <string>
#include <vector>

class UBigInteger {
public:
  UBigInteger();

  UBigInteger(const UBigInteger &other);

  UBigInteger(const std::uint64_t num);

  UBigInteger(const std::string &numStr);

  ~UBigInteger();

  operator std::string() const;

  UBigInteger operator=(const UBigInteger &other);

  UBigInteger operator+(const std::uint64_t num) const;

  UBigInteger operator+(const UBigInteger &other) const;

  UBigInteger operator-(const std::uint64_t num) const;

  UBigInteger operator-(const UBigInteger &other) const;

  UBigInteger operator*(const std::uint64_t num) const;

  UBigInteger operator*(const UBigInteger &other) const;

  UBigInteger operator/(const std::uint64_t num) const;

  UBigInteger operator/(const UBigInteger &other) const;

  UBigInteger operator%(const std::uint64_t num) const;

  UBigInteger operator%(const UBigInteger &other) const;

  bool operator==(const UBigInteger &other) const;

  bool operator<(const UBigInteger &other) const;

  bool operator<=(const UBigInteger &other) const;

  bool operator>(const UBigInteger &other) const;

  bool operator>=(const UBigInteger &other) const;


private:
  std::string digits;

  UBigInteger add(const std::string &num) const;

  UBigInteger subtract(const std::string &num) const;

  UBigInteger multiply(const std::uint64_t num) const;

  UBigInteger multiply(const UBigInteger &other) const;

  UBigInteger divide(const UBigInteger &other) const;

  UBigInteger modulus(const UBigInteger &other) const;

  static std::string convertToDigits(const std::uint64_t num);

  static std::string removeLeadingZeroes(const std::string &digits);

  static const std::uint8_t DIGIT_LOWER_BOUND;

  static const std::uint8_t DIGIT_UPPER_BOUND;
};

#endif // UBIGINTEGER_HPP
