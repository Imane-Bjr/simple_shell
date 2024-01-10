#include "main.h"

/**
 * concatenate -function that concatenate two strings.
 * @str: input string.
 * Return: string .
 */
char *concatenate(char *str)
{
	char *path = "/bin/";
	int len = 0;
	char *full_path = NULL;
	int i = 0, p = 0;

	if (str)
		len = _strlen(str);
	full_path = malloc(len + _strlen(path) + 1);

	if (full_path == NULL)
	{
		return (NULL);
	}

	while (path[i] != '\0')
	{
		full_path[i] = path[i];
		i++;
	}
	p = i;
	i = 0;
	while (str[i] != '\0')
	{
		full_path[p] = str[i];
		i++;
		p++;
	}

	free(str);
	full_path[p] = '\0';
	return (full_path);
}
