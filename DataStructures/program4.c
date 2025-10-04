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
#define QUIT              0       /* Quit program                     */
#define DATA_ALLOC_ERR    1       /* Error code if malloc fails       */
#define END_OF_STRING     '\0'    /* End of string marker             */
#define MAX_CUSTOMER      100     /* Maximum number of customers      */
#define MIN_CUSTOMER      2       /* Minimum number of customers      */
#define MAX_NAME_LENGTH   20      /* Maximum length of a name         */


/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
  /* Print program heading                                            */
void print_instructions();
  /* Print brief instruction of the program's purpose before each run */
int  get_num_of_customers();
  /* Ask user how many values they want to enter with validation      */
void get_customers(float *p_start, int quantity);
  /* Read values and convert negatives to positives immediately       */
void clean_up_names(float *p_start, int quantity);
  /* Sort the array into descending order using selection sort        */ 
  /* implemented with pointer aritmetic                               */
void sort_customers(float *p_start, int quantity);
  /* Print sorted values, if consecutive values are equal, mark them  */
  /* as duplicate for clarity                                         */
float print_customers(float *p_start, int quantity);
  /* Return the sum of all values                                     */

/**********************************************************************/
/*                              Main Function                         */
/**********************************************************************/
int main(void)
{
   int   quantity;  /* Number of data values entered by the user      */
   p_instruct_costumer_data_base;
   /*taks in main*?

   while loop
   printf("\n\n\n");
   print_heading();

   /* Repeat until user decides to quit                               */
   while (print_instructions(), (quantity = get_quantity()) 
          != QUIT_VALUE)
   {
       /* Allocate memory for the data values otherwise               */
       /* terminate the program                                       */
       p_data = (float *)malloc(sizeof(*p_data) * quantity);

       if (p_data == NULL)
       {
           printf("\nError #%d: Unable to allocate memory for data.", 
                  ALLOC_ERROR_CODE);
           printf("\nProgram is terminating.\n\n");

           exit  (ALLOC_ERROR_CODE);
       }

       /* get data and convert negatives                              */
       get_data(p_data, quantity);
       /* Sort the array into descending order                        */
       sort_desc_data(p_data, quantity);
       /* Print the sorted data with duplicates flagged               */
       print_sorted_data(p_data, quantity);
       /* Compute and print the total sum                             */
       {
           total = get_sum(p_data, quantity);
           printf("                   ---------");
           printf("\n                 %9.2f total\n", total);
       }

       /* Free the memory before next loop iteration                  */
       free(p_data);
   }

   /*print a goodbye message and terminate the program                */
   printf("\nThanks for processing data. Have a nice day! :-)\n");
   printf("\n\n\n\n");
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
   printf("\nThis program processes experimental scientific data.");
   printf("\n----------------------------------------------------");
   return;
}

/**********************************************************************/
/*              Get the quantity of experimental scientific data      */
/**********************************************************************/
int get_quantity()
{
   int quantity;

   do 
   {
       printf("\nHow many data values are there (%d to %d, %d=quit): ",
               MIN_DATA_COUNT, MAX_DATA_COUNT, QUIT_VALUE);
       scanf ("%d", &quantity);
        
   }
   while ((quantity != QUIT_VALUE) && 
          (quantity < MIN_DATA_COUNT || quantity > MAX_DATA_COUNT));

   return quantity;
}

/**********************************************************************/
/*                           Get Data Values                          */
/**********************************************************************/
void get_data(float *p_start, int quantity)
{
    float *p_data;
    for (p_data = p_start; p_data < p_start + quantity; ++p_data)
    {
        printf("    Enter data value %d: ", (int)(p_data - p_start) + 1);
        scanf("%f", p_data);
    
        if (*p_data < 0.0f)
        {
            printf("        Negative %.2f converted to positive %.2f\n", 
                   *p_data, -*p_data);
            *p_data = -*p_data;
        }
    }
    return;
}

/**********************************************************************/
/*       Sort the scientific data to put it into descending order     */
/**********************************************************************/
void sort_desc_data(float *p_start, int quantity)
{
   float *current_position, 
         *scan_position, 
         *largest_position;

    for (current_position = p_start; 
         current_position < p_start + quantity - 1; 
         ++current_position)
    {
        largest_position = current_position;

        for (scan_position = current_position + 1; 
             scan_position < p_start + quantity; 
             ++scan_position)
        {   
            if (*scan_position   > *largest_position)
                largest_position = scan_position;
        }    
             
        if  (largest_position != current_position) 
        {
            float temp         = *current_position;
            *current_position  = *largest_position;
            *largest_position  = temp;
        }
    }
    return;
}


/**********************************************************************/
/*                          Print Sorted Data                         */
/**********************************************************************/
void print_sorted_data(float *p_begin, int quantity)
{
    float *p_sorted_data;
          
    printf("\nThe data in descending order (with duplicates noted):");
    printf("\n-----------------------------------------------------");
          
    for   (p_sorted_data = p_begin; p_sorted_data < p_begin + quantity; 
          ++p_sorted_data)
    {
        printf("\n                 %9.2f", *p_sorted_data);
              
        if    (p_sorted_data > p_begin && *p_sorted_data == 
               *(p_sorted_data - 1))
        {
           printf(" (duplicate)");
        }
    }
    printf("\n");

    return;
}

/**********************************************************************/
/*                            Get the sum                             */
/**********************************************************************/
float get_sum(float *p_start, int quantity)
{
    float  sum = 0.0f,
           *p_current_data;
          
    for    (p_current_data = p_start; p_current_data < p_start + quantity; 
           ++p_current_data)
           
           sum += *p_current_data;
           
    return sum;
}