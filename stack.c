/* stack.c */

/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability, not by
 * modifying this code, but by providing a cleverly
 * constructed input. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BSIZE 517

int bof(char *str, unsigned int filesize)
{
  char buffer[32];

  /* The following allows buffer overflow */ 
  memcpy(buffer, str, filesize);

  return 1;
}


int main(int argc, char **argv)
{
  char str[BSIZE];
  FILE *badfile;
  char *badfname = "badfile";
  unsigned int filesize;

  badfile = fopen(badfname, "r");
  filesize = fread(str, sizeof(char), BSIZE, badfile);
  bof(str, filesize);

  printf("Returned Properly\n");
  return 1;
}
