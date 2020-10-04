/*-----------------------------------------------------
---------------Circular Linked list program-----------
-----------------------------------------------------*/

//Header files
#include <stdio.h>
#include <stdlib.h>

//Sturcture for storing node information 
struct Clinked
{
    int data;
    struct Clinked *link;
};

//For declaring the structure pointers for linked list
struct Clinked *ctop = NULL, *init, *temp, *rep;
 
/*------------------------------------------
----Defination of all neccessary function----
---------------------------------------------*/

//This function si to create a new circular linked list for our execution
void New()
{
    int op;
 
    init = (struct Clinked*)malloc(sizeof(struct Clinked));       //dynmically allocating memory
    printf("\nPlease enter the integer: ");
    scanf("%d", &init->data);
    init->link = init;
    ctop = init;
    printf("\nTo enter another integer press 1 or 0 to discontinue:  ");
    scanf("%d", &op);
    while (op != 0)
    {
        temp = (struct Clinked*)malloc(sizeof(struct Clinked));    //dynamically allocation memory
        printf("\nPlease enter the integer: ");
        scanf("%d", &temp->data);
        init->link = temp;
        temp->link = ctop;
        init = temp;
        printf("\nTo enter another integer press 1 or 0 to discontinue:  ");
        scanf("%d", &op); 
    }
}
 
//This function is to insert element at beginning of circular linked list
 
void InsertBeg()
{
    init = ctop;
    temp = (struct Clinked*)malloc(sizeof(struct Clinked));
    printf("\nPlease enter the integer: ");
    scanf("%d", &temp->data);
    while (init->link != ctop)
    {
        init = init->link;
    }
    init->link = temp;
    temp->link = ctop;
    ctop = temp;
}
 
//This function is to insert element at any position of circular linked list
 
void InsertPos()
{
    struct Clinked *ptr;
    int c = 1, pos, count = 1;
 
    temp = (struct Clinked*)malloc(sizeof(struct Clinked));
    if (ctop == NULL)
    {
        printf(\n"Whoops!, cannot insert the element at this positon...\n");
    }
    printf("\nPlease enter the integer: ");
    scanf("%d", &temp->data);
    printf("\nPlease enter a position where you want to insert the above element: ");
    scanf("%d", &pos);
    init = ctop;
    ptr = ctop;
    while (ptr->link != ctop)
    {
        count++;
        ptr = ptr->link;
    }
    count++;
    if (pos > count)
    {
        printf("Warning!! Linked List beyond boundary!!\n");
        return;
    }
    while (c < pos)
    {
        rep = init;
        init = init->link;
        c++;
    }
    temp->link = init;
    rep->link = temp;
}
 
//This function is to delete the beginning element of the circular linked list
 
void DeleteBeg()
{
    if (ctop == NULL) 
        printf("\nOops!, The list is empty...\n");
    else
    {
        init = ctop;
        temp = ctop;
        while (init->link !=  ctop)
        {
            init = init->link;
        }
        ctop = temp->link;
        init->link = ctop;
        free(temp);
    }
}
 
//This function is to delete element at any given postion or end of circular linked list
 
void DeletePos()
{
    if (ctop == NULL)
        printf("\nOops!, The list is empty...\n");
    else
    {
        int c = 1, pos;
        printf("\nPlease enter the position from where you want to delete a element: ");
        scanf("%d", &pos);
        init = ctop;
        while (c < pos)
        {
            temp = init;
            init = init->link;
            c++;
        }
        temp->link = init->link;
        free(init);
    }
}
 
//This function is to dsplay all the elements of linked list
 
void Display()
{
    if (ctop == NULL)
        printf("\nOh no!, Nothing to show...\n");
    else
    {
        init = ctop;
        while (init->link !=  ctop)
        { 
            printf("%d->", init->data);
            init = init->link;
        }
        printf("%d", init->data);
    }
}
 
/*-----------------------
------main function------
-------------------------*/

int main()
{

    printf("\n\n------------------------------------\n");
    printf("       Circular linked list\n");
    printf("------------------------------------\n");

    int op;   //for options selection

    printf("\nPlease enter the options you want to execute:\n ");

    while (1)
    {
        //menu
        printf("\n(1) Create a circular linked list");
        printf("\n(2) Insert an element at beginning");
        printf("\n(3) Insert an element at end or any position");
        printf("\n(4) Delete an element at beginning");
        printf("\n(5) Delete an element from end or any position");
        printf("\n(6) Display the list");
        printf("\n(7) Exit :(");

        printf("\nOption: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
                New();
            break;
        case 2:
                InsertBeg();
            break;
        case 3:
                InsertPos();
            break;
        case 4:
                DeleteBeg();
            break;
        case 5:
                DeletePos();
            break;
        case 6:
                Display();
            break;
        case 7:
            printf("\nBye bye..:(\n----------------\n\n");
            exit(0);
            break;  //for better coding practice
        default:
            printf("\nHey! you like to enter wrong key, :D...Try again!");
            break;
        }

        printf("\n\nPlease enter a option again: \n");
    }
    return 0;
}
 