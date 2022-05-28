/* Get String from a file and turn it into Int
Then, add the numbers into a array */
int* get_str_int(int count) 
{
  FILE *file = fopen("addresses.txt", "r");

  char adr_char[20]; 
  int a = 0;
  int *array;

  //Allocate space for array
  array = (int*) malloc(count*sizeof(int));

  while(fgets(adr_char, 20, file)) {
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