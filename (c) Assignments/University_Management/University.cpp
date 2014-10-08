/*
 * File Name: University.cpp
 * File Purpose: University class implementation file
 *
 * Author: Ian Kane
 * Email: kane010@cougars.csusm.edu
 * Completion Date: April 13, 2014
 * CS211 - Assignment 3
 * Purpose: Implement university administrative system
 * Inputs: transaction file for entries into program
 * Output: results of transactions
 */

#include "University.h"

bool University::failure = false;
bool University::success = true;

//----------------------------------------------------------------------------
University::University()
{
}
//----------------------------------------------------------------------------

University::~University()
{
}
//----------------------------------------------------------------------------
/*
 * This function adds a new department to the university. Before creating the
 * new department, the department chair id is validated. If the department 
 * chair id is 0, it means the chair id is not known yet and will be added
 * later. If the id is not 0, the id is compared against faculty ids to see 
 * if chair id is valid. If valid, a new department is created using the 
 * information provided in the parameter list.
 *
 * @param: string deptName - name of department
 * @param: string deptLoc - location name of department
 * @param: long deptChairID - department chair's id
 * @return: true if new department is successfully added to university,
 *          else false
 */
bool University::createNewDepartment(string deptName, string deptLoc,
                                     long deptChairID)
{
  if(deptChairID != 0){
    
    Faculty *const inFaculty = validateFacultyID(deptChairID);
    
    if(inFaculty == NULL){
      cout << "\nCould not create " << deptName << " department. Chair id "
           << deptChairID << " is not part of faculty." << endl;
      return failure;
    }
  }
  
  Department dept(deptName, deptLoc, deptChairID);
  departments.push_back(dept);
  
  return success;
};
//----------------------------------------------------------------------------
/*
 * This function adds a new student to the university. Before creating the
 * new student, the student's major is checked to see if it is a valid 
 * major offered at the university. If major is "0", then student has not 
 * declared major and major is not validated. The advisor id is also 
 * validated. If advisor id is "0", then student has not chosen an advisor
 * or does not need one, and advisor id is not validated. If student's major 
 * and advisor's id are both valid, a new student is created using the 
 * information provided in the parameter list.
 *
 * @param: const string &sName - name of student
 * @param: const string &sEmail - student's email address
 * @param: const string &sAddress - student's street address
 * @param: const string &birthday - student's date of birth
 * @param: const string &sGender - student's gender
 * @param: const int &sYearsOfStudy - student's years of study
 * @param: const long &sAdvID - student's advisor id
 * @return: true if new student is successfully added to university, 
 *          else false
 */
bool University::CreateNewStudent(string sName, string sEmail,
                                  string sAddress, string sDateOfBirth,
                                  string sGender, int sYearsOfStudy,
                                  string sMajor, long sAdvisorId)
{
  if(sMajor != "0"){
    
    bool validMajor = validateMajor(sMajor);
    
    if(!validMajor){
      cout << "\nCould not add " << sName << ". " << sMajor
           << " is not a valid major." << endl;
      return failure;
    }
  }
  
  if(sAdvisorId != 0){
    Faculty *const validAdvisor = validateFacultyID(sAdvisorId);
    
    if(validAdvisor == NULL){
      cout << "\nCould not add " << sName << ". Advisor ID " << sAdvisorId
           << " is not part of faculty." << endl;
      return failure;
    }
  }
  
  Student student(sName, sEmail, sAddress, sDateOfBirth, sGender,
                  sYearsOfStudy, sMajor, sAdvisorId);
  students.push_back(student);

  return success;
};
//----------------------------------------------------------------------------
/*
 * This function adds a new course to the university. Before creating the
 * new course, the course's teacher id is checked to see if it is a valid
 * faculty id. If teacher id is "0", then the course has not has not been 
 * assigned an instructor and the teacher id is not validated. The class's 
 * department id is also validated before creating a new course. If the 
 * teacher id and department id are both valid, a new course is created using 
 * the information provided in the parameter list.
 *
 * @param: const string cName - name of course
 * @param: const long cDeptID - department that course is part of
 * @param: const long cTaughtBy - id of course instructor
 * @param: const int maxSeats - max available seats in course
 * @return: true if new course is successfully added to university, else false
 */
