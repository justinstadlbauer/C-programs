/* Program that compares files and prints 
   the number of times a test string from
   stdin occurs in each file. Files are
   supplied to the program as command-line 
   arguments */

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#define  BUF_LEN  64

void init_fp(int argc);
FILE* newFile(void);

FILE *file_array[64];
char* quit = "exit";
char in[BUF_LEN];
char test[BUF_LEN];
int found_it = 0;
int n = 1;
int k = 1;

int main(int argc, char *argv[])
{
	init_fp(argc-1);
	
	if (argc == 1)
	{
		printf("Usage: main [filename] [filename] ...\n");
		exit(EXIT_FAILURE);
	}

	int j;
	for (j = 0; j < argc-1; j++)
	{
		file_array[j] = fopen(argv[n], "r");
		
		if (file_array[j] == NULL)
		{
			printf("error: %s does not exist\n",argv[n]);
			exit(EXIT_FAILURE);
		}
		n++;
	}
  
	while (scanf("%s", test) == 1)
	{
		if ((strcmp(quit, test) == 0))
		{
			exit(EXIT_SUCCESS);
		}
      
		for (j = 0; j < argc-1; j++)
		{
			rewind(file_array[j]);
		}

		for (j = 0; j < argc-1; j++)
		{
			while (fscanf(file_array[j],"%s",in) == 1)
			{
				if ((strcmp(in, test) == 0))
				{
					found_it++;
				}
			}
			printf("Number of \"%s\" in %s: %d\n", test, argv[k++], found_it);
			found_it = 0;
		}
		k = 1;
	}

	for (j = 0; file_array[j] != NULL; j++)
	{
		fclose(file_array[j]);
		free(file_array[j]);	    
	}

	return 0;
  }


FILE* newFile(void)
{
	return (FILE *)malloc(sizeof(FILE*));
}

void init_fp(int argc)
{
	int j;
	for (j = 0; j < argc; j++)
	{
		file_array[j] = newFile();
	}
}
