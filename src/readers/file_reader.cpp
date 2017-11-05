#include "file_reader.h"

namespace rdr {

FileReader::FileReader(const std::string &fileLocation)
    : ifs_{fileLocation, READER_FLAGS} {

  // get file size
  init_size_ = pos();

  // reset position
  Seek(0);
}

// TODO: implement range checking
void FileReader::Skip(const std::streamsize len) {
  Seek(pos() + len);
}

void FileReader::Seek(const std::streamoff pos) {
  ifs_.seekg(pos);
}

std::streampos FileReader::pos() const {
  return ifs_.tellg();
}

void FileReader::Read(char *const dst, const size_t len) {
  ifs_.read(dst, len);
}

FileReader::operator bool() const {
  return ifs_.is_open();
}

} // namespace rdr