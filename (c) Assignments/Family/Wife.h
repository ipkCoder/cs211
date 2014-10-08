/*
 * File Name: Wife.h
 * File Purpose: Wife class header file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: May 7, 2014
 * CS211 - Assignment 4
 * Purpose: Implement linked list structure to keep track of families
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */

#ifndef Wife_H
#define Wife_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Person.h"
#include "Child.h"

class Person;

class Wife: public Person
{
protected:
  Child* children;
  
public:
  Wife();
  Wife(const long &SSN, const string &fName, const string &lName);
  void addChild(Child* const &child);
  void printChildren();
  Child *getChildren();
  bool removeChild(const long &ssn);
  void removeChildren();
  bool searchForChild(const long &ssn);
  void print() const;
};

#endif

