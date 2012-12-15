#include "StudentInterface.h"

void InitializeStudent (char *name, int grade, Student *S) 
{ 
    
#ifdef DEBUG
    if (strlen(name) == 0) 
    {
        printf("Please insert a valid name!\n");
        exit(1);
    }
    if ((grade >100) || (grade<0)) 
    {
        printf("Please insert a valid grade!\n");
        exit(1);
    }
#endif
    
    //Allocates memory for student
    S->name = malloc(strlen(name)+1);
    strcpy(S->name, name);
    S->grade = grade;
}

char *NameOfStudent (Student S) 
{
    //Gets name of student
    char *name;
    name = S.name;
    return name;
    
#ifdef DEBUG
    if (strlen(name) == 0) 
    {
        printf("Name is invalid!\n");
        exit(1);
    }
#endif
    
}

int GradeOfStudent (Student S) 
{
    //Gets grade of student
    return S.grade;
    
#ifdef DEBUG
    if ((S.grade >100) || (S.grade<0)) 
    {
        printf("Grade is invalid!\n");
        exit(1);
    }
#endif
    
}

void FreeStudent (Student *S) 
{
    //Frees student pointer
    free(S->name);
    S->name = NULL;
    free(S);
    S = NULL;
}
