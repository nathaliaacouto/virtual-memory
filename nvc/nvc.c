/* What the code does */

/* to-do
[X] transformação de binário para decimal
[X] fazer testes com os números da tabela
[X] aplicar a questão do binário para todos os números do array
[X] fazer a tabela de páginas
[] verificar se a instrução está na tabela de páginas
[] abrir a memória secundária
[] colocar o array dentro da memória principal
[] update na page table
[X] analisar melhor o código
[] fazer os testes para ver se está funcionando

depois de colocar a instrução na memória, preciso ler ela dnv
*/

/* erros:
[X] transformação de decimal para binário incorreta
[X] divisão do número binário incorreta
[X] transformação de binário para decimal incorreta
[] offset e page num do primeiro número dá 0 
[X] funções de ler do arquivo binário 
[] fifo tá dando erro e alguns números não se acham na memória
*/

/* Begin - Library declaration */
#include "errors.h"
#include "functions.h"
/* End - Library declaration */

int main()
{
  remove("correct.txt"); //delete file

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