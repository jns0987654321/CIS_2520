/*****************************************************************
 * AUTHOR: Junior Samaroo
 * DATE: October 1st, 2011
 * Assignment #1 CIS2520
 *
 * Sequential List Implementation
 *
 ****************************************************************/

#include "ListInterface.h"

/* Function to print list of students */
void demo(List , Student); 

int main (int argc, const char * argv[])
{
    List people; //List to store students
    Student man, woman, boy, girl, tempStudent; //Diffent student structs
    Initialize(&people);
    demo(people, tempStudent);  //prints empty list
    
    //prints list after 1st insertion
    InitializeStudent("John", 80, &man);
    Insert(man, 0, &people);
    demo(people, tempStudent); 
    
    //inserts student into position 0 and prints list
    InitializeStudent("Mary", 75, &woman);
    Insert(woman, 0, &people);
    demo(people, tempStudent);
    
    //inserts student into position 2 and prints list
    InitializeStudent("Pete", 90, &boy);
    Insert(boy, 2, &people);   
    demo(people, tempStudent);
    
    //inserts student into position 2 and prints list
    InitializeStudent("Liz", 85, &girl);
    Insert(girl, 2, &people);
    demo(people, tempStudent);
    
    //deletes student in position 0 and prints list
    Delete(0, &people);
    demo(people, tempStudent);
    
    //deletes student in position 1 and prints list
    Delete(1, &people);
    demo(people, tempStudent);
    
    //deletes student in position 1 and prints list
    Delete(1, &people);
    demo(people, tempStudent);
    
    //deletes last student and prints empty list
    Delete(0, &people);
    demo(people, tempStudent);
    
    return 0;
}

void demo(List test, Student temp)
{
    int i=0; //loop counter
    int length=0; //length of list
    
    printf("************************************************************\n");
    //Checks if list is empty
    if (Empty(&test))
        printf("List is empty; ");
    else
        printf("List is not empty; ");
    
    //Checks if list is full
    if (Full(&test)) {
        printf("List is full; ");
    }else
        printf("List is not full; ");
    
    //Gets length of list
    length = Length(&test);
    printf("List is of length %d; \n", length);
    
    //Loop prints students in list
    for(i=0; i<length; i++)
    {
        if(!Empty(&test))
        {
            Peek(i, &test, &temp);
            printf("    %-10s ", temp.name);
            printf("    %d%%\n", temp.grade);
        }
        
    }
    printf("************************************************************\n");
}



