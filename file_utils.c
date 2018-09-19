#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

int read_file( char* filename, char **buffer){
  // Find file size
  struct stat st;
  stat(filename, &st);
  int size = st.st_size;

  // Allocate memory
  char* fileArr;
  fileArr = (char*)malloc(size * sizeof(char));

  // Read file
  FILE *in;
  in = fopen(filename, "r");
  char read;

  // See if file exists
  if(in == NULL){
    printf("File could not be opened.\n");
    exit(1);
  }

  // Put file into memory
  int i = 0;
  while(!feof(in)){
    fscanf(in, "%c", &read);
    fileArr[i] = read;
    i++;
  }

  // Make buffer point to file contents
  *buffer = fileArr;

  fclose(in);
  return size; // successful
}

int write_file( char* filename, char *buffer, int size){

  // Open output file
  FILE *out = fopen(filename, "w");

  // For loop to write file
  for(int i = 0; i < size; i++){
    fprintf(out, "%c", buffer[i]);
  }

  fclose(out);
  return 0;
}
