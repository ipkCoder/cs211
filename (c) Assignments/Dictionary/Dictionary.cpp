/*********************************************************************************
 * File name: Dictionary.cpp
 * File purpose: Dictionary class implementation file
 * 
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: March 22, 2014
 * CS 211 - Assignment 2
 * Program purpose: create dictionary, perform dictionary functionality
 * Inputs: 1) Transaction file
 *              - The transaction file contains a list of commands and 
 *                information about the command. The command is used to 
 *                determine which operation to perform on the dictionary.
 *                Valid operations include adding a word, deleting a word,
 *                searching for a word, inserting words from a file into the 
 *                dictionary, and printing a file from the dictionary. The
 *                information about the command is used to help process the
 *                the command. See function processTransaction() for 
 *                more info.
 * Outputs: 1) Results from transaction file are printed onto screen.
 ********************************************************************************/

#ifndef Dictionary_C
#define Dictionary_C

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "Dictionary.h"

//================================================================================

// initialize static data members
bool Dictionary::failure = false;
bool Dictionary::success = true;

//================================================================================
/*
 * Default constructor sets numOfWordsInFile array to zero.
 *
 * @attribute: vector<string> numOfWordsInFile[26]
 *     - each element in array represents how many words are in file 'i'
 *     - each file holds words beginning with a certain letter
 *     - ex: numOfWordsInFile[2] represents the file containing words
 *       with the letter C
 * @attribute: const int numOfEnglishLetters
 *     - number of letters in english alphabet
 * @attribute: const int maxWordsInDict
 *     - maximum number of words allowed in dictionary
 * @attribute: int totalWordsInDict - current number of word in dictionary
 * @attribute: const int maxWordsPerFile
 *     - maximum number of words allowed in each letter file
 */

Dictionary::Dictionary():
  numOfEnglishLetters(26),maxWordsInDict(10000),maxWordsPerFile(100),totalWordsInDict(0)
{
  // assign array numOfWordsInFile elements to zero
  int i;
  for(i = 0; i < numOfEnglishLetters; i++){
    numOfWordsInFile[i] = 0;
  }
};
//================================================================================
/*
 * Constructor sets maximum num of words in dictionary, letter files
 * and sets numOfWordsInFile[26] to 0.
 *
 * This function initializes maxWordsInDict and maxWordsPerFile to
 * values supplied in the parameters. Constructor also sets elements in
 * numOfWordsPerFile array to zero.
 *
 * @param: int dictMaxWords
 *     - maximum words allowed in dictionary
 *     - class attribute maxWordsInDict is initialized to this value
 * @param: int fileMaxWords
 *     - maximum words allowed in each first-letter file (A-Z)
 *     - class attribute maxWordsPerFile is initialized to this value
 * @attribute: vector<string> numOfWordsInFile[26]
 *     - each element in array represents how many words are in file 'i'
 *     - each file holds words beginning with a certain letter
 *     - ex: numOfWordsInFile[2] represents the file containing words
 *       with the letter C
 * @attribute: const int numOfEnglishLetters
 *     - number of letters in english alphabet
 * @attribute: const int maxWordsInDict
 *     - maximum number of words allowed in dictionary
 * @attribute: const int maxWordsPerFile
 *     - maximum number of words allowed in each letter file (A-Z)
 * @attribute: int totalWordsInDict - current number of word in dictionary
 */
Dictionary::Dictionary(int dictMaxWords, int fileMaxWords):
  numOfEnglishLetters(26),maxWordsInDict(dictMaxWords),maxWordsPerFile(fileMaxWords), totalWordsInDict(0)
{
  // assign array numOfWordsInFile elements to zero
  int i;
  for(i = 0; i < numOfEnglishLetters; i++){
    numOfWordsInFile[i] = 0;
  }
};
//================================================================================
/*
 * Add word to dictionary
 *
 * This function adds a word to the dictionary. Before doing so, the function
 * checks to see if the word alreadys exists in the dictionary. If the word
 * does not exist, the function checks to see if the maximum number of words
 * allowed in the appropriate file has already been reach. For example, if
 * the word to be added is 'apple', the file to add 'apple' to would be A.txt.
 * If there is already the maximum words for A.txt has been reached, then
 * 'apple' cannot be added. The function then checks to see if the maximum words
 * allowed in the dictionary has been reached. If so, the word cannot be added.
 * If all conditions are met, the word is added to the appropriate file and
 * the number of words in the file, and in the dictionary, is incremented by one.
 *
 * @param: string word - word to be added to dictionary
 * @local: string file - name of file to add 'word' to
 * @local: int index - index of file with first letter of 'word'
 * @local: bool wordExitsInDict - true if 'word' is already in dictionary,
 *                                else false
 * @attribute: int maxWordsPerFile - max words allowed for each each kind of
 *                                   first letter (A - Z) in dictionary
 * @attribute: int maxWordsInDict - max words allowed in dictionary
 * @attribute: int totalWordsInDict - current number of words in dictionary
 * @attribute: vector<string> numOfWordsInFile[26]
 *     - each element in array represents how many words are in file 'i'
 *     - each file holds words beginning with a certain letter
 *     - ex: numOfWordsInFile[2] represents the file containing words
 *           with the letter C
 * @return: returns true if word was added to dictionary, else false
 */
