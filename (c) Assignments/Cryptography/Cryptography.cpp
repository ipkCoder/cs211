/***************************************************************************
 * File name: Cryptography.cpp
 * File purpose: Cryptography class implementation file
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
          
#ifndef Cryptography_C
#define Cryptography_C

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

#include "Cryptography.h"

// =========================================================================

/**
 * Default constructor.
 *
 * This function initializes class attributes to default values.
 *
 * @attribute: bool encrypt - tells if user wants to encrypt/decrypt 
 * @attribute: string method - cryptography method selected
 * @attribute: int shift - class attribute representing how many times
 *                         to shift origLetter in the alphabet
 * @attribute: string cryptogramString - string used to encrypt letters in
 *                                       original message. Each letter in
 *                                       the string corresponds to letter
 *                                       in the alphabet.
 */
Cryptography::Cryptography(){
 
  encrypt = true;
  method = "";
  shift = 0;
  cryptogramString = "";

};
/**
 * Get input file name from user.
 *
 * This function gets the name of the file containing 
 * a message from the user. The file name is checked to see
 * if the file exists. If not able to find file, the user 
 * is again asked to provide a file name.
 * 
 * @local: string file - name of file containing message
 * @local: ifstream fin - file input stream
 * @return: string - return file name
 */
string Cryptography::getInputFileName(){

  string file;

  // get file name
  cin >> file;

  // open file
  ifstream fin;
  fin.open(file.data());

  // while cant locate file or won't open, ask again
  while(!fin){
    cout << "Not able to locate file. Please try again.: ";
    cin >> file;
    fin.open(file.data());
  }

  fin.close();

  return file;

};
/**
 * Collect message from file provided.
 * 
 * This function asks user to provide file name containing message.
 * Each word in the file is then put into a vector of type string.
 * 
 * @local: string file - file name containing message
 * @locak: ifstream fin - file input stream
 * @local: string temp - temporarily holds word from message
 * @attribute: vector<string> inputMessage - class attribute vector which 
 *                                 holds inputed message.
 */
void Cryptography::collectMessage(){

  string file;
  
  cout << "\nEnter file name with message to encrypt/decrypt: ";
  file = getInputFileName();

  // open file
  ifstream fin;
  fin.open(file.data());
  
  // read in and load into vector one word at a time
  string temp;
  while(fin >> temp){
    inputMessage.push_back(temp);
  }

  fin.close();

};
/**
 * Ask user whether they want to encrypt or decrypt a message.
 *
 * This function asks the user whether they want to encrypt,
 * by entering 1, or decrypt a message, by entering 0. 
 * If option selected is not a valid a input, the user is 
 * again asked to input a 1 or 0.
 * 
 * @local: bool valid - tells if user provided a valid input
 * @local: int option - user's choice whether to encrypt or decrypt
 * @attribute: bool encrypt - tells if user wants to encrypt/decrypt 
 */
void Cryptography::encryptOrDecrypt(){

  bool valid = false;
  int option = -1; 

  // ask user to encrypt or decrypt
  cout << "\nTo encrypt, enter 1.\n"
          "To decrypt, enter 0.\n"
          "Enter: ";

  // get input from user and check for validity
  do{
    
    // if invalid input, reprompt user for valid input and clear cin
    if(!(cin >> option)){
      cout << "Please enter a 1 or 0: ";
      cin.clear();
      cin.ignore(10000, '\n');
    }
    else{// else set valid to true
      valid = true;
    }

  }while(!valid);

  // if 1, set to encrypt, else decrypt
  if(option == 1)
    encrypt = true;
  else
    encrypt = false;

};
/**
 * Ask user for cryptography method. 
 *
 * This function asks the user a valid cryptography method.
 * If input not valid, the function continues to ask for
 * a valid method.
 *
 * @attribute: string method - cryptography method selected
 */
void Cryptography::cryptographyMethod(){

  // ask user for cryptography method, while not acceptable answer
  cout << endl;
  do{
    cout << "Which cryptography method would you like," 
            "'caeser' or 'cryptogram'?: ";
    cin >> method;
  }while((method != "caeser") && (method != "cryptogram"));

};
/**
 * Get shift count from user.
 *
 * This function asks user for a shift count. The number provided
 * is then mod by 26 to make the number an acceptable value.
 * 
 * @attribute: int shift - class attribute representing how many
 *                         times to shift a letter in the alphabet.
 */
