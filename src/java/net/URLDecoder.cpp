#include "URLDecoder.hpp"
#include <curl/curl.h>

namespace bestofjava {

   std::string URLDecoder::decode(const std::string& encoded, const std::string& encoding) {
      if (encoding.compare("UTF-8") != 0) {
         //  throw java.io.UnsupportedEncodingException();
         return "";
      }
      CURL *curl = curl_easy_init();
      if (curl) {
         int output_length;
         char* decoded_value = curl_easy_unescape(nullptr, encoded.c_str(), static_cast<int>(encoded.length()), &output_length);
         if (decoded_value) {
            std::string result(decoded_value, output_length);
            curl_free(decoded_value);
            curl_easy_cleanup(curl);
            return result;
         }
         curl_easy_cleanup(curl);
      }
      return "";
   }

} // namespace
