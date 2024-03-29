#include "main.h"

/**
 * remove_new_Line- this function removes new line at the end of command line.
 * @str: command line.
 * Return: new string after removing \n or NULL if it fail.
 */
char *remove_new_Line(char *str)
{
	int len, i = 0;
	char *new_str = NULL;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	new_str = malloc(len * sizeof(char));
	if (new_str == NULL)
		return (NULL);

	while (str[i] != '\n' || str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	free(str);
	new_str[i] = '\0';
	return (new_str);
}
/**
 * clean_command- this function remove new line at the end
 * and also clean extra space at the beginning.
 * @str: command line.
 * Return: return string after cleanning it.
 */
char *clean_command(char *str)
{
	int count = 0, i = 0, p = 0;
	int len = _strlen(str);
	int new_str_len = 0;
	int space_only = 0;
	char *new_string = NULL;

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			space_only += 1;
		if (str[i] == ' ')
			count++;
		else
			break;
		i++;
	}

	new_str_len = len - count;
	new_string = malloc(new_str_len * sizeof(char));
	while (str[i] != '\n')
	{

		new_string[p] = str[i];
		i++;
		p++;
	}
	new_string[p] = '\0';
	free(str);
	return (new_string);
}
