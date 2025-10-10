/**********************************************************************/
/*                                                                    */
/* Program Name: program3 - Process Experimental Scientific Data      */
/* Author:       Arturo Chira                                         */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: October 2, 2025                                      */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/* I pledge  all of the lines  in this C program  are my own original */
/* work, and none of the lines in this C program have been copied     */
/* from anyone else, unless I was specifically authorized to do so by */
/* my CS227 instructor.                                               */
/*                                                                    */
/*                                                                    */
/*                      Signed: _____________________________________ */
/*                                                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* This program reads experimental scientific data, converts negative */
/* to  positive  at input  time, sorts the values in descending order */
/* computes the total sum, and prints the sorted list of values       */
/* flagging duplicates.                                               */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>    /* printf, scanf                                */
#include <stdlib.h>   /* malloc, free, exit                           */
#include <string.h>   /* strlen                                       */
#include <ctype.h>    /* toupper                                      */


/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER     "CS227" /* PCC assigned course number       */
#define PROGRAM_NUMBER    "3"     /* Teacher asigned program number   */
#define LAST_NAME         "Chira" /* The programer's last name        */
#define DATA_ALLOC_ERR    1       /* Error code if malloc fails       */
#define END_OF_STRING     '\0'    /* End of string marker             */
#define MAX_CUSTOMER      100     /* Maximum number of customers      */
#define MIN_CUSTOMER      2       /* Minimum number of customers      */
#define MAX_NAME_LENGTH   20      /* Maximum length of a name         */
#define MIN_NAME_LENGTH   2       /* Minimum length of a name         */
#define QUIT              0       /* Quit program                     */


/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/

/**********************************************************************/
/*                           Program Structures                       */
/**********************************************************************/
struct Customer
{
    char  name[MAX_NAME_LENGTH + 1]; /* Customer's last name           */
    int   priority;                  /* Customer's priority level      */
    float salary;                    /* Customer's salary              */
};

/**********************************************************************/
/*                           Program Structures                       */
/**********************************************************************/
void print_data(struct Customer *p_customer)
{
   
   printf("Customer name %s: \n", p_customer->name);
   printf("Customer's priority: %d\n", p_customer->priority);
   printf("Amount owed: %.2f\n", p_customer->salary);

return;
}

/**********************************************************************/
/*                              Main Function                         */
/**********************************************************************/
int main(void)
{
   struct Customer customers[MAX_CUSTOMER + 1];
   strcpy(customers.name, "Juan");
   customers.priority = 0;
   customers.salary = 0.0f;

   print_data(&customers);

   return 0;
}