bool Dictionary::addWord(string word){

  // get file name to add 'word' to
  string file = getDictFileName(word);
  
  // get index of file with words beginning with first letter of 'word' 
  int index = word[0] - 'a';
  
  // check to see if maximum words in dictionary hasn't been met
  if(totalWordsInDict >= maxWordsInDict){
    cout << "Max words in dictionary has already been met." << endl;
    return failure;
  }
  
  // check to see if enough room in proper file for word
  if(numOfWordsInFile[index] >= maxWordsPerFile){
    cout << "Maximum words beginning with '" << word[0] << "' has been reached."
         << endl;
    return failure;
  }
  
  // search for word
  bool wordExistsInDict = searchForWord(word);
  
  // if word already exist in dictionary, return failure, else add word
  // to dictionary and update information
  if(wordExistsInDict){
    return failure;
  }
  else{
    // open output stream, append 'word' to end
    ofstream fout;
    fout.open(file.data(), fstream::app);
    fout << word << endl;
    // update counts
    ++numOfWordsInFile[index];
    ++totalWordsInDict;
    // return success
    return success;
  }
  
};
//================================================================================
/*
 * Search for word in dictionary.
 *
 * This funtion searches the appropriate file for 'word' to see if 'word' is in
 * dictionary.
 *
 * @param: string word - word to be added to dictionary
 * @local: string file - name of file to add 'word' to
 * @local: string wordInDict - temp placeholder for words collected from dictionary
 * @local: bool found - true if found 'word' in dictionary, else false
 * @return: function returns true if 'word' is in dictionary, else false
 */
bool Dictionary::searchForWord(string word){

  // get name of file that would have word in it
  string file = getDictFileName(word);
  
  // open stream
  ifstream fin;
  fin.open(file.data());

  // change first letter to lowercase
  //word[0] = tolower(word[0]);

  string wordInDict;
  bool found = false;
  
  // search for word
  while(fin >> wordInDict){
    // if word read from dictionary file is the same as 'word', set
    // found to true and stop searching
    if(wordInDict == word){
      found = true;
      break;
    }
  }

  // if word is in dictionary, return true, else false
  if(found)
    return success;
  else
    return failure;

};
//================================================================================
/*
 * Delete word from dictionary.
 *
 * This function deletes a word from the dictionary. Before doing so, the word is
 * is searched for in the appropriate file. If found, the word is removed from the
 * dictionary and the number of words in the file and in the dictionary is
 * decremented by one.
 *
 * @param: string word - word to be added to dictionary
 * @local: char firstLetter - uppercased first letter of 'word'
 * @local: string file - name of file to add 'word' to
 * @local: vector<string> wordsInDict - vector to hold words read from file
 * @local: bool found - true if 'word' was found, else false
 * @local: string wordInDict - temp placeholder for words collected from dictionary
 * @attribute: int totalWordsInDict - current number of words in dictionary
 * @attribute: vector<string> numOfWordsInFile[26]
 *     - each element in array represents how many words are in file 'i'
 *     - each file holds words beginning with a certain letter
 *     - ex: numOfWordsInFile[2] represents the file containing words
 *           with the letter C
 * @return: function returns true if 'word' was deleted, else false
 */
