#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>
#include <vector>

class FileHandler {
private:
    std::string current_file_path;
    
public:
    FileHandler();
    ~FileHandler() = default;
    bool fileExists(const std::string& filepath);
    std::string readFile(const std::string& filepath);
    bool writeFile(const std::string& filepath, const std::string& content);
    bool deleteFile(const std::string& filepath);
    long long getFileSize(const std::string& filepath);
    std::string getFileExtension(const std::string& filepath);
    std::string getFileName(const std::string& filepath);
    void setCurrentFile(const std::string& filepath);
    std::string getCurrentFile() const;
};

#endif
