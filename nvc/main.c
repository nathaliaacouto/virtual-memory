/* What the code does */

/* Begin - Library declaration */
#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "file_functions.h"
/* End - Library declaration */

/* Begin - Function declaration */
int error_open_file(FILE *file);
void get_str_int(void);
int count_file_lines(FILE *file);
/* End - Function declaration */


int main()
{
  /* Begin - Variable declaration */
  FILE *adr_txt;
  int *secondary_mem_adr;
  /* End - Variable declaration */

  //Open file
  adr_txt = fopen("addresses.txt","r");
  error_open_file(adr_txt);

  //Count lines
  int c = count_file_lines(adr_txt);

  //Allocate space for array
  secondary_mem_adr = (int*) malloc(c*sizeof(int));

  //Get String and turn into Int
  get_str_int();

  //Close file
  fclose(adr_txt);
}