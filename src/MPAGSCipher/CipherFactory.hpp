#ifndef MPAGSCIPHER_CIPHERFACTORY_HPP
#define MPAGSCIPHER_CIPHERFACTORY_HPP

#include "Cipher.hpp"
#include "CipherType.hpp"

#include <memory>
#include <string>

/**
 * \file VigenereCipher.hpp
 * \brief Contains the declaration of the VigenereCipher class
 */

/**
 * \namespace CipherFactory
 * \brief Creates a unique instance of a given cipher using a supplied key
 * \param type The type of cipher we want to implement
 * \param key The key which we wish to use for the cipher
 */
namespace CipherFactory{
    std::unique_ptr<Cipher> makeCipher(const CipherType type,const std::string key);
}

#endif  //CIPHERFACTORY_HPP