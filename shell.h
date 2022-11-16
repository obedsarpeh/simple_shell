#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>
#include <stdarg.h>
#include <errno.h>

extern char **environ;

/* string_manip */
char *_strdup(char *);
char *_strcat(char *, char *);
int _strcmp(char *, char *);
int _strncmp(char *, char *, int);

/* parser */
int parse(char *, int, char *argv[], int);

/* executer*/
int executor(char *, char **, char *, char **, char **argv, int);

/* shell_utils */
void myfree(char *, char **, char *, char **);
int token_count(char *);

/* shell_builtin */
int bltin(char *, char **, char *, char **);
void change_dir(char **);

/* handle_path */
int search_path(char *, char **);
int find_current_path(char **);
void path(char *, char **);
char *_strcpy(char *, char *);

/* print_str_args */
int print_str_arg(va_list *);

/* puts_putchar */
void _puts(char *);
int _putchar(char);

/**
 * struct fmt - types of data and their function
 * @ltr: the type of data
 * @type: pointer to function for type
 */
typedef struct fmt
{
	char *ltr;
	int (*type)();
} fmt;

#endif
