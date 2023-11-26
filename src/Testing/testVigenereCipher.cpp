//! Unit Tests for MPAGSCipher VigenereCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"

TEST_CASE("Vigenere Cipher encryption", "[vigenere]") {
  VigenereCipher cc{"key"};
  REQUIRE( cc.applyCipher("test", CipherMode::Encrypt) == "DIQD");
}

TEST_CASE("Vigenere Cipher decryption", "[vigenere]") {
  VigenereCipher cc{"key"};
  REQUIRE( cc.applyCipher("diqd", CipherMode::Decrypt) == "TEST");
}