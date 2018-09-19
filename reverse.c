#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

int main(int argc, char** argv) {

  // Must have three arguments in comand line
  if (argc != 3) {
    printf ("Please pass the <filename> and end <fileresult> to execute.\n");
    exit(1);
  }

  // File contents
  char* buffer;

  // Size of file
  int size;

  // Pass file to read_file
  size = read_file(filename, &buffer);

  char* fileresult = argv[2];


  // Testing **************
  printf("\nEnd of main reached.\n");
}
