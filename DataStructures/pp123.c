/********************************************************************************/
/*                                                                              */
/* Program Name: program1 - Calculate the sum of a whole number range           */
/* Author:       Arturo Chira                                                   */
/* Installation: Pensacola Christian College, Pensacola, Florida                */
/* Course:       CS 227, Data Structures and Algorithms                         */
/* Date Written: September 18, 2025                                             */
/*                                                                              */                                          
/********************************************************************************/
                                                                          
/********************************************************************************/                                                                        */
/* I pledge tis assignment is my own first time work.                           */
/* I pledge I did not copy or try to copy any code from the internet.           */
/* I pledge I did not copy or try to copy any code from anyone else.            */
/* I pledge I did not attepmt to give code to anyone else on this.              */
/* I understand if I violate this pledge I will receive a 0 grade.              */                             
/*                                                                              */
/*                      Signed: ____________________________________            */
/*                                         (signature)                          */
/*                                                                              */ 
/*                                                                              */
/********************************************************************************/

/********************************************************************************/                                                                   */
/* The program displays a menu for operations on two integers. The user         */
/* chooses to add them, raise the first to the power of the second, sum         */
/* the inclusive range between them, or show them in ascending order.           */
/* After each action it returns to the menu; entering 5 or any invalid          */
/* number ends the program.                                                     */
/*                                                                              */
/********************************************************************************/
#include <stdio.h>   /* printf and scanf                                        */
#include <stdlib.h>  /* exit                                                    */
#include <math.h>    /* pow                                                     */

/********************************************************************************/
/*                         Symbolic Constants                                   */
/********************************************************************************/
#define COURSE_NUMBER     "CS227"          /* PCC assigned course number        */
#define PROGRAM_NUMBER    2                /* Assigned program number           */
#define USER_NAME         "Chira"          /* The Programmer's last name        */
#define MIN_MENU_CHOICE   1                /* Minimum menu choice               */
#define MAX_MENU_CHOICE   5                /* Maximum menu choice               */
#define MENU_CHOICE_ERROR 1                /* Error menu choice                 */
/********************************************************************************/
/*                        Function Prototypes                                   */
/********************************************************************************/
void print_heading();
   /* This function prints the program heading                                  */
void print_menu();
   /* This function prints the program menu                                     */
int get_menu_input();
   /* This function gets the menu choice                                        */
void get_whole_numbers_input(int *p_first_number, int *p_last_number);
   /* This function gets the two whole numbers                                  */
int add_numbers(int first_number, int last_number);
   /* This function adds two numbers                                            */
int raise_to_power(int base, int exponent);
   /* This function raises the first number to the power of the second          */
int calc_range_sum(int range_small_number, int range_large_number);
   /* Calculates the sum of the numbers in the range                            */
void ascending_order(int *p_first_number, int *p_last_number);
   /* This function puts two numbers in ascending order                         */ 

/********************************************************************************/
/*                             Main Function                                    */
/********************************************************************************/
int main() 
{
   int first_number, /* First whole number input                                */
       last_number,  /* Second whole number input                               */
       menu_choice = 0; /* Menu choice input                                    */
      
   print_heading(); 
                                            
   while (1) 
   {
      print_menu(); /* Print the program menu                                   */ 
      menu_choice = get_menu_input();
      
      if (menu_choice == 5)
      {
         printf("\n Invalid input. Please enter a number between 1 and 5.\n");
         break;
      } 
   
      switch (menu_choice) /* Process the user menu choice                      */
      {
            /* Get the addition of two whole numbers                            */
         case 1: 
            get_whole_numbers_input(&first_number, &last_number); 
         
            printf("\n The sum of %d and %d is %d\n", first_number, 
                    last_number, add_numbers(first_number, last_number));
            break;

            /* Get the first number raised to the power of the second           */
         case 2:
            get_whole_numbers_input(&first_number, &last_number);
            printf("\n %d raised to the power of %d is %d\n", first_number, 
                       last_number, raise_to_power(first_number, 
                        last_number));
            break;

            /* Calculate the sum of all numbers between a range                 */
         case 3:   
            get_whole_numbers_input(&first_number, &last_number);
            if (first_number > last_number) 
            {
               int temp_value = first_number; first_number = last_number; 
               last_number = temp_value;
            }  
            printf("The sum of all numbers between %d and %d (inclusive) is %d\n", 
                 first_number, last_number, 
                 calc_range_sum(first_number, last_number));
            break;

            /* Put two numbers in ascending order                               */
         case 4:
            get_whole_numbers_input(&first_number, &last_number);
            if (first_number > last_number)
            {
               printf("\n%d and %d properly ordered are: "
                       ,first_number, last_number);
               ascending_order(&first_number, &last_number);
               printf("%d and %d", first_number, last_number);
            }
            else
               printf("\n%d and %d are already in order",
               first_number, last_number);
            break;

         /* Quit the program                                                    */
         default:
            printf("\nError #%d occurred in main().", MENU_CHOICE_ERROR);
            printf("\nAn impossible menu choice occurred.");
            printf("\nThe program is aborting.");
            exit(MENU_CHOICE_ERROR);
      }  
   }
   /* Print a goodbye message and quit the program */
   printf("\nThanks for processing numbers. Have a nice day! ;-)");
   printf("\n");
   return 0;
}

