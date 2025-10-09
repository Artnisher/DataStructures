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

#include <stdio.h>  /* printf, scanf                                  */
#include <stdlib.h> /* malloc, free, exit                             */
#include <string.h> /* memcpy                                         */                    

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER     "CS227" /* PCC assigned course number       */
#define PROGRAM_NUMBER    3       /* Teacher assigned program number  */
#define LAST_NAME         "Chira" /* The programmer's last name       */
#define MIN_DATA_COUNT    2       /* Minimum number of values allowed */
#define MAX_DATA_COUNT    100     /* Maximum number of values allowed */
#define QUIT              0       /* Quit program                     */
#define ALLOC_ERROR_CODE  1       /* Error code if malloc fails       */


/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading    ();
  /* Print the program heading                                        */
void print_instruction();
  /* Print brief instruction of the program's purpose before each run */
int  get_quantity     ();
  /* Get the quantity of values with validation                       */
void get_data         (float *p_start, int quantity);
  /* Read values and convert negatives to positives                   */
void sort_desc_data   (float *p_start, int quantity);
  /* Sort the array into descending order using selection sort        */ 
  /* implemented with pointer arithmetic                               */
void print_sorted_data(float *p_start, int quantity);
  /* Print sorted values, if consecutive values are equal, mark them  */
  /* as duplicate for clarity                                         */
float get_sum         (float *p_start, int quantity);
  /* Return the sum of all values                                     */
void print_sum        (float data_sum);
/**********************************************************************/
/*                              Main Function                         */
/**********************************************************************/
int main()
{
   int   quantity;  /* Number of data values entered by the user      */
   float *p_data;   /* Pointer to dynamically allocated array of data */
    
   /* Print program heading once at the beginning                     */
   printf("\n\n\n\n\n\n");
   print_heading();

   /* Repeat until user decides to quit                               */
   while (print_instruction(), (quantity = get_quantity()) 
          != QUIT)
   {
       /* Allocate memory for the data values otherwise               */
       /* terminate the program                                       */
       if((p_data = (float *)malloc(sizeof(*p_data) * quantity))== NULL)
       {
           printf("\nError #%d: Unable to allocate memory for the data.", 
                                                       ALLOC_ERROR_CODE);
           printf("\nThe Program is aborting.");
           printf("\n\n\n\n\n\n");
           exit  (ALLOC_ERROR_CODE);
       }

       /* get data and convert negatives                              */
       get_data         (p_data, quantity);
       /* Sort the array into descending order                        */
       sort_desc_data   (p_data, quantity);
       /* Print the sorted data with duplicates flagged               */
       print_sorted_data(p_data, quantity);
       /* Compute and print the total sum                             */
       print_sum        (get_sum(p_data, quantity));
       
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
   printf("\n                Program Number: %d",    PROGRAM_NUMBER);
   printf("\n                Programmer: %s",        LAST_NAME);
   printf("\n                PCC Course Number: %s", COURSE_NUMBER);
   printf("\n========================================================");
   return;
}

/**********************************************************************/
/*                         Print the instruction                      */
/**********************************************************************/
void print_instruction()
{
   printf("\n\n\nThis program processes experimental scientific data.");
   printf(    "\n----------------------------------------------------");
   printf("\n");
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
       printf("How many data values are there (%d to %d, %d=quit): ",
               MIN_DATA_COUNT, MAX_DATA_COUNT, QUIT);
       scanf ("%d", &quantity);
        
   }
   while ((quantity < MIN_DATA_COUNT || quantity > MAX_DATA_COUNT) && 
         (quantity != QUIT));

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
            printf("        Negative %.2f converted to positive %.2f",
                    *p_data, -*p_data);
            printf("\n");
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
   float *p_largest_data,
         *p_data,                                     
         *p_sort_start,
         *p_sort_data;

   if((p_sort_start = (float *)malloc(sizeof(*p_start) * quantity)) == NULL)
   {
      printf("\nError #%d occurred in sort_desc_data().", ALLOC_ERROR_CODE);
      printf("\nUnable to allocate memory for the sorted experimental");
      printf(" scientific data.");
      printf("\nThe program is aborting.");
      printf("\n\n\n\n\n\n");
      exit  (ALLOC_ERROR_CODE);
   }

   for(p_sort_data = p_sort_start; (p_sort_data - p_sort_start) < quantity; 
                                                          p_sort_data++)
   {
      *p_sort_data = -1.0f;
      p_largest_data = NULL;

      for(p_data = p_start; (p_data - p_start) < quantity; p_data++)
      {
         if(*p_data > *p_sort_data)
         {
            p_largest_data = p_data;
            *p_sort_data   = *p_data;
         }
      }

      if(p_largest_data != NULL)
      {
         *p_largest_data = 0.0f;
      }
   }

   /* Copy experimental scientific data sorted into descending mode    */
   memcpy(p_start, p_sort_start, sizeof(*p_sort_start) * quantity);
   /* Free the memory used for the sorted data                        */
   free(p_sort_start);

   return;
}

/**********************************************************************/
/*                          Print Sorted Data                         */
/**********************************************************************/
void print_sorted_data(float *p_start, int quantity)
{
    float *p_sorted_data;
          
    printf("\nThe data in descending order (with duplicates noted):");
    printf("\n-----------------------------------------------------");
          
    for(p_sorted_data = p_start; p_sorted_data < p_start + quantity; 
                                                        ++p_sorted_data)
    {
        printf("\n                 %9.2f", *p_sorted_data);
              
        if(p_sorted_data > p_start && *p_sorted_data == 
                                                   *(p_sorted_data - 1))
        {
           printf(" (duplicate)");
        }
    }
    printf("\n");

    return;
}

/**********************************************************************/
/*                Get the sum of the scientific data                  */
/**********************************************************************/
float get_sum(float *p_start, int quantity)
{
    float sum = 0.0f,
          *p_current_data;
          
    for(p_current_data = p_start; p_current_data < p_start + quantity; 
                                                      ++p_current_data)
           
        sum += *p_current_data;
           
    return sum;
}

/**********************************************************************/
/*                   Print the sum of the scientific data             */
/**********************************************************************/
void print_sum(float data_sum)
{
    printf("\n                 ---------");
    printf("\n                 %9.2f total", data_sum);
    return;
}