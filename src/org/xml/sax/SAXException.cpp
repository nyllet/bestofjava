#include "SAXException.hpp"

namespace bestofjava {

   SAXException::SAXException(const std::string& message) : std::runtime_error(message) {
   }

} // namespace bestofjava
