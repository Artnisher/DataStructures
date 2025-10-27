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
/*                           Program Structures                       */
/**********************************************************************/
struct Customer
{
    char  name[MAX_NAME_LENGTH + 1]; /* Customer's last name           */
    int   priority;                  /* Customer's priority level      */
    float salary;                    /* Customer's salary              */
};

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
  /* Print program heading                                            */
void print_instructions();
  /* Print brief instruction of the program's purpose before each run */
int  get_num_of_customers();
  /* Get the quantity of customers with validation                    */
void get_customers(struct Customer *p_struct_customer_data_base, int quantity);
  /* Read values and convert negatives to positives immediately       */
void clean_up_names();
  /* Sort the array into descending order using selection sort        */
  /* implemented with pointer aritmetic                               */
void sort_customers(struct Customer *p_struct_customer_data_base, int quantity);
  /* Print sorted values, if consecutive values are equal, mark them  */
//void print_customers();
  /* Return the sum of all values                                     */

/**********************************************************************/
/*                              Main Function                         */
/**********************************************************************/
int main(void)
{

   int   quantity;  /* Number of data values entered by the user      */
   struct Customer *p_struct_customer_data_base;

   /*Task one, Print heading */
   print_heading();
   printf("\n\n\n");

   print_instructions();
   /* Task two, while loop */
   while (quantity = get_num_of_customers(), quantity != 0 )
{
  /* Task three, malloc allocate memory...and abort if.... */
    if((p_struct_customer_data_base = (struct Customer*)
       malloc(sizeof (*p_struct_customer_data_base) * quantity)) ==NULL)
    {
      printf("\n Error #%d: Unable to allocate memory for data.", 
              DATA_ALLOC_ERR);
      printf("\n Program is aborting.\n\n");
  
    exit (DATA_ALLOC_ERR);
    }
    
    /* task four, call functions */
    get_customers(p_struct_customer_data_base, quantity);
    free(p_struct_customer_data_base);
    sort_customers(p_struct_customer_data_base, quantity);
   
    /* Task five, print customers */
    //print_customers(&p_struct_costumer_data_base, quantity);//
   
   }

   /* Task seven, print goodbye message */
   printf("\nThanks for processing data. Have a nice day! :-)\n");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                           Print the heading                        */
/**********************************************************************/
void print_heading()
{
   printf("\n========================================================");
   printf("\n                Program Number: %s",    PROGRAM_NUMBER);
   printf("\n                Programmer: %s",        LAST_NAME);
   printf("\n                PCC Course Number: %s", COURSE_NUMBER);
   printf("\n========================================================\n");
   return;
}

/**********************************************************************/
/*                         Print the instruction                      */
/**********************************************************************/
void print_instructions()
{
   printf("\nThis program allows you to input customers which owe\n");
   printf(" you money (your accounts receivable), and manage these\n");
   printf(" accounts in a database.  You will enter the following:\n");
   printf("    Customer last name (%d - %d characters)\n", MAX_NAME_LENGTH, 
           MIN_NAME_LENGTH);
   printf(" Amount the customer owes (to the exact cent)\n");
   printf(" Customer priority (1=VIP, 2=Important, 3=Regular)\n");
   printf(" From %d to %d customers may be processed.\n", MIN_CUSTOMER, 
           MAX_CUSTOMER); 
   return;
}

/**********************************************************************/
/*                    Get the number of customers                     */
/**********************************************************************/
int get_num_of_customers()
{
  int quantity;
   do 
   {
       printf("\n Get the customers for the database\n");
       printf("------------------------------------------------------\n");
       printf("How many customers do you have (%d to %d, 0=%d): ", MIN_CUSTOMER, 
               MAX_CUSTOMER, QUIT);
       scanf ("%d", &quantity);
   /* while this condition is false */
   } while ((quantity < MIN_CUSTOMER || quantity > MAX_CUSTOMER) && quantity != QUIT);

   return quantity;
}

/**********************************************************************/
/*                           Get customers                            */
/**********************************************************************/
void get_customers(struct Customer *p_struct_customer_data_base, int quantity)
{
  for(int count = 0; count < quantity; count++) /*task 1*/
  {
     printf("Customer number %d: \n", count + 1); /* task 2 */

     printf("Enter the customer's last name: ");
     scanf(" %s", p_struct_customer_data_base->name); /* task3 */
     printf("Enter the amount owed: ");
     scanf(" %f", &p_struct_customer_data_base->salary); /*task 4*/
     
     do 
     {
         printf("Enter the customer priority (1-3): ");
         scanf(" %d", &p_struct_customer_data_base->priority); /* task 5 */

     } while (p_struct_customer_data_base->priority < 1 || p_struct_customer_data_base->priority > 3);
  
    }
  return;
}

/**********************************************************************/
/*                           Sort customers                           */
/**********************************************************************/
void sort_customers(struct Customer *p_struct_customer_data_base, int quantity)
{
    for (int i = 0; i < quantity; i++) {
        char *p_fast = p_struct_customer_data_base[i].name;
        while (*p_fast != END_OF_STRING) 
        {
            *p_fast = tolower(*p_fast);
            p_fast++;
        }
    }
    p_fast = '\0';
    return;
}

/**********************************************************************/
/*                           Print Database                           */
/**********************************************************************/