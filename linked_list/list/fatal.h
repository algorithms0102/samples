#include <stdio.h>
#include <stdlib.h>

#define error(str)  fatal_error(str)
#define fatal_error(str) fprintf(stderr, "%s\n", str), exit(1)
