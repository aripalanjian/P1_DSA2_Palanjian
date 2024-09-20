/***************************************************************
  Student Name: Ari Palanjian
  File Name: viginiere.hpp
  Assignment number: Project 1

  Defines Vigniere class:
    Encrypts or decrpyts a string based on a key
***************************************************************/
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