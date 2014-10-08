/***************************************************************************
 * File name: main.cpp
 * File purpose: main file for cryptography program
 * 
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: February 25, 2014
 * CS 211 - Assignment 1
 * Program purpose: encrypt or decrypt a message
 * Inputs: 1) name of file with message to be encrypted or decrypted
 *         2) encrypt or decrypt option (boolean)
 *         3) cryptography method
 *         4) if selected cryptography is: 
 *                - caeser cipher: shift count
 *                - cryptogram: name of file containing cryptogram string
 *         5) name of file to which encrypted or decrypted message 
 *            should be written 
 * Outputs: 1) file containing encrypted or decrypted message
 ***************************************************************************/

#ifndef Main_C
#define Main_C

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

#include "Cryptography.h"

class Cryptography;

// =========================================================================

int main(){

  // create Cryptography object
  Cryptography crypt;
  
  // get message to encrypt or decrypt
  crypt.collectMessage();

  // ask user whether to encrypt or decrypt
  crypt.encryptOrDecrypt();

  // ask user which method to use
  crypt.cryptographyMethod();

  // perform cryptography on message
  crypt.performCrypt();

  // print encrypted/decrypted message to screen
  crypt.printCrypted();

  // output encrypted/decrypted message to file
  crypt.outputToFile();

};

#endif // endif
