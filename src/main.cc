#include <cstdint>
#include <iostream>

#include "readers/memory_reader.h"
#include "encoders/arm_encoder.h"

int main() {
  using namespace enc;

  // testing encoder stuff
  ARMEncoder instr{0x012fff1e}; // bxeq lr
  std::cout << arm_cond_to_str(instr.cond()) << '\n';

  // testing reader abstractions
  uint8_t buffer[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xDE, 0xAD, 0xBA, 0xBE};
  if (rdr::StreamReader *rdr = new rdr::MemoryReader(buffer, sizeof(buffer))) {
    if (*rdr) {
      std::cout << std::hex << rdr->Read<uint32_t>() << '\n' << rdr->Read<uint32_t>() << '\n';
      std::cout << rdr->pos() << '\n';
    }

    delete rdr;
  }

}
