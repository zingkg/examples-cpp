#ifndef BUFFERSTREAM_HPP
#define BUFFERSTREAM_HPP

#include <cstdint>

class BufferStream {
public:
  BufferStream(const std::uint64_t length = 2048);

  ~BufferStream();

  void* getBuffer();

  std::uint64_t getLength() const;

  std::uint64_t getPosition() const;

  void setPosition(const std::uint64_t position);

  void read(void* buf, const std::uint64_t size);

  void write(const void* buf, const std::uint64_t size);

private:
  std::uint64_t position;  // current read/write position in buffer
  char* buffer;       // the underlying byte buffer
  std::uint64_t length;        // the length in bytes of the underlying buffer
};

#endif // BUFFERSTREAM_HPP
