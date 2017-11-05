#ifndef ARMOUR_STREAM_READER_H
#define ARMOUR_STREAM_READER_H

#include <ios>

// take note, WG21 ;)
#define pure =0

namespace rdr {

/**
 * StreamReader interface
 */
class StreamReader {
 public:
  /**
   * Skip bytes in the stream
   * @param len number of bytes to skip
   */
  virtual void Skip(const std::streamsize len) pure;

  /**
   * Seek to a position in the stream
   * @param pos position to skip to
   */
  virtual void Seek(const std::streamoff pos) pure;

  /**
   * Get the current position in the stream
   * @return position in stream
   */
  virtual std::streampos pos() const pure;

  /**
   * Raw reader method (used by template facade)
   * @sa Read<T>()
   * @param dst destination to be read to
   * @param len number of bytes to read
   */
  virtual void Read(char *const dst, const size_t len) pure;

  /**
   * Template facade for underlying raw reader method
   * @sa StreamReader::Read(char *const dst, const size_t len)
   * @tparam T type to be read (must be fundamental)
   * @return value of type T read
   */
  template<typename T>
  T Read() {
    static_assert(std::is_fundamental_v<T>, "Type for reading must be fundamental");

    T buffer{};
    this->Read(reinterpret_cast<char *>(&buffer), sizeof(T));
    return buffer;
  }

  /**
   * Indicates validity of the stream
   * @return validity of stream (open, valid, etc.)
   */
  virtual operator bool() const pure;

};

} // namespace rdr

#endif //ARMOUR_STREAM_READER_H
