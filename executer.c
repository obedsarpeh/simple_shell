#include "shell.h"
/**
 * executor - function to execute new processes
 * @i: input from user
 * @ar1: array to be handled by execve
 * @new: duplicate of line
 * @ar2: Tokens to check
 * @argv: arguments
 * @f: number of commands that have failed
 * Return: 0 for success
 */
int executor(char *i, char **ar1, char *new, char **ar2, char **argv, int f)
{
	int status, current_path = -1;
	pid_t child;
	struct stat *statbuf;

	statbuf = malloc(sizeof(struct stat));
	if (stat(ar1[0], statbuf) == -1)
	{
		current_path = find_current_path(ar1);
		if (current_path == 0)
		{
			free(statbuf);
			return (0);
		}
	}
	child = fork();
	if (child == 0)
	{
		if (execve(ar1[0], ar1, environ) == -1)
		{
			printf("%s: %d: %s: not found\n", argv[0], f, ar1[0]);
			free(statbuf);
			myfree(i, ar1, new, ar2);
			_exit(-1);
		}
	}
	else
	{
		while (waitpid(-1, &status, 0) != child)
			;
	}
	free(statbuf);
	if (status == 0)
		errno = 0;
	if (status == 512)
		errno = 2;
	if (status == 65280)
		errno = 127;
	return (0);
}
