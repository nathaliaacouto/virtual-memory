#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "errors.h"

#define BIN_SIZE 16 //size of Binary
#define PAGE_TABLE_SIZE 256
#define MAIN_MEM_SIZE 128
#define SECOND_MEM_SIZE 256
#define ON 1
#define OFF 0

int pagenum_dec; //page number
int offset_dec; //offset
int page_table[PAGE_TABLE_SIZE][2];
int main_memory[MAIN_MEM_SIZE];
int pagefault; //count for page faults
int main_mem_count;
int *fifo_pointer = main_memory;
int count_fifo = 0;

/* File functions */
int* get_str_int(int count);
int count_file_lines(FILE *file);

/* Number functions */
void dec_to_bin(int i);
void my_strrev(char *str);
void divide_binary(char *binary);
void pagenum_offset(char *pg, char *of);
int get_page_number(void);
int get_offset(void);
int my_pow(int a, int b);
int bin_to_dec(int binary);
int len_of_int(int i);

/* Memory functions */
int in_page_table(int num);
void page_fault(void);
void open_second_mem(void);
void in_main_men(int index);
void add_to_main_mem(int arr);
void att_page_table(int index);
void up_page_table(int frame);
void write_file(void);
int fifo(void);
void print_arr(void);

/*
1. decimal para binário -> dec_to_bin
2. inverter binário -> my_strrev
3. dividir binário em dois -> divide_binary
4. pegar offset e page number -> pagenum_offset
5. binário para decimal -> bin_to_dec
*/