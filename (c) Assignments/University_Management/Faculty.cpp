/*
 * File Name: Faculty.cpp
 * File Purpose: Faculty class implementation file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: April 13, 2014
 * CS211 - Assignment 3
 * Purpose: Implement university administrative system
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */
 
#include "Faculty.h"

//----------------------- Initialize Static Data Members -------------------------
long Faculty::nextFacultyID = 600;
//--------------------------------------------------------------------------------

/*
 * Default constructor
 */
Faculty::Faculty(): salary(0), yearsOfExp(0), deptID(0), Person(nextFacultyID, "Unknown", "None", "Unknown", "1/1/1990", "Unknown")
{
  ++nextFacultyID;
};
//--------------------------------------------------------------------------------
/*
 * Paramaterized constructor
 *
 * @param: const string &fName - name of faculty member
 * @param: const string &fEmail - faculty member's email address
 * @param: const string &fAddress - faculty member's street address
 * @param: const string &birthday - faculty member's date of birth
 * @param: const string &fGender - faculty member's gender
 * @param: const float &fSalary - faculty member's salary
 * @param: const int &years - faculty member's years of experience
 * @param: const long &fDeptID - department number where faculty member works
 * @static: static long nextFacultyID - id number given to new faculty member
 */
Faculty::Faculty(const string &fName, const string &fEmail, const string &fAddress,
                 const string &birthday, const string &fGender,
                 const float &fSalary, const int &years, const long &fDeptID):
                 Person(nextFacultyID, fName, fEmail, fAddress, birthday, fGender)
                 // pass parameters to Person constructor
{
  setSalary(fSalary);
  setYearsOfExp(years);
  setDeptID(fDeptID);
  ++nextFacultyID;
};
//----------------------- Data Member (salary) Getter ----------------------------
float Faculty::getSalary()
{
  return salary;
};
//----------------------- Data Member (salary) Setter ----------------------------
void Faculty::setSalary(float fSalary)
{
  salary = fSalary;
};

//--------------------- Data Member (yearsOfExp) Getter --------------------------
int Faculty::getYearsOfExp()
{
  return yearsOfExp;
};
//--------------------- Data Member (yearsOfExp) Setter --------------------------
void Faculty::setYearsOfExp(int years)
{
  yearsOfExp = years;
};
//---------------------- Data Member (deptID) Getter -----------------------------
long Faculty::getDeptID()
{
  return deptID;
};
//---------------------- Data Member (deptID) Setter -----------------------------
void Faculty::setDeptID(long fDeptID)
{
  deptID = fDeptID;
};
//-------------------- Data Member (nextFacultyID) Getter ------------------------
long Faculty::getNextFacultyID()
{
  return nextFacultyID;
};
//--------------------------------------------------------------------------------
/*
 * Print all Faculty data member information (including data members inherited 
 * from Person class.
 */
void Faculty::print() const
{
  Person::print();
  cout << "Years of Exp:\t\t" << yearsOfExp << "\n"
       << "Dept ID:\t\t" << deptID << "\n"
       << "Salary:\t\t\t" << salary << endl;
};
//------------------------ Test Main --------------------------------------------
/*
int main()
{
  Faculty f(12345, "Ian Kane", "k@csusm.edu", "12/6/92", "Male", 50000, 10, 54321);
  f.print();
};*/

