/*****************************************************************
 * FILE NAME: StudentInterface.h
 * PURPOSE: Provide a standard interface for accessing student
 functions.
 * AUTHOR: Junior Samaroo
 * DATE: October 1st, 2011
 * NOTES: This file is the same in the sequential and linked
 list implementations.
 ****************************************************************/
#include "StudentType.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************
 * FUNCTION NAME: InitializeStudent
 * PURPOSE: Creates a new instance of a student.
 * ARGUMENTS: Student name, Grade of Student, Student struct
 * RETURNS: Void function which returns nothing.
 * REQUIRES: A valid name and grade of student.
 * ENSURES: Ensures that there is a student to be inserted.
 * NOTES: Name must not be empty & grade must be between 0 and 100
 ****************************************************************/
extern void InitializeStudent (char *name, int grade, Student *S); 

/*****************************************************************
 * FUNCTION NAME: NameOfStudent
 * PURPOSE: To get the name of a student.
 * ARGUMENTS: Student struct type variable.
 * RETURNS: The name of the student as a char*
 * REQUIRES: An initialized student.
 * ENSURES: A valid name of a student can be retreived.
 * NOTES: 
 ****************************************************************/
extern char *NameOfStudent (Student S);

/*****************************************************************
 * FUNCTION NAME: GradeOfStudent
 * PURPOSE: To get the grade of a student.
 * ARGUMENTS: Student struct type variable.
 * RETURNS: The grade of a student as an int.
 * REQUIRES: An initialized student.
 * ENSURES: A valid grade of a student can be retrieved.
 * NOTES: 
 ****************************************************************/
extern int GradeOfStudent (Student S);

/*****************************************************************
 * FUNCTION NAME: FreeStudent
 * PURPOSE: To free a student.
 * ARGUMENTS: An initialzed student address.
 * RETURNS: Void function returns nothing.
 * REQUIRES: An initialized student.
 * ENSURES: That student is deleted.
 * NOTES: 
 ****************************************************************/
extern void FreeStudent (Student *S);
