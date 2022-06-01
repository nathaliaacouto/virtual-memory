#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BIN_SIZE 16 //size of Binary
#define PAGE_TABLE_SIZE 256
int pagenum_dec; //page number
int offset_dec; //offset
int page_table[256][2];

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

int in_page_table(int num);

/*
1. decimal para binário -> dec_to_bin
2. inverter binário -> my_strrev
3. dividir binário em dois -> divide_binary
4. pegar offset e page number -> pagenum_offset
5. binário para decimal -> bin_to_dec
*/