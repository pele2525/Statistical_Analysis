#include "analyzedata.h"
#include <iostream>
#include <sstream>
#include <numeric>
#include <algorithm>

AnalyzeData::AnalyzeData(const std::string &stringPtr) : rawString(stringPtr) {}

void AnalyzeData::parseData(const std::string& inputDate)
{
    std::istringstream* iss = new std::istringstream(rawString);
    std::string line;
    while (std::getline(*iss, line))
    {
        std::vector<std::string> tmp;
        std::string date;
        std::string restOfTheData;
        std::stringstream ss(line);

        std::getline(ss, date, '\t');
        while (std::getline(ss, restOfTheData, '\t'))
        {
            tmp.push_back(restOfTheData);
        }

        if(date.find(inputDate) != std::string::npos)
        {
            double pairWind(atof((tmp.back()).c_str()));
            windSpeedVector.push_back(pairWind);
        }
    }
}

double AnalyzeData::calculateMean(const std::vector<double>& data)
{
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    double mean = sum / data.size();

    return mean;
}

double AnalyzeData::getMeanWindSpeed()
{
    return calculateMean(windSpeedVector);
}