/*********************************************************************************/
/*                      Print the program heading                                */
/*********************************************************************************/
void print_heading() 
{
   printf("\n==========================================================");
   printf("\n         Program Number: %d",     PROGRAM_NUMBER);
   printf("\n         Programmer: %s",         USER_NAME);
   printf("\n         PCC Course Number: %s",  COURSE_NUMBER);
   printf("\n=========================================================");
   printf("\n   Miscellaneous operations on your two whole numbers."); 
   printf("\n");
   return;
}

/********************************************************************************/
/*                      Print the program Menu                                  */
/********************************************************************************/
void print_menu() 
{
   printf("\n Make a selection from the following menu:");
   printf("\n------------------------------------------");
   printf("\n 1 - Add two whole numbers");
   printf("\n 2 - Raise the 1st number to the power of the 2nd");
   printf("\n 3 - Sum all numbers between two whole numbers");
   printf("\n 4 - Put two whole numbers into ascending order");
   printf("\n 5 - Quit");
   return;
}

/********************************************************************************/
/*                              Get menu choice                                 */
/********************************************************************************/
int get_menu_input()
{
   int menu_choice; /* The user choice                                          */  

   printf("\nEnter your menu selection (%d-%d): ", 
         MIN_MENU_CHOICE, MAX_MENU_CHOICE);             
   scanf("%d", &menu_choice);
   return menu_choice;
}

/********************************************************************************/
/*                              Get the numbers                                 */
/********************************************************************************/
void get_whole_numbers_input(int *p_first_number, int *p_last_number) 
{
   printf("\n Type any two whole numbers now:");
   printf("\n    What is your first number: ");
   scanf ("%d", p_first_number);
   printf("    Give me your second number: ");
   scanf ("%d", p_last_number);
   return;
}

/********************************************************************************/
/*                        Get the sum of two numbers                            */
/********************************************************************************/
int add_numbers(int first_number, int last_number)
{
   return first_number + last_number;
}

/********************************************************************************/
/*                        Get the power of a number                             */
/*******************************************************************************/
int raise_to_power(int base_number, int exponent_number)
{
   int power_solution = 1,/* The result of the base raised to the exponent      */
       counter;           /* Loop counter                                       */

   for (counter = 1; counter <= exponent_number; counter++)
   {
      power_solution *= base_number;
   }
   return power_solution;
}

/********************************************************************************/
/*             Calculates the inclusive sum of a number range                   */
/********************************************************************************/
int calc_range_sum(int range_small_number, int range_large_number) 
{
   int range_sum = 0, /* The sum of small and large number                      */
       counter;

   for (counter = range_small_number; counter <= range_large_number; 
        counter++) 
        range_sum += counter; 
   return range_sum;
}

/********************************************************************************/
/*                  Get the two number in ascending order                       */
/********************************************************************************/
void ascending_order(int *p_first_number, int *p_last_number)
{
   int swap_value; 
/* Swap the numbers if they are not in ascending order                          */
   if (*p_first_number > *p_last_number)
   {
       swap_value     = *p_first_number;
      *p_first_number = *p_last_number;
      *p_last_number  =  swap_value;
   }
   return;
}

