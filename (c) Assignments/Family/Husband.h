/*
 * File Name: Husband.h
 * File Purpose: Husband class header file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: May 7, 2014
 * CS211 - Assignment 4
 * Purpose: Implement linked list structure to keep track of families
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */

#ifndef Husband_H
#define Husband_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Person.h"
#include "Wife.h"

class Person;
class Wife;

class Husband: public Person
{
protected:
  Husband* nextFamily;
  Wife* wife;

public:
  Husband();
  Husband(const long &SSN, const string &first, const string &last);
  void setNextFamily(Husband* const &husband);
  Husband *getNextFamily();
  void setWife(Wife* const &hWife);
  Wife* getWife();
  bool removeWifeAndChildren();
  void printFamily();
  void print() const;

};

#endif