void Cryptography::getShift(){
  
  // ask for shift
  cout << "\nEnter shift count: ";
  cin >> shift;

  // mod shift down to acceptable number range
  shift %= 26;

};
/**
 * Get cryptogram string from user.
 * 
 * This function asks the user for he name of the file
 * containing the cryptogram string and retrieves string
 * from file,.
 * 
 * @local: string file - the name of the file with cryptogram string
 * @local: ifstream fin - file input stream
 * @attribute: string cryptogramString -
 */
void Cryptography::getCryptString(){
  
  string file;

  // ask user for file name
  cout << "\nEnter file name containing cryptogram string: ";
  file = getInputFileName();

  // open file
  ifstream fin;
  fin.open(file.data());

  // read in cryptogram string
  fin >> cryptogramString; 

  fin.close();

};
/**
 * Encrypt word using caeser encryption method.
 *
 * This function loops around each letter in a word and changes the
 * letter by shifting the letter to the right in the alphabet. If 
 * shift causes the letter to pass 'z' or 'Z', based on capitalization 
 * of the letter, the shift continues at the start of the alphabet.
 *`
 * @param: string word - word to encrypt using rot method
 * @local: int origLetter - integer representation of original letter
 * @local: int cryptLetter - integer representation of encrypted letter
 * @attribute: int shift - class attribute representing how many times 
 *                         to shift origLetter in the alphabet
 * @return: string - return encrypted word
*/
string Cryptography::caeserEncryptWord(string word){

  int origLetter, cryptLetter;

  int i;
  for(i = 0; i < word.length(); i++){

    // store original letter as int and set to cryptLetter
    origLetter = (int) word[i];
    cryptLetter = origLetter;

    // if original letter was alphanumeric, add shift
    if(isalpha(word[i])){
      cryptLetter += shift;
      // if origLetter was lowercase and shift caused cryptLetter to 
      // exceed 'z', subtract 26 to move cryptLetter to propper position
      if((origLetter >= 'a') && (origLetter <= 'z'))
	if(cryptLetter > 'z')
	  cryptLetter -= 26;
      // if origLetter was uppercase and shift caused cryptLetter to
      // exceed 'Z', subtract 26 to move cryptLetter to propper position
      if((origLetter >= 'A') && (origLetter <= 'Z'))
	if(cryptLetter > 'Z')
	  cryptLetter -= 26;
    }

    // set letter to char and push back into word
    word[i] = (char) cryptLetter;
  }

  return word;

};
/**
 * Decrypt word using caeser decryption method.
 *
 * This function loops around each letter in a word and changes the
 * letter by shifting the letter to the left in the alphabet. If shift 
 * causes the letter to pass 'a' or 'A', based on capitalization of 
 * cryptLetter, the shift continues from the end of the alphabet.
 *`
 * @param: string word - word to decrypt using rot method
 * @local: int origLetter - integer representation of original letter
 * @local: int cryptLetter - integer representation of encrypted letter
 * @attribute: int shift - class attribute representing how many times 
 *                         to shift cryptLetter in the alphabet
 * @return: string - return decrypted word
*/
string Cryptography::caeserDecryptWord(string word){

  int origLetter, cryptLetter;

  int i;
  /// for each letter
  for(i = 0; i < word.length(); i++){

    // store original letter as int and set to origLetter
    cryptLetter = (int) word[i];
    origLetter = cryptLetter;

    // if original letter was alphanumeric, subtract shift
    if(isalpha(word[i])){
      origLetter -= shift;
      // if cryptLetter was lowercase and shift caused origLetter to drop 
      // below 'a', add 26 to move origLetter to proper position
      if((cryptLetter >= 'a') && (cryptLetter <= 'z'))
	if(origLetter < 'a')
	  origLetter += 26;
      // if cryptLetter was uppercase and shift caused origLetter to drop
      // below 'A', add 26 to move cryptLetter to proper position
      if((cryptLetter >= 'A') && (cryptLetter <= 'Z'))
	if(origLetter < 'A')
	  origLetter += 26;
    }

    // set letter to char and push back into word
    word[i] = (char) origLetter;
  }

  return word;

};
/**
 * Encrypt message using caeser shift method.
 *
 * This function loops around each word in a message and encrypts the
 * word. 
 *`
 * @local: string encryptedWord - holds the encrypted word
 * @attribute: vector<string> inputMessage - class attribute vector that 
 *                                           holds original message
 * @attribute: vector<string> outputMessage - class attribute vector that 
 *                                            holds encrypted message
*/
void Cryptography::caeserEncrypt(){

  string encryptedWord;

  int i;
  // for each word
  for(i = 0; i < inputMessage.size(); i++){  
    // encrypt word using caeser method
    encryptedWord = caeserEncryptWord(inputMessage[i]);
    // add to vector
    outputMessage.push_back(encryptedWord);
  }

};
/**
 * Decrypt message using caeser shift method.
 *
 * This function loops around each word in a message and decrypts the
 * word. 
 *`
 * @local: string decryptedWord - holds the decrypted word
 * @attribute: vector<string> inputMessage - class attribute vector that 
 *                                           holds encrypted message
 * @attribute: vector<string> outputMessage - class attribute vector that 
 *                                            holds decrypted message
*/
void Cryptography::caeserDecrypt(){

  string decryptedWord;
  
  int i;
  // for each word
  for(i = 0; i < inputMessage.size(); i++){
    // decrypt word using caeser method
    decryptedWord = caeserDecryptWord(inputMessage[i]);
    // add to vector
    outputMessage.push_back(decryptedWord);
  }

};
/**
 * Encrypt word using cryptogram encryption method.
 *
 * This function loops around each letter in a word and changes the
 * letter with the corresponding letter in the cryptogram string provided.
 * Capitalization is considered.
 *`
 * @param: string word - word to encrypt using cryptogram method
 * @local: int origLetter - integer representation of original letter
 * @local: int cryptLetter - integer representation of encrypted letter
 * @local: int index - index of original letter in the alphabet
 * @attribute: string cryptogramString - string used to encrypt letters in
 *                                       original message. Each letter in 
 *                                       the string corresponds to letter 
 *                                       in the alphabet.
 * @return: string - return encrypted word
*/
string Cryptography::cryptogramEncryptWord(string word){

  char origLetter, cryptLetter;
  int index;

  int i;
  // for each letter
  for(i = 0; i < word.length(); i++){
    
    origLetter = word[i];

    // find index of letter in the alphabet
    index = tolower(origLetter) - 'a';
    
    // encrypt letter with corresponding letter in cryptogram string
    // if not alphanumeric, don't change
    if((origLetter >= 'a') & (origLetter <= 'z')){
      cryptLetter = cryptogramString[index];    
    }
    else if((origLetter >= 'A') & (origLetter <= 'Z')){
      cryptLetter = toupper(cryptogramString[index]);
    }
    else{
      cryptLetter = origLetter;
    }
    
    // put back encrypted letter
    word[i] = cryptLetter;
  }
  
  return word;

};
/**
 * Decrypt word using cryptogram decryption method.
 *
 * This function loops around each letter in a word and changes the
 * letter back to the original letter by finding the index of the 
 * encrypted letter in the cryptogram string provided. The index
 * represents the original letter character in the alphabet.
 * Capitalization is considered.
 *`
 * @param: string word - word to decrypt using cryptogram method
 * @local: int origLetter - integer representation of original letter
 * @local: int cryptLetter - integer representation of encrypted letter
 * @local: int index - index of encrypted letter in the cryptogram string
 * @attribute: string cryptogramString - string used to decrypt letters in
 *                                       encrypted message. Each letter in 
 *                                       the string corresponds to letter 
 *                                       in the alphabet.
 * @return: string - return decrypted word
*/
string Cryptography::cryptogramDecryptWord(string word){

  char origLetter, cryptLetter;
  int index;

  int i;
  // for each letter in the word
  for(i = 0; i < word.length(); i++){

    origLetter = word[i];

    // find index of origLetter in cryptogram string
    index = cryptogramString.find(tolower(origLetter), 0);

    // retrieve original letter, or punctuation if not a letter
    if((origLetter >= 'a') & (origLetter <= 'z')){
      cryptLetter = 'a' + index;
    }
    else if((origLetter >= 'A') & (origLetter <= 'Z')){
      cryptLetter = 'A' + index;
    }
    else{
      cryptLetter = origLetter;
    }

    // put back decrypted letter
    word[i] = cryptLetter;
  }

  return word;

};
/**
 * Encrypt message using cryptogram encryption method.
 *
 * This function loops around each word in a message and encrypts the
 * word. 
 *`
 * @local: string encryptedWord - holds the encrypted word
 * @attribute: vector<string> inputMessage - class attribute vector that 
 *                                           holds original message
 * @attribute: vector<string> outputMessage - class attribute vector that 
 *                                            holds encrypted message
*/
void Cryptography::cryptogramEncrypt(){

  string encryptedWord;

  int i;
  // for each word
  for(i = 0; i < inputMessage.size(); i++){
    // encrypt word using cryptogram method
    encryptedWord = cryptogramEncryptWord(inputMessage[i]);
    // add word to vector
    outputMessage.push_back(encryptedWord);
  }

};
/**
 * Decrypt message using cryptogram decryption method.
 *
 * This function loops around each word in a message and encrypts the
 * word. 
 *`
 * @local: string decryptedWord - holds the decrypted word
 * @attribute: vector<string> inputMessage - class attribute vector that 
 *                                           holds encrypted message
 * @attribute: vector<string> outputMessage - class attribute vector that 
 *                                            holds decrypted message
*/
void Cryptography::cryptogramDecrypt(){

  string decryptedWord;

  int i;
  // for each word
  for(i = 0; i < inputMessage.size(); i++){
    // decrypt word using cryptogram method
    decryptedWord = cryptogramDecryptWord(inputMessage[i]);
    // add word to vector
    outputMessage.push_back(decryptedWord);
  }

};
/**
 * Perform cryptography on message.
 * 
 * This function performs encryption or decryption on 
 * the message provided, using the cryptography method 
 * selected by the user.
 * 
 * @attribute: string method - cryptography method selected
 * @attribute: bool encrypt - tells if user wants to 
 *                            encrypt or decrypt message
 */
