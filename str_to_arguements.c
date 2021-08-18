#include "shell.h"

/**
 *str_to_arguments - a
 *@buffer: a
 *@sep: a
 *Return: a
 */
char **str_to_arguments(char *buffer, char sep)
{
	char **out;
	int i, i2, i3, error = 0, arg_amount = 1;
	char *ptr, *tmp;

	for (i = 0; buffer[i]; i++)
		if (buffer[i] == sep)
			if (buffer[i + 1] && (buffer[i + 1] != sep))
				arg_amount++;
	out = malloc((arg_amount + 1) * sizeof(char *));
	if (!out)
		return (out);
	out[arg_amount] = NULL;
	ptr = buffer;
	for (i = 0; i < arg_amount; i++)
	{
		while (ptr[0] == sep)
			ptr = ptr + 1;
		for (i2 = 0; ptr[i2] && (ptr[i2] != sep); i2++)
			;
		tmp = malloc(i2 + 1);
		tmp[i2] = 0;
		if (!tmp)
		{
			error = 1;
			break;
		}
		for (i3 = 0; i3 < i2; i3++)
			tmp[i3] = ptr[i3];
		ptr += i2;
		out[i] = tmp;
	}
	if (error)
	{
		for (i2 = 0; i2 < i; i2++)
			free(out[i2]);
		free(out);
	}
	return (out);
}
char *mystrcat(char *a, char *b)
{
	char *p, *q, *rtn;

	rtn = q = malloc(strlen(a) + strlen(b) + 2);
	if (rtn)
	{
		for (p = a; (*q = *p) != '\0'; ++p, ++q)
			;
		*q = '/';
		++q;
		for (p = b; (*q = *p) != '\0'; ++p, ++q)
			;
	}
	return (rtn);
}
char *get_env(char *str)
{
	extern char **environ;
	int i, a, differ;

	for (i = 0; environ[i]; i++)
	{
		differ = 1;
		for (a = 0; str[a]; a++)
			if (str[a] != environ[i][a])
			{
				differ = 0;
				break;
			}
		if (differ)
			return (environ[i] + a + 1);
	}
	return (NULL);
}
void set_col(int c)
{
	switch(c)
	{
	case 0:
		write(1, "\e[0;37m", 7);
		break;
	case 1:
		write(1, "\e[0;33m", 7);
		break;
	case 2:
		write(1, "\e[0;32m", 7);
		break;
	case 3:
		write(1, "\e[0;31m", 7);
		break;
	case 4:
		write(1, "\e[46;1m", 7);
		break;
	}
}
