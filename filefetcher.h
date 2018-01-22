#ifndef FILEFETCHER_H
#define FILEFETCHER_H

#include <string>
#include <fstream>
#include <streambuf>
#include <memory>

class FileFetcher
{
public:
    explicit FileFetcher(const std::string& filePath);
    std::string& getRawString() const;
    const std::string& getFilePath() const;
private:
    const std::string filePath;
    std::unique_ptr<std::string> rawString;
};

#endif // FILEFETCHER_H
