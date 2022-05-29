#include "functions.h"

/* File functions */

/* Get String from a file and turn it into Int
Then, add the numbers into a array and returns this array */
int* get_str_int(int count) 
{
  FILE *file = fopen("addresses.txt", "r");

  char adr_char[50]; 
  int a = 0;
  int *array;

  //Allocate space for array
  array = (int*) malloc(count*sizeof(int));

  while(fgets(adr_char, 50, file)) {
    int adr_char_int = atoi(adr_char);
    array[a] = adr_char_int;
    a++;
  } 

  fclose(file);

  return array;
}

/* Counts how many lines there are in a file */
int count_file_lines(FILE *file) 
{
  char a = 0;
  int count = 0;

  while (a != EOF) {
    a = getc(file);
    if (a == '\n') {
      count++;
    }
  }

  int b = count + 1;
  return b;
}

/* Number functions */

void int_to_bin(int i) 
{ 
  int n[16];
  int bin = 0;
  for (int a = 0; i > 0; a++) {
    n[a] = i % 2;
    i = i/2;
  }

  char str[128];
  int index = 0;
  for (int f = 0; f < 16; f++) {
    index += sprintf(&str[index], "%d", n[f]);
  }

  //binário fica invertido
  my_strrev(str);
}

int my_pow(int a, int b) 
{
  int result = a; 
  for (int i = 0; i < (b-1); i++) { 
    result = result * a;
  }
  return result;
}

void my_strrev(char *str)
{
  char bin[16];
  int j = 0;
  for (int i = 13; i >= 0; i--) {
    bin[j] = str[i];
    j++;
  }
  printf("\nbinário: %s\n", bin);

  divide_binary(bin);
}

void divide_binary(char *binary)
{
  char *pagenum_c;
  char *offset_c;
  int j = 0;

  pagenum_c = (char*) malloc(7*sizeof(char));
  offset_c = (char*) malloc(7*sizeof(char));

  for (int i = 0; i < (strlen(binary)/2); i++) {
    pagenum_c[i] = binary[i];
  }
  for (int i = (strlen(binary)/2); i < strlen(binary); i++) {
    offset_c[j] = binary[i];
    j++;
  }
  int pagenum = atoi(pagenum_c);
  int offset = atoi(offset_c);
  printf("\npagenum: %d, offset: %d\n", pagenum, offset);
}

void bin_to_int(int binary)
{
  int numbers[7];

  for (int i = 0; i < 7; i++) {
    numbers[i] = binary/my_pow(10,i);
  }
  printf("\narray:");
  for (int i = 0; i < 7; i++) {
    printf("%d", numbers[i]);
  }
}