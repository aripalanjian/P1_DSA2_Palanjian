/***************************************************************
  Student Name: Ari Palanjian
  File Name: procControl.hpp
  Assignment number: Project 1

  Defines class ProcControl:
    This object calls methods from other objects to read and write users and passwords
  either raw or encrypted from or to a file. The processes stores the users id and password
  as a node in a hash table. The first five odd entries in the raw data is read from file
  and compared to the corresponding entries in the encrypted data to see check if
  passwords are a match. The original passwords are modified to show that the encryption 
  is accurate as the new comparison will not match.

***************************************************************/
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