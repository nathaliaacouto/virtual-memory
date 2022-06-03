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
  int n[BIN_SIZE];
  int bin = 0, a = 0;

  for (a = 0; i > 0; a++) {
    n[a] = i % 2;
    i = i/2;
  }

  //"a" will be equivalent to the size of the binary
  //thus, if "a" is less than BIN_SIZE, more zeros(0) need to be added
  while (a < BIN_SIZE) { 
    n[a] = 0;
    a++;
  }
  
  char str[128];
  int frame = 0;
  for (int f = 0; f < BIN_SIZE; f++) {
    sprintf(&str[f], "%d", n[f]);
  }
  
  //We must reverse the string to get the final binary
  my_strrev(str);
}

/* Inverts a String and stores the result in another string */
void my_strrev(char *str) 
{
  char bin[BIN_SIZE];
  int j = 0;
  for (int i = (BIN_SIZE - 1); i >= 0; i--) {
    bin[j] = str[i];
    j++;
  }

  divide_binary(bin);
}

/* Divides a string in two, stroring both parts in
two other strings of half the size of Binary */
void divide_binary(char *binary)
{
  int size = BIN_SIZE/2;
  char *pt1;
  char *pt2;
  int j = 0;

  pt1 = (char*) malloc(size*sizeof(char));
  pt2 = (char*) malloc(size*sizeof(char));

  for (int i = 0; i < size; i++) {
    pt1[i] = binary[i];
  }
  for (int i = size; i < BIN_SIZE; i++) {
    pt2[j] = binary[i];
    j++;
  }
  
  pagenum_offset(pt1, pt2);
}

/* Gets Page number and Offset in binary
and turn both to integer, then calls another function
to turn them to decimal, storing the final value
in the global variable */
void pagenum_offset(char *pg, char *of)
{
  int pagenum_bin = atoi(pg);
  int offset_bin = atoi(of);

  pagenum_dec = bin_to_dec(pagenum_bin);
  offset_dec = bin_to_dec(offset_bin);
}

/* Power of a number (a^b) */
int my_pow(int a, int b) 
{
  int result = a; 
  if (b == 0) {
    result = 1;
  }
  if (b == 1) {
    result = a;
  }
  for (int i = 0; i < (b-1); i++) { 
    result = result * a;
  }
  return result;
}

/* Gets a binary number and turn to decimal */
int bin_to_dec(int binary)
{
  int decimal = 0, aux = 0;

  for (int i = 0; i < BIN_SIZE; i++) {
    aux = binary % 10;
    decimal = decimal + (aux * (my_pow(2,i)));
    binary = binary/10;
  }
  return decimal;
}

/* Returns the Page Number as a decimal */
int get_page_number(void)
{
  return pagenum_dec;
}

/* Returns the Offset as a decimal */
int get_offset(void)
{
  return offset_dec;
}

/* PAGE TABLE FUNCTIONS */

/* Gets a number and see if it is already
inside the page table */
int in_page_table(int num)
{
  int pg[2]; 
  int j = 0;
  if (page_table[num][0] == num) {
    in_main_men(num);
  }
  else {
    page_fault();
  }
}

/* Counts the amout of Page Faults */
void page_fault(void)
{
  pagefault++;
  //faz page fault 18x -> ou seja, não está achando na memória
  open_second_mem();
}

/* Opens the Secondary Memory (in this 
implementation is equivalent to the BACKING_STORE.bin)
and find the page with the same number as the 
current page number. Stores de content of that page in a array */
void open_second_mem(void) 
{
  FILE *second_mem;
  int *aux;
  aux = (int*) malloc(256*sizeof(int));

  second_mem = fopen("BACKING_STORE.bin", "rb");
  error_open_file(second_mem);

  fseek(second_mem, pagenum_dec, SEEK_SET);
  fread(aux, 256, 1, second_mem); //está lendo sempre o mesmo número
  
  fclose(second_mem);

  add_to_main_mem(aux);
}

/* Adds the array to a empty frame
in the Main Memory */
void add_to_main_mem(int* arr)
{
  for(int i = 0; i < MAIN_MEM_SIZE; i++) {
    if(main_memory[i] == NULL) {
      main_memory[i] = arr;
      up_page_table(i);
      return;
    }
  }
}

/* Update the Page Table */
void up_page_table(int frame)
{
  page_table[pagenum_dec][0] = frame;
  page_table[pagenum_dec][1] = ON;
}

/* Check if a array is already
inside a frame in the Main Memory */
void in_main_men(int index)
{
  if (page_table[pagenum_dec][1] == ON) {
    make_file();
  } 
  else {
    open_second_mem();
  }
}

void make_file(void)
{
  FILE *file;
  file = fopen("correct.txt", "w");
  fprintf(file, "Page number: %d, Main mem: %d, Offset: %d", pagenum_dec, page_table[pagenum_dec][0], offset_dec);
  fclose(file);
}