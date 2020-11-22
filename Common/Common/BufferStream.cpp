#include "BufferStream.hpp"

#include <cassert>
#include <cstring>

BufferStream::BufferStream(const std::uint64_t length)
  : position(0), buffer(new char[length]), length(length) {
}

BufferStream::~BufferStream() {
  delete[] buffer;
}

void* BufferStream::getBuffer() {
  return buffer;
}

std::uint64_t BufferStream::getLength() const {
  return length;
}

std::uint64_t BufferStream::getPosition() const {
  return position;
}

void BufferStream::setPosition(const std::uint64_t position) {
  assert(position <= length);
  this->position = position;
}

void BufferStream::read(void* buf, const std::uint64_t size) {
  assert(position + size <= length);
  memcpy(buf, buffer + position, size);
  position += size;
}

void BufferStream::write(const void* buf, const std::uint64_t size) {
  assert(position + size <= length);
  memcpy(buffer + position, buf, size);
  position += size;
}