bool Dictionary::deleteWord(string word){

  // vector to hold words in dictionary 
  vector<string> wordsInDict;

  // get name of file that would have word in it
  string file = getDictFileName(word);

  // open stream
  ifstream fin;
  fin.open(file.data());
 
  if(fin){
    
    bool found = searchForWord(word);
    
    // if word is in ditionary
    if(found){
      // load all words except word to delete into wordsInDict
      string wordInDict;
      while(fin >> wordInDict){
        if(wordInDict != word){
          wordsInDict.push_back(wordInDict);
        }
      }
      // close ifstream, open ofstream, erase content in file
      fin.close();
      ofstream fout(file.data(), fstream::trunc);
      // put words, except word to delete, back into dictionary
      int i;
      for(i = 0; i < wordsInDict.size(); i++){
        fout << wordsInDict[i] << endl;
      }
      // find file index, decrement word counts
      --numOfWordsInFile[word[0] -'a'];
      --totalWordsInDict;
    
      return success;
    }
    else{
      cout << "'" << word << "' is not in dictionary." << endl;
      return failure;
    }
  }
  else{
    cout << "Unable to open file to delete word." << endl;
    return failure;
  }

};
//================================================================================
/*
 * Spell check words in a file.
 *
 * This function spell checks each word in a file. Each word in the file is
 * searched for in the dictionary. If the word is not found in the dictionary,
 * it is printed onto the screen.
 *
 * @param: string fileName - file containing words to spell check
 * @local: string wordInDict - temporary placeholder for words read from dictionary
 * @local: bool inDict - true if word is in dictionary, else false
 * @return: function returns true if file was opened and spell checked, else false
 */
bool Dictionary::spellCheck(const string &fileName)
{
  // open file input stream
  ifstream fin;
  fin.open(fileName.data());

  // if file found
  if(fin){

    cout << "\nMisspelled words in file\n"
            "-----------------------" << endl;
    
    // print mispelled words onto screen    
    string wordInDict;
    bool inDict;
    while(fin >> wordInDict){
      inDict = searchForWord(wordInDict);
      if(!inDict){
        cout << wordInDict << endl;
      }
    }
    cout << endl;
    return success;
  }
  else{
    cout << "Could not open file." << endl;
    return failure;
  }

};
//================================================================================
/*
 * Insert words into dictionary.
 *
 * This function attempts to add a set of words into the dictionary. The function'
 * takes in as input the name of a file containing words to add to the dictionary.
 * If the file is found, words are read from the file one by one. Each word is 
 * searched for in the dictionary before being added. If the word is not already
 * in the dictionary, it is added to the appropriate file (the file which holds
 * all the words beginning with the first letter.
 *
 * @param: string fileName - file containing words to spell check
 * @local: string wordInDict - temporary placeholder for words read from dictionary
 * @local: bool added - true if successfully added to dictionary, else false
 *                    - value determined from return value of function 
 *                      addWord(string word)
 * @return: function returns true if able to open fileName
 */
bool Dictionary::insertWordsIntoDict(const string &fileName){

  // open file input stream
  ifstream fin;
  fin.open(fileName.data());

  // if file found
  if(fin){
    // read words from file add to dictionary if not already there
    string wordInDict;
    bool added;
    while(fin >> wordInDict){
      added = addWord(wordInDict);
      //if(!added)
      //  cout << "Unable to add " << "'" << wordInDict << "'" << endl;
    }
    
    return success;
  }
  else{
    cout << "Unable to open file" << endl;
    return failure;
  }

};
//================================================================================
/*
 * Process transaction file
 *
 * This function processes a transaction file provided by the user. Inside the 
 * transaction file, each line should have a single word command and a single 
 * word about the command (info). Acceptable commands include AddW, DeleteW,
 * SearchW, SpellCheck, InsertF, and PrintF. The command AddW is used to insert
 * a word into the dictionary. The info about the command should be the word to 
 * add to the dictionary. The command DeleteW is used to delete a word from the
 * dictionary. The info about the command is the word to delete. The command
 * SearchWwill search the dictionary for a word (provided in command info). The 
 * command SpellCheck will use the dictionary to spell check words in a file. 
 * The command info should be the name of the file the user wants to spell check. 
 * The command InsertF is used to insert words from a file into the dictionary.
 * The command info should be the name of the file. This function will report 
 * onto screen the words that couldn't be added. Reasons include: couldn't open
 * file, word is already in dictionary, the maximum allowed words beginning with
 * the first letter of the word has been reached, or maximum words in dictionary 
 * has been reached. The PrintF command will print a file from the dictionary. 
 * There are 26 files in the dictionary, one for each letter in the alphabet. Each
 * file has the format '#.txt', where # is a capital letter. For example, to 
 * print the words beginning with 'a', provide the file name 'A.txt' as the 
 * command info.
 *
 * @local: string fileName - name of file, provided by user, to print from dictionary
 * @local: string command - command read from transaction file
 * @local: string info - information about the command (what to do with the command)
 * @local: bool processed - true if no problem processing command, else false 
 */
