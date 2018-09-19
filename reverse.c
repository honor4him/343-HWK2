#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

/********************************************************************
 * This program takes in a file and reverses it's output. This is done
 * using pointers and double pointers in file_utils.c.
 *
 * @author Zachary Thomas
 * @version 1.0
 *******************************************************************/

int main(int argc, char** argv) {

  /** Holds file contents*/
  char* buffer;

  /** For file size*/
  int size;

  /** Input Filename argument*/
  char* filename = argv[1];

  /** Output Filename argument*/
  char* fileresult = argv[2];

  // Only continue if there are three command line arguments.
  if (argc != 3) {
    printf ("Please pass the <filename> and end <fileresult> to execute.\n");
    exit(1);
  }

  // Pass file to read_file
  size = read_file(filename, &buffer);

  // Begin writing the file backwards
  char* reverse = (char*)malloc(size * sizeof(char));

  // Use for loop to reverse file contents
  for(int i = 0; i < size; i++){
    reverse[size - 1 - i] = buffer[i];
  }

  // Call write_file to output reversed contents to file
  write_file(fileresult, reverse, size);

  // Free allocated memory
  free(buffer);
  free(reverse);

  // Print if done correctly
  printf("\nSuccess.\n\n");

  return 0;
}
