#include "BitVector.hpp"

#include "Common.hpp"
#include "Exception.hpp"

BitVector::BitVector() {
  for (std::uint32_t i = 0; i < 4; i++)
    bits.push_back(0);
}

BitVector::BitVector(const BitVector &other) {
  bits = other.bits;
}

BitVector::BitVector(const std::uint32_t num) {
  for (std::uint32_t i = 0; i < sizeof(num); i++)
    bits.push_back(0);

  std::vector<std::uint8_t>::reverse_iterator it = bits.rbegin();
  std::uint8_t charBits = 0x80;
  for (
    std::uint32_t checker = 0x80000000;
    checker > 0x00000000 && it != bits.rend();
    checker = checker >> 1, charBits = charBits >> 1
  ) {
    if (charBits == 0x00) {
      ++it;
      charBits = 0x80;
    }

    if ((num & checker) == checker)
      *it |= charBits;
  }
}

BitVector::~BitVector() {}

BitVector BitVector::operator=(const BitVector &other) {
  BitVector copy(other);
  std::swap(bits, copy.bits);
  return *this;
}

bool BitVector::getBit(const std::uint32_t position) const {
  const std::uint32_t maxSize = bits.size() * 32;
  if (position > maxSize)
    throw Exception(
      std::string("BitVector position ") + Common::toString(position) + std::string(" is invalid"),
      __FILE__,
      __LINE__);

  const std::uint32_t bytePosition = position / (sizeof(position) * 8);
  const std::uint32_t checker = 1 << (position % (sizeof(position) * 8));
  return (bits[bytePosition] & checker) == checker;
}

std::string BitVector::getBitString() const {
  std::string bitStr;
  for (auto it = bits.crbegin(); it != bits.crend(); ++it) {
    for (std::uint8_t byte = 0x80; byte > 0x00; byte = byte >> 1) {
      if ((*it & byte) == byte)
        bitStr += '1';
      else
        bitStr += '0';
    }
  }
  return bitStr;
}
std::uint32_t BitVector::getBitNum() const {
  return bits.size();
}
