/* What the code does */

/* Begin - Library declaration */
#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "file_functions.h"
/* End - Library declaration */

/* Begin - Function declaration */
int error_open_file(FILE *file);
int* get_str_int(int count);
int count_file_lines(FILE *file);
/* End - Function declaration */


int main()
{
  //numeros -> colocar em array
  //pegar array -> transformar os número em binário
  //ou fazer shift que nem mendas falou
  //8bits -> page index

  /* Begin - Variable declaration */
  FILE *adr_txt;
  int *secondary_mem_adr;
  /* End - Variable declaration */

  //Open file
  adr_txt = fopen("addresses.txt","r");
  error_open_file(adr_txt);

  //Count lines
  int c = count_file_lines(adr_txt);

  //Get numbers from file and put them in array
  secondary_mem_adr = (int*) malloc(c*sizeof(int));
  secondary_mem_adr = get_str_int(c); 

  //Close file
  fclose(adr_txt);
}