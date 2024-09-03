#include "hashtable.hpp" 
 
HashTable::HashTable(){
    Table = new Node[size];
}

HashTable::~HashTable(){
    for (int i = 0; i < size; i++){
        Node* toDelete = &(Table[i]);
        while(toDelete != nullptr){
            toDelete = toDelete->getNext();
            delete &(Table[i]);
        }
    }
    delete [] Table;
}

void HashTable::insert(Node* user){
    int bucket = hash(user->getUserId());
    Node* head = &Table[bucket];
    if (head == nullptr){
        head = user;
    } else {
        user->setNext(head);
        Table[bucket] = *user;
        // Node* current = head;
        // Node* next = head->getNext();
        // while(next != nullptr){
        //     current = next;
        //     next = next->getNext();
        // }
        // current->setNext(user);
    }
}

Node* HashTable::lookup(std::string userId){
    int bucket = hash(userId);
    Node* head = &Table[bucket];
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
    for (int i = 0; i < userId.length(); i++){
        idVal += userId.at(i);
    }
    return idVal % size;
}

void HashTable::checkHashDistribution(){
    int max = 0;
    for (int i = 0; i < size; i++){
        Node* head = &(Table[i]);
        int cnt = 0;
        if (head != nullptr){
            Node*current = head;
            cnt++;
            while(current->getNext()!=nullptr){
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
