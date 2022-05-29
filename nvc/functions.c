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

/* Turns a decimal to binary */
void dec_to_bin(int i) 
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
  //Binary is inverted, so another function is used
  my_strrev(str);
}

/* Inverts a String and stores the result in another string */
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

/* Divides a string in two, stroring both parts in
two other strings of size 7 */
void divide_binary(char *binary)
{
  int size = 7;
  char *pt1;
  char *pt2;
  int j = 0;

  pt1 = (char*) malloc(size*sizeof(char));
  pt2 = (char*) malloc(size*sizeof(char));

  for (int i = 0; i < (strlen(binary)/2); i++) {
    pt1[i] = binary[i];
  }
  for (int i = (strlen(binary)/2); i < strlen(binary); i++) {
    pt2[j] = binary[i];
    j++;
  }
  
  pagenum_offset(pt1, pt2);
}

/* Gets Page number and Offset in binary
and turn both to decimal */
void pagenum_offset(char *pg, char *of)
{
  int pagenum_bin = atoi(pg);
  int offset_bin = atoi(of);
  printf("\npagenum: %d, offset: %d\n", pagenum_bin, offset_bin);
  bin_to_dec(pagenum_bin);
  bin_to_dec(offset_bin);
}

/* Power of a number */
int my_pow(int a, int b) 
{
  int result = a; 
  for (int i = 0; i < (b-1); i++) { 
    result = result * a;
  }
  return result;
}

/* Gets a binary number and turn to decimal */
//!NOT WORKING!
void bin_to_dec(int binary)
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