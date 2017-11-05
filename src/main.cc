#include <cstdint>
#include <iostream>

#include "readers/file_reader.h"

int main() {
  using namespace rdr;

  // small test of stream (TODO: implement memory-based implementation)
  if (StreamReader *rdr = new FileReader("/home/dosto/test")) {
    if (*rdr) {
      std::cout << "Successfully opened file!\n";
      std::cout << "0x" << std::hex << rdr->Read<uint32_t>() << '\n';
    }
    delete rdr;
  }
}
