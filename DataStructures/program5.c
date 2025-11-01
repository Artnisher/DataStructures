/**********************************************************************/
/*                                                                    */
/* Program Name: program5 - Recursively calculate even sum in a range inclusively      */
/* Author:       Arturo Chira                                         */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: October 31, 2025                                     */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
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
/* This program recursively determines the sum of all even whole      */ 
/* numbers within a specified inclusive range. The user provides the  */
/* starting and ending values of the range, and the program validates */
/* the input before proceeding with the calculation.                  */
/*                                                                    */
/* The recursive function performs successive calls until the range   */
/* limit is reached, accumulating the total of even values. The result*/
/* is then displayed along with the corresponding range information.  */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>    /* printf, scanf                                */
#include <ctype.h>    /* toupper                                      */


/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER     "CS227" /* PCC assigned course number       */
#define PROGRAM_NUMBER    "5"     /* Teacher asigned program number   */
#define LAST_NAME         "Chira" /* The programer's last name        */
#define DATA_ALLOC_ERR    1       /* Error code if malloc fails       */
#define MAX_VALUE         5000    /* Maximum number of customers     */
#define MIN_VALUE        -5000    /* Minimum number of customers   */
#define POSITIVE_ANSWER   'y'     /* Maximum length of a name         */
#define NEGATIVE_ANSWER   'n'     /* Minimum length of a name        */


/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
  /* Print program heading                                            */
void print_instructions();
  /* Print brief instruction of the program's purpose before each run */
char get_response();
  /* Get user response to continue or quit the program                */
void  get_range(int *p_start_range, int *p_end_range);
  /* Get the start and end range from the user                        */
int  swap_numbers(int *p_start_range, int *p_end_range);
  /* Swap the start and end range if needed                           */
long even_numbers(int p_start_range, int p_end_range);
  /* Print even numbers in the range                                  */
int  sum_even_numbers(int p_start_range, int p_end_range);
  /* Calculate the sum of even numbers in the range                   */

/**********************************************************************/
/*                              Main Function                         */
/**********************************************************************/
int main()
{
  char answer;
  int p_start_range,
      p_end_range;
   printf("\n\n\n\n\n\n");
   print_heading();                                     
   print_instructions();
   /* Processing a range of numbers until user quits                  */
   while ((answer = get_response()) == POSITIVE_ANSWER)
   {
       /* Get the start and end range from the user                   */
       get_range(&p_start_range , &p_end_range);
       printf("\nProcessing the range %d to %d\n", p_start_range, p_end_range);
       swap_numbers(&p_start_range, &p_end_range);
        
       sum_even_numbers(p_start_range, p_end_range);  
   }
  
   /* Print goodbye message before terminate the program              */
   printf("\nThanks for \"even summing.\"  Have a nice day! ;-)\n");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                     Print Heading Function                         */
/**********************************************************************/
void print_heading()
{
   printf("\n========================================================");
   printf("\n                Program Number: %s",    PROGRAM_NUMBER);
   printf("\n                Programmer: %s",        LAST_NAME);
   printf("\n                PCC Course Number: %s", COURSE_NUMBER);
   printf("\n========================================================");
   return;
}
/**********************************************************************/
/*                     Print the Instructions                         */
/**********************************************************************/
void print_instructions()
{
   printf("\nThis program recursively calculates the sum of all\n");
   printf("even whole numbers between two numbers inclusively.\n");
   printf("You are repeatedly asked to enter in the start and\n");
   printf("end of a range, and the sum of all even numbers in\n");
   printf("that range is calculated and printed.  Information\n");
   printf("about the recursive action of the function is also\n");
   printf("printed so the recursive nature of the calculation\n");
   printf("                 may be observed.\n"); 
   return;
}

/**********************************************************************/
/*                          Get Response                              */
/**********************************************************************/
char get_response()
{
   char answer[2];

   printf("\n");
   do
   {
       printf("\nDo you want to process another range (y or n): ");
       scanf (" %1s", &answer[0]);
       answer[0] = tolower(answer[0]);
   }
   while (answer[0] != POSITIVE_ANSWER && answer[0] != NEGATIVE_ANSWER);
  
   return answer[0];
}

/**********************************************************************/
/*                          Get Range                                 */
/**********************************************************************/
void get_range(int *p_start_range, int *p_end_range)
{
  printf("\n");
    do
    {
        printf("Enter in the first number (from %d to %d): ", 
               MIN_VALUE, MAX_VALUE);
        scanf ("%d", p_start_range);
    }
    while (*p_start_range < MIN_VALUE || *p_start_range > MAX_VALUE);

    printf("\n");
    do
    {
      printf("Enter in the last number (from %d to %d):", 
               MIN_VALUE, MAX_VALUE);
        scanf ("%d", p_end_range);
    }
    while (*p_end_range   < MIN_VALUE || *p_end_range   > MAX_VALUE);
    
    return;
}
/**********************************************************************/
/*                          Swap Range                                */
/**********************************************************************/
int swap_numbers(int *p_start_range, int *p_end_range)
{
    if(*p_start_range > *p_end_range)
    {
        *p_start_range = *p_start_range + *p_end_range;
        *p_end_range   = *p_start_range - *p_end_range;
        *p_start_range = *p_start_range - *p_end_range;
    }
    return 0;
}

/**********************************************************************/
/*                         even numbers                               */
/**********************************************************************/
long even_numbers(int p_start_range, int p_end_range)
{
    long  result;

    printf("    Entering sum function for range %d to %d\n", 
                                            p_start_range, p_end_range);
    if(p_start_range > p_end_range)
    {
        printf("\n");
       // printf("    Exiting sum function for range %d to %d\n", 
          //                                  p_start_range, p_end_range);
        return 0;
    }
    
    if(p_start_range % 2 == 0)
    {
        printf("      Adding: %d\n", p_start_range);
        result = (long)p_start_range + even_numbers(p_start_range + 1, p_end_range);
    }
    else
    {
        printf("      Skipping: %d\n", p_start_range);
        return even_numbers(p_start_range + 1, p_end_range);
    }

    printf(" Exiting sum function for range %d to %d with result: %ld\n", 
                                            p_start_range, p_end_range, result);

    return result;

}
/**********************************************************************/
/*                     Sum even numbers                               */
/**********************************************************************/
int sum_even_numbers(int p_start_range, int p_end_range)
{
    long total = even_numbers(p_start_range, p_end_range);
    printf("\n The sum of even numbers is: %ld\n", total);
    return 0;
}