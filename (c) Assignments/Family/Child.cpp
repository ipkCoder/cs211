/*
 * File Name: Child.cpp
 * File Purpose: Child class implementation file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: May 7, 2014
 * CS211 - Assignment 4
 * Purpose: Implement linked list structure to keep track of families
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */

#include "Child.h"

//--------------------------------------------------------------------------------
/*
 * Default constructor
 */
Child::Child()
{
  sibling = NULL;
}
//--------------------------------------------------------------------------------
/*
 * Parameterized constructor
 *
 * @param: const long &SSN - child's social security number
 * @param: const string &first - child's first name
 * @param: const string &last - child's last name
 */
Child::Child(const long &SSN, const string &first, const string &last):
             Person(SSN, first, last)
{
  sibling = NULL;
}
//---------------------- Data Member (sibling) Getter ----------------------------
/*
 * Return next child in linked list of children
 */
Child *Child::getSibling()
{
  return sibling;
}
//---------------------- Data Member (sibling) Setter ----------------------------
/*
 * Set next child in linked list of children
 *
 * @param: Child* const &child - pointer to child to add to family
 */
void Child::setSibling(Child* const &child)
{
  sibling = child;
}
//--------------------------------------------------------------------------------
/*
 * This function prints a child's information.
 */
void Child::print() const
{
  cout << setw(20) << left << "Child"
       << setw(25) << left << (fName + " " + lName) // print full name
       << setw(20) << left << ssn << endl;
}
