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
void print_heading();
  /* Print program heading                                            */
void print_instructions();
  /* Print brief instruction of the program's purpose before each run */
int  get_num_of_customers();
  /*      */
void get_customers(int customer, int quantity);
  /* Read values and convert negatives to positives immediately       */
void clean_up_names(int customer, int quantity);
  /* Sort the array into descending order using selection sort        */ 
  /* implemented with pointer aritmetic                               */
void sort_customers(int customer, int quantity);
  /* Print sorted values, if consecutive values are equal, mark them  */
  /* as duplicate for clarity                                         */
void print_customers(int customer, int quantity);
  /* Return the sum of all values                                     */

/**********************************************************************/
/*                              Main Function                         */
/**********************************************************************/
int main(void)
{
   int   quantity,  /* Number of data values entered by the user      */
         p_instruct_costumer_data_base, 
         customer;
   /*Task one Print heading */
   print_heading();
   printf("\n\n\n");
   /* Task two, while loop */
   while (print_instructions(), (quantity = get_number_of_customers()) != QUIT)
   {
       /* Task three malloc, allocate memory...and abort if.... */
      if((p_instruct_costumer_data_base = (int *)malloc(sizeof
        (p_instruct_costumer_data_base) * quantity)) ==NULL)
      {
        printf("\n Error #%d: Unable to allocate memory for data.", 
              DATA_ALLOC_ERR);
        printf("\n Program is aborting.\n\n");
  
        exit (DATA_ALLOC_ERR);
      }

   }

   
   /* task four, call functions */
   get_customers(customer, quantity);
   clean_up_names(customer, quantity);
   sort_customers(customer, quantity);
   
   /* Task five, print customers */
   print_customers(customer, quantity);
   
   /* Task six, free database */
   free(customer);

   /* Task seven, print goodbye message */
   printf("\nThanks for processing data. Have a nice day! :-)\n");
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
   printf("you money (your accounts receivable), and manage these\n");
   printf("accounts in a database.  You will enter the following:\n");
   printf("    Customer last name (%d - %d characters)\n", MAX_NAME_LENGTH, 
           MIN_NAME_LENGTH);
   printf(" Amount the customer owes (to the exact cent)\n");
   printf(" Customer priority (1=VIP, 2=Important, 3=Regular)\n");
   printf("From %d to %d customers may be processed.\n", MIN_CUSTOMER, 
           MAX_CUSTOMER); 
   return;
}

/**********************************************************************/
/*                    Get the number of customers                     */
/**********************************************************************/
int get_number_of_customers()
{
   int customers_number,
       quantity;  

   do 
   {
       printf("\n Get the customers for the database\n");
       printf("------------------------------------------------------");
       printf("How many customers do you have (%d to %d, 0=%d):", MIN_CUSTOMER, 
               MAX_CUSTOMER, QUIT);
       scanf ("%d", &customers_number);
        
   }
   while ((customers_number != QUIT) && 
          (customers_number < MIN_CUSTOMER || customers_number > MAX_CUSTOMER));
          
          quantity = customers_number;

   return quantity ;
}

/**********************************************************************/
/*                           Get customers                            */
/**********************************************************************/
void get_customers(customer, p_customer, quantity)
{
  struct p_customer
  {
    char name[MAX_NAME_LENGTH + 1];
    float salary;
    int priority;
  }

  for(customer = 0;customer < quantity; quantity++);
     printf("Customer number %d: \n", quantity);
     printf("Enter the customer's last name: ");
     scanf(" %s", p_customer->name);
     printf("Enter the amount owed: ");
     scanf(" %f", p_customer->salary);
     printf("Enter the customer priority (1-3): ");
     scanf(" %d", p_customer->priority);  
  return;
}



/**********************************************************************/
/*            */
/**********************************************************************/
void sort_customers(customer, quantity)


/**********************************************************************/
/*                          Print Sorted Data                         */
/**********************************************************************/
void print_customers(customer, quantity)
{

}