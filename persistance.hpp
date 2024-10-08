/***************************************************************
  Student Name: Ari Palanjian
  File Name: persistance.hpp
  Assignment number: Project 1

  Defines the classes ReadFile and Writefile.
***************************************************************/
#ifndef PERSISTANCE_HPP
#define PERSISTANCE_HPP

#include <iostream>

class ReadFile{
    std::string file;
    std::string data;
public:
    ReadFile(std::string file);
    ~ReadFile();
    bool getNames();
    bool getIdsAndPWs();
    std::string getData();
};

class WriteFile{
    std::string file;
    std::string data;
public:
    WriteFile(std::string file, std::string data);
    ~WriteFile();
    bool writeToFile();
};

#endif