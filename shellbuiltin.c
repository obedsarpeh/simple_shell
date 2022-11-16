#include "shell.h"
/**
 * change_dir - changes directory to ar
 * @array: the directory to change to or nothing
 */
void change_dir(char **array)
{
	int i = 0;
	char *home_value = NULL, *home = NULL;

	if (array[1] == NULL)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			if (_strncmp("HOME=", environ[i], 5) == 0)
			{
				home = _strdup(environ[i]);
				strtok(home, "=");
				home_value = strtok(NULL, "=");
				break;
			}
		}
	}
	else
		home_value = array[1];
	chdir(home_value);
	free(home);
}
/**
 * bltin - checks if the command entered is a built-in
 * @input: input entered by user
 * @ar: array that can be handled by execve
 * @newline: duplicate of line
 * @array: Tokens to check
 * Return: Return depends upon if the built-in was found
 */
int bltin(char *input, char **ar, char *newline, char **array)
{
	int i = 0;

	if (_strcmp(ar[0], "exit") == 0)
	{
		myfree(input, ar, newline, array);
		_exit(errno);
	}
	if (_strcmp(ar[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			_puts(environ[i]);
			write(1, "\n", 1);
		}
		return (2);
	}
	if (_strcmp(ar[0], "cd") == 0)
	{
		change_dir(ar);
		return (2);
	}
	return (0);
}
