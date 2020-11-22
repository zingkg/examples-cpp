#include "UBigInteger.hpp"

#include "Common.hpp"

UBigInteger::UBigInteger(): digits(1, '0' - DIGIT_LOWER_BOUND) {
}

UBigInteger::UBigInteger(const UBigInteger &other): digits(other.digits) {
}

UBigInteger::UBigInteger(const std::uint64_t num): digits(convertToDigits(num)) {
}

UBigInteger::UBigInteger(const std::string &numStr): digits(numStr) {
}

UBigInteger::~UBigInteger() {
}

UBigInteger::operator std::string() const {
  std::string numStr;
  for (auto it = digits.cbegin(); it != digits.cend(); ++it) {
    numStr += *it + DIGIT_LOWER_BOUND;
  }

  return numStr;
}

UBigInteger UBigInteger::operator=(const UBigInteger &other) {
  UBigInteger copy(other);
  std::swap(digits, copy.digits);
  return *this;
}

UBigInteger UBigInteger::operator+(const std::uint64_t num) const {
  return add(convertToDigits(num));
}

UBigInteger UBigInteger::operator+(const UBigInteger &other) const {
  return add(other.digits);
}

UBigInteger UBigInteger::operator-(const std::uint64_t num) const {
  return subtract(convertToDigits(num));
}

UBigInteger UBigInteger::operator-(const UBigInteger &other) const {
  return subtract(other.digits);
}

UBigInteger UBigInteger::operator*(const std::uint64_t num) const {
  return multiply(convertToDigits(num));
}

UBigInteger UBigInteger::operator*(const UBigInteger &other) const {
  return multiply(other.digits);
}

UBigInteger UBigInteger::operator/(const std::uint64_t num) const {
  return divide(UBigInteger(num));
}

UBigInteger UBigInteger::operator/(const UBigInteger &other) const {
  return divide(other);
}

UBigInteger UBigInteger::operator%(const std::uint64_t num) const {
  return modulus(UBigInteger(num));
}

UBigInteger UBigInteger::operator%(const UBigInteger &other) const {
  return modulus(other);
}

bool UBigInteger::operator==(const UBigInteger &other) const {
  return digits == other.digits;
}

bool UBigInteger::operator<(const UBigInteger &other) const {
  if (digits.size() < other.digits.size())
    return true;
  else if (digits.size() > other.digits.size())
    return false;
  else {
    std::string::const_iterator digitIt = digits.cbegin();
    std::string::const_iterator otherIt = other.digits.cbegin();
    for (; digitIt != digits.cend() && otherIt != other.digits.cend(); ++digitIt, ++otherIt) {
      if (*digitIt < *otherIt) {
        return true;
      } else if (*digitIt > *otherIt) {
        return false;
      }
    }
  }
  return false;
}

bool UBigInteger::operator<=(const UBigInteger &other) const {
  return *this == other || *this < other;
}

bool UBigInteger::operator>(const UBigInteger &other) const {
  if (digits.size() > other.digits.size())
    return true;
  else if (digits.size() < other.digits.size())
    return false;
  else {
    std::string::const_iterator digitIt = digits.cbegin();
    std::string::const_iterator otherIt = other.digits.cbegin();
    for (; digitIt != digits.cend() && otherIt != other.digits.cend(); ++digitIt, ++otherIt) {
      if (*digitIt > *otherIt) {
        return true;
      } else if (*digitIt < *otherIt) {
        return false;
      }
    }
  }
  return false;
}

bool UBigInteger::operator>=(const UBigInteger &other) const {
  return *this == other || *this > other;
}

UBigInteger UBigInteger::add(const std::string &num) const {
  UBigInteger copy(*this);
  while (num.length() > copy.digits.length()) {
    copy.digits.insert(copy.digits.begin(), 0);
  }

  std::string::reverse_iterator copyDigit = copy.digits.rbegin();
  std::string::const_reverse_iterator otherDigit = num.crbegin();
  bool carry = false;
  for (; copyDigit != copy.digits.rend(); ++copyDigit) {
    if (carry) {
      *copyDigit = *copyDigit + *otherDigit + 1;
      carry = false;
    } else if (otherDigit != num.crend()) {
      *copyDigit = *copyDigit + *otherDigit;
    }

    if (*copyDigit >= 10) {
      *copyDigit -= 10;
      carry = true;
    }

    if (otherDigit != num.crend()) {
      ++otherDigit;
    } else if (otherDigit == num.crend() && !carry) {
      break;
    }
  }

  if (carry) {
    copy.digits.insert(copy.digits.begin(), 1);
  }

  return copy;
}

UBigInteger UBigInteger::subtract(const std::string &num) const {
  UBigInteger copy(*this);
  std::string::reverse_iterator digits = copy.digits.rbegin();
  std::string::const_reverse_iterator otherDigit = num.crbegin();
  bool carry = false;
  for(; digits != copy.digits.rend(); ++digits) {
    if (carry) {
      *digits = *digits - *otherDigit - 1;
      carry = false;
    } else if (otherDigit != num.crend()) {
      *digits = *digits - *otherDigit;
    }

    if (*digits < 0) {
      *digits += 10;
      carry = true;
    }

    if (otherDigit != num.crend()) {
      ++otherDigit;
    } else if (otherDigit == num.crend() && !carry) {
      break;
    }
  }

  if (carry && digits != copy.digits.rend()) {
    *digits = *digits - 1;
  }

  // Remove leading 0s.
  copy.digits = removeLeadingZeroes(copy.digits);
  return copy;
}

UBigInteger UBigInteger::multiply(const std::uint64_t num) const {
  UBigInteger result(*this);
  if (num == 0) {
    result = 0;
  } else {
    for (std::uint64_t i = 1; i < num; i++) {
      result = result + *this;
    }
  }

  return result;
}

UBigInteger UBigInteger::multiply(const UBigInteger &other) const {
  UBigInteger result(*this);
  if (other.digits == "0") {
    result = 0;
  } else {
    for (UBigInteger i = 1; i.digits != other.digits; i = i + 1) {
      result = result + *this;
    }
  }

  return result;
}

UBigInteger UBigInteger::divide(const UBigInteger &other) const {
  UBigInteger copy(*this);
  UBigInteger result(0);
  while (other <= copy) {
    copy = copy - other;
    result = result + 1;
  }
  return result;
}

UBigInteger UBigInteger::modulus(const UBigInteger &other) const {
  UBigInteger result(*this);
  while (other <= result) {
    result = result - other;
  }
  return result;
}

std::string UBigInteger::convertToDigits(const std::uint64_t num) {
  std::string numStr = Common::toString(num);
  for (auto it = numStr.begin(); it != numStr.end(); ++it) {
    *it = *it - DIGIT_LOWER_BOUND;
  }

  return numStr;
}

std::string UBigInteger::removeLeadingZeroes(const std::string &digits) {
  if (digits.size() == 1 && *digits.begin() == 0)
    return digits;

  std::string noZeroes = digits;
  while (*noZeroes.begin() == 0) {
    noZeroes.erase(noZeroes.begin());
  }
  return noZeroes;
}

const std::uint8_t UBigInteger::DIGIT_LOWER_BOUND = 48;

const std::uint8_t UBigInteger::DIGIT_UPPER_BOUND = 57;
