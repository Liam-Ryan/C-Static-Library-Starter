#include "library.h"

int hello(FILE *stream)
{
	return fprintf(stream ? stream : stdout, "Hello, World!\n");
}