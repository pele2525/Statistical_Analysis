#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <string>
#include <memory>
#include "analyzedata.h"

static const char * _json_format =
    "{ \"%s\": {\n"
    "  \"windSpeed\": { \"mean\": %lf }\n"
    "} }\n"
;

class JsonParser
{
public:
    JsonParser(AnalyzeData& dataRef);
    std::string getJsonData(const char* date,double windSpeed);
    double getMeanWindSpeed() const;

    template< typename... argv >
    std::string stringf( const char* format, argv... args ) {
        const size_t SIZE = std::snprintf( NULL, 0, format, args... );
        std::string output;
        output.resize(SIZE);
        std::snprintf( &(output[0]), SIZE+1, format, args... );
        return std::move(output);
    }

private:
    AnalyzeData& data;
};

#endif // JSONPARSER_H
