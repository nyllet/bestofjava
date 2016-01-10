#ifndef SAX_EXCEPTION
#define SAX_EXCEPTION

#include <exception>
#include <string>

namespace bestofjava {

   class SAXException : public std::exception {
   public:
      explicit SAXException(const std::string& message);
      ~SAXException();
      const char* what() const noexcept;
   private:
      std::string myMessage;
   };


} //namespace

#endif
