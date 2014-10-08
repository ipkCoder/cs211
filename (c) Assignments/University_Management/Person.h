/*
 * File Name: Person.h
 * File Purpose: Person class header file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: April 13, 2014
 * CS211 - Assignment 3
 * Purpose: Implement university administrative system
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */

#ifndef Person_h
#define Person_h

#include <iostream>
#include <string>
using namespace std;

class Person
{

protected:
  long id;
  string name;
  string email;
  string address;
  string dateOfBirth;
  string gender;
  
public:
  Person();
  Person(const long &pID, const string &pName, const string &pEmail,
         const string &pAddress, const string &birthday, const string &pGender);

  long getID() const;
  void setID(const long &pID);

  string getName() const;
  void setName(const string &pName);
  
  string getEmail() const;
  void setEmail(const string &pEmail);
  
  string getAddress() const;
  void setAddress(const string &pAddress);

  string getDateOfBirth() const;
  void setDateOfBirth(const string &birthday);

  string getGender() const;
  void setGender(const string &pGender);
  
  void print() const;
};

#endif
