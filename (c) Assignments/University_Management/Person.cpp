/*
 * File Name: Person.cpp
 * File Purpose: Person class implementation file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: April 13, 2014
 * CS211 - Assignment 3
 * Purpose: Implement university administrative system
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */
 
#include "Person.h"

//--------------------------------------------------------------------------------
/*
 * Default constructor
 */
Person::Person(): id(0), name("Unknown"), email("None"),
                  address("Unknown"), dateOfBirth("1/1/1990"), gender("Unknown")
{
};
//--------------------------------------------------------------------------------
/*
 * Constructor initializes Person data members
 *
 * @param: const long &pID - id number given to person
 * @param: const string &pName - name of person
 * @param: const string &pEmail - person's email address
 * @param: const string &pAddress - person's street address
 * @param: const string &birthday - person's date of birth
 * @param: const string &pGender - person's gender
 */
Person::Person(const long &pID, const string &pName, const string &pEmail,
               const string &pAddress, const string &birthday,
               const string &pGender)
{
  setID(pID);
  setName(pName);
  setEmail(pEmail);
  setAddress(pAddress);
  setDateOfBirth(birthday);
  setGender(pGender);
};
//----------------------- Data Member (id) Getter --------------------------------
long Person::getID() const
{
  return id;
};
//----------------------- Data Member (id) Setter --------------------------------
void Person::setID(const long &pID)
{
  id = pID;
};
//----------------------- Data Member (name) Getter ------------------------------
string Person::getName() const
{
  return name;
};
//----------------------- Data Member (name) Setter ------------------------------
void Person::setName(const string &pName)
{
  name = pName;
};
//----------------------- Data Member (email) Getter -----------------------------
string Person::getEmail() const
{
  return email;
};
//----------------------- Data Member (email) Setter -----------------------------
void Person::setEmail(const string &pEmail)
{
  email = pEmail;
};
//----------------------- Data Member (address) Getter ---------------------------
string Person::getAddress() const
{
  return address;
};
//----------------------- Data Member (adrress) Setter ---------------------------
void Person::setAddress(const string &pAddress)
{
  address = pAddress;
};
//--------------------- Data Member (dateOfBirth) Getter -------------------------
string Person::getDateOfBirth() const
{
  return dateOfBirth;
};
//--------------------- Data Member (dateOfBirth) Setter -------------------------
void Person::setDateOfBirth(const string &birthday)
{
  dateOfBirth = birthday;
};
//---------------------- Data Member (gender) Getter -----------------------------
string Person::getGender() const
{
  return gender;
};
//---------------------- Data Member (gender) Setter -----------------------------
void Person::setGender(const string &pGender)
{
  gender = pGender;
};
//--------------------------------------------------------------------------------
/*
 * Print all Person data member information
 */
void Person::print() const
{
  cout << "\nName:\t\t\t" << name << "\n"
       << "Date of Birth:\t\t" << dateOfBirth << "\n"
       << "Gender:\t\t\t" << gender << "\n"
       << "Address:\t\t" << address << "\n"
       << "Email:\t\t\t" << email << "\n"
       << "ID:\t\t\t" << id << endl;
};
//---------------------------- Test Main -----------------------------------------
/*
int main()
{
  Person p(12345, "Ian Kane", "k@csusm.edu", "1000 Hello St", "12/6/92", "Male");
  p.print();
  return 0;
};*/
