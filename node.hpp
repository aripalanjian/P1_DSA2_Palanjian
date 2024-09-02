#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

class Node{
    std::string userId = "";
    std::string password = "";
    std::string encrypted = "";
    Node* next = nullptr;
    Node* prev = nullptr;
public:
    Node(){};
    Node(std::string userId, std::string password);
    Node(Node& nodeToCopy);
    ~Node();
    void setPassword(std::string password);
    void setEncrypted(std::string encrypted);
    void setPrev(Node* prev);
    void setNext(Node* next);
    std::string getUserId();
    std::string getPassword();
    std::string getEncrypted();
    Node* getNext();
};

#endif