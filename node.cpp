#include "node.hpp"
#include <cstdlib>

Node::Node(std::string userId, std::string password){
    this->userId = userId;
    this->password = password;
}

Node::Node(Node& nodeToCopy){
    this->userId = nodeToCopy.userId;
    this->password = nodeToCopy.password;
    this->next = nodeToCopy.next;
}

Node& Node::operator= (Node& nodeToCopy){
    if (this != &nodeToCopy){
        delete next;

        this->userId = nodeToCopy.userId;
        this->password = nodeToCopy.password;
        this->next = nodeToCopy.next;
    }

    return *this;
}

Node::~Node(){}

std::string Node::generatePW(){
    //97 to 122:a to z
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

void Node::setNext(Node* next){
    this->next = next;
}

std::string Node::getUserId(){
    return userId;
}

std::string Node::getPassword(){
    return password;
}

Node* Node::getNext(){
    return next;
}