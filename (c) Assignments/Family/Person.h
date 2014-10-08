/*
 * File Name: Person.h
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

#ifndef Person_h
#define Person_h

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Person
{

protected:
  long ssn;
  string fName;
  string lName;
  
public:
  Person();
  Person(const long &SSN, const string &firstName, const string &lastName);

  long getSSN() const;
  void setSSN(const long &SSN);

  string getFirstName() const;
  void setFirstName(const string &first);
  
  string getLastName() const;
  void setLastName(const string &last);
  
  void print(string familyRelation) const;

};

#endif
