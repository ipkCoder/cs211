/*
 * File Name: Family.cpp
 * File Purpose: manage linked list of families
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: May 7, 2014
 * CS211 - Assignment 4
 * Purpose: Implement linked list structure to keep track of families
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */

#include "Family.h"

bool Family::success = true;
bool Family::failure = false;

//--------------------------------------------------------------------------------
/*
 * Defacult constructor sets head of linked list of families to NULL.
 */
Family::Family()
{
  head = NULL;
};
//--------------------------------------------------------------------------------
/*
 * Default destructor deletes all families.
 */
Family::~Family()
{
  while(head != NULL){
    RemoveHusband(head->getSSN());
  }
}
//--------------------------------------------------------------------------------
/*
 * This function adds a new husband to the head of the linked list of families.
 *
 * @return: true if able to add husband, else false
 */
bool Family::AddHusband(const long &SSN, const string &fName, const string &lName)
{
  Husband* const foundHusband = searchForHusband(SSN);
  
  if(foundHusband != NULL){
    cout << "Husband with ssn " << SSN << " already exists." << endl;
    return failure;
  }
  
  Husband* const husband = new Husband(SSN, fName, lName);
  
  husband->setNextFamily(head);
  head = husband;
  return success;
}
//--------------------------------------------------------------------------------
/*
 * This function removes a husband from the list of families. In order to remove
 * the husband, the husband is seached for. If the husbnd is found, the husband
 * is removed from the list. Once removed, the husband's children and wife are
 * deleted, if they exist. When the children and wife no longer exist, the
 * husband is deleted.
 *
 * @return: true if able to remove husband, else false 
 */
bool Family::RemoveHusband(const long &SSN)
{
  if(head == NULL){
    return failure;
  }

  // check if first husband is to be deleted
  if(head->getSSN() == SSN){
    Husband *husband = head;
    head = husband->getNextFamily();
    husband->removeWifeAndChildren();
    delete husband;
    return success;
  }
  
  Husband *prevHusband = head;
  Husband *currHusband = head->getNextFamily();
  
  // check rest of list for husband
  // if husband exists, point previous husbands nextFamily pointer to husband
  // after husband to be deleted
  while(currHusband != NULL){
    if(currHusband->getSSN() == SSN){
      prevHusband->setNextFamily(currHusband->getNextFamily());
      break;
    }
    else{
      prevHusband = currHusband;
      currHusband = currHusband->getNextFamily();
    }
  }
  
  if(currHusband == NULL){
    cout << "\nCan't remove husband with ssn " << SSN
         << ". Husband doesn't exist." << endl;
    return failure;
  }
  
  currHusband->removeWifeAndChildren();
  delete currHusband;
  return success;
}
//--------------------------------------------------------------------------------
/*
 * This function adds a wife to a husband. The husbands social security number 
 * is used to search for the wife's husbnad. If the husband is found and the 
 * husband doesn't have a wife, the wife is added to the husband's family.
 *
 * @return: true if able to add wife, else false
 */
bool Family::AddWife(const long &SSN, const string &fName, const string &lName,
                     const long &husbandSSN)
{
  Husband* const husband = searchForHusband(husbandSSN);
  
  if(husband == NULL){
    cout << "\nCan't add wife. Husband with ssn " << husbandSSN
         << " doesn't exist" << endl;
    return failure;
  }
  
  if(husband->getWife() != NULL){
    cout << "Can't add wife to husband with ssn " << husbandSSN
         << ". Husband already has a wife." << endl;
    return failure;
  }
  
  Wife *wife = new Wife(SSN, fName, lName);
  husband->setWife(wife);
  return success;
}
//--------------------------------------------------------------------------------
/*
 * This function removes a wife from a husband. The husband is searched for by 
 * using his social security number. If the husband is found and a wife exists,
 * the children of the wife are deleted and then the wife is deleted.
 *
 * @return: true if able to remove wife, else false
 */
bool Family::RemoveWife(const long &husbandSSN)
{
  Husband* const husband = searchForHusband(husbandSSN);
  
  if(husband == NULL){
    cout << "\nCan't remove wife. Husband with ssn " << husbandSSN
         << " doesn't exist." << endl;
    return failure;
  }

  bool removed = husband->removeWifeAndChildren();

  if(!removed){
    cout << "\nCan't remove wife. Husband with ssn" << husbandSSN
         << " doesn't have a wife." << endl;
    return failure;
  }
  
  return success;
}
//--------------------------------------------------------------------------------
/*
 * This function adds a child to a family. If the father and mother exist and the 
 * child is not already part of the family, then the child is added to the family.
 *
 * @return: true if able to add child, else false
 */
bool Family::AddAChild(const long &SSN, const string &fName, const string &lName,
                       const long &fatherSSN)
{
  Husband* const father = searchForHusband(fatherSSN);
  
  if(father == NULL){
    cout << "\nCan't add child. Father with ssn " << fatherSSN
         << " doesn't exist" << endl;
    return failure;
  }
  
  Wife* const mother = father->getWife();
  
  if(mother == NULL){
    cout << "\nCan't add child. Mother does not exist." << endl;
    return failure;
  }
  
  bool foundChild = mother->searchForChild(SSN);
  
  if(foundChild){
    cout << "\nCan't add child with ssn " << SSN << ". Child with this ssn"
         << " already exists in family." << endl;
    return failure;
  }
  
  Child *child = new Child(SSN, fName, lName);
  mother->addChild(child);
  return success;
}
//--------------------------------------------------------------------------------
/*
 * This function removes a child from a family. To remove the child, the father
 * is searched for in the list of families. If the father/husband and wife exist,
 * then the child is removed from the family.
 *
 * @return: true if able to remove child, else false
 */
