/*
 * File Name: Student.cpp
 * File Purpose: Student class implementation file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: April 13, 2014
 * CS211 - Assignment 3
 * Purpose: Implement university administrative system
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */
 
#include "Student.h"

//----------------------- Initialize Static Data Members -------------------------
long Student::nextStdID = 500;
//--------------------------------------------------------------------------------

/*
 * Default Constructor
 */
Student::Student(): Person(nextStdID, "Unknown", "None", "Unknown", "1/1/1990",
                           "Unknown")
{
  ++nextStdID;
};
//--------------------------------------------------------------------------------
/*
 * Paramaterized constructor
 *
 * @param: const string &sName - name of student
 * @param: const string &sEmail - student's email address
 * @param: const string &sAddress - student's street address
 * @param: const string &birthday - student's date of birth
 * @param: const string &sGender - student's gender
 * @param: const int &years - student's years of study
 * @param: const long &sAdvID - student's advisor id
 * @static: static long nextStdID - id number given to new student
 */
Student::Student(const string &sName, const string &sEmail,
                 const string &sAddress, const string &birthday,
                 const string &sGender, const int &years, const string &sMajor,
                 const long &sAdvID):
                 Person(nextStdID, sName, sEmail, sAddress, birthday, sGender)
                 // pass parameters to Person constructor
{
  setMajor(sMajor);
  setAdvisorID(sAdvID);
  setYearsOfStudy(years);
  ++nextStdID;
};
//----------------------- Data Member (major) Getter -----------------------------
string Student::getMajor()
{
  return major;
};
//----------------------- Data Member (major) Setter -----------------------------
void Student::setMajor(string sMajor)
{
  major = sMajor;
};
//--------------------- Data Member (advisorID) Getter ---------------------------
long Student::getAdvisorID()
{
  return advisorID;
};
//--------------------- Data Member (advisorID) Setter ---------------------------
void Student::setAdvisorID(long sAdvID)
{
  advisorID = sAdvID;
};
//-------------------- Data Member (yearsOfStudy) Getter -------------------------
int Student::getYearsOfStudy()
{
  return yearsOfStudy;
}
//-------------------- Data Member (yearsOfStudy) Setter -------------------------
void Student::setYearsOfStudy(int years)
{
  yearsOfStudy = years;
};
//--------------------------------------------------------------------------------
/*
 * This function adds a course to student's schedule.
 */
void Student::addCourse(Course *course)
{
  coursesTaken.push_back(*course);
};
//--------------------------------------------------------------------------------
/*
 * This function drops a course from students schedule. Before calling function, 
 * should use function checkToSeeIfCourseAlreadyTaken(long courseId), to make
 * sure student is taking course and course can be dropped.
 */
void Student::dropCourse(long courseId)
{
  int i;
  for (i = 0; i < coursesTaken.size(); i++) {
    if(coursesTaken[i].getCRN() == courseId){
      coursesTaken.erase(coursesTaken.begin() + i);
      break;
    }
  }
};
//--------------------------------------------------------------------------------
/*
 * Print all Student data member information (including data members inherited
 * from Person class.
 */
void Student::print() const
{
  Person::print();
  cout << "Years of Study:\t\t" << yearsOfStudy << "\n"
       << "Major:\t\t\t" << major << "\n"
       << "Advisor ID:\t\t" << advisorID << endl;
};
//--------------------------------------------------------------------------------
/*
 * For each course student is taking, print course name and id
 */
void Student::printCourses()
{
  int i;
  for (i = 0; i < coursesTaken.size(); ++i) {
    cout << setw(30) << left << coursesTaken[i].getName()
         << setw(30) << left << coursesTaken[i].getCRN() << endl;
  }
};
//--------------------------------------------------------------------------------
/*
 * Check to see if student is already taking a course. 
 * 
 * Before adding course to student's courses, need to check to make sure
 * he is not already taking the course. Don't want to sign him up for
 * same course twice.
 *
 * @param: long courseID - course number of course trying to add
 * @return: bool taken - true if courseID matches a course student is 
 *                       already taking, else false
 */
bool Student::checkToSeeIfCourseAlreadyTaken(long courseId)
{
  bool taken = false;
  
  int i;
  for (i = 0; i < coursesTaken.size(); i++) {
    if(coursesTaken[i].getCRN() == courseId){
      taken = true;
      break;
    }
  }
  
  return taken;
};
//------------------------ Test Main --------------------------------------------
/*
int main()
{
  Student stu("Ian Kane", "k@csusm.edu", "1000 Hello St", "12/6/92", "Male", 10,
              "Finance", 54321);
  stu.addCourse();
  stu.print();
  //stu.printCourses();
  
};*/