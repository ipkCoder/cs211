/*
 * File Name: Husband.cpp
 * File Purpose: Husband class implementation file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: May 7, 2014
 * CS211 - Assignment 4
 * Purpose: Implement linked list structure to keep track of families
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */

#include "Husband.h"

/*
 * Default constructor
 */
Husband::Husband()
{
  nextFamily = NULL;
  wife = NULL;
}
//--------------------------------------------------------------------------------
/*
 * Parameterized constructor
 *
 * @param: const long &SSN - husband's social security number
 * @param: const string &first - husband's first name
 * @param: const string &last - husband's last name
 */
Husband::Husband(const long &SSN, const string &first, const string &last):
                 Person(SSN, first, last)
{
  nextFamily = NULL;
  wife = NULL;
}
//-------------------- Data Member (nextFamily) Getter --------------------------
/*
 * Return pointer to next family
 */
Husband* Husband::getNextFamily()
{
  return nextFamily;
}
//-------------------- Data Member (nextFamily) Setter --------------------------
/*
 * Set next family pointer to next family
 *
 * @param: Husband* const &family - pointer to husband of next family
 */
void Husband::setNextFamily(Husband* const &family)
{
  nextFamily = family;
}
//----------------------- Data Member (wife) Getter -----------------------------
/*
 * Return pointer to husband's wife
 */
Wife* Husband::getWife()
{
  return wife;
}
//----------------------- Data Member (wife) Setter -----------------------------
/*
 * Set wife pointer to husband's wife
 *
 * @param: Wife* const &hWife - pointer to wife of husband
 */
void Husband::setWife(Wife* const &hWife)
{
  wife = hWife;
}
//--------------------------------------------------------------------------------
/*
 * This function removes the wife and children from the family.
 */
bool Husband::removeWifeAndChildren()
{
  if(wife != NULL){
    wife->removeChildren();
    delete wife;
    wife = NULL;
    return true;
  }
  else{
    return false;
  }
}
//--------------------------------------------------------------------------------
/*
 * This function prints the name of each member in the family.
 */
void Husband::printFamily()
{
  cout << endl;
  
  // print self
  print();
  
  // print wife and children
  if(wife != NULL){
    wife->print();
    if(wife->getChildren() != NULL)
      wife->printChildren();
  }
}
//--------------------------------------------------------------------------------
/*
 * This function prints a husband's information.
 */
void Husband::print() const
{
  cout << setw(20) << left << "Husband"
       << setw(25) << left << (fName + " " + lName) // print full name
       << setw(20) << left << ssn << endl;
}


