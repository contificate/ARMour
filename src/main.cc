#include <cstdint>
#include <iostream>

#include "encoders/arm_encoder.h"
#include "readers/file_reader.h"

int main() {
  using namespace enc;

  // testing encoder stuff
  ARMEncoder instr{0x012fff1e}; // bxeq lr
  std::cout << arm_cond_to_str(instr.cond()) << '\n';

  if (rdr::StreamReader *rdr = new rdr::FileReader("/home/dosto/Projects/ARMour/tests/libc.arm.text")) {
    if (*rdr) {

      for (unsigned i = 0; i < (rdr->size() >> 2); i++) {
        ARMEncoder instr {rdr->Read<uint32_t>()};
        if(instr & arm_mask::BX)
        {
          std::cout << "Branch exchange at 0x" << std::hex << (i << 2) << '\n';
          std::cout << std::hex << static_cast<uint32_t>(instr) << '\n';
          std::cout << arm_cond_to_str(instr.cond()) << '\n';
        }
      }

    }

    delete rdr;
  }

}
