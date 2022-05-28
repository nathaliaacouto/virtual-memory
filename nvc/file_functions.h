/* Get String from a file and turn it into Int
Then, add Integers in a array */
void get_str_int(FILE *file, int count) 
{
  char adr_char[20]; 
  int a = 0, b = 0;
  int secondary_mem_adr[count];

  while(a != EOF){
    a = fscanf(file, "%s", adr_char);
    int adr_char_int = atoi(adr_char);
    secondary_mem_adr[b] = adr_char_int; 
    printf("oi%d\n", adr_char_int);
    b++;
  }
  
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