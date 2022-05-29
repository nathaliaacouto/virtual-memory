#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* File functions */
int* get_str_int(int count);
int count_file_lines(FILE *file);

/* Number functions */
/* passo a passo:
1. decimal para binário -> int_to_bin
2. inverter binário -> my_strrev
3. dividir binário em dois -> divide_binary
4. binário para decimal -> bin_to_int
*/
void int_to_bin(int i);
void my_strrev(char *str);
void divide_binary(char *binary);
int my_pow(int a, int b);
void bin_to_int(int binary);