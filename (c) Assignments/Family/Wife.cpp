/*
 * File Name: Wife.cpp
 * File Purpose: Wife class implementation file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: May 7, 2014
 * CS211 - Assignment 4
 * Purpose: Implement linked list structure to keep track of families
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */

#include "Wife.h"

//--------------------------------------------------------------------------------
/*
 * Default constructor
 */
Wife::Wife()
{
  children = NULL;
};
//--------------------------------------------------------------------------------
/*
 * Parameterized constructor
 *
 * @param: const long &SSN - wife's social security number
 * @param: const string &first - wife's first name
 * @param: const string &last - wife's last name
 */
Wife::Wife(const long &SSN, const string &first, const string &last):
           Person(SSN, first, last)
{
  children = NULL;
}
//--------------------------------------------------------------------------------
/*
 * This function adds a child to the family. The child is inserted at the of the
 * linked list of children. In order to i=add the child to the end of the list, 
 * the function checks whether the list is empty, if there is already one child,
 * or if there are more than one child. If there is no children in list, the 
 * child is added at the head of the list. If there is already one child, the 
 * the child is added after the first child. If there is more than one child in
 * the list, then the end of the list is searched for and the child is added at
 * the end.
 *
 * @param: Child* const &child - pointer to child to be added to list of children
 * @attribute: Child *children - head pointer to linked list of children   
 */
void Wife::addChild(Child* const &child)
{
  if(children == NULL){
    children = child;
  }
  else if(children->getSibling() == NULL){
    children->setSibling(child);
  }
  else{
    Child *curr = children;
    while(curr->getSibling() != NULL){
      curr = curr->getSibling();
    }
    curr->setSibling(child);
  }
}
//--------------------------------------------------------------------------------
/*
 * This function prints the names of all the children in the family.
 *
 * @attribute: Child *children - head pointer to linked list of children
 */
void Wife::printChildren()
{
  Child *child = children;
  
  while(child != NULL){
    child->print();
    child = child->getSibling();
  }
}
//--------------------------------------------------------------------------------
/*
 * Return linked list of children
 */
Child *Wife::getChildren()
{
  return children;
}
//--------------------------------------------------------------------------------
/*
 * This function removes a child from the linked list of children. The child is 
 * searched for using their social security number. To search the list and delete 
 * a child, two steps must be performed. The first step is to check if the first
 * chlid in the list is the child to be deleted. If not, then the rest of the 
 * list is searched. These two steps are necessary because they each require
 * different procedures to remove a child from the list.
 *
 * @param: const long &ssn - social security number associated with child 
 *                           to search for
 * @attribute: Child *children - head pointer to linked list of children
 */
bool Wife::removeChild(const long &ssn)
{
  if(children == NULL){
    return false;
  }
  
  // check if first child is to be removed
  if(children->getSSN() == ssn){
    Child *child = children;
    children = child->getSibling();
    delete child;
    return true;
  }
  
  // set current child to second child and previous child to first child
  Child *prevChild = children;
  Child *currChild = children->getSibling();
  
  // if child exists in the rest of the list of children, point previous
  // child's sibling pointer to the child after the child to be deleted
  while(currChild != NULL){
    if(currChild->getSSN() == ssn){
      prevChild->setSibling(currChild->getSibling());
      break;
    }
    else{
      prevChild = currChild;
      currChild = currChild->getSibling();
    }
  }
  
  // if child found, delete child and return true, else false
  if(currChild != NULL){
    delete currChild;
    return true;
  }
  else{
    return false;
  }
}
//--------------------------------------------------------------------------------
/*
 * This function removes all children from a family. 
 *
 * @attribute: Child *children - head pointer to linked list of children
 */
void Wife::removeChildren()
{
  Child *child = children;
  Child *temp = NULL;
  
  while(child != NULL){
    temp = child;
    child = child->getSibling();
    delete temp;
  }
  
  children = NULL;
}

/*
 * This function searches for a child in a family by searching for the child's 
 * social security number in the linked list of children. 
 *
 * @return: true if child's social security number is found, else false
 */
bool Wife::searchForChild(const long &ssn)
{
  Child *curr = children;
  bool found = false;
  
  while(curr != NULL){
    if(curr->getSSN() == ssn){
      found = true;
      break;
    }
    else
      curr = curr->getSibling();
  }
  
  return found;
}
//--------------------------------------------------------------------------------
/*
 * This function prints a wife's information.
 */
void Wife::print() const
{
  cout << setw(20) << left << "Wife"
       << setw(25) << left << (fName + " " + lName) // print full name
       << setw(20) << left << ssn << endl;
}

