#pragma once
#include <stdexcept>
#include <string>

namespace leap {
  struct serialization_error :
    public std::runtime_error
  {
    serialization_error(std::string what);
  };
}
