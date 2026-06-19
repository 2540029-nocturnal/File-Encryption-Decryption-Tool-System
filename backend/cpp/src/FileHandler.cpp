#include "../include/FileHandler.h"
#include <fstream>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

FileHandler::FileHandler() : current_file_path("") {}

bool FileHandler::fileExists(const std::string& filepath) {
    return fs::exists(filepath);
}

std::string FileHandler::readFile(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        return "";
    }
    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
    file.close();
    return content;
}

bool FileHandler::writeFile(const std::string& filepath, const std::string& content) {
    std::ofstream file(filepath);
    if (!file.is_open()) {
        return false;
    }
    file << content;
    file.close();
    return true;
}

bool FileHandler::deleteFile(const std::string& filepath) {
    try {
        return fs::remove(filepath) > 0;
    } catch (...) {
        return false;
    }
}

long long FileHandler::getFileSize(const std::string& filepath) {
    try {
        return fs::file_size(filepath);
    } catch (...) {
        return -1;
    }
}

std::string FileHandler::getFileExtension(const std::string& filepath) {
    size_t dot_pos = filepath.find_last_of('.');
    if (dot_pos != std::string::npos) {
        return filepath.substr(dot_pos);
    }
    return "";
}

std::string FileHandler::getFileName(const std::string& filepath) {
    size_t slash_pos = filepath.find_last_of("/\\");
    if (slash_pos != std::string::npos) {
        return filepath.substr(slash_pos + 1);
    }
    return filepath;
}

void FileHandler::setCurrentFile(const std::string& filepath) {
    current_file_path = filepath;
}

std::string FileHandler::getCurrentFile() const {
    return current_file_path;
}
