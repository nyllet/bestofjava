#ifndef IO_EXCEPTION
#define IO_EXCEPTION

#include <exception>
#include <string>

namespace bestofjava {

   class IOException : public std::exception {
   public:
      explicit IOException(const std::string& message);
      ~IOException();
      const char* what() const noexcept;
   private:
      std::string myMessage;
   };


} //namespace

#endif
