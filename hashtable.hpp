#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#define MAX_SIZE 211

#include "Node.hpp"

// prime number of buckets
//             -int hash(string) h = (string*key + val) % size

class HashTable{
    // int size = 211;
    Node** table;
public:
    HashTable();
    ~HashTable();
    void insert(Node* user);
    // void insert(const Node& user);
    Node* lookup(std::string userId);
    int hash(std::string userId);
    void checkHashDistribution();
};

#endif
