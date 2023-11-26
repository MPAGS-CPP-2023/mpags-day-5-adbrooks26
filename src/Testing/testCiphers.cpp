//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

bool testCipher(const Cipher& cipher, const CipherMode mode,const std::string& inputText, const std::string& outputText){
    if(cipher.applyCipher(inputText,mode) == outputText){
        return true;
    } else {
        return false;
    }
}

TEST_CASE("Caesar Cipher encryption", "[caesar]")
{
    CaesarCipher cc{10};
    REQUIRE(testCipher(cc,CipherMode::Encrypt,"Helloworld","ROVVYGYBVN") == true);
}

TEST_CASE("Caesar Cipher decryption", "[caesar]")
{
    CaesarCipher cc{10};
    REQUIRE(testCipher(cc,CipherMode::Decrypt,"rovvygybvn","HELLOWORLD") == true);
}

TEST_CASE("Playfair Cipher encryption", "[playfair]") {
    PlayfairCipher pfc{"hello"};
    REQUIRE(testCipher(pfc,CipherMode::Encrypt,"BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING","FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA") == true);
}

TEST_CASE("Playfair Cipher decryption", "[playfair]") {
  PlayfairCipher pfc{"hello"};
  REQUIRE(testCipher(pfc,CipherMode::Decrypt,"FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA","BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ") == true);
}

TEST_CASE("Vigenere Cipher encryption", "[vigenere]") {
  VigenereCipher vc{"key"};
  REQUIRE(testCipher(vc,CipherMode::Encrypt,"test","DIQD")==true);
}

TEST_CASE("Vigenere Cipher decryption", "[vigenere]") {
  VigenereCipher vc{"key"};
  REQUIRE(testCipher(vc,CipherMode::Decrypt,"diqd","TEST")==true);
}