/*
 * File Name: Child.h
 * File Purpose: Child class header file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: May 7, 2014
 * CS211 - Assignment 4
 * Purpose: Implement linked list structure to keep track of families
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */

#ifndef Child_H
#define Child_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Person.h"

class Person;

class Child: public Person
{
protected:
  Child *sibling;
  
public:
  Child();
  Child(const long &SSN, const string &first, const string &last);
  void setSibling(Child* const &child);
  Child *getSibling();
  void print() const;
};

#endif

