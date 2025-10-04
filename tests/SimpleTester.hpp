#include "org/xml/sax/helpers/DefaultHandler.hpp"
#include "org/xml/sax/Attributes.hpp"
#include <string>

class SimpleTester : public bestofjava::DefaultHandler {

public:
   void startElement(const std::string& uri, const std::string& localname, const std::string& qname, const bestofjava::Attributes& attrs) override;
   void characters(const std::string&) override;
   void endElement(const std::string& uri, const std::string& localname, const std::string& qname) override;

private:
   std::string temp;
   
};
