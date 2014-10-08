/*
 * File Name: Faculty.h
 * File Purpose: Faculty class header file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: April 13, 2014
 * CS211 - Assignment 3
 * Purpose: Implement university administrative system
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 *
 * Inherits: Person class
 */
 
#ifndef Faculty_H
#define Faculty_H

#include <iostream>
using namespace std;

#include "Person.h"

class Person;

class Faculty: public Person
{
protected:
  float salary;
  int yearsOfExp;
  long deptID;
  static long nextFacultyID;
  
public:
  Faculty();
  Faculty(const string &fName, const string &fEmail, const string &fAddress,
          const string &birthday, const string &fGender, const float &fSalary,
          const int &years, const long &fDeptID);
  
  float getSalary();
  void setSalary(float fSalary);
  
  int getYearsOfExp();
  void setYearsOfExp(int years);
  
  long getDeptID();
  void setDeptID(long fDeptID);
  
  long getNextFacultyID();
  
  void print() const;
};

#endif

