#include "../persistance.hpp"
#include "../vigniere.hpp"
#include "../hashtable.hpp"
#include <cstdlib>
#include <sstream>

std::string readIDsAndEncryptedPWsTest(){
    std::cout << "\nRead Names File Test:\n";
    ReadFile readIDsAndPWs = ReadFile("test/testEncrypted.txt");
    if (readIDsAndPWs.getIdsAndPWs()){
        std::cout << "File successfully read.\n";
        return readIDsAndPWs.getData();
    } else {
        std::cout << "Error: Unable to read file.\n";
        return "";
    }
}

void iDsAndEncryptPWsToNodes(HashTable* table, std::string data){
    std::stringstream ss(data);
    std::string line;
    std::string name;
    std::string encrypted;
    Vigniere cypher = Vigniere();
    int cnt = 0;
    Node *node;
    while(std::getline(ss,line)){
        int partition = line.find(' ');
        name = line.substr(0,partition);
        encrypted = line.substr(partition);

        node =  new Node(name, encrypted);
        table->insert(node);
        cnt++;
    }
    std::cout << "Number of Nodes: " << cnt << std::endl;

}

int main() {
    HashTable userTable = HashTable();

    std::string data = readIDsAndEncryptedPWsTest();

    iDsAndEncryptPWsToNodes(&userTable, data);

    userTable.checkHashDistribution();

    /*
    TODO:
        Insert or checkHashDist function is not working properly
        Create = overload operator for Node*/
}