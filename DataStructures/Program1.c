/**************************************************************************/
/*                                                                        */
/* Program Name: program1 - Calculate the sum of a whole number range     */
/* Author:       Arturo Chira                                             */
/* Installation: Pensacola Christian College, Pensacola, Florida          */
/* Course:       CS 227, Data Structures and Algorithms                   */
/* Date Written: September 4, 2025                                        */
/*                                                                        */                                          
/**************************************************************************/
                                                                          
/**************************************************************************/
/*                                                                        */
/* I pledge tis assignment is my own first time work.                     */
/* I pledge I did not copy or try to copy any code from the internet.     */
/* I pledge I did not copy or try to copy any code from anyone else.      */
/* I pledge I did not attepmt to give code to anyone else on this.        */
/* I understand if I violate this pledge I will receive a 0 grade.        */                             
/*                                                                        */
/*                      Signed: ____________________________________      */
/*                                         (signature)                    */
/*                                                                        */ 
/*                                                                        */
/**************************************************************************/

/**************************************************************************/
/*                                                                        */
/* This program asks the user a range between 2 numbers,                  */
/* then print the summ of all the numbers inside the range entered        */
/* by the user                                                            */
/*                                                                        */
/**************************************************************************/

#include <stdio.h> /* printf and scanf                                    */

/**************************************************************************/
/*                         Symbolic Constants                             */
/**************************************************************************/
#define COURSE_NUMBER   "CS227" /* PCC assigned course number             */
#define PROGRAM_NUMBER  1       /* Assigned program number                */
#define USER_NAME  "Chira"      /* The Programmer's last name             */
/**************************************************************************/
/*                        Function Prototypes                             */
/**************************************************************************/
void print_heading();
/* This function prints the program heading                               */
void get_number_range(int *p_range_small_number, int *p_range_large_number);
/* This function read the first and last value entered by the user        */ 
int calc_range_sum(int range_small_number, int range_large_number);
/* Calculates the sum of the numbers in the range                         */

/**************************************************************************/
/*                             Main Function                              */
/**************************************************************************/
int main() 
{
   int range_small_number, /* The range first  number                     */
       range_large_number; /* The range second number                     */

/* Print the program heading                                              */
   print_heading(); 

/* Prompts the user to enter a number range and retrieves the first       */
/* and last numbers                                                       */
   get_number_range(&range_small_number, &range_large_number);

/* Calculates the sum of the number range and prints the result           */
   printf("The sum of all numbers between %d amd %d (inclusively) is %d\n", 
           range_small_number, range_large_number, 
           calc_range_sum(range_small_number, range_large_number));

/* Print a goodbye message and terminate the program                      */
   printf("\nThanks for your range summing. Have a nice day! ;-)");
   printf("\n\n\n\n\n");
   return 0;
}

/**************************************************************************/
/*                      Print the program heading                         */
/**************************************************************************/
void print_heading() 
{
   printf("\n==========================================================");
   printf("\n         Program Number: %d",     PROGRAM_NUMBER);
   printf("\n         Programmer: %s",         USER_NAME);
   printf("\n         PCC Course Number: %s",  COURSE_NUMBER);
   printf("\n==========================================================");
   printf("\n I'll sum whole numbers in a number range (inclusively).");
   printf("\n--------------------------------------------------------");
   return;
}

/**************************************************************************/
/*                        Get the number range                            */
/**************************************************************************/
void get_number_range(int *p_range_small_number, int *p_range_large_number)
{
   printf("\n Enter a range of whole numbers now, lower number first:");
   printf("\n    What is your small number:");
   scanf ("%d", p_range_small_number);
   printf("    Give me your large number:");
   scanf ("%d", p_range_large_number);
   printf("\n");
   return;
}

/**************************************************************************/
/*             Calculates the inclusive sum of number range               */
/**************************************************************************/
int calc_range_sum(int range_small_number, int range_large_number) 
{
   int range_sum = 0; /* The sum of small and large number                */
   int counter;
   for (int counter = range_small_number; counter <= range_large_number; 
            counter++) 
   {
      range_sum += counter; 
   }
   return range_sum;
}
