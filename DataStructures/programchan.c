/**********************************************************************/
/* */
/* Program Name: program2 - Miscellaneous Operations of Two Numbers */
/* Author: */
/* Installation: Pensacola Christian College, Pensacola, Florida */
/* Course: CS227, Data Structures and Algorithms */
/* Date Written: September 22, 2017 */
/* */
/**********************************************************************/
/**********************************************************************/
/* */
/* I pledge all of the lines in this C program are my own original */
/* work and that none of the lines in this C program have been copied */
/* from anyone else, unless I was specifically authorized to do so by */
/* my CS227 instructor. */
/* */./programchan
/* */
/* Signed: _____________________________________ */
/* (signature) */
/* */
/* */
/**********************************************************************/
/**********************************************************************/
/* */
/* This program does miscellaneous operations on two whole numbers */
/* such as addition, exponentiation, calculating the inclusive sum, */
/* and setting the two numbers in ascending order. */
/* */
/**********************************************************************/
#include <stdio.h> /* printf, scanf */
#include <stdlib.h> /* exit */
#include <math.h> /* pow */
/**********************************************************************/
/* Symbolic Constants */
/**********************************************************************/
#define COURSE_NUMBER "CS227" /* PCC assigned course number */
#define PROGRAM_NUMBER 2 /* Teacher assigned program number */
#define LAST_NAME "Payani" /* The programmer's last name */
#define MIN_MENU_CHOICE 1 /* Minimum menu choice */
#define MAX_MENU_CHOICE 5 /* Maximum menu choice */
#define MENU_CHOICE_ERR 1 /* Impossible menu choice */
#define QUIT MAX_MENU_CHOICE
 /* Program exit value */
/**********************************************************************/
/* Function Prototypes */
/**********************************************************************/
void print_heading ();
 /* Print the program heading */
void print_menu ();
 /* Print the program menu */
int get_menu_choice ();
 /* Get the menu choice */
void get_whole_numbers(int *p_first_number, int *p_second_number);
 /* Get two whole numbers */
int add_two_numbers (int first_number, int second_number);
 /* Add two whole numbers */
float raise_to_power (int base, int exponent);
 /* Raise a number to the power of another number */
int sum_range (int range_start, int range_end);
 /* Calculate the inclusive sum of a whole number range */
void swap_numbers (int *p_first_number, int *p_second_number);
 /* Swap the contents of the two given numbers */
/**********************************************************************/
/* Main Function */
/**********************************************************************/
int main()
{
 int first_number, /* First whole number input */
 menu_choice, /* User menu choice */
 second_number; /* Second whole number input */

 /* Print the program heading */
 printf("\n\n\n\n\n\n");
 print_heading();
 /* Loop processing pairs of whole numbers until the user quits */
 while(print_menu(), (menu_choice = get_menu_choice()) != QUIT)
 {
 /* Get two whole numbers */
 get_whole_numbers(&first_number, &second_number);
 /* Do miscellaneous operations on two whole numbers such as */
 /* addition, exponentiation, getting the inclusive sum, and */
 /* setting the numbers in ascending order */
 switch(menu_choice)
 {
 /* Add two whole numbers */
 case 1:
 printf("\nThe sum of %d and %d is %d", first_number,
 second_number,
 add_two_numbers(first_number, second_number));
 break;
 /* Raise a number to the power of another number */
 case 2:
 printf("\n%d raised to the power of %d = %e",
 first_number, second_number,
 raise_to_power(first_number,second_number));
 break;
 /* Calculate the inclusive sum of a whole number range */
 case 3:
 printf("\nThe sum of the numbers between ");
 printf("%d and %d (inclusive)", first_number, second_number);
 if (first_number > second_number)
 swap_numbers(&first_number, &second_number);
 printf(" is %d", sum_range(first_number, second_number));
 break;
 /* Put two numbers into ascending order if they are out of */
 /* order */
 case 4:
 if (first_number > second_number)
 {
 printf("\n%d and %d properly ordered are: ",first_number, second_number);
 swap_numbers(&first_number, &second_number);
 printf("%d and %d", first_number, second_number);
 }
 else
 printf("\n%d and %d are already in order",
 first_number, second_number);
 break;

 /* Abort the program if impossible user menu choice */
 default:
 printf("\nError #%d occurred in main().", MENU_CHOICE_ERR);
 printf("\nAn impossible menu choice occurred.");
 printf("\nThe program is aborting.");
 exit(MENU_CHOICE_ERR);
 }
 }
 /* Print a goodbye message and terminate the program */
 printf("\nThanks for processing numbers. Have a nice day! ;-)");
 printf("\n\n\n\n\n\n");
 return 0;
}
/**********************************************************************/
/* Print Heading */
/**********************************************************************/
void print_heading()
{
 printf("\n========================================================");
 printf("\n Program Number: %d", PROGRAM_NUMBER);
 printf("\n Programmer: %s", LAST_NAME);
 printf("\n PCC Course Number: %s", COURSE_NUMBER);
 printf("\n========================================================");
 printf("\n Miscellaneous operations on your two whole numbers");
 return;
}
/**********************************************************************/
/* Print the program menu */
/**********************************************************************/
void print_menu()
{
 printf("\n\nMake a selection from the following menu:");
 printf( "\n-----------------------------------------");
 printf( "\n 1 - Add two whole numbers");
 printf( "\n 2 - Raise the 1st number to the power of the 2nd");
 printf( "\n 3 - Sum all numbers between two whole numbers");
 printf( "\n 4 - Put two whole numbers into ascending order");
 printf( "\n 5 - Quit");
 return;
}
/**********************************************************************/
/* Get the menu choice */
/**********************************************************************/
int get_menu_choice ()
{
 int user_menu_choice; /* The user menu choice */

 printf("\n\n");
 do
 {
 printf("Enter your menu selection (%d-%d): ", MIN_MENU_CHOICE,
 MAX_MENU_CHOICE);

 scanf("%d", &user_menu_choice);
 }

 while(user_menu_choice < MIN_MENU_CHOICE ||
 user_menu_choice > MAX_MENU_CHOICE);
 return user_menu_choice;
}
/**********************************************************************/
/* Get two whole numbers */
/**********************************************************************/
void get_whole_numbers(int *p_first_number, int *p_second_number)
{
 printf("\nType in any two whole numbers now:");
 printf("\n What is your first number: ");
 scanf ("%d", p_first_number);
 printf( " Give me your second number: ");
 scanf ("%d", p_second_number);
 return;
}
/**********************************************************************/
/* Add two whole numbers */
/**********************************************************************/
int add_two_numbers (int first_number, int second_number)
{
 return first_number + second_number;
}
/**********************************************************************/
/* Raise a number to the power of another number */
/**********************************************************************/
float raise_to_power(int base, int exponent)
{
 return (float)pow((double)base, (double)exponent);
}
/**********************************************************************/
/* Calculate the inclusive sum of a whole number range */
/**********************************************************************/
int sum_range(int range_start, int range_end)
{
 int range_counter, /* Counts through every number in the range */
 range_sum = 0; /* The inclusive sum of numbers in the range */

 for(range_counter = range_start; range_counter <= range_end;
 range_counter++)
 range_sum += range_counter;
 return range_sum;
}
/**********************************************************************/
/* Swap the contents of the two given numbers */
/**********************************************************************/
void swap_numbers(int *p_first_number, int *p_second_number)
{
 int temp_number; /* Temporary number for swap */
 temp_number = *p_first_number;
 *p_first_number = *p_second_number;
 *p_second_number = temp_number;
 return;
}
