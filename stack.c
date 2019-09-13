/* stack.c */

/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability, not by
 * modifying this code, but by providing a cleverly
 * constructed input. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BSIZE 509

int length(FILE *fp) {
  struct stat file_stats;
  fstat(fileno(fp), &file_stats);
  return file_stats.st_size;
}

int bof(char *str, unsigned int filesize)
{
  char buffer[32];

  /* The following allows buffer overflow */ 
  memcpy(buffer, str, filesize);

  return 1;
}


int main(int argc, char **argv)
{
  char dummy[BSIZE];
  char *str;
  FILE *badfile;
  char *badfname = "badfile";
  unsigned int filesize;

  badfile = fopen(badfname, "r");
  filesize = length(badfile);
  str = malloc(filesize);
  fread(str, sizeof(char), filesize, badfile);
  bof(str, filesize);

  printf("Returned Properly\n");
  return 1;
}
