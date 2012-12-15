#include "ListInterface.h"

void Initialize (List *L) 
{ 
    int i=0;
    
    //Loop initializes each student in list
    for (i=0; i<MAXLISTSIZE; i++) {
        strcpy(L->items[i].name, "");
        L->items[i].grade = 0;
    }
    L->count = 0;
}

void Insert (Item X, int position, List *L) 
{
    
#ifdef DEBUG
    if (position>L->count) 
    {
        printf("Please insert a valid position to insert!\n");
        exit(1);
    }
#endif
    
    int i =0;
    int temp = L->count;

    //Loop inserts into position and shifts array up
    for (i=L->count; i!=position-1; i--) 
    {
        L->items[i+1] = L->items[i];
    }
    
    L->count = temp+1; //size of list
    L->items[position] = X; //inserts new student
}

void Delete (int position, List *L) 
{
    
#ifdef DEBUG
    if (position>L->count) 
    {
        printf("Please insert a valid position to delete!\n");
        exit(1);
    }
#endif
    
    int i =0;
    int temp = L->count;
    
    //Loop shifts array down
    for (i=position; i!=temp; i++) 
    {
        L->items[i] = L->items[i+1];
    }
    
    L->count = temp-1; //decrements size of list
}

int Full (List *L) 
{
    //Checks size of list
    if (L->count == MAXLISTSIZE) 
    {
        return 1;
    } else {
        return 0;
    }
}

int Empty (List *L) {

    //Checks size of list
    if (L->count == 0) 
    {
        return 1;
    }else{
        return 0;
    }
}

int Length (List *L) 
{
    return L->count;
}

void Peek (int position, List *L, Item *X) 
{ 
    
#ifdef DEBUG
    if (position>L->count) 
    {
        printf("Please insert a valid position to peek!\n");
        exit(1);
    }
#endif
    
    //Stores student data into temp student struct
    X->grade = L->items[position].grade;
    strcpy(X->name, L->items[position].name);    
}

void Destroy (List *L) 
{
    int i=0;
    
    //Loops frees each student in list
    for (i=0; i<MAXLISTSIZE; i++) 
    {
        FreeStudent(&L->items[i]);
    }
    
    L->count = 0;
}