bool Family::RemoveAChild(const long &fatherSSN, const long &childSSN)
{
  Husband* const father = searchForHusband(fatherSSN);
  
  if(father == NULL){
    cout << "\nCan't remove child. Father with ssn " << fatherSSN
         << " doesn't exist." << endl;
    return failure;
  }
  
  Wife* const mother = father->getWife();

  if(mother == NULL){
    cout << "\nCan't remove child. Mother doesn't exist." << endl;
    return failure;
  }

  bool removed = mother->removeChild(childSSN);
  
  if(!removed){
    cout << "\nCan't remove child with ssn " << childSSN << ". Child with this"
         << " ssn doesn't exist." << endl;
    return failure;
  }
  
  return success;
}
//--------------------------------------------------------------------------------
/*
 * This function prints the members of one family. The family is searched for 
 * using the husband's social security number.
 *
 * @return: true if able to print family, else false
 */
bool Family::PrintAFamily(const long &fatherSSN)
{
  Husband* const husband = searchForHusband(fatherSSN);
  
  if(husband == NULL){
    cout << "\nCan't print family. Husband with ssn " << fatherSSN
         << " doesn't exist." << endl;
    return failure;
  }
  
  husband->printFamily();
  return success;
}
//--------------------------------------------------------------------------------
/*
 * This function prints all the families in the linked list. For each family, 
 * each member of the family has his/her name printed.
 */
void Family::PrintAllFamilies()
{ 
  Husband *currFamily = head;
  
  while(currFamily != NULL){
    currFamily->printFamily();
    currFamily = currFamily->getNextFamily();
  }
}

//--------------------------------------------------------------------------------
/*
 * This function reads a transaction file and executes each transaction. Each
 * transaction has a command and a list of information. The command represents 
 * the function to call. The list of information represents the parameters that
 * are required to execute the function.
 */
void Family::ReadTransactionFile()
{
  ifstream fin("transactions.txt");
  
  if(!fin){
    cout << "Error: Couldn't open file." << endl;
    return;
  }
  
  string command, fName, lName;
  long ssn, husbandSSN;
  
  while(fin >> command){
    if(command == "AddHusband"){
      fin >> ssn >> fName >> lName;
      AddHusband(ssn, fName, lName);
    }
    else if(command == "AddWife"){
      fin >> ssn >> fName >> lName >> husbandSSN;
      AddWife(ssn, fName, lName, husbandSSN);
    }
    else if(command == "AddAchild"){
      fin >> ssn >> fName >> lName >> husbandSSN;
      AddAChild(ssn, fName, lName, husbandSSN);
    }
    else if(command == "RemoveHusband"){
      fin >> ssn;
      RemoveHusband(ssn);
    }
    else if(command == "RemoveWife"){
      fin >> husbandSSN;
      RemoveWife(husbandSSN);
    }
    else if(command == "RemoveAchild"){
      fin >> husbandSSN >> ssn;
      RemoveAChild(husbandSSN, ssn);
    }
    else if(command == "PrintAFamily"){
      fin >> husbandSSN;
      PrintAFamily(husbandSSN);
    }
    else if(command == "PrintAllFamilies"){
      PrintAllFamilies();
    }
    else{
      cout << "Command " << command << " is not a valid command." << endl;
    }
  }
}
//--------------------------------------------------------------------------------
/*
 * This function searches for a husband in the linked list of families using
 * the social security number passed to the function. If the husband is found, 
 * then a pointer to the husband is returned, else NULL is returned.
 *
 * @param: long ssn - social security number of husband to search for
 */
Husband *Family::searchForHusband(const long &SSN)
{
  Husband *husband = NULL;
  Husband *curr = head;
  
  while(curr != NULL){
    if(curr->getSSN() == SSN){
      husband = curr;
      break;
    }
    else{
      curr = curr->getNextFamily();
    }
  }
  
  return husband;
}
//--------------------------------------------------------------------------------
/*
int main()
{
  Family usa;
  usa.AddHusband(12345, "Pat", "Smith");
  usa.AddHusband(23456, "John", "Smith");
  usa.AddHusband(34567, "Brian", "Smith");
  
  usa.AddWife(54321, "Wendi", "Smith", 12345);
  usa.AddWife(65432, "Sue", "Smith", 23456);
  usa.AddWife(76543, "Sharolin", "Smith", 34567);
  
  usa.AddAChild(11111, "Ian", "Smith", 12345);
  usa.AddAChild(22222, "Jacqueline", "Smith", 12345);
  usa.AddAChild(33333, "Weston", "Smith", 12345);
  
  usa.AddAChild(44444, "Johnny", "Smith", 23456);
  usa.AddAChild(22222, "Mary", "Smith", 23456);
  usa.AddAChild(33333, "Erin", "Smith", 23456);
  
  usa.PrintAllFamilies();
  cout << "-----------------------------------------------" << endl;
  
  usa.RemoveHusband(23456);
  usa.RemoveWife(34567);
  usa.RemoveAChild(12345, 22222);
  usa.PrintAllFamilies();
 
  usa.PrintAFamily(56789);
  usa.RemoveAChild(12345, 22222);
  usa.PrintAFamily(12345);
  usa.RemoveWife(12345);
  usa.PrintAFamily(12345);
}
*/