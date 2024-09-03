#include "vigniere.hpp"

Vigniere::Vigniere(){}

Vigniere::Vigniere(std::string key){
    this->key = key;
}

std::string Vigniere::encrypt(std::string password){
    std::string encrypted = "";
    for (unsigned i = 0; i < password.length(); i++){
        int keyPos = 0;
        if (i > key.length()-1){
            keyPos = i - key.length();
        } else {
            keyPos = i;
        }

        int offset = int(key.at(keyPos)) - 97;
        int asciiValue = int(password.at(i)) + offset;
        
        if (asciiValue == 123){
            encrypted += ' ';
        } else if (asciiValue > 123) {
            int wrapValue = asciiValue - 123;
            asciiValue = 97 + wrapValue;
            encrypted += char(asciiValue);
        } else {
            encrypted += char(asciiValue);
        }
    }

    return encrypted;
}

std::string Vigniere::decode(std::string encrypted){
    std::string decoded = "";
    for (unsigned i = 0; i < encrypted.length(); i++){
        int keyPos = 0;
        if (i > key.length()-1){
            keyPos = i - key.length();
        } else {
            keyPos = i;
        }

        // TODO:
        //     Do opposite calculation 
        // int offset = int(key.at(keyPos)) - 97;
        // int asciiValue = int(password.at(i)) + offset;
        // if (asciiValue == 123){
        //     encrypted += ' ';
        // } else {
        //     encrypted += char(asciiValue);
        // }
    }
}