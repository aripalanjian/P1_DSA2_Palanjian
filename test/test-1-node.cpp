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

int main(){
    std::string title = std::string(20, '#') + " Test 1 Node Class " + std::string(20, '#');
    std::cout << title << "\n";

    Node testNode = Node();
    std::cout << "Initializing Test Node\n";
    testNode.setUserId("Ari");
    testNode.setPassword();

    passwordTest(testNode.getPassword());

    std::cout << "Node1: " << testNode.getUserId() << " " << testNode.getPassword() << std::endl;
    
    std::cout << std::string(title.size(), '-') << "\nCopy Node Test:\n";
    Node copyTest = Node(testNode);
    testNode.setUserId("Ari2");
    std::cout << "Node1Copy: " << copyTest.getUserId() << " " << copyTest.getPassword() << std::endl;
    std::cout << "Node1NewName: " << testNode.getUserId() << " " << testNode.getPassword() << std::endl;
    std::cout << "Node1Copy: " << copyTest.getUserId() << " " << copyTest.getPassword() << std::endl;

    std::cout << std::string(title.size(), '-') << "\nCypher Test:\n";
    cypherTest(testNode.getPassword());

    return 0;
}