void Dictionary::processTransactionFile(){

  // ask user for transaction file
  string fileName;
  cout << "Enter transaction file name: ";
  cin >> fileName;

  ifstream fin;
  fin.open(fileName.data());

  // if able to open file, process commands
  if(fin){
    string command, info; 
    bool processed;
    // while able to read command and info, process command
    while(fin >> command >> info){
      // if command is to add a word, pass info to addWord function
      if(command == "AddW"){
        processed = addWord(info);
        if(processed)
          cout << "\nAdded " << "'" << info << "'" << " to dictionary" << endl;
        else
          cout << "\nUnable to add " << "'" << info << "'" << " to dictionary" << endl;
      }
      // if command is to delete a word, pass info to deleteWord function
      else if(command == "DeleteW"){
        processed = deleteWord(info);
        if(processed)
          cout << "Deleted '" << info << "'" << endl;
        else
          cout << "Unable to delete '" << info << "'" << endl;
      }
      // if command is to search for  word in dictionary, pass info to searchForWord function
      else if(command == "SearchW"){
        processed = searchForWord(info);
        if(processed)
          cout << "\n" << info << " was found" << endl;
        else
          cout << "\n" << info << " was not found" << endl;
      }
      // if command is to spell check a file, pass info (file name) to spellCheck function
      else if(command == "SpellCheck"){
        processed = spellCheck(info);
        if(!processed)
          cout << "\nUnable to spell check " << info << endl;
      }
      // if command is to insert words from a file into dictionary, pass info (file name)
      // into to insertWordsIntoDict function
      else if(command == "InsertF"){
        processed = insertWordsIntoDict(info);
        if(processed)
          cout << "\n" << info << " inserted into dictionary" << endl;
        else
          cout << "\nUnable to insert " << info << " into dictionary" << endl;
      }
      // if command is to print a file from dictionary, pass info (file name) into to 
      // printAFileFromDict function
      else if(command == "PrintF"){
        processed = printAFileInDict(info);
        if(!processed)
          cout << "\nUnable to print " << info << endl;
      }
      // if not a valid command, inform user
      else{
        cout << "\nInvalid command" << endl;
      }
    }
  }
  else{
    cout << "\nUnable to open " << fileName << endl;
  }

};
//================================================================================
/*
 * Print a file from dictionary.
 *
 * This function prints a file from the dictionary. There are a total of 26 files,
 * one for each letter of the alphabet. For example, the file A.txt contains all
 * the words beginning with the letter 'a'. Words are printed onto screen five
 *  words per line.
 *
 * @param: string fileName - name of dictionary file to print
 * @local: string wordInFile - temporary placeholder for word read from file
 * @return: function returns true if able to open file, else false
 */
bool Dictionary::printAFileInDict(string &fileName) const
{
  ifstream fin;
  fin.open(fileName.data());

  // if able to open file, read words from file and print onto screen
  if(fin){

    cout << "\n\nWords in " << fileName << '\n'
         << "------------------" << endl;

    string wordInFile;
    // while not finished reading file
    while(!fin.eof()){
      // attempt to read five words
      // for each word read, print onto one line of the screen
      int i;
      for(i = 0; i < 5; i++){
        // read word from file
        fin >> wordInFile;
        // if no problem reading in word, print onto screen
        if(fin.good()){
          cout << left << setw(18) << wordInFile;
        }
      }
      cout << endl; // move to next line
    }
    return success;
  }
  else{
    return failure;
  }

};
//================================================================================
/*
 * Get name of file containing 'word'
 *
 * This function returns the file name associate with the first letter of 'word'.
 * The first letter of the word determines the file name. Each letter in the 
 * alphabet has its own file. For example, if the word provided as the parameter
 * is 'apple', the function will return 'a.txt'. The first letter of the word is 
 * changed to lower case.
 *
 * @param: string word - word provided is used to determine name of file to return
 * @local - string fileName - name of file to return
 * @return: function returns name of file which would contain 'word'
 */
string Dictionary::getDictFileName(string &word)
{
  string file = "#.txt";
  word[0] = tolower(word[0]);
  file[0] = word[0];
 
  return file;
};


#endif

