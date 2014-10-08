/***************************************************************************
 * File name: Cryptography.h
 * File purpose: Cryptography class interface
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

#ifndef Cryptography_H
#define Cryptography_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// =========================================================================

class Cryptography{

private:

  // ------------------- Attributes ---------------------

  bool encrypt;                  // encrypt or decryp message
  string method;                 // name or cryptography method
  int shift;                     // amount to shift letter by in ceaser cipher
  string cryptogramString;       // string to use in cryptogram method
  vector<string> inputMessage;   // vector to hold words in message
  vector<string> outputMessage;  // vector to hold encrypted/decrypted words

public:

  // -------------------- Methods -----------------------

  // default constructor
  Cryptography();
    
  // get file name from user, error check input
  string getInputFileName();

  // read message from input file to vector inputMessage
  void collectMessage();

  // ask user whether they want to encrypt/decrypt message
  void encryptOrDecrypt();

  // get name of cryptography method from user
  void cryptographyMethod();

  // get shift count from user
  void getShift();

  // get cryptogram string from user
  void getCryptString();

  // encrypt word using caeser cipher
  string caeserEncryptWord(string word);
  
  // decrypt word using caeser cipher
  string caeserDecryptWord(string word);
  
  // encrypt message using caeser cipher
  void caeserEncrypt();
  
  // decrypt message using caeser cipher
  void caeserDecrypt();
  
  // encrypt word using cryptogram method
  string cryptogramEncryptWord(string word);
  
  // decrypt word using cryptogram method
  string cryptogramDecryptWord(string word);
  
  // encrypt message using cryptogram method
  void cryptogramEncrypt();
  
  // decrypt message using cryptogram method
  void cryptogramDecrypt();
  
  // perform encryption/decryption on message
  void performCrypt();
  
  // output encrypted/decrypted message to a file
  void outputToFile();

  // print encrypted/decrypted message to screen
  void printCrypted() const;

};

#endif // endif
