#include "IOException.hpp"

namespace bestofjava {

   IOException::IOException(const std::string& message) : std::runtime_error(message) {
   }

} // namespace bestofjava
