/*
 * File Name: Family.h
 * File Purpose: Person class header file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: May 7, 2014
 * CS211 - Assignment 4
 * Purpose: Implement linked list structure to keep track of families
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */

#ifndef Family_H
#define Family_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Husband.h"
#include "Wife.h"
#include "Child.h"

class Family
{
protected:
  Husband *head;
  static bool success;
  static bool failure;

public:
  Family();
  ~Family();
  bool AddHusband(const long &SSN, const string &fName, const string &lName);
  bool RemoveHusband(const long &SSN);
  bool AddWife(const long &SSN, const string &fName, const string &lName,
               const long &husbandSSN);
  bool RemoveWife(const long &husbandSSN);
  bool AddAChild(const long &SSN, const string &fName, const string &lName,
                 const long &fatherSSN);
  bool RemoveAChild(const long &FatherSSN, const long &childSSN);
  bool PrintAFamily(const long &fatherSSN);
  void PrintAllFamilies();
  void ReadTransactionFile();
  Husband *searchForHusband(const long &SSN);

};

#endif