void Cryptography::performCrypt(){

  // if rot method selected
  if(method == "caeser"){
    // get shift number from user
    getShift();
    // encrypt or decrypt using rot method
    if(encrypt == true)
      caeserEncrypt();
    else
      caeserDecrypt();
  }
  else{// else cryptogram method selected
    // get cryptogram string from user
    getCryptString();
    // encrypt or decrypt using cryptogram method
    if(encrypt == true)
      cryptogramEncrypt();
    else
      cryptogramDecrypt();
  }

};
/**
 * Outputs encrypted or decrypted message to file.
 *
 * This function gets the name of the output file from the user
 * and writes the encrypted or decrypted message to the output 
 * file word by word.
 *
 * @local: string file - output file name
 * @local: ofstream fout - output file stream
 * @attribute: vector<string> outputMessage - class attribute vector which 
 *                                            holds encrypted/decrypted message
 */
void Cryptography::outputToFile(){

  string file;

  cout << "\nEnter output file name: ";
  cin >> file;

  // open output file
  ofstream fout;
  fout.open(file.data());

  // print to file one word at a time
  int i;
  for(i = 0; i < outputMessage.size(); i++)
    fout << outputMessage[i] << " ";

  fout.close();

  cout << endl;

};
/**
 * Print encrypted/decrypted message to screen.
 *
 * This function prints the encrypted/decrypted message to 
 * the screen.
 *
 * @attribute: vector<string> outputMessage - class attribute vector which 
 *                                            holds encrypted/decrypted message
 */
void Cryptography::printCrypted() const{

  // print message to screen one word at a time
  cout << "\nEncrypted/Decrypted Message\n"
            "---------------------------" << endl;
  int i;
  // print message word by word
  for(i = 0; i < outputMessage.size(); i++)
    cout << outputMessage[i] << " ";
  cout << endl;

};

#endif // endif
