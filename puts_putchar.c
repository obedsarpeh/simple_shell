#include "shell.h"

/**
 * _puts - functiont to write string
 * @str: string to write
 * Return: void
 */

void _puts(char *str)
{
	while (*str  != '\0')
	{
		write(1, str, 1);
		str++;
	}
}
/**
 * _putchar - writes the character c to sterr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(2, &c, 1));
}

