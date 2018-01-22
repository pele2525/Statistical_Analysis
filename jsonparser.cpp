#include "jsonparser.h"

JsonParser::JsonParser(AnalyzeData& dataRef) : data(dataRef)
{

}

std::string JsonParser::getJsonData(const char* date,double windSpeed)
{
    std::string JsonData = stringf(_json_format,date,windSpeed, 0.00);
    return std::move(JsonData);
}

double JsonParser::getMeanWindSpeed() const
{
    return data.getMeanWindSpeed();
}
