#include "ListInterface.h"

void Initialize (List *L) 
{ 
    L->count = 0;
    L->first = NULL;
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
    
    ListNode *tempNode, *ptr; //list nodes to step through list
    int i =0;
    int temp = L->count;
    
    InitializeStudent(NameOfStudent(X), GradeOfStudent(X), &X);
    
    tempNode = malloc(sizeof(ListNode));
    tempNode->item = X;
    tempNode->next= NULL;
    ptr=L->first;
    
    //Checks if insert is into 1st position
    if (ptr==NULL || position==0)
    {
        tempNode->next=L->first;
        L->first=tempNode;
    }
    else
    {
        //Loop finds position in list
        while((i<position-1) && (ptr->next!=NULL))
        {
            ptr=ptr->next;
            i++;
        }
        tempNode->next=ptr->next;
        ptr->next=tempNode;
    }
    
    L->count = temp+1;
    ptr=L->first;
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
    
    ListNode *ptr, *toDelete, *last; //listnodes to step through list
    int i =0;
    
    L->count = L->count-1;
    ptr=L->first;
    
    //Reorders list if student is 1st position in list
    if (position==0)
    {
        toDelete=L->first;
        L->first=L->first->next;
    }
    else
    {
        //Loop to find position in list
        while((i<position) && (ptr->next!=NULL))
        {
            last=ptr;
            ptr=ptr->next;
            i++;
        }
        last->next=ptr->next;
        toDelete=ptr;
    }
    
    //once list reordered frees student
    FreeStudent(&toDelete->item);
    toDelete = NULL;        
    ptr=L->first;
}

int Full (List *L) 
{
    //Checks size of list
    if (L->count == MAXLISTSIZE) 
    {
        return 1;
    } else 
    {
        return 0;
    }
}

int Empty (List *L) 
{
    //Checks size of list
    if (L->count == 0) 
    {
        return 1;
    }else
    {
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
    
    int i=0;
    ListNode *temp;
    temp = L->first;
    
    //Steps though list to find position
    while((i<position) && (temp!=NULL))
	{      
		temp = temp->next;
        i++;
	}
    
    //Stores found student
    X->name = temp->item.name;
    X->grade = temp->item.grade;
}

void Destroy (List *L) 
{
    ListNode *temp;
    
    //Loop frees each student in list
    while (L->first != NULL) 
	{
        temp = L->first;
		L->first = L->first->next;
        free(temp);
	}
    
    L->count = 0;
    
}