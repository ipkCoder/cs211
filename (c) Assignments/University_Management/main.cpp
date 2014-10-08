/*
 * File Name: main.cpp
 * File Purpose: main file for university system program
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: April 13, 2014
 * CS211 - Assignment 3
 * Purpose: Implement university administrative system
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */

#include <string>
#include <iostream>
using namespace std;

#include "University.h"

//----------------------------------------------------------------------------
int main() 
{
	University csusm;
	csusm.ProcessTransactionFile("Transactions.txt");
};