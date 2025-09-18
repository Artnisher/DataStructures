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
#define PROGRAM_NUMBER  2       /* Assigned program number                */
#define USER_NAME  "Chira"      /* The Programmer's last name             */
/**************************************************************************/
/*                        Function Prototypes                             */
/**************************************************************************/
void print_heading();
/* This function prints the program heading                               */
void print_menu();
/* This function prints the program menu  */
void add_numbers(void);
/*                                                                        */
void raise_to_power(void);
/*                                                                        */
void ascending_order(void);
/* This function puts two numbers in ascending order                      */ 
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
       range_large_number, /* The range second number                     */ 
       menu_choice;

/* Print the program heading                                              */
   print_heading(); 

/* Print the program Nmenu                                                */
   print_menu();
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
   printf("\n    Miscellaneous operations on your two whole numbers."); 
   printf("\n--------------------------------------------------------");
   return;
}
/**************************************************************************/
/*                      Print the program Menu                            */
/**************************************************************************/
void print_menu() 
{
       int menu_choice,
       range_small_number, 
       range_large_number; 
    do {
           printf("\n Make a selection from the following menu:");
              printf("\n 1 - Add two whole numbers");
              printf("\n 2 - Raise the 1st number to the power of the 2nd");
              printf("\n 3 - Sum all numbers between two whole numbers");
              printf("\n 4 - Put two whole numbers into ascending order");
              printf("\n 5 - Quit");
              printf("\nEnter your menu selection (1-5): ");
              
              if (scanf("%d", &menu_choice) != 1) 
              {
                  printf("\n Invalid input. Please enter a number between 1 and 5.\n");
                  return;
              }

                switch (menu_choice)
                {
                    case 1:
                         add_numbers();
                        break;
                    case 2:
                         raise_to_power();
                        break;
                    case 3:
                        get_number_range(&range_small_number, &range_large_number);
                        
                        printf("The sum of all numbers between %d amd %d (inclusively) is %d\n", 
                                range_small_number, range_large_number, 
                                calc_range_sum(range_small_number, range_large_number));
                        break;
                    case 4:
                         ascending_order();
                        break;
                    case 5:
                        printf("\n Thanks for processing numbers. Have a nice day! ;-)");
                        break;
                    default:
                        printf("\n Invalid selection. Please try again.");
                }

        } while (menu_choice != 5);





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
