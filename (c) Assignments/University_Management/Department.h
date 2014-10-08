/*
 * File Name: Department.h
 * File Purpose: Department class header file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: April 13, 2014
 * CS211 - Assignment 3
 * Purpose: Implement university administrative system
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */
 
#ifndef Department_H
#define Department_H

#include <iostream>
#include <string>
using namespace std;

class Department
{
protected:
  long id;
  string name;
  string location;
  long chairID;
  static long nextDeptID;
  
public:
  Department();
  Department(string dName, string dLocation, long dChairID);
  
  long getID();
  void setID(long dID);
  
  string getName();
  void setName(string dName);
  
  string getLocation();
  void setLocation(string dLocation);
  
  long getChairID();
  void setChairID(long dChairID);
  
  long getNextDeptID();
  
  void print();
  
};

#endif