#ifndef ARMOUR_MEMORY_READER_H
#define ARMOUR_MEMORY_READER_H

#include <cstring>

#include "stream_reader.h"

namespace rdr {

class MemoryReader : public StreamReader {
 public:

  MemoryReader(uint8_t *const src, const size_t len);

  void Skip(const std::streamsize len) override;
  void Seek(const std::streamoff pos) override;
  std::streampos pos() const override;

  void Read(char *const dst, const size_t len) override;

  operator bool() const override;

 private:
  const uint8_t *base_addr_;
  const size_t init_size_;
  size_t current_ptr_;
};

} // namespace rdr

#endif //ARMOUR_MEMORY_READER_H
