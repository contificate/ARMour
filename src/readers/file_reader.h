#ifndef ARMOUR_FILE_READER_H
#define ARMOUR_FILE_READER_H

#include <fstream>

#include "stream_reader.h"

#define READER_FLAGS (std::ios::binary | std::ios::ate)

namespace rdr {

class FileReader : public StreamReader {
 public:
  FileReader(const std::string &fileLocation);

  void Skip(const std::streamsize len) override;
  void Seek(const std::streamoff pos) override;
  std::streampos pos() const override;

  void Read(char *const dst, const size_t len) override;

  size_t size() const override;

  operator bool() const override;

 private:
  mutable std::ifstream ifs_; // mutable because std::ifstream's tellg() isn't const
  std::streamsize init_size_;
};

} // namespace rdr

#endif //ARMOUR_FILE_READER_H
