/* This code simulates the adition of a 
program in the main memory  */

/* Begin - Library declaration */
#include "errors.h"
#include "functions.h"
/* End - Library declaration */

int main(int argc, char *argv[])
{
  for(int cont = 0; cont < argc; cont++)
    printf("%d Parametro: %s\n", cont, argv[cont]);

  error_number_arguments(argc);
  //error_invalid_parameters(argv); -> não consegue ler os parâmetros
  char *file_name = argv[1];

  remove("correct.txt"); //delete file

  // Begin - Variable declaration 
  FILE *adr_txt;
  int *secondary_mem_adr;
  int pagenum = 0; //page number
  int offset = 0; //offset 
  // End - Variable declaration

  //Open file
  adr_txt = fopen(file_name, "r");
  error_open_file(adr_txt);

  //Count lines
  int c = count_file_lines(adr_txt);
  error_file_empty(c);

  //Get numbers from file and put them in array
  secondary_mem_adr = (int*) malloc(c*sizeof(int));
  secondary_mem_adr = get_str_int(c); 

  //Close file
  fclose(adr_txt);

  for (int i = 0; i < c; i++) {
    int count = 0;
    FILE *arquivo;
    arquivo = fopen("correct.txt", "a");
    fprintf(arquivo, "Num: %d\n", secondary_mem_adr[i]);
    fclose(arquivo);
  
    while(count != 2) { //Call the same instruction twice
      dec_to_bin(secondary_mem_adr[i]);
      pagenum = get_page_number();
      in_page_table(pagenum);
      count++;
    }
  }
  
}