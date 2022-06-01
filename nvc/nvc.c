/* What the code does */

/* to-do
[X] transformação de binário para decimal
[] aplicar a questão do binário para todos os números do array
[] adicionar mais duas funções de tratamento de erro
*/

/* erros:
[X] transformação de decimal para binário incorreta
[X] divisão do número binário incorreta
[] transformação de binário para decimal incorreta -> PRINCIPAL ERRO
*/

/* Begin - Library declaration */
#include "errors.h"
#include "functions.h"
/* End - Library declaration */


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

  dec_to_bin(1245);

  //Count lines
  int c = count_file_lines(adr_txt);
  error_file_empty(c);

  //Get numbers from file and put them in array
  secondary_mem_adr = (int*) malloc(c*sizeof(int));
  secondary_mem_adr = get_str_int(c); 

  //Close file
  fclose(adr_txt);
}