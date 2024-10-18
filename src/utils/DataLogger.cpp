#include "DataLogger.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <filesystem>
#include <sstream>

DataLogger::DataLogger(const std::string& defaultFilePath)
    : filePath(defaultFilePath), headerWritten(false) {
    prepareFile(); // Ensure the file and header are ready at construction
}

void DataLogger::writeHeaderRow(const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        return;
    }
    if (!headerWritten) {
        file << "CommitID,Data\n";
        headerWritten = true;
    }
    file.close();
}

void DataLogger::logData(const std::string& currentCommit, const std::string& data) {
    std::ofstream file(filePath, std::ios::app); // Open file in append mode
    if (!file.is_open()) {
        std::cerr << "Error opening file " << filePath << std::endl;
        return;
    }
    file << currentCommit << "," << data << std::endl;
    file.close();
}

void DataLogger::prepareFile() {
    int counter = 1;
    std::string originalPath = filePath;
    // Check if the file already exists and modify the filename if it does
    while (std::filesystem::exists(filePath)) {
        filePath = originalPath + "-" + std::to_string(counter++) + ".csv";
    }
    // Write the header row if it's the first time creating the file
    writeHeaderRow(filePath);
}
