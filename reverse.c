#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

int main(int argc, char** argv) {

  // Only continue if there are three command line arguments.
  if (argc != 3) {
    printf ("Please pass the <filename> and end <fileresult> to execute.\n");
    exit(1);
  }

  // File contents
  char* buffer;

  // Find file size
  int size;

  // Pass file to read_file
  char* filename = argv[1];
  size = read_file(filename, &buffer);

  // Begin writing the file backwards
  char* fileresult = argv[2];
  char* reverse = (char*)malloc(size * sizeof(char));

  for(int i = 0; i < size; i++){
    reverse[size - 1 - i] = buffer[i];
  }

  write_file(fileresult, reverse, size);

  free(buffer);
  free(reverse);

  // Testing **************
  printf("\nEnd of main reached.\n");
}
