/*
 * File Name: University.h
 * File Purpose: University class header file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: April 13, 2014
 * CS211 - Assignment 3
 * Purpose: Implement university administrative system
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */
 
#ifndef University_H
#define University_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#include "Department.h"
#include "Faculty.h"
#include "Student.h"

class University
{
  
public:
	vector<Department> departments;
	vector<Student> students;
	vector<Course> courses;
	vector<Faculty> faculties;
	static bool failure;
	static bool success;
  
  
public:
	University();
	~University();
	
	bool createNewDepartment(string deptName, string deptLoc, long deptChairId);
	
  bool CreateNewStudent(string sName, string sEmail, string sAddress,
                        string sDateOfBirth, string sGender, int sYearOfStudy,
                        string sMajor, long sAdvisorId);
	
  bool CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
	
  bool CreateNewFaculty(string fName, string fEmail, string fAddress,
                        string fDateOfBirth, string fGender,
                        float fSalary, int fYearOfExp, long fDepId);
	
	bool ListCoursesTaughtByFaculty(long facultyId);
	bool ListCoursesTakenByStudent(long studentId);
	bool ListFacultiesInDepartment (long departId);
	bool ListStudentsOfAFaculty(long facultyId);
	bool ListCoursesOfADepartment(long departId);
	
  bool AddACourseForAStudent(long courseId, long stId);
	bool DropACourseForAStudent(long courseId, long stId);
	bool AssignDepartmentChair(long facultyId, long departId);
	bool AssignInstructorToCourse (long facultyId, long courseId);
	
	bool ListDepartments();
	bool ListStudents();
	bool ListCourses();
	bool ListFaculties();
  
  Department *validateDepartmentID(long id);
  Faculty *validateFacultyID(long id);
  Student *validateStudentID(long id);
  Course *validateCourseID(long id);
  bool validateMajor(const string &major);
	
	bool ProcessTransactionFile(string fileName);
  
  void printDepartmentChairs();
};

#endif 
