#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

class Node{
    std::string userId = "";
    std::string password = "";
    Node* next = nullptr;
    std::string generatePW();
public:
    Node(){};
    Node(std::string userId);
    Node(std::string userId, std::string password);
    Node(Node& nodeToCopy);
    ~Node();
    void setUserId(std::string userId);
    void setPassword();
    void setNext(Node* next);
    std::string getUserId();
    std::string getPassword();
    Node* getNext();
};

#endif