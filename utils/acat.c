#include <stdio.h>
#include <stdlib.h>

static void print_file( char* filename);

int main(int argc, char *argv[])
{
  for( int i = 1; i < argc; i++ )
  {
    print_file(argv[i]);
  }
}

static void print_file(char* filename)
{
  char *line;
  size_t len;
  FILE * file = fopen(filename, "r");
  while( getline(&line, &len, file) )
  {
    printf(line);
  }
  free(line);
  fclose( file );
}

