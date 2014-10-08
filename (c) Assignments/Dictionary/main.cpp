/*********************************************************************************
 * File name: main.cpp
 * File purpose: main file for dictionary program
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

#ifndef main_C
#define main_C

#include <iostream>
using namespace std;

#include "Dictionary.h"

//-----------------------------------------
int main(){

  Dictionary dict;
  dict.processTransactionFile();
  return 0;

};

#endif




