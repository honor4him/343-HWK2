#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#ifndef __FILE_UTILS_
#define __FILE_UTILS_

int read_file( char* filename, char **buffer );
int write_file( char* filename, char *buffer, int size);

#endif
