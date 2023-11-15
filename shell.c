#include "shell.h"
/**
 * main - entry point of the shell
 * @argc: arg count
 * @argv: array of arguments
 *
 * Return: 0 on success or other integer
 */
int main(int argc, char *argv[])
{
	size_t bufsize = 0;
	char *input = NULL;
	int i, tokens = 0, cmd = 1, shell_interaction;

	signal(SIGINT, SIG_IGN);
	shell_interaction = isatty(STDIN_FILENO);
	if (shell_interaction == 0 && argc == 1)
	{
		while (getline(&input, &bufsize, stdin) > 0)
		{
			tokens = token_count(input);
			parse(input, tokens, argv, cmd);
			input = NULL;
		}
		free(input);
		return (0);
	}
	while (shell_interaction)
	{
		write(1, "($) ", 4);
		tokens = 0;
		i = getline(&input, &bufsize, stdin);
		if (i < 0)
		{
			free(input);
			write(1, "\n", 1);
			break;
		}
		tokens = token_count(input);
		parse(input, tokens, argv, cmd);
		cmd++;
		input = NULL;
	}
	return (0);
}
