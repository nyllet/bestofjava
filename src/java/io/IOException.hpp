#ifndef IO_EXCEPTION
#define IO_EXCEPTION

#include <stdexcept>
#include <string>

namespace bestofjava {

   class IOException : public std::runtime_error {
   public:
      explicit IOException(const std::string& message);
      ~IOException() = default;
   };

} //namespace

#endif
