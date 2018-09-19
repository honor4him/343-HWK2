#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#ifndef __FILE_UTILS_
#define __FILE_UTILS_

/********************************************************************
 * This header file defines functions that read a file with a double
 * pointer and output it to a file.
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
int read_file( char* filename, char **buffer );

/********************************************************************
 * This function outputs a given arry to a file. In this case, it
 * prints the reversed file.
 *
 * @param filename File to output
 * @param buffer Location of array
 * @param size Holds the size of the array
 * @return int Done successfully if 0.
 *******************************************************************/
int write_file( char* filename, char *buffer, int size);

#endif
