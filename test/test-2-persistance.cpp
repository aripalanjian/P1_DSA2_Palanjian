#include "../persistance.hpp"
#include "../vigniere.hpp"
#include <cstdlib>
#include <sstream>


std::string generatePW(){
    //97 to 122:a to z
    std::string password = "";
    for (int i = 0; i < 9; i++){
        password += char(97 + ( rand() % (122 - 97) ));
    }

    return password;
}

std::string readInNamesTest(){
    std::cout << "\nRead Names File Test:\n";
    ReadFile readNames = ReadFile("names.txt");
    if (readNames.getNames()){
        std::cout << "File successfully read.\n";//Printing data...\n";
        // std::cout << readNames.getData() << std::endl;
    } else {
        std::cout << "Error: Unable to read file.\n";
    }
    
    //Debug
    // WriteFile storeNames("test/testNames.txt", readNames.getData());
    // storeNames.writeToFile();

    return readNames.getData();
}

void writeIDsAndPWs(std::string names){
    std::stringstream namesSS(names);
    std::string data = "";
    std::string name;

    while(namesSS >> name){
        data += name + " " + generatePW() + "\n";
    }
    WriteFile storePlain("test/testPlainText.txt", data);
    
    if (storePlain.writeToFile()){
        std::cout << "Data successfully stored.\n";
    } else {
        std::cout << "Error: Unable to write to file.\n";
    }
}

std::string readIDsAndPWsTest(){
    std::cout << "\nRead Names File Test:\n";
    ReadFile readIDsAndPWs = ReadFile("test/testPlainText.txt");
    if (readIDsAndPWs.getIdsAndPWs()){
        std::cout << "File successfully read.\n";
        return readIDsAndPWs.getData();
    } else {
        std::cout << "Error: Unable to read file.\n";
        return "";
    }
}

void writeIDsAndEncryptPWs(std::string plainData){
    std::stringstream ss(plainData);
    std::string name;
    std::string password;
    std::string encrypted;
    Vigniere cypher = Vigniere();

    while(ss >> name >> password){
        encrypted += name + " " + cypher.encrypt(password) + "\n";
    }

    WriteFile storeEncrypted("test/testEncrypted.txt", encrypted);
    if (storeEncrypted.writeToFile()){
        std::cout << "Data successfully stored.\n";
    } else {
        std::cout << "Error: Unable to write to file.\n";
    }
}

int main(){
    srand(time(0));//must call srand outside of function because calls are to close together

    std::string title = std::string(17, '#') + " Test 2 Persistance Class " + std::string(16, '#');
    std::cout << title << "\n";

    std::string names = readInNamesTest();

    std::cout << std::string(title.size(), '-') << std::endl;
    writeIDsAndPWs(names);

    std::cout << std::string(title.size(), '-') << std::endl;
    std::string data = readIDsAndPWsTest();

    std::cout << std::string(title.size(), '-') << std::endl;
    writeIDsAndEncryptPWs(data);

    return 0;
}