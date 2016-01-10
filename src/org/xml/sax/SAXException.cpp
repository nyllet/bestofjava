#include "SAXException.hpp"

namespace bestofjava {

   SAXException::SAXException(const std::string& message) : myMessage(message) {
   }

   SAXException::~SAXException() {
   }

   const char* SAXException::what() const noexcept {
      return myMessage.c_str();
   }

} //namespace
