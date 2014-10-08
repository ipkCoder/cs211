/*
 * File Name: Student.h
 * File Purpose: Student class header file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: April 13, 2014
 * CS211 - Assignment 3
 * Purpose: Implement university administrative system
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 *
 * Inherits: Person class
 */
 
#ifndef Student_H
#define Student_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#include "Person.h"
#include "Course.h"

class Person;
class Course;

class Student: public Person
{
protected:
  int yearsOfStudy;
  string major;
  long advisorID;
  vector<Course> coursesTaken;
  static long nextStdID;
  
public:
  Student();
  Student(const string &sName, const string &sEmail, const string &sAddress,
          const string &birthday, const string &sGender, const int &years,
          const string &sMajor, const long &sAdvID);
  
  string getMajor();
  void setMajor(string sMajor);
  
  long getAdvisorID();
  void setAdvisorID(long sAdvID);
  
  int getYearsOfStudy();
  void setYearsOfStudy(int years);
  
  void addCourse(Course *course);
  void dropCourse(long courseID);
  bool checkToSeeIfCourseAlreadyTaken(long courseId);
  void print() const;
  void printCourses();
};

#endif 
