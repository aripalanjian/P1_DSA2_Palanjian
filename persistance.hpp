#ifndef PERSISTANCE_HPP
#define PERSISTANCE_HPP

#include <iostream>

class ReadFile{
    std::string file;
    std::string data;
public:
    ReadFile(std::string file);
    ~ReadFile();
    void readFromFile();
};

class WriteFile{
    std::string file;
    std::string data;
public:
    WriteFile(std::string file);
    ~WriteFile();
    void writeToFile();
};

#endif