#include "shell.h"
/**
 * parse - function to convert user input to tokens
 * @input: input to be parsed
 * @tokens: number of tokens
 * @argv: array of arguments
 * @cmd: number of commands that have been entered
 * Return: return 0 upon sucess
 */
int parse(char *input, int tokens, char **argv, int cmd)
{
	int i = 0, j, exval = 0;
	char *p = NULL, *new_input = NULL, **array = NULL, **ar = NULL;
	char *del = " \t\r\n\f\v";

	array = malloc(sizeof(char *) * tokens);
	new_input = _strdup(input);
	p = strtok(new_input, del);
	if (!p)
	{
		myfree(input, ar, new_input, array);
		return (0);
	}
	for (; p != NULL; p = strtok(NULL, del))
		array[i++] = p;
	ar = malloc(sizeof(char *) * (tokens + 1));
	for (i = 0; i < tokens; i++)
		ar[i] = _strdup(array[i]);
	ar[i] = NULL;
	j = bltin(input, ar, new_input, array);
	if (j == 0)
		exval = executor(input, ar, new_input, array, argv, cmd);
	myfree(input, ar, new_input, array);
	return (exval);
}
