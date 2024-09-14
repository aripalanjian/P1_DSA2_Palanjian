#ifndef PROCCONTROL_HPP
#define PROCCONTROL_HPP

#include "hashtable.hpp"
#include "vigniere.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

class ProcControl{
    HashTable* table;
    Vigniere cypher;
    std::string usersToCheck[5];
    std::string rawPW[5];

    std::string generatePW();
    std::string readInNames();
    void writeIDsAndPWs(std::string names);
    std::string readIDsAndPWs();
    void writeIDsAndEncryptPWs(std::string plainData);
    std::string readIDsAndEncryptedPWs();
    void iDsAndEncryptPWsToNodes(std::string data);
    void comparePasswords();
    void formatOutput(std::string userId, std::string raw, std::string encrypted , std::string result);
public:
    ProcControl();
    ~ProcControl();
    void run();
};

#endif