#include "arm.h"

namespace arm {

std::string arm_cond_to_str(const arm_cond cond) {
  switch (cond) {
    case arm_cond::EQ:
      return "Equal";

    case arm_cond::NE:
      return "Not equal";

    case arm_cond::CS:
      return "C set";

    case arm_cond::CC:
      return "C cleared";

    case arm_cond::MI:
      return "Negative";

    case arm_cond::PL:
      return "Positive or zero";

    case arm_cond::VS:
      return "Overflow";

    case arm_cond::VC:
      return "No overflow";

    case arm_cond::HI:
      return "Unsigned higher";

    case arm_cond::LS:
      return "Unsigned lower or same";

    case arm_cond::GE:
      return "Greater or equal";

    case arm_cond::LT:
      return "Less than";

    case arm_cond::GT:
      return "Greater than";

    case arm_cond::LE:
      return "Less or equal";

    case arm_cond::AL:
      return "Always"; // default

    default:
      return "Unknown";
  }
}

std::string arm_gpr_to_str(const arm_gpr gpr)
{
  switch(gpr) {
    case arm_gpr::LR:
      return "lr";

    default:
      return "Unknown";
  }
}

} // namespace arm
