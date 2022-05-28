/* Check for error opening a file */
int error_open_file(FILE *file)
{
  if (file == NULL) {
    printf("Error opening file");
    exit(0);
  }
  return 0;
}
