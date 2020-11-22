#ifndef BITVECTOR_HPP
#define BITVECTOR_HPP

#include <cstdint>
#include <string>
#include <vector>

class BitVector {
public:
  BitVector();

  BitVector(const BitVector &other);

  BitVector(const std::uint32_t num);

  virtual ~BitVector();

  BitVector operator=(const BitVector &other);

  BitVector operator+(const std::int32_t other) const;

  BitVector operator+(const BitVector &other) const;

  bool getBit(const uint32_t position) const;

  std::string getBitString() const;

  std::uint32_t getBitNum() const;

private:
  std::vector<std::uint8_t> bits;
};

#endif // BITVECTOR_HPP
