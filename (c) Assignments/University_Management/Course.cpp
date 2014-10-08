/*
 * File Name: Course.cpp
 * File Purpose: Course class implementation file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: April 13, 2014
 * CS211 - Assignment 3
 * Purpose: Implement university administrative system
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */

#include "Course.h"

//----------------------- Initialize Static Data Members -------------------------
long Course::nextCRN = 200;
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
/*
 * Default constructor
 */
Course::Course(): CRN(nextCRN), name("Unknown"), deptID(0),
                  maxAvailableSeats(100), assignedSeats(0), isTaughtBy(0)
{
  ++nextCRN;
};
//--------------------------------------------------------------------------------
/*
 * Paramaterized constructor
 *
 * @param: const string cName - name of course
 * @param: const long cDeptID - department that course is part of
 * @param: const int maxSeats - max available seats in course
 * @param: const long teacher - id of course instructor
 * @static: static long nextCRN - course number given to new course
 */
Course::Course(string cName, long cDeptID, int maxSeats, long teacher):
               CRN(nextCRN), name(cName), deptID(cDeptID),
               maxAvailableSeats(maxSeats), assignedSeats(0), isTaughtBy(teacher)
{
  ++nextCRN;
};
//------------------------ Data Member (CRN) Getter ------------------------------
long Course::getCRN()
{
  return CRN;
};
//------------------- Data Member (maxAvailableSeats) Getter ---------------------
int Course::getMaxAvailableSeats()
{
  return maxAvailableSeats;
};
//------------------- Data Member (maxAvailableSeats) Setter ---------------------
void Course::setMaxAvailableSeats(int maxSeats)
{
  maxAvailableSeats = maxSeats;
};
//------------------------ Data Member (name) Getter -----------------------------
string Course::getName()
{
  return name;
};
//------------------------ Data Member (name) Setter -----------------------------
void Course::setName(string cName)
{
  name = cName;
};
//----------------------- Data Member (deptID) Getter ----------------------------
long Course::getDeptID()
{
  return deptID;
};
//----------------------- Data Member (deptID) Setter ----------------------------
void Course::setDeptID(long cDeptID)
{
  deptID = cDeptID;
};
//-------------------- Data Member (assignedSeats) Getter ------------------------
long Course::getAssignedSeats()
{
  return assignedSeats;
};
//-------------------- Data Member (assignedSeats) Setter ------------------------
void Course::setAssignedSeats(long seats)
{
  assignedSeats = seats;
};
//---------------------- Data Member (isTaughtBy) Getter -------------------------
long Course::getIsTaughtBy()
{
  return isTaughtBy;
};
//---------------------- Data Member (isTaughtBy) Setter -------------------------
void Course::setIsTaughtBy(long teacher)
{
  isTaughtBy = teacher;
};
//--------------------------------------------------------------------------------
/*
 * Print all Course data member information.
 */
void Course::print() const
{
  cout << "\nCourse Name:\t\t" << name << "\n"
  << "Teacher ID:\t\t" << isTaughtBy << "\n"
  << "CRN:\t\t\t" << CRN << "\n"
  << "Dept ID:\t\t" << deptID << "\n"
  << "Max Seats:\t\t" << maxAvailableSeats << "\n"
  << "Assigned Seats:\t\t" << assignedSeats << endl;
};
//--------------------------------------------------------------------------------
/*
 * Increment assignedSeats by one. Use when add student to course.
 */
void Course::incrementAssignedSeats()
{
  ++assignedSeats;
};
//--------------------------------------------------------------------------------
/*
 * Decrement assignedSeats by one. Use when drop student from course.
 */
void Course::decrementAssignedSeats()
{
  --assignedSeats;
};
//--------------------------------------------------------------------------------
/*
 * Check to make sure there is at least one available seat left in the class.
 * 
 * @return: return true if assignedSeats is less than maxAvailableSeats 
 */
bool Course::checkAvailability()
{
  return assignedSeats < maxAvailableSeats;
};
//------------------------ Test Main ---------------------------------------------
/*
int main()
{
  Course course("CS211", 12345, 120, 105, 54321);
  course.print();
  return 0;
};*/