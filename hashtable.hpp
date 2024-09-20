/***************************************************************
  Student Name: Ari Palanjian
  File Name: hashtable.hpp
  Assignment number: Project 1

  Defines HashTable class
***************************************************************/

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#define MAX_SIZE 211

#include "node.hpp"

class HashTable{
    Node** table;
public:
    HashTable();
    ~HashTable();
    void insert(Node* user);
    Node* lookup(std::string userId);
    int hash(std::string userId);
    void checkHashDistribution();
};

#endif
