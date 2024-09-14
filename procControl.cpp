#include "procControl.hpp"
#include "persistance.hpp"
#include <cstdlib>

ProcControl::ProcControl(){
    table =  new HashTable();
    cypher = Vigniere();
    for(int i = 0; i < 5; i++){
        usersToCheck[i] = "";
        rawPW[i] = "";
    }
}

ProcControl::~ProcControl(){
    delete table;
}

std::string ProcControl::generatePW(){
    //97 to 122:a to z
    std::string password = "";
    for (int i = 0; i < 9; i++){
        password += char(97 + ( rand() % (122 - 97) ));
    }

    return password;
}

std::string ProcControl::readInNames(){
    ReadFile readNames = ReadFile("names.txt");
    readNames.getNames();
    // if (readNames.getNames()){
    //     std::cout << "File successfully read.\n";
    // } else {
    //     std::cout << "Error: Unable to read file.\n";
    // }

    return readNames.getData();
}

void ProcControl::writeIDsAndPWs(std::string names){
    std::stringstream namesSS(names);
    std::string data = "";
    std::string name;

    while(namesSS >> name){
        data += name + " " + generatePW() + "\n";
    }
    WriteFile storePlain("rawdata.txt", data);
    
    storePlain.writeToFile();
    namesSS.flush();
    // if (storePlain.writeToFile()){
    //     std::cout << "Data successfully stored.\n";
    // } else {
    //     std::cout << "Error: Unable to write to file.\n";
    // }
}

std::string ProcControl::readIDsAndPWs(){
    ReadFile readIDsAndPWs = ReadFile("rawdata.txt");
    if (readIDsAndPWs.getIdsAndPWs()){
        // std::cout << "File successfully read.\n";
        return readIDsAndPWs.getData();
    } else {
        // std::cout << "Error: Unable to read file.\n";
        return "";
    }
}

void ProcControl::writeIDsAndEncryptPWs(std::string plainData){
    std::stringstream ss(plainData);
    std::string name;
    std::string password;
    std::string encrypted;
    int count = 0;
    int i = 0;

    while(ss >> name >> password){
        if (count == 0 || count == 2 || count == 4 || count == 6 || count == 8){
            usersToCheck[i] = name;
            rawPW[i] = password;
            i++;
        }
        encrypted += name + " " + cypher.encrypt(password) + "\n";
        count++;
    }
    ss.flush();

    WriteFile storeEncrypted("encrypteddata.txt", encrypted);
    storeEncrypted.writeToFile();
    // if (storeEncrypted.writeToFile()){
    //     std::cout << "Data successfully stored.\n";
    // } else {
    //     std::cout << "Error: Unable to write to file.\n";
    // }
}

std::string ProcControl::readIDsAndEncryptedPWs(){
    ReadFile readIDsAndPWs = ReadFile("encrypteddata.txt");
    if (readIDsAndPWs.getIdsAndPWs()){
        // std::cout << "File successfully read.\n";
        return readIDsAndPWs.getData();
    } else {
        // std::cout << "Error: Unable to read file.\n";
        return "";
    }
}

void ProcControl::iDsAndEncryptPWsToNodes(std::string data){
    std::stringstream ss(data);
    std::string line;
    std::string name;
    std::string encrypted;

    int cnt = 0; 
    Node *node;
    while(std::getline(ss,line)){
        int partition = line.find(' ');
        name = line.substr(0,partition);
        encrypted = line.substr(partition+1);

        node = new Node(name, encrypted);
        table->insert(node);
        cnt++; 
        line = "";
    }
    ss.flush();

}

void ProcControl::comparePasswords(){
    using std::cout; using std::endl; using std::setw; using std::left;
    int width = 25;
    cout << setw(width) << left << "Userid";
    cout << setw(width) << "Password(file)";
    cout << setw(width) << "Password(table/un)";
    cout << setw(width) << left << "Result" << endl;

    for (int i = 0; i < 5; i++){
        Node *user = table->lookup(usersToCheck[i]);
        std::string id = user->getUserId();
        std::string pw = user->getPassword();
        std::string result = (cypher.encrypt(rawPW[i]) == user->getPassword()) ? "match" : "no match";
        formatOutput(usersToCheck[i], cypher.encrypt(rawPW[i]), pw, result);
        rawPW[i][0] = 'z';
    }

    cout << endl;

    cout << setw(width) << left << "Userid";
    cout << setw(width) << "Password(mod)";
    cout << setw(width) << "Password(table/un)";
    cout << setw(width) << left << "Result" << endl;

    for (int i = 0; i < 5; i++){
        Node *user = table->lookup(usersToCheck[i]);
        std::string result = (cypher.encrypt(rawPW[i]) == user->getPassword()) ? "match" : "no match";
        formatOutput(usersToCheck[i], cypher.encrypt(rawPW[i]), user->getPassword(), result);
    }
}

void ProcControl::formatOutput(std::string userId, std::string raw, std::string encrypted , std::string result){
    using std::cout; using std::endl; using std::setw; using std::left;
    int width = 25;

    cout << setw(width) << left << userId;
    cout << setw(width) << raw;
    cout << setw(width) << encrypted;
    cout << setw(width) << left << result << endl;
}

void ProcControl::run(){
    srand(time(0));//must call srand outside of function because calls are to close together

    writeIDsAndPWs(readInNames());

    writeIDsAndEncryptPWs(readIDsAndPWs());

    iDsAndEncryptPWsToNodes(readIDsAndEncryptedPWs());

    comparePasswords();
}