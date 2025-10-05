#ifndef SAX_EXCEPTION
#define SAX_EXCEPTION

#include <stdexcept>
#include <string>

namespace bestofjava {

   class SAXException : public std::runtime_error {
   public:
      explicit SAXException(const std::string& message);
      ~SAXException() = default;
   };


} // namespace bestofjava

#endif