bool University::CreateNewCourse(string cName, long cDeptId, long cTaughtBy,
                                 int cMaxSeats)
{
  if(cTaughtBy != 0){
    
    Faculty *const inFaculty = validateFacultyID(cTaughtBy);
    
    if(inFaculty == NULL){
      cout << "\nCould not create " << cName << " course. Faculty ID "
           << cTaughtBy << " is not part of faculty." << endl;
      return failure;
    }
  }
  
  Department *const validDept = validateDepartmentID(cDeptId);
    
  if(validDept == NULL){
    cout << "\nCould not create course " << cName << ". Department "
         << cDeptId << " is not a valid department." << endl;
    return failure;
  }
  
  Course course(cName, cDeptId, cMaxSeats, cTaughtBy);
  courses.push_back(course);
  
  return success;
};
//----------------------------------------------------------------------------
/*
 * This function adds a new faculty member to the university. Before creating
 * the new faculty member, the department id, to which the faculty is assigned,
 * is checked to see if it is a valid department id. If the department id is
 * valid, a new faculty member is is created using the information provided
 * in the parameter list.
 *
 * @param: const string &fName - name of faculty member
 * @param: const string &fEmail - faculty member's email address
 * @param: const string &fAddress - faculty member's street address
 * @param: const string &birthday - faculty member's date of birth
 * @param: const string &fGender - faculty member's gender
 * @param: const float &fSalary - faculty member's salary
 * @param: const int &years - faculty member's years of experience
 * @param: const long &fDeptID - department number where faculty member works
 * @return: true if new faculty is successfully added to university, 
 *          else false
 */
bool University::CreateNewFaculty(string fName, string fEmail,
                                  string fAddress, string fDateOfBirth,
                                  string fGender, float fSalary,
                                  int fYearOfExp, long fDeptId)
{
  Department *const validDept = validateDepartmentID(fDeptId);
    
  if(validDept == NULL){
    cout << "\nCould not add " << fName << " to faculty. Department "
         << fDeptId << " is not a valid department." << endl;
    return failure;
  }

  Faculty faculty(fName, fEmail, fAddress, fDateOfBirth, fGender,
                  fSalary, fYearOfExp, fDeptId);
  faculties.push_back(faculty);
  
  return success;
};
//----------------------------------------------------------------------------
/*
 * This function lists all the courses taught by a faculty member. For each
 * course, the course name and id are printed. Before printing, the faculty
 * member's id is validated to make sure the faculty members exists.
 *
 * @param: long facultyId - id of faculty member
 * @return: return true if faculty exists and able to print courses, 
 *          else false
 */
bool University::ListCoursesTaughtByFaculty(long facultyId)
{
  Faculty *const inFaculty = validateFacultyID(facultyId);
  
  if(inFaculty == NULL){
    cout << "\nCould not list courses. Faculty ID " << facultyId
         << " is not part of faculty." << endl;
    return failure;
  }
  
  // print header
  cout << "\nCourses taught by faculty " << facultyId << endl;
  cout << setw(30) << left << "\nCourse Name"
       << setw(30) << left << "Course ID" << endl;
  cout << "-------------------------------------------------------" << endl;
  
  // print only courses' name and id
  int i;
  for (i = 0; i < courses.size(); i++) {
    if(courses[i].getIsTaughtBy() == facultyId)
      cout << setw(30) << left << courses[i].getName()
           << setw(30) << left << courses[i].getCRN() << endl;
  }
  
  return success;
};
//----------------------------------------------------------------------------
/*
 * This function prints the name and id of all the courses taken by a 
 * particular student. Before printing the student's courses, the student's 
 * id is validated to make sure the student id provided is a valid student id.
 *
 * @param: long studentId - id of student
 * @return: return true if student id is valid and able to print courses,
 *          else false
 */
