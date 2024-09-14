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
    // Node* head = table[bucket];

    if (table[bucket] == nullptr){
        table[bucket] = user;
        // std::cout << "Bucket " << bucket << " Head is null" << std::endl;
 
    } else {
        user->setNext(table[bucket]);
        table[bucket] = user;
        // std::cout << "New head: " << table[bucket]->getUserId() << ", next: " << table[bucket]->getNext()->getUserId() << std::endl;
        // std::cout << "Bucket " << bucket << " Head is not null" << std::endl;
    }

    // std::cout << "Inserting " << user->getUserId() << " into bucket " << bucket << std::endl;
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
            // std::cout << "Bucket " << i << ": " << cnt << " - " << current->getUserId() << std::endl;
            while(current->getNext() !=nullptr){
                current = current->getNext();
                cnt++;
                // std::cout << "Bucket " << i << ": " << cnt << " - " << current->getUserId() << std::endl;
            }
        }
        // std::cout << "Bucket " << i << ": " << cnt << std::endl;
        if (cnt>max){
            max = cnt;
        }
    }

    std::cout << "Max row size: " << max << std::endl;
}
