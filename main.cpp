#include <iostream>
#include "filefetcher.h"
#include "analyzedata.h"
#include "jsonparser.h"
#include <memory>

using namespace std;

int main(int argc, char *argv[])
{
    std::unique_ptr<FileFetcher> fd(new FileFetcher("Environmental_Data_Deep_Moor_2012.txt"));
    std::unique_ptr<AnalyzeData> dataAnalizator(new AnalyzeData(fd->getRawString()));
    dataAnalizator->parseData("2012_01_05");
    JsonParser* jsonParser = new JsonParser(*dataAnalizator);
    const std::string& output = jsonParser->getJsonData("2012_01_01",jsonParser->getMeanWindSpeed());
    std::cout << output << std::endl;
    return 0;
}
