/* What the code does */

/* to-do
[X] transformação de binário para decimal
[X] fazer testes com os números da tabela
[X] aplicar a questão do binário para todos os números do array
[] fazer a tabela de páginas
[] verificar se a instrução está na tabela de páginas
[] adicionar mais duas funções de tratamento de erro

depois de colocar a instrução na memória, preciso ler ela dnv
*/

/* erros:
[X] transformação de decimal para binário incorreta
[X] divisão do número binário incorreta
[X] transformação de binário para decimal incorreta
*/

/* Begin - Library declaration */
#include "errors.h"
#include "functions.h"
/* End - Library declaration */

int main()
{
  /* Begin - Variable declaration */
  FILE *adr_txt;
  int *secondary_mem_adr;
  int pagenum = 0; //page number
  int offset = 0; //offset 
  /* End - Variable declaration */

  //Open file
  adr_txt = fopen("addresses.txt","r");
  error_open_file(adr_txt);

  //Count lines
  int c = count_file_lines(adr_txt);
  error_file_empty(c);

  //Get numbers from file and put them in array
  secondary_mem_adr = (int*) malloc(c*sizeof(int));
  secondary_mem_adr = get_str_int(c); 

  //Close file
  fclose(adr_txt);

  for (int i = 0; i < 10; i++) {
    printf("%d: ", secondary_mem_adr[i]);
    dec_to_bin(secondary_mem_adr[i]);
    pagenum = get_page_number();
    in_page_table(pagenum);
  }

}