bool University::ListCoursesTakenByStudent(long studentId)
{
  Student *validStudent = validateStudentID(studentId);
  
  if(validStudent == NULL){
    cout << "\nCould not list courses. Student ID " << studentId
         << " is not a valid student ID." << endl;
    return failure;
  }
  
  // print header
  cout << "\nCourses taken by student " << studentId << endl;
  cout << setw(30) << left << "\nCourse Name"
       << setw(30) << left << "Course ID" << endl;
  cout << "-------------------------------------------------------" << endl;
  
  // print only courses' name and id
  int i;
  for (i = 0; i < students.size(); i++) {
    if(students[i].getID() == studentId){
      students[i].printCourses();
      break;
    }
  }
  
  return success;
};
//----------------------------------------------------------------------------
/*
 * This function prints the name and id of each faculty member in a particular
 * department of the university. Before printing faculty information, the 
 * department id is validated in order to make sure department exists.
 *
 * @param: long deptId - id of department
 * @return: return true if department id is valid and able to print faculty,
 *          else false
 */
bool University::ListFacultiesInDepartment (long deptId)
{
  Department *const validDept = validateDepartmentID(deptId);
  
  if(validDept == NULL){
    cout << "\nCould not list faculty. Dept ID " << deptId
         << " is not a valid department." << endl;
    return failure;
  }
  
  // print header
  cout << "\nFaculties in Department " << deptId << endl;
  cout << setw(30) << left << "\nFaculty Name"
       << setw(30) << left << "Faculty ID" << endl;
  cout << "-------------------------------------------------------" << endl;
  
  // print only faculties name and id
  int i;
  for (i = 0; i < faculties.size(); i++) {
    if(faculties[i].getDeptID() == deptId)
      cout << setw(30) << left << faculties[i].getName()
           << setw(30) << left << faculties[i].getID() << endl;
  }
  
  return success;
};
//----------------------------------------------------------------------------
/*
 * This function prints the name and id of all the students of a particular
 * faculty member. Before printing, the faculty id is validated in order
 * to make sure that the faculty member exists.
 *
 * @param: long facultyId - id of faculty member
 * @return: return true if faculty id is valid and able to print student 
 *          information, else false
 */
bool University::ListStudentsOfAFaculty(long facultyId)
{
  Faculty *inFaculty = validateFacultyID(facultyId);
  
  if(inFaculty == NULL){
    cout << "\nCould not list students. Faculty ID " << facultyId << " is not part of faculty."
         << endl;
    return failure;
  }
  
  // print header
  cout << "\nStudents of faculty " << facultyId << endl;
  cout << setw(30) << left << "\nStudent Name"
       << setw(30) << left << "Student ID" << endl;
  cout << "-------------------------------------------------------" << endl;
  
  // print only students' name and id
  int i;
  for (i = 0; i < students.size(); i++) {
    if(students[i].getAdvisorID() == facultyId)
      cout << setw(30) << left << students[i].getName()
           << setw(30) << left << students[i].getID() << endl;
  }

  return success;
};
//----------------------------------------------------------------------------
/*
 * This function prints the name and id of the courses in a particular 
 * department. Before printing the courses, the department id is validated 
 * in order to make sure the department exists.
 *
 * @param: long deptId - id of department 
 * @return: return true if department id is valid and able to course
 *          information, else false
 */
bool University::ListCoursesOfADepartment(long deptId)
{
  Department *const validDept = validateDepartmentID(deptId);
  
  if(validDept == NULL){
    cout << "\nCould not list courses. Dept ID " << deptId << " is not a valid department." << endl;
    return failure;
  }
  
  // print header
  cout << "\nCourses in Department " << deptId << endl;
  cout << setw(30) << left << "\nCourse Name"
       << setw(30) << left << "Course ID" << endl;
  cout << "-------------------------------------------------------" << endl;
  
  // print only courses' name and id
  int i;
  for (i = 0; i < courses.size(); i++) {
    if(courses[i].getDeptID() == deptId)
      cout << setw(30) << left << courses[i].getName()
           << setw(30) << left << courses[i].getCRN() << endl;
  }
  
  return success;
};
//----------------------------------------------------------------------------
/*
 * This function adds a course to a student's schedule. Before doing so, the
 * function checks that 1) the course id is valid, 2) student's id is valid, 
 * 3) there is a seat available in the course, and 4) the student is not 
 * already taking the course. If the student can be added to the course, the
 * number of assigned seats in the course is incremented by one and the
 * course is added to the student's schedule.
 *
 * @param: long courseId - id of course to add
 * @param: long studentId - id of student
 * @return: return true if course was successfully added, else false
 */
