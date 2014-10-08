/*
 * File Name: Person.cpp
 * File Purpose: Person class implementation file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: May 7, 2014
 * CS211 - Assignment 4
 * Purpose: Implement linked list structure to keep track of families
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */

#include "Person.h"

//--------------------------------------------------------------------------------
/*
 * Default constructor
 */
Person::Person(): ssn(0), fName(""), lName("")
{
};
//--------------------------------------------------------------------------------
/*
 * Parameterized constructor
 *
 * @param: const long &SSN - person's social security number
 * @param: const string &first - person's first name
 * @param: const string &last - person's last name
 */
Person::Person(const long &SSN, const string &first, const string &last)
{
  ssn = SSN;
  fName = first;
  lName = last;
};
//----------------------- Data Member (ssn) Getter -------------------------------
/*
 * Return person's social security number
 */
long Person::getSSN() const
{
  return ssn;
};
//----------------------- Data Member (ssn) Setter -------------------------------
/*
 * Set person's social security number
 *
 * @param: const long &SSN - person's social security number
 */
void Person::setSSN(const long &SSN)
{
  ssn = SSN;
};
//----------------------- Data Member (fName) Getter -----------------------------
/*
 * Return person's first name
 */
string Person::getFirstName() const
{
  return fName;
};
//----------------------- Data Member (fName) Setter -----------------------------
/*
 * Set person's first name
 *
 * @param: const long &first - person's first name
 */
void Person::setFirstName(const string &first)
{
  fName = first;
};
//----------------------- Data Member (lName) Getter -----------------------------
/*
 * Return person's last name
 */
string Person::getLastName() const
{
  return lName;
};
//----------------------- Data Member (lName) Setter -----------------------------
/*
 * Set person's last name
 *
 * @param: const long &last - person's last name
 */
void Person::setLastName(const string &last)
{
  lName = last;
};
//--------------------------------------------------------------------------------
/*
 * This function prints the info of a person.
 *
 * @param: string familyRelation 
 *             - description of how person is related to a family
 *             - ex: "husband", "wife", "child", "cousin", ... 
 */
void Person::print(string familyRelation) const
{
  cout << setw(20) << left << familyRelation
       << setw(25) << left << (fName + " " + lName) // print full name
       << setw(20) << left << ssn << endl;
}

