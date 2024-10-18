#ifndef DATALOGGER_HPP
#define DATALOGGER_HPP

#include <string>

class DataLogger {
public:
    DataLogger(const std::string& defaultFilePath);
    void writeHeaderRow(const std::string& filename);
    void logData(const std::string& currentCommit, const std::string& data);

private:
    void prepareFile();

    std::string filePath;
    bool headerWritten;
};

#endif // DATALOGGER_HPP
