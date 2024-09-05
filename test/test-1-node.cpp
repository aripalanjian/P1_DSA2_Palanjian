#include <iostream>
#include "../node.hpp"
#include "../vigniere.hpp"

void passwordTest(std::string pW){
    bool pWCheck =true;
    for (unsigned i = 0; i < pW.length(); i++){
        int charVal = int(pW.at(i));
        if ( (charVal < 97) || (charVal > 122) ){
            pWCheck = false;
            break;
        }
    }

    if (!pWCheck){
        std::cout << "Generated password: " << pW << " is not valid\n";
    } else {
        std::cout << "Generated password: " << pW << " is valid\n";
    }
}

void cypherTest(std::string password){
    std::cout << "\nCypher Test:\n";
    Vigniere cypher = Vigniere();
    std::string encrypted = cypher.encrypt(password);
    std::cout << "Encrypted Password: " << encrypted << std::endl;
    std::string decoded = cypher.decode(encrypted);
    std::cout << "Decoded Password: " << decoded << std::endl;
    if (decoded == password){
        std::cout << "Password is a match\n";
    } else {
        std::cout << "Password is a match\n";
    }
}

Node copyNodeTest(Node* testNode){
    std::cout << "\nCopy Node Test:\n";
    Node copyTest = Node(*testNode);
    testNode->setUserId("Ari2");
    std::cout << "Node1Copy: " << copyTest.getUserId() << " " << copyTest.getPassword() << std::endl;
    std::cout << "Node1NewName: " << testNode->getUserId() << " " << testNode->getPassword() << std::endl;
    std::cout << "Node1Copy: " << copyTest.getUserId() << " " << copyTest.getPassword() << std::endl;
    return copyTest;
}

void getNextTest(Node *testNode, Node *copyNode){
    if (testNode->getNext() == nullptr)
        std::cout << "Node before: " << testNode->getUserId() << " " << testNode->getPassword() << std::endl;
    std::cout << "Setting " << copyNode->getUserId() << " as next node..." << std::endl;
    testNode->setNext(copyNode);
    std::cout << "Node after: " << testNode->getUserId() << " " << testNode->getPassword() << " Next Node Id: " << testNode->getNext()->getUserId() << std::endl;

}

int main(){
    std::string title = std::string(20, '#') + " Test 1 Node Class " + std::string(20, '#');
    std::cout << title << "\n";

    Node testNode = Node();
    std::cout << "Initializing Test Node\n";
    testNode.setUserId("Ari");
    testNode.setPassword();

    passwordTest(testNode.getPassword());

    std::cout << "Node1: " << testNode.getUserId() << " " << testNode.getPassword() << std::endl;
    
    std::cout << std::string(title.size(), '-') << std::endl;
    Node copyNode(copyNodeTest(&testNode));

    std::cout << std::string(title.size(), '-') << std::endl;
    cypherTest(testNode.getPassword());

    std::cout << std::string(title.size(), '-') << std::endl;
    getNextTest(&testNode, &copyNode);

    return 0;
}