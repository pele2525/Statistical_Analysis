#ifndef ANALYZEDATA_H
#define ANALYZEDATA_H

#include "filefetcher.h"
#include <vector>
#include <memory>

class AnalyzeData
{
public:
    explicit AnalyzeData(const std::string& stringPtr);
    void parseData(const std::string& date);
    double calculateMean(const std::vector<double>& data);
    double getMeanWindSpeed();
private:
    const std::string& rawString;
    std::vector<double> windSpeedVector;
};

#endif // ANALYZEDATA_H
