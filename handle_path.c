#include "shell.h"
/**
 * _strcpy - copies str from src to dest
 * @src: source string
 * @dest: destination string
 * Return: pointer to destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int len = 0;

	while (*(src + len) != '\0')
	{
		len++;
	}

	for (i = 0; i <= len; i++)
	{
		*(dest + i) = *(src + i);
	}
	return (dest);
}
/**
 * execute_path - function to access PATH
 * @path: directory in PATH to access
 * @tokens: array of tokens to check
 */
void execute_path(char *path, char **tokens)
{
	int status, length_1, length_2;
	pid_t child;
	char *new_path = NULL;

	for (length_1 = 0; *(path + length_1) != '\0'; length_1++)
		;
	for (length_2 = 0; tokens[0][length_2] != '\0'; length_2++)
		;
	new_path = malloc(sizeof(char) * (length_1 + length_2 + 2));
	_strcpy(new_path, path);
	_strcat(new_path, "/");
	_strcat(new_path, tokens[0]);
	new_path[(length_1 + length_2 + 1)] = '\0';

	child = fork();

	if (child == 0)
	{
		if (access(new_path, X_OK) == 0)
		{
			execve(new_path, tokens, environ);
		}
	}
	else
	{
		while (waitpid(-1, &status, 0) != child)
			;
	}
	if (status == 0)
		errno = 0;
	free(new_path);
}
/**
 * search_path - function to search PATH
 * @path: part of PATH to search
 * @tokens: array of tokens
 * Return: 0 for success
 */

int search_path(char *path, char **tokens)
{
	struct dirent *de;
	int reached = 0, current_path = -1;
	DIR *dr;

	path = strtok(path, ":");
	while (path && reached != 1)
	{
		dr = opendir(path);
		if (!dr)
		{
			return (0);
		}
		while ((de = readdir(dr)) != NULL)
		{
			if (_strcmp(de->d_name, tokens[0]) == 0)
			{
				execute_path(path, tokens);
				current_path = 0;
				reached = 1;
				break;
			}
		}
		closedir(dr);
		if (reached == 0)
			path = strtok(NULL, ":");
	}
	return (current_path);
}
/**
 * find_current_path - find PATH in environ
 * @tokens: token to pass along to PATH
 * Return: 0 for success
 */

int find_current_path(char **tokens)
{
	int i = 0, current_path;
	char *p = NULL;
	char *path = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp("PATH=", environ[i], 5) == 0)
		{
			path = _strdup(environ[i]);
			strtok(path, "=");
			p = strtok(NULL, "=");
			current_path = search_path(p, tokens);
			break;
		}
	}
	free(path);
	return (current_path);
}

