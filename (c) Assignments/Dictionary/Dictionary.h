/********************************************************************************
 * File name: Dictionary.h
 * File purpose: Dictionary class interface file
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

#ifndef Dictionary_H
#define Dictionary_H

#include <iostream>
#include <string>
using namespace std;

class Dictionary{

protected:
  static bool failure;
  static bool success;
  const int numOfEnglishLetters;
  const int maxWordsInDict;
  const int maxWordsPerFile;
  int totalWordsInDict;
  int numOfWordsInFile[26];
  
public:
  Dictionary();
  Dictionary(int dictMaxWords, int fileMaxWords);
  bool addWord(string word);
  bool deleteWord(string word);
  bool searchForWord(string word);
  bool printAFileInDict(string &fileName) const;
  bool spellCheck(const string &fileName);
  bool insertWordsIntoDict(const string &fileName);
  void processTransactionFile();
  string getDictFileName(string &word);

};

#endif
