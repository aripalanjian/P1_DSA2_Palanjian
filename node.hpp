#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

class Node{
    std::string userId = "";
    std::string password = "";
    std::string encrypted = "";
    Node* next = nullptr;
    Node* prev = nullptr;
    std::string generatePW();
public:
    Node(){};
    Node(std::string userId);
    Node(Node& nodeToCopy);
    ~Node();
    void setUserId(std::string userId);
    void setPassword();
    void setEncrypted(std::string encrypted);
    void setPrev(Node* prev);
    void setNext(Node* next);
    std::string getUserId();
    std::string getPassword();
    std::string getEncrypted();
    Node* getNext();
};

#endif