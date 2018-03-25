/* Program that compares 2 files and prints 
   the first line where they differ */

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <errno.h>

#define  BUF_LEN  64
 
int main(int argc, char *argv[])
{
  FILE* fp;
  char* quit = "exit";
  char* input_file = argv[1];
  char in[BUF_LEN];
  char test[BUF_LEN];
  int found_it = 0;
  
  if ((argc > 2) || (argc == 1))
  {
    printf("Usage: main [filename]\n");
    exit(EXIT_FAILURE);
  }

  fp = fopen(input_file, "r");

  if (fp == NULL)
  {
    if (argv[1] != NULL)
    {
      printf("error: %s does not exist\n", argv[1]);
      exit(EXIT_FAILURE);
    }
  }
  else
  {
    while (scanf("%s", test) == 1)
    {
      if ((strcmp(quit, test) == 0))
      {
	exit(EXIT_SUCCESS);
      }

      rewind(fp);
      while (fscanf(fp,"%s",in) == 1)
      {
	if ((strcmp(in, test) == 0))
	{
	  found_it++;
	}  
      }
      printf("Number of \"%s\" in %s: %d\n",test, input_file, found_it);
      found_it = 0;
    }
    fclose(fp);
    return 0;
  }
} 

