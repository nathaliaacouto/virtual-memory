#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_strrev(char *str);

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
  /*

  printf("\nbinário invertido:");
  for (int a = 0; a < 16; a++) {
    if (n[a] != 1 && n[a] != 0) {
      n[a] = 7;
    }
    printf("%d", n[a]);
  }
  printf("\n");

  printf("\nsegunda parte:");
  int c = 0;
  int v = 1;
  for (int a = 16; a > 0; a--) {
    printf("\nvalor de a: %d", a);
    if (n[a] == 7) {
      continue;
    }
    else {
      int aux = my_pow(10,a);
      printf("\naux = %d", aux);
      printf("\nbin = %d", bin);
      bin = bin + (n[a] * aux);
    }
    v++;
  }

  printf("\nbin: %d", bin);
  */
}
/*
int my_pow(int a, int b) 
{
  int result = a; 
  for (int i = 0; i < (b-1); i++) { 
    result = result * a;
  }
  return result;
}
*/


void my_strrev(char *str)
{
  char bin[16];
  int j = 0;
  for (int i = 13; i >= 0; i--) {
    bin[j] = str[i];
    j++;
  }
  printf("\nbinário 1: %s\n", bin);

  divide_binary(bin);
}

void divide_binary(char* binary)
{
  printf("%s", binary);
}