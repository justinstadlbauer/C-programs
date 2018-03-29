/* Program that compares files and prints 
   the number of times a test string from
   stdin occurs in each file. Files are
   supplied to the program as command-line 
   arguments */

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#define  BUF_LEN  64

FILE *file_array[BUF_LEN];
char* quit = "exit";
char in[BUF_LEN];
char test[BUF_LEN];
int found_it = 0;
int n = 1;
int j, k;

int main(int argc, char *argv[])
{
	k = (argc - 1);
	
	if (argc == 1)
	{
		fprintf(stderr,"Usage: main [filename] [filename] ...\n");
		exit(EXIT_FAILURE);
	}

	for (j = 0; j < k; j++) 
	{
		file_array[j] = fopen(argv[n], "r");

		if (file_array[j] == NULL)
  		{
			fprintf(stderr,"error: %s does not exist\n",argv[n]);

			for (j = 0; j < k; j++)
			{
				if (file_array[j] == NULL)
				{
					continue;
				}
				else
				{
					fclose(file_array[j]);
				}
			}

			exit(EXIT_FAILURE);
		}
		n++;
	}
	
	n = 1;
	while (scanf("%s", test) == 1)
	{
		if ((strcmp(quit, test) == 0))
		{
			for (j = 0; j < k; j++)
			{
				fclose(file_array[j]);
			}
			
			exit(EXIT_SUCCESS);
		}

		for (j = 0; j < k; j++)
	        {
			rewind(file_array[j]);
		}
		
		for (j = 0; j < k; j++)
		{
			while (fscanf(file_array[j],"%s",in) == 1)
			{
				if ((strcmp(in, test) == 0))
				{
					found_it++;
				}
			}
			printf("Number of \"%s\" in %s: %d\n", test, argv[n++], found_it);
			found_it = 0;
		}
	        n = 1;
	}
     
	return 0;
  }
