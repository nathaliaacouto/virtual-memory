#include "errors.h"

void error_number_arguments(int num)
{
  if(num != 4) {
    printf("Número de argumentos passados na linha de comando inválido\n");
    exit(0);
  }
}

void error_invalid_parameters(char **str)
{
  if(str[0] != "./vm") {
    printf("Erro no primeiro parâmetro passado na linha de comando!\n");
  }
  if(str[2] != "fifo") {
    if(str[2] == "lru") {
      printf("Infelizmente não foi possível implementar o LRU");
    }
    else {
      printf("Erro no terceiro parâmetro passado na linha de comando!\n");
    }
  }
  if(str[3] != "fifo") {
    if(str[3] == "lru") {
      printf("Infelizmente não foi possível implementar o LRU");
    }
    else {
      printf("Erro no quarto parâmetro passado na linha de comando!\n");
    }
  }
}

/* Check for error opening a file */
int error_open_file(FILE *file)
{
  if (file == NULL) {
    printf("Error opening file");
    exit(0);
  }
  return 0;
}

/* Check if file is empty */
int error_file_empty(int count)
{
  if (count < 1) {
    printf("Error: file empty");
    exit(0);
  }
  return 0;
}