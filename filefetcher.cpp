#include "filefetcher.h"
#include <string>
#include <fstream>
#include <streambuf>

FileFetcher::FileFetcher(const std::string& path) : filePath(path)
{
    std::ifstream t(filePath);
    rawString = std::unique_ptr<std::string>{new std::string((std::istreambuf_iterator<char>(t)),
                                                             std::istreambuf_iterator<char>())};
}

std::string& FileFetcher::getRawString() const
{
    return *rawString;
}

const std::string& FileFetcher::getFilePath() const
{
    return filePath;
}
