/* What the code does */

/* Begin - Library declaration */
#include "errors.h"
#include "functions.h"
/* End - Library declaration */


/* Begin - Function declaration */

//Errors
int error_open_file(FILE *file);
int error_file_empty(int count);

//Others
int* get_str_int(int count);
int count_file_lines(FILE *file);
void int_to_bin(int i);
int my_pow(int a, int b);
void my_strrev(char *str);
void divide_binary(char* binary);

/* End - Function declaration */


int main()
{
  //numeros -> colocar em array
  //pegar array -> transformar os número em binário
  //ou fazer shift que nem mendas falou
  //8bits -> page index
  //12107 -> 1011110|1001011 -> 94 | 75
  //12107 >> 7 = 94

  /* Begin - Variable declaration */
  FILE *adr_txt;
  int *secondary_mem_adr;
  /* End - Variable declaration */

  //Open file
  adr_txt = fopen("addresses.txt","r");
  error_open_file(adr_txt);

  int_to_bin(12108);

  //Count lines
  int c = count_file_lines(adr_txt);
  error_file_empty(c);

  //Get numbers from file and put them in array
  secondary_mem_adr = (int*) malloc(c*sizeof(int));
  secondary_mem_adr = get_str_int(c); 

  //Close file
  fclose(adr_txt);
}