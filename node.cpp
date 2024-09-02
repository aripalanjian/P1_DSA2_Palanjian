#include "node.hpp"
#include <cstdlib>

Node::Node(std::string userId){
    this->userId = userId;
    this->password = generatePW();
}

Node::Node(Node& nodeToCopy){
    this->userId = nodeToCopy.userId;
    this->password = nodeToCopy.password;
    this->encrypted = nodeToCopy.encrypted;
    this->next = nodeToCopy.next;
    this->prev = nodeToCopy.prev;
}

Node::~Node(){
}

std::string Node::generatePW(){
    //97 to 122
    //122 - 97
    srand(time(0));
    std::string password = "";
    for (int i = 0; i < 9; i++){
        password += char(97 + ( rand() % (122 - 97) ));
    }
    return password;
}

void Node::setUserId(std::string userId){
    this->userId = userId;
}

void Node::setPassword(){
    if (password == "")
        this->password = generatePW();
}

void Node::setEncrypted(std::string encrypted){
    this->encrypted = encrypted;
}

void Node::setPrev(Node* prev){
    this->prev = prev;
}

void Node::setNext(Node* next){
    this->next = next;
}

std::string Node::getUserId(){
    return userId;
}

std::string Node::getPassword(){
    return password;
}

std::string Node::getEncrypted(){
    return encrypted;
}

Node* Node::getNext(){
    return next;
}