bool University::AddACourseForAStudent(long courseId, long studentId)
{ 
  Course *validCourse = validateCourseID(courseId);
  
  if(validCourse == NULL){
    cout << "\nCould not add course to students schedule. Course ID "
         << courseId << " is not a valid course ID." << endl;
    return failure;
  }

  Student *validStudent = validateStudentID(studentId);
  
  if(validStudent == NULL){
    cout << "\nCould not add course to students schedule. Student ID "
         << studentId << " is not a valid student ID." << endl;
    return failure;
  }
  
  bool courseTaken = validStudent->checkToSeeIfCourseAlreadyTaken(courseId);
  
  if(courseTaken){
    cout << "\nCould not add course to students schedule. Student "
         << studentId << " is already taking course " << courseId
         << "." << endl;
    return failure;
  }
  
  bool seatAvailable = validCourse->checkAvailability();
  
  if(!seatAvailable){
    cout << "\nCould not add course to students schedule. No available seats"
         << " in course " << courseId << "." << endl;
    return failure;
  }
  
  validCourse->incrementAssignedSeats();
  validStudent->addCourse(validCourse);
  
  return success;
  
};
//----------------------------------------------------------------------------
/*
 * This function drops a student from a course. Before doing so,  the
 * function checks that 1) the course id is valid, 2) student's id is valid,
 * and 3) the student is currently taking the course. If the course, student 
 * ids anre valid and the student i taking the course, the number of assigned
 * seats is decremented by one and the student is dropped from the course.
 *
 * @param: long courseId - id of course to drop
 * @param: long studentId - id of student
 * @return: return true if course was successfully dropped, else false
 */
bool University::DropACourseForAStudent(long courseId, long studentId)
{
  Course *validCourse = validateCourseID(courseId);
  
  if(validCourse == NULL){
    cout << "\nStudent " << studentId << " cannot drop course. Course ID "
         << courseId << " is not a valid course ID." << endl;
    return failure;
  }
  
  Student *validStudent = validateStudentID(studentId);
  
  if(validStudent == NULL){
    cout << "\nStudent " << studentId << " cannot drop course. Student ID "
         << studentId << " is not a valid student ID." << endl;
    return failure;
  }
  
  bool courseTaken = validStudent->checkToSeeIfCourseAlreadyTaken(courseId);
  
  if(!courseTaken){
    cout << "\nStudent " << studentId << " cannot drop course. Student "
         << studentId << " is not taking course " << courseId << "." << endl;
    return failure;
  }
  
  validCourse->decrementAssignedSeats();
  validStudent->dropCourse(courseId);
  
  return success;
};
//----------------------------------------------------------------------------
/*
 * This function assigns a faculty member to department chair. Before
 * assignment, both the faculty id and deparment id passed to the fiunction 
 * are validated.
 *
 * @param: long facultyId - id of faculty member
 * @param: long deptId - id of department 
 * @return: true if able to assign faculty to department chair, else false
 */
bool University::AssignDepartmentChair(long facultyId, long deptId)
{
  Faculty *const inFaculty = validateFacultyID(facultyId);
  
  if(inFaculty == NULL){
    cout << "\nCould not assign faculty " << facultyId << " to department "
         << "chair. Faculty ID " << facultyId << " is not part of faculty."
         << endl;
    return failure;
  }
  
  Department *validDept = validateDepartmentID(deptId);
  
  if(validDept == NULL){
    cout << "\nCould not assign faculty " << facultyId << " to department "
         << "chair. Dept ID " << deptId << " is not a valid department."
         << endl;
    return failure;
  }
  
  validDept->setChairID(facultyId);

  return success;
}
//----------------------------------------------------------------------------
/*
 * This function assigns an instructor to a course. Before assigning the
 * instructor, the faculty id and course id passed to the function are both
 * validated in order to make sure the instructor and course are both part of 
 * the university. Also, the function checks to makes sure that the 
 * instructor is not already teaching the course.
 *
 * @param: long facultyId - id of faculty member
 * @param: long courseId - id of course
 * @return: return true if able to assign instructor to course, elsre false
 */
