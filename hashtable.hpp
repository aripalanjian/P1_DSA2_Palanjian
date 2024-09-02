#ifndef HASTABLE_HPP
#define HASHTABLE_HPP

#include "Node.hpp"

// prime number of buckets
//             -int hash(string) h = (string*key + val) % size

class HashTable{
    int size = 8803;
    Node* Table;
public:
    HashTable();
    ~HashTable();
    void insert(Node* user);
    Node* lookup(std::string userId);
    int hash(std::string);
};

#endif
