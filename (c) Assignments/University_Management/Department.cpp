/*
 * File Name: Department.cpp
 * File Purpose: Department class implementation file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: April 13, 2014
 * CS211 - Assignment 3
 * Purpose: Implement university administrative system
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */
 
#include "Department.h"

//----------------------- Initialize Static Data Members -------------------------
long Department::nextDeptID = 100;
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
/*
 * Default constructor
 */
Department::Department(): id(nextDeptID), name("Unknown"), location("Unknown"), chairID(0)
{
  ++nextDeptID;
};
//--------------------------------------------------------------------------------
/*
 * Paramaterized constructor.
 *
 * @param: string dName - name of department
 * @param: string dLocation - location of department building
 * @param: long chairID - faculty id of department chair
 * @static: static long nextDeptID - id given to next new department
 */
Department::Department(string dName, string dLocation, long dChairID):
                       id(nextDeptID), name(dName), location(dLocation),
                       chairID(dChairID)
{
  ++nextDeptID;
};
//------------------------ Data Member (id) Getter -------------------------------
long Department::getID()
{
  return id;
};
//------------------------ Data Member (id) Setter -------------------------------
void Department::setID(long dID)
{
  id = dID;
};
//----------------------- Data Member (name) Getter ------------------------------
string Department::getName()
{
  return name;
};
//----------------------- Data Member (name) Setter ------------------------------
void Department::setName(string dName)
{
  name = dName;
};
//--------------------- Data Member (location) Getter ----------------------------
string Department::getLocation()
{
  return location;
};
//--------------------- Data Member (location) Setter ----------------------------
void Department::setLocation(string dLocation)
{
  location = dLocation;
};
//---------------------- Data Member (chairID) Getter ----------------------------
long Department::getChairID()
{
  return chairID;
};
//---------------------- Data Member (chairID) Setter ----------------------------
void Department::setChairID(long dChairID)
{
  chairID = dChairID;
};
//-------------------- Data Member (nextDeptID) Getter ---------------------------
long Department::getNextDeptID()
{
  return nextDeptID;
};
//--------------------------------------------------------------------------------
/*
 * Print all Department data member information.
 */
void Department::print()
{
  cout << "\nDept Name:\t\t" << name << "\n"
       << "Dept ID:\t\t" << id << "\n"
       << "Location:\t\t" << location << "\n"
       << "Chair ID:\t\t" << chairID << endl;
};
//------------------------ Test Main ---------------------------------------------
/*
int main()
{
  Department dept("Business", "Markstein", 12345);
  dept.print();
}*/