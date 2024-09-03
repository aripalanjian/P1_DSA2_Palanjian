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

int main(){
    std::string title = std::string(20, '#') + " Test 1 Node Class " + std::string(20, '#');
    std::cout << title << "\n";

    Vigniere cypher = Vigniere();

    Node testNode = Node();
    std::cout << "Initialize Test Node Ari: \n";
    testNode.setUserId("Ari");
    testNode.setPassword();

    passwordTest(testNode.getPassword());
    std::string encrypted = cypher.encrypt(testNode.getPassword());
    std::cout << "Encrypted Password: " << encrypted << std::endl;
    std::cout << "Decoded Password: " << cypher.decode(encrypted) << std::endl;

    std::cout << "Node1: " << testNode.getUserId() << " " << testNode.getPassword() << std::endl;
    
    std::cout << std::string(title.size(), '-') << "\nCopy Node Test:\n";
    Node copyTest = Node(testNode);
    testNode.setUserId("Ari2");
    std::cout  << "Node1Copy: " << copyTest.getUserId() << " " << copyTest.getPassword() << std::endl;
    std::cout << "Node1NewName: " << testNode.getUserId() << " " << testNode.getPassword() << std::endl;
    std::cout  << "Node1Copy: " << copyTest.getUserId() << " " << copyTest.getPassword() << std::endl;
}