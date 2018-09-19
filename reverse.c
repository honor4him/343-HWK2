#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

int main(int argc, char** argv) {

  if (argc != 3) {
    printf ("Please pass the <filename> and end <fileresult> to execute.\n");
    exit(1);
  }

  // File contents
  char* buffer;

  // Find file size
  char* filename = argv[1];
  struct stat st;
  stat(filename, &st);
  int size = st.st_size;

  // Pass file to read_file
  read_file(filename, &buffer);

  char* fileresult = argv[2];


  // Testing **************
  printf("\nEnd of main reached.\n");
}
