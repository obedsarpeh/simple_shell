#include "shell.h"
/**
 * myfree - function to free memory
 * @line: line to be freed
 * @ar: array to be freed
 * @newline: line to be freed
 * @array: array to be freed
 */
void myfree(char *line, char **ar, char *newline, char **array)
{
	int i = 0;

	if (ar != NULL)
	{
		while (ar[i] != NULL)
		{
			free(ar[i]);
			i++;
		}
		free(ar);
	}
	if (newline != NULL)
		free(newline);
	if (line != NULL)
		free(line);
	if (array != NULL)
		free(array);
}
/**
 * token_count - function to count number of tokens that will be created
 * @input: input to check number of tokens to make out of
 *
 * Return: number of tokens to make
 */
int token_count(char *input)
{
	int num_tokens = 0, i, check = 1;

	for (i = 0; input[i]; i++)
	{
		if (input[i] == ' ' || input[i] == 10 || input[i] == '\t')
			check = 1;
		else if (check == 1)
		{
			check = 0;
			++num_tokens;
		}
	}
	return (num_tokens);
}