bool University::AssignInstructorToCourse (long facultyId, long courseId)
{
  Faculty *const inFaculty = validateFacultyID(facultyId);
  
  if(inFaculty == NULL){
    cout << "\nCould not assign faculty " << facultyId << " to teach course "
         << courseId << ". Faculty ID " << facultyId << " is not part of"
         << " faculty." << endl;
    return failure;
  }
  
  Course *validCourse = validateCourseID(courseId);
  
  if(validCourse == NULL){
    cout << "\nCould not assign faculty " << facultyId << " to teach course "
         << courseId << ". Course ID " << courseId << " is not a valid "
         "course ID." << endl;
    return failure;
  }
  
  // check to see if faculty member is already teaching this course
  if(facultyId == validCourse->getIsTaughtBy()){
    cout << "\nCould not assign faculty " << facultyId << " to teach course "
         << courseId << ". Faculty " << facultyId << " is already teaching "
         "this course." << endl;
    return failure;
  }
  
  // assign instructor to course
  validCourse->setIsTaughtBy(facultyId);
  
  return success;
  
};
//----------------------------------------------------------------------------
/*
 * Print a list of all departments at the university. For each department,
 * print department's name and department id.
 *
 * @attribute: vector<Department> departments
 *                 - vector of all departments at the university
 */
bool University::ListDepartments()
{
  cout << "\nList of Departments" << endl;
  cout << setw(30) << left << "\nDept Name"
       << setw(30) << left << "Dept ID" << endl;
  cout << "-------------------------------------------------------" << endl;
  
  int i;
  for (i = 0; i < departments.size(); i++) {
    cout << setw(30) << left << departments[i].getName()
         << setw(30) << left << departments[i].getID() << endl;
  }
};
//----------------------------------------------------------------------------
/*
 * Print a list of all students at the university. For each student, print 
 * student's name and student id.
 *
 * @attribute: vector<Student> students - vector of all students at the
 *                                        university
 */
bool University::ListStudents()
{
  cout << "\nList of Students" << endl;
  cout << setw(30) << left << "\nStudent Name"
       << setw(30) << left << "Student ID" << endl;;
  cout << "-------------------------------------------------------" << endl;

  
  int i;
  for (i = 0; i < students.size(); i++) {
    cout << setw(30) << left << students[i].getName()
         << setw(30) << left << students[i].getID() << endl;
  }
};
//----------------------------------------------------------------------------
/*
 * Print a list of all courses being offered at the university. For each
 * course, print course name and course id.
 *
 * @attribute: vector<Course> courses - vector of all classes at the 
 *                                      university
 */
bool University::ListCourses()
{
  cout << "\nList of Courses" << endl;
  cout << setw(30) << left << "\nCourse Name"
       << setw(30) << left << "Course ID" << endl;
  cout << "-------------------------------------------------------" << endl;
  
  int i;
  for (i = 0; i < courses.size(); i++) {
    cout << setw(30) << left << courses[i].getName()
         << setw(30) << left << courses[i].getCRN() << endl;
  }
};
//----------------------------------------------------------------------------
/*
 * Print a list of all faculty at the university. For each faculty member,
 * print faculty's name and faculty id.
 *
 * @attribute: vector<Faculty> faculties - vector of all faculty members at 
 *                                         the university
 */
bool University::ListFaculties()
{
  cout << "\nList of Faculties" << endl;
  cout << setw(30) << left << "\nFaculty Name"
       << setw(30) << left << "Faculty ID" << endl;
  cout << "-------------------------------------------------------" << endl;
  
  int i;
  for (i = 0; i < faculties.size(); i++) {
    cout << setw(30) << left << faculties[i].getName()
         << setw(30) << left << faculties[i].getID() << endl;
  }
};
//----------------------------------------------------------------------------
/*
 * This funcion processes a transaction file. In the transaction file should
 * be a list of commands and the appropriate paramaters. For each command in
 * the transaction file, the command is matched with the appropriate function
 * to be executed.
 *
 * @param: string fileName - name of transaction file
 * @return: return false if can't open transaction file, else true
 */
