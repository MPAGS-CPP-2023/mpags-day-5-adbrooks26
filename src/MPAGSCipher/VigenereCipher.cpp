#include "VigenereCipher.hpp"
#include "Alphabet.hpp"

#include <string>
#include <algorithm>
#include <iostream>

void VigenereCipher::setKey(const std::string& key){
    key_ = key;
    // Make sure the key is uppercase
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),::toupper);
    // Remove non-alphabet characters
    key_.erase(std::remove_if(std::begin(key_), std::end(key_),[](char c) { return !std::isalpha(c); }),std::end(key_));
    // Check if the key is empty and replace with default if so
    if(key_.size()==0){
        key_ = "KEY";
    }
    // loop over the key
    for(std::size_t i{0};i<key_.size();i++){
        // Find the letter position in the alphabet
        std::size_t letterpos{Alphabet::alphabet.find(key_[i])};
        // Create a CaesarCipher using this position as a key
        CaesarCipher cipher{letterpos};
        // Insert a std::pair of the letter and CaesarCipher into the lookup
        std::pair<char,CaesarCipher> p0{key_[i],cipher};
        charLookup_.insert(p0);
    }
    
}


VigenereCipher::VigenereCipher(const std::string& key){
    setKey(key);
}

std::string VigenereCipher::applyCipher( const std::string& inputText,const CipherMode cipherMode ) const {
    std::string outputText{""};
    // For each letter in input:
    for(std::size_t i{0};i<inputText.size();i++){
        std::string tempstring{""};
        tempstring += inputText[i];
        // Find the corresponding letter in the key,
        char corrletter{key_[i%key_.size()]};
        // repeating/truncating as required
        // Find the Caesar cipher from the lookup
        CaesarCipher corrcipher{charLookup_.at(corrletter)};
        // Run the (de)encryption
        std::string outputchar{corrcipher.applyCipher(tempstring,cipherMode)};
        // Add the result to the output
        outputText += outputchar;
    }

    return outputText;
}