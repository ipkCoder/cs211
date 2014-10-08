/*
 * File Name: main.cpp
 * File Purpose: main file for Linked list of families program
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: May 7, 2014
 * CS211 - Assignment 4
 * Purpose: Implement linked list structure to keep track of families
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */

#include <iostream>
using namespace std;

#include "Family.h"

int main()
{
  Family USAFamilies;
  USAFamilies.ReadTransactionFile();
  return 0;
} 
