#ifndef URL_DECODER_H
#define URL_DECODER_H

#include <string>

namespace bestofjava {

   class URLDecoder {

   public:
      static std::string decode(const std::string& s, const std::string& enc);

   };

} // namespace

#endif
