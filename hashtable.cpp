/***************************************************************
  Student Name: Ari Palanjian
  File Name: hashtable.cpp
  Assignment number: Project 1

  HashTable function definitions
***************************************************************/
#include "hashtable.hpp" 
 
HashTable::HashTable(){
    table = new Node*[MAX_SIZE];
    for(int i = 0; i < MAX_SIZE; i++){
        table[i] = nullptr;
    }
}

HashTable::~HashTable(){
    for (int i = 0; i < MAX_SIZE; i++){
        Node* head = table[i];
        Node* next;
        while(head != nullptr){
            next = head->getNext();
            delete head;
            head = next;
        }
    }
    delete [] table;
}

void HashTable::insert(Node* user){
    int bucket = hash(user->getUserId());

    if (table[bucket] == nullptr){
        table[bucket] = user;
 
    } else {
        user->setNext(table[bucket]);
        table[bucket] = user;
    }
}

Node* HashTable::lookup(std::string userId){
    int bucket = hash(userId);
    Node* head = table[bucket];
    Node* checkedNode = head;
    while (checkedNode->getUserId() != userId){
        checkedNode = checkedNode->getNext();
        if (checkedNode == nullptr){
            std::cout << "Lookup Error: UserId: " << userId << " not found in bucket\n";
            return nullptr;
        }
    }

    return checkedNode;
}

int HashTable::hash(std::string userId){
    int idVal = 0;
    for (unsigned i = 0; i < userId.length(); i++){
        idVal += int(userId.at(i));
    }

    return idVal % (MAX_SIZE);
}

void HashTable::checkHashDistribution(){
    int max = 0;
    for (int i = 0; i < MAX_SIZE; i++){
        Node* head = table[i];
        int cnt = 0;
        if (head != nullptr){
            Node*current = head;
            cnt++;
            while(current->getNext() !=nullptr){
                current = current->getNext();
                cnt++;
            }
        }
        if (cnt>max){
            max = cnt;
        }
    }

    std::cout << "Max row size: " << max << std::endl;
}
