#include "Node.hpp"

Node::Node(std::string userId, std::string password){
    this->userId = userId;
    this->password = password;
}

Node::Node(Node& nodeToCopy){
    this->userId = nodeToCopy.userId;
    this->password = nodeToCopy.password;
    this->encrypted = nodeToCopy.encrypted;
    this->next = nodeToCopy.next;
    this->prev = nodeToCopy.prev;
}

Node::~Node(){
    delete this;
}

void Node::setPassword(std::string password){
    this->password = password;
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
    return password;
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