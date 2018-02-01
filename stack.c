/* stack.c */

/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability, not by
 * modifying this code, but by providing a cleverly
 * constructed input. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BSIZE 517

int bof(char *str)
{
  char buffer[32];

  /* The following allows buffer overflow */ 
  memcpy(buffer, str, BSIZE);

  return 1;
}


int main(int argc, char **argv)
{
  char str[BSIZE];
  FILE *badfile;
  char *badfname = "badfile";

  badfile = fopen(badfname, "r");
  fread(str, sizeof(char), BSIZE, badfile);
  bof(str);

  printf("Returned Properly\n");
  return 1;
}
