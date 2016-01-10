#include "IOException.hpp"

namespace bestofjava {

   IOException::IOException(const std::string& message) : myMessage(message) {
   }

   IOException::~IOException() {
   }

   const char* IOException::what() const noexcept {
      return myMessage.c_str();
   }

} //namespace