bool University::ProcessTransactionFile (string fileName)
{

  ifstream fin;
  fin.open(fileName.data());
  
  if(!fin){
    cout << "\nUnable to open transaction file " << fileName << endl;
    return failure;
  }
  
  string command;
  
  while(fin >> command){

    if(command == "CreateNewDepartment"){
      string deptName, deptLocation;
      long chairID;
      fin >> deptName >> deptLocation >> chairID;
      createNewDepartment(deptName, deptLocation, chairID);
    }
    else if(command == "CreateNewFaculty"){
      string name, email, address, dateOfBirth, gender;
      float salary;
      int yearsOfExp;
      long deptID;
      fin >> name >> email >> address >> dateOfBirth >> gender >> salary
          >> yearsOfExp >> deptID;
      CreateNewFaculty(name, email, address, dateOfBirth, gender, salary,
                       yearsOfExp, deptID);
    }
    else if(command == "CreateNewCourse"){
      string cName;
      long cDeptId, cTaughtBy;
      int cMaxSeats;
      fin >> cName >> cDeptId >> cTaughtBy >> cMaxSeats;
      CreateNewCourse(cName, cDeptId, cTaughtBy, cMaxSeats);
    }
    else if(command == "CreateNewStudent"){
      string sName, sEmail, sAddress, sDateOfBirth, sGender, sMajor;
      int sYearsOfStudy;
      long sAdvisorId;
      fin >> sName >> sEmail >> sAddress >> sDateOfBirth >> sGender
          >> sYearsOfStudy >> sMajor >> sAdvisorId;
      CreateNewStudent(sName, sEmail, sAddress, sDateOfBirth, sGender,
                       sYearsOfStudy, sMajor, sAdvisorId);
    }
    else if(command == "ListDepartments"){
      ListDepartments();
    }
    else if(command == "ListFaculties"){
      ListFaculties();
    }
    else if(command == "ListStudents"){
      ListStudents();
    }
    else if(command == "ListCourses"){
      ListCourses();
    }
    else if(command == "ListCoursesOfADepartment"){
      long deptID;
      fin >> deptID;
      ListCoursesOfADepartment(deptID);
    }
    else if(command == "ListCoursesTaughtByFaculty"){
      long facultyID;
      fin >> facultyID;
      ListCoursesTaughtByFaculty(facultyID);
    }
    else if(command == "ListCoursesTakenByStudent"){
      long stdID;
      fin >> stdID;
      ListCoursesTakenByStudent(stdID);
    }
    else if(command == "ListFacultiesInDepartment"){
      long deptID;
      fin >> deptID;
      ListFacultiesInDepartment(deptID);
    }
    else if(command == "ListStudentsOfAFaculty"){
      long facultyID;
      fin >> facultyID;
      ListStudentsOfAFaculty(facultyID);
    }
    else if(command == "AssignDepartmentChair"){
      long facultyID, deptID;
      fin >> facultyID >> deptID;
      AssignDepartmentChair(facultyID, deptID);
    }
    else if(command == "AssignInstructorToCourse"){
      long facultyID, courseID;
      fin >> facultyID >> courseID;
      AssignInstructorToCourse(facultyID, courseID);
    }
    else if(command == "AddACourseForAStudent"){
      long courseID, studentID;
      fin >> courseID >> studentID;
      AddACourseForAStudent(courseID, studentID);
    }
    else if(command == "DropACourseForAStudent"){
      long courseID, studentID;
      fin >> courseID >> studentID;
      DropACourseForAStudent(courseID, studentID);
    }
    else if(command == "PrintChairs"){
      printDepartmentChairs();
    }
    else{
      cout << "\nerror" << endl;
    }
  }
  
  return success;
};
//----------------------------------------------------------------------------
/*
 * This function validates a department id. The function searches through a 
 * vector of departments for the department id (deptId) passed to function. 
 * If deptId is found in vector of departments, then deptId is a valid 
 * department id.
 *
 * @param: long deptId - department id to validate
 * @attribute: vector<Department> departments
 *                 - vector of all departments at the university
 * @return: bool valid - if deptID found in vector departments, return true,
 *                       else false
 */
