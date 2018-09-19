#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

/********************************************************************
 * This file_utils.c file defines functions that read a file with
 * a double pointer and output it to a file.
 *
 * @author Zachary Thomas
 * @version 1.0
 *******************************************************************/

/********************************************************************
 * This function reads the file passed to it and allocates memory
 * in the heap. This stores the location of the memory in the
 * buffer.
 *
 * @param filename File open
 * @param buffer Double pointer that holds the location of memory
 * @return int The size of the file.
 *******************************************************************/
int read_file( char* filename, char **buffer){
  // Find file size
  struct stat st;
  stat(filename, &st);
  int size = st.st_size;

  // Allocate memory
  /** Holds file contents*/
  char* fileArr;
  fileArr = (char*)malloc(size * sizeof(char));

  // Read file
  /** Open file*/
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

/********************************************************************
 * This function outputs a given arry to a file. In this case, it
 * prints the reversed file.
 *
 * @param filename File to output
 * @param buffer Location of array
 * @param size Holds the size of the array
 * @return int Done successfully if 0.
 *******************************************************************/
int write_file( char* filename, char *buffer, int size){

  // Open output file
  FILE *out = fopen(filename, "w");

  // For loop to write file
  for(int i = 0; i < size; i++){
    fprintf(out, "%c", buffer[i]);
  }

  // Close file
  fclose(out);
  return 0;
}
