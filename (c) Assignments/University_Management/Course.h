/*
 * File Name: Course.h
 * File Purpose: Course class header file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: April 13, 2014
 * CS211 - Assignment 3
 * Purpose: Implement university administrative system
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */
 
#ifndef Course_H
#define Course_H

#include <iostream>
using namespace std;

class Course
{
protected:
  long CRN;
  int maxAvailableSeats;
  string name;
  long deptID;
  long assignedSeats;
  long isTaughtBy;
  static long nextCRN;
  
public:
  Course();
  Course(string cName, long cDeptID, int maxSeats, long teacher);
  
  long getCRN();
  
  int getMaxAvailableSeats();
  void setMaxAvailableSeats(int maxSeats);
  
  string getName();
  void setName(string cName);
  
  long getDeptID();
  void setDeptID(long cDeptID);
  
  long getAssignedSeats();
  void setAssignedSeats(long seats);
  
  long getIsTaughtBy();
  void setIsTaughtBy(long teacher);
  
  void print() const;
  
  void incrementAssignedSeats();
  void decrementAssignedSeats();
  bool checkAvailability();
  
};


#endif
