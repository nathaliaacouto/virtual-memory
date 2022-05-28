/* What the code does */

/* Begin - Library declaration */
#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "file_functions.h"
/* End - Library declaration */

/* Begin - Function declaration */
int error_open_file(FILE *file);
void get_str_int(FILE *file, int count);
int count_file_lines(FILE *file) ;
/* End - Function declaration */


int main()
{
  /* Begin - Variable declaration */
  FILE *adr_txt;
  /* End - Variable declaration */

  //Open file
  adr_txt = fopen("addresses.txt","r");
  error_open_file(adr_txt);

  //Count lines
  int c = count_file_lines(adr_txt);

  //Get String and turn into Int
  get_str_int(adr_txt, c);

  //Close file
  fclose(adr_txt);
}
