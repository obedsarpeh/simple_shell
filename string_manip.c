#include "shell.h"
/**
 * _strcmp - compares two strings
 * @str1: string 1
 * @str2: string 2
 *
 * Return: 0 on success, -1 on fail
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 || *str2)
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
			return (-1);
	}
	return (0);
}
/**
 * _strncmp - function to compare strings
 * @str1: first string to compare
 * @str2: second string to compare
 * @length: length of string to compare
 *
 * Return: 0 for success
 */

int _strncmp(char *str1, char *str2, int length)
{
	for (; *str1 && *str2 && length >= 0; length--)
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
			return (-1);
	}
	return (0);
}
/**
 * _strcat - concatenates two strings
 * @dest: the destination string
 * @src: the source string
 *
 * Return: pointer to dest.
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int len1 = 0;
	int len2 = 0;

	while (*(src + len1) != '\0')
	{
		len1++;
	}

	while (*(dest + len2) != '\0')
	{
		len2++;
	}

	for (i = 0; i <= len1; i++)
	{
		*(dest + (len2 + i)) = *(src + i);
	}
	return (dest);
}
/**
 * _strdup - duplicates one string into another
 * @str: the string to be duplicated
 *
 * Return: a pointer to a duplicate of the string
 */
char *_strdup(char *str)
{
	char *ptr;
	unsigned int i;
	unsigned int size;

	if (!str)
		return (NULL);
	for (size = 0; *(str + size) != '\0'; size++)
		;
	ptr = malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		ptr[i] = str[i];
	}
	ptr[i] = '\0';
	return (ptr);
}
