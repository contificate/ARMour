#include "memory_reader.h"

namespace rdr {

MemoryReader::MemoryReader(uint8_t *const src, const size_t len)
    : base_addr_{src}, init_size_{len} {

}

void MemoryReader::Seek(const std::streamoff pos) {
  current_ptr_ = pos;
}

// TODO: again, implement range checking (and handling, error flag?)
void MemoryReader::Skip(const std::streamsize len) {
  current_ptr_ += len;
}

void MemoryReader::Read(char *const dst, const size_t len) {
  std::memcpy(dst, (base_addr_ + current_ptr_), len);
  Skip(len);
}

std::streampos MemoryReader::pos() const {
  return current_ptr_;
}

MemoryReader::operator bool() const {
  return (base_addr_ && (current_ptr_ >= 0));
}

} // namespace rdr
