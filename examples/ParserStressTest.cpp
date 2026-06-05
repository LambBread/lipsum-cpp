#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif
#include <chrono>
#include <json-c/json.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <lipsum.hpp>

int main()
{
    lpsm::Generator gen;
    gen.change_setting("jsonLength", 10, 20);
    std::string xml  = gen.xml(500000);
    std::string json = gen.json(0, 6, lpsm::OBJECT);

    LIBXML_TEST_VERSION

    auto startJson = std::chrono::steady_clock::now();

    json_object* obj = json_tokener_parse(json.c_str());

    auto endJson = std::chrono::steady_clock::now();

    auto startXml = std::chrono::steady_clock::now();

    xmlDocPtr doc = xmlReadMemory(xml.c_str(),
                                  xml.size(),
                                  "noname.xml",
                                  NULL,
                                  XML_PARSE_HUGE);

    auto endXml = std::chrono::steady_clock::now();

    auto milliXml = std::chrono::duration_cast<std::chrono::milliseconds>(
            endXml - startXml);
    auto milliJson = std::chrono::duration_cast<std::chrono::milliseconds>(
            endJson - startJson);
    if (doc == NULL)
    {
        std::cerr << "Failed to parse XML\n";
        return -1;
    }
    std::cout << "Took " << milliXml.count() << " ms to parse XML\n";
    std::cout << "Took " << milliJson.count() << " ms to parse JSON\n";

    xmlFreeDoc(doc);
    return 0;
}
