#include "persistance.hpp"
#include <fstream>
#include <sstream>

ReadFile::ReadFile(std::string file){
    this->file = file;
}

ReadFile::~ReadFile(){}

bool ReadFile::getNames(){
    std::ifstream dataFile;
    dataFile.open(file);
    // std::cout << file << " attempting to open...\n";

    std::stringstream ss;
    std::string line;

    if (dataFile.is_open()){
        // std::cout << "File " << file << " is open.\n";
        std::string name;
        while(std::getline(dataFile,line)){
            ss.clear();
            ss.str(line);
            ss >> name;
            data += name + "\n";
        }
        dataFile.close();
        ss.clear();
        return true;
    }
    return false;
}

bool ReadFile::getIdsAndPWs(){
    std::ifstream dataFile;
    dataFile.open(file);
    // std::cout << file << " attempting to open...\n";

    std::string line;

    if (dataFile.is_open()){
        // std::cout << "File " << file << " is open.\n";

        std::string name;
        std::string password;
        while(std::getline(dataFile,line)){
            data +=line + "\n";
        }

        dataFile.close();
        return true;
    }
    return false;
}

std::string ReadFile::getData(){
    return data;
}

WriteFile::WriteFile(std::string file, std::string data){
    this->file = file;
    this->data = data;
}

WriteFile::~WriteFile(){

}

bool WriteFile::writeToFile(){
    std::stringstream ss(data);
    std::string line;
    std::ofstream outfile;
    outfile.open(file);

    if (outfile.is_open()){       
        
        while(std::getline(ss,line)){
            outfile << line << "\n";
        }

        outfile.close();
        return true;
    }
    return false;
}