Department *University::validateDepartmentID(long deptId)
{
  Department *deptPtr = NULL;
  
  int i;
  for (i = 0; i < departments.size(); i++) {
    if(departments[i].getID() == deptId){
      deptPtr = &departments[i];
      break;
    }
  }
  
  return deptPtr;
};
//----------------------------------------------------------------------------
/*
 * This function validates a faculty id. The function searches through a
 * vector of faculty for the faculty id (facultyId) passed to function.
 * If facultyId is found in vector of faculties, then facultyId is a valid
 * faculty id.
 *
 * @param: long facultyId - faculty id to validate
 * @attribute: vector<Faculty> faculties
 *                 - vector of all faculty at the university
 * @return: bool valid - if facultyId found in vector faculties, return true,
 *                       else false
 */
Faculty *University::validateFacultyID(long facultyId)
{
  Faculty *facultyPtr = NULL;
  
  int i;
  for (i = 0; i < faculties.size(); i++) {
    if(faculties[i].getID() == facultyId){
      facultyPtr = &faculties[i];
      break;
    }
  }
  
  return facultyPtr;
};
//----------------------------------------------------------------------------
/*
 * This function validates a student id. The function searches through a
 * vector of students for the student id (studentId) passed to function.
 * If studentId is found in vector of students, then studentId is a valid
 * student id.
 *
 * @param: long studentId - student id to validate
 * @attribute: vector<Student> students
 *                 - vector of all students at the university
 * @return: bool valid - if studentId found in vector students, return true,
 *                       else false
 */
Student *University::validateStudentID(long studentId)
{
  Student *studentPtr = NULL;
  
  int i;
  for (i = 0; i < students.size(); i++) {
    if(students[i].getID() == studentId){
      studentPtr = &students[i];
      break;
    }
  }
  
  return studentPtr;
};
//----------------------------------------------------------------------------
/*
 * This function validates a course id. The function searches through a
 * vector of courses for the course id (courseId) passed to function.
 * If courseId is found in vector of courses, then courseId is a valid
 * course id.
 *
 * @param: long courseId - course id to validate
 * @attribute: vector<Course> courses
 *                 - vector of all courses at the university
 * @return: bool valid - if courseId found in vector courses, return true,
 *                       else false
 */
Course *University::validateCourseID(long courseId)
{
  Course *coursePtr = NULL;
  
  int i;
  for (i = 0; i < courses.size(); i++) {
    if(courses[i].getCRN() == courseId){
      coursePtr = &courses[i];
      break;
    }
  }
  
  return coursePtr;
};
//----------------------------------------------------------------------------
/*
 * This function validates a name of a major. The function searches through a
 * vector of departments for the major's name (major) passed to the function.
 * Each major has the name of a department. If major is found in vector of
 * departments, then major is a valid major name.
 *
 * @param: const string &major - name of major to validate
 * @attribute: vector<Department> departments
 *                 - vector of all departments at the university
 * @return: bool valid - if major found in vector departments, return true,
 *                       else false
 */
bool University::validateMajor(const string &major)
{
  bool valid = false;
  
  int i;
  for (i = 0; i < departments.size(); i++) {
    if(departments[i].getName() == major){
      valid = true;
      break;
    }
  }
  
  return valid;
};
//----------------------------------------------------------------------------
void University::printDepartmentChairs()
{
  cout << "\nList of Chairs" << endl;
  cout << setw(30) << left << "\nChair Name"
       << setw(30) << left << "Chair ID" << endl;
  cout << "-------------------------------------------------------" << endl;
  
  int i;
  for (i=0; i<departments.size(); i++) {
    cout << setw(30) << left << departments[i].getName()
         << setw(30) << left << departments[i].getChairID() << endl;
  }
};
//----------------------------------------------------------------------------
/*
int main()
{
  University csusm;
  csusm.ProcessTransactionFile("trans.txt");
};
*/
