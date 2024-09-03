#ifndef VIGINIERE_HPP
#define VIGINIERE_HPP

#include <iostream>

class Vigniere{
    std::string key = "bashir";
public:
    Vigniere();
    Vigniere(std::string key);
    std::string encrypt(std::string password);
    std::string decode(std::string encrypted);